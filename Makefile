# OS DEPENDENCIES

OSTYPE=$(shell echo $$OSTYPE)

ifdef CROSS_COMPILE_WIN
     OSTYPE=cc_win
     export CROSS_COMPILE_WIN
endif

ifeq ($(OSTYPE),$(filter linux% darwin%,$(OSTYPE)))
     CC=gcc
     EXCLUDE_DIR="*win*"
     PLATFORM_DIR="*linux*"
     PFLAGS=-std=c99 -pedantic -D_XOPEN_SOURCE=600
     LIBS=$(LIBS_MBEDTLS) -lpthread
     INCLUDES_OTHERS=
else
    # PREFIX_CHECK must be defined for windows: path to libcheck installation
    LIB_CHECK=$(PREFIX_CHECK)/lib
    INCLUDE_CHECK=$(PREFIX_CHECK)/include
    EXCLUDE_DIR="*linux*"
    PLATFORM_DIR="*win*"
    PFLAGS=-std=c99 -pedantic
    LIBS=$(LIBS_MBEDTLS) -lrpcrt4 -lws2_32 -L$(LIB_CHECK)
    INCLUDES_OTHERS=-I$(INCLUDE_CHECK)
    DEF_WINDOWS=-D_WIN32_WINNT=0x0600 # minimum Vista for IPV6 support
    WINDOWS=1
    export WINDOWS
ifdef CROSS_COMPILE_WIN
    CC=i686-w64-mingw32-gcc
else
    CC=gcc
endif
endif

export CC

ifdef STACK_1_01
    DEF_STACK=-DSTACK_1_01 
else
    ifdef STACK_1_02
       DEF_STACK=-DSTACK_1_02 
    else
       DEF_STACK=-DSTACK_1_03 
    endif
endif

ifdef WRAPPER_RECEPTION_THREAD
    DEF_THREAD=-DWRAPPER_RECEPTION_THREAD
endif

ifdef SHARED
    SHARED_FLAG=-fPIC
    MBED_SHARED="SHARED=yes"
endif

# OUTPUTS
WORKSPACE_DIR=.
CERT_DIR=$(WORKSPACE_DIR)/cert
EXEC_DIR=$(WORKSPACE_DIR)/out
BUILD_DIR=$(WORKSPACE_DIR)/build
BUILD_DIR_SED=$(subst /,\/,$(BUILD_DIR))
LOCAL_INSTALL_DIR=$(WORKSPACE_DIR)/install

# INPUTS

## Directories
### srcs directories definition
UASTACK_DIR=$(WORKSPACE_DIR)/src
STUBCLIENT_DIR=$(WORKSPACE_DIR)/stub_client
STUBSERVER_DIR=$(WORKSPACE_DIR)/stub_server
TESTS_DIR=$(WORKSPACE_DIR)/test/ingopcs
### concatenate all srcs directories
C_SRC_DIRS=$(UASTACK_DIR) $(STUBCLIENT_DIR) $(STUBSERVER_DIR) $(TESTS_DIR)

## Stack
### includes stack
INCLUDES_UASTACK=$(shell find $(UASTACK_DIR) -not -path $(EXCLUDE_DIR) -type d)
## object files stack
STACK_SRC_FILES=$(shell find $(UASTACK_DIR) -not -path $(EXCLUDE_DIR) -not -path $(PLATFORM_DIR) -type f -name "*.c" -exec basename "{}" \;)
STACK_OBJ_FILES=$(patsubst %.c,$(BUILD_DIR)/%.o,$(STACK_SRC_FILES))

PLATFORM_BUILD_DIR=$(BUILD_DIR)_platform
PLATFORM_BUILD_DIR_SED=$(subst /,\/,$(PLATFORM_BUILD_DIR))
PLATFORM_SRC_FILES=$(shell find $(UASTACK_DIR) -path $(PLATFORM_DIR) -type f -name "*.c" -exec basename "{}" \;)
PLATFORM_OBJ_FILES=$(patsubst %.c,$(PLATFORM_BUILD_DIR)/%.o,$(PLATFORM_SRC_FILES))

# add platform objs prior to stack objs
UASTACK_OBJ_FILES=$(PLATFORM_OBJ_FILES) $(STACK_OBJ_FILES)

## Tests object files
TESTS_SRC_FILES=$(shell find $(TESTS_DIR) -type f -name "*.c" -exec basename "{}" \;)
TESTS_OBJ_FILES=$(patsubst %.c,$(BUILD_DIR)/%.o,$(TESTS_SRC_FILES))

## All .c and .h files to compute dependencies
C_SRC_PATHS=$(shell find $(C_SRC_DIRS) -not -path $(EXCLUDE_DIR) -type f -name "*.c")
H_SRC_PATHS=$(shell find $(C_SRC_DIRS) -not -path $(EXCLUDE_DIR) -type f -name "*.h")
H_INCLUDE_PATHS=$(shell find $(UASTACK_DIR)/API $(UASTACK_DIR)/APIwrappers $(UASTACK_DIR)/crypto $(UASTACK_DIR)/core_types -maxdepth 1 -type f -name "*.h")

# MBEDTLS INPUTS
MBEDTLS_DIR=$(WORKSPACE_DIR)/lib/mbedtls-2.3.0
INCLUDES_MBEDTLS=-I$(MBEDTLS_DIR)/include
LIBS_MBEDTLS=-L$(MBEDTLS_DIR)/library -lmbedtls -lmbedx509 -lmbedcrypto

# C COMPILER CONFIG
CFLAGS=-c -g -Wall -Wextra -O0 $(SHARED_FLAG)
C99FLAGS=-std=c99 -pedantic
LFLAGS=-g
INCLUDES=$(INCLUDES_MBEDTLS) $(addprefix -I, $(INCLUDES_UASTACK)) $(INCLUDES_OTHERS)
DEFS=$(DEF_STACK) $(DEF_THREAD) $(DEF_WINDOWS)

# MAKEFILE CONTENT

.PHONY : all doc config mbedtls library install check clean clean_doc clean_config clean_mbedtls cleanall
.DELETE_ON_ERROR : .depend.tmp .depend .pdepend

default: all

all: config library $(EXEC_DIR)/stub_client_ingopcs $(EXEC_DIR)/stub_server_ingopcs $(EXEC_DIR)/check_stack

# TODO: replace by unique filter
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),clean_doc)
ifneq ($(MAKECMDGOALS),clean_config)
ifneq ($(MAKECMDGOALS),clean_mbedtls)
ifneq ($(MAKECMDGOALS),cleanall)
ifneq ($(MAKECMDGOALS),config)
ifneq ($(MAKECMDGOALS),doc)
ifneq ($(MAKECMDGOALS),install)
-include .depend
-include .pdepend
endif
endif
endif
endif
endif
endif
endif
endif

doc:
	@echo "Generating documentation in apidoc/ with doxygen"
	@doxygen doxygen/ingopcs-stack.doxyfile -DOPCUA_HAVE_CLIENTAPI=1

config: mbedtls
	@echo "Configuring build dirs..."
	@"mkdir" -p $(BUILD_DIR) $(PLATFORM_BUILD_DIR) $(EXEC_DIR)
	@"mkdir" -p $(EXEC_DIR)/revoked $(EXEC_DIR)/untrusted $(EXEC_DIR)/trusted \
	 $(EXEC_DIR)/client_private $(EXEC_DIR)/server_private \
	 $(EXEC_DIR)/client_public $(EXEC_DIR)/server_public
	@"cp" $(CERT_DIR)/cacert.der $(EXEC_DIR)/trusted
	@"cp" $(CERT_DIR)/client.key $(EXEC_DIR)/client_private
	@"cp" $(CERT_DIR)/client.der $(EXEC_DIR)/client_public
	@"cp" $(CERT_DIR)/server.key $(EXEC_DIR)/server_private
	@"cp" $(CERT_DIR)/server.der $(EXEC_DIR)/server_public

$(BUILD_DIR)/%.o:
	@echo "  CC $@"
	@$(CC) $(CFLAGS) $(C99FLAGS) $(INCLUDES) $< -o $@ $(DEFS)

$(PLATFORM_BUILD_DIR)/%.o:
	@echo "  CC $@"
	@$(CC) $(CFLAGS) $(PFLAGS) $(INCLUDES) $< -o $@ $(DEFS)

.depend: $(C_SRC_PATHS) #$(H_SRC_PATHS)
	@echo "Building dependencies..."
	@$(CC) $(CFLAGS) $(DEFS) $(INCLUDES) -MM $(C_SRC_PATHS) > $@.tmp
	@sed 's/^\(.*\)\.o:/$(BUILD_DIR_SED)\/\1.o:/g' $@.tmp > $@

.pdepend: .depend
	@echo "Building platform dependencies..."
	@sed 's/^\(.*\)\.o:/$(PLATFORM_BUILD_DIR_SED)\/\1.o:/g' $^.tmp > $@

$(EXEC_DIR)/stub_client_ingopcs: $(UASTACK_OBJ_FILES) $(BUILD_DIR)/stub_client_ingopcs.o
	@echo "Linking $@..."
	@$(CC) $(LFLAGS) $(INCLUDES) $^ -o $@ $(LIBS_DIR) $(LIBS)

$(EXEC_DIR)/stub_server_ingopcs: $(UASTACK_OBJ_FILES) $(BUILD_DIR)/stub_server_ingopcs.o
	@echo "Linking $@..."
	@$(CC) $(LFLAGS) $(INCLUDES) $^ -o $@ $(LIBS_DIR) $(LIBS)

$(EXEC_DIR)/check_stack: $(UASTACK_OBJ_FILES) $(TESTS_OBJ_FILES) $(BUILD_DIR)/check_stack.o
	@echo "Linking $@..."
	@$(CC) $(LFLAGS) $(INCLUDES) $^ -o $@ $(LIBS_DIR) $(LIBS) -lcheck -lm

library: $(UASTACK_OBJ_FILES)
	@echo "Generating static library in $(LOCAL_INSTALL_DIR)/lib"
	@"mkdir" -p $(LOCAL_INSTALL_DIR)/lib
	@ar -rc $(LOCAL_INSTALL_DIR)/lib/libingopcs.a $^
	@ar -s $(LOCAL_INSTALL_DIR)/lib/libingopcs.a
	@echo "Copying headers to includes in $(LOCAL_INSTALL_DIR)/include"
	@"mkdir" -p $(LOCAL_INSTALL_DIR)/include
	@"cp" $(H_INCLUDE_PATHS) $(LOCAL_INSTALL_DIR)/include

install: 
	@echo "Install INGOPCS library files into $INSTALL_PREFIX"
	@"cp" -r $(LOCAL_INSTALL_DIR)/* $(INSTALL_PREFIX)/

client_server_test: $(EXEC_DIR)/stub_client_ingopcs $(EXEC_DIR)/stub_server_ingopcs
	./run_client_server_test.sh

mbedtls:
	@echo "Building mbedtls..."
	@$(MAKE) $(MBED_SHARED) -C $(MBEDTLS_DIR) programs tests

check: $(EXEC_DIR)/check_stack
	@echo "Executing tests..."
	@\cd $(EXEC_DIR) && ./check_stack

clean_mbedtls:
	@echo "Cleaning mbedtls"
	@$(MAKE) -C $(MBEDTLS_DIR) clean

clean_config:
	@echo "Cleaning configuration..."
	@"rm" -rf $(BUILD_DIR) $(PLATFORM_BUILD_DIR) $(EXEC_DIR)

clean_doc:
	@echo "Cleaning documentation..."
	@"rm" -rf apidoc

clean:
	@echo "Cleaning..."
	@"rm" -rf $(BUILD_DIR)/* $(PLATFORM_BUILD_DIR)/* $(EXEC_DIR)/check_stack $(EXEC_DIR)/stub_*
	@"rm" -rf $(LOCAL_INSTALL_DIR)
	@"rm" -f .depend.tmp .depend .pdepend

cleanall: clean clean_config clean_doc clean_mbedtls
