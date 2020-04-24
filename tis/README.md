# First try

The idea here is to use the S2OPC repository as the root of the analysis.
A `tis` branch is created to add the files needed to do the analysis.
Except the `tis.config` file that must be at the root of the repository,
all the other files and directory should be in in a `tis` directory,
in particular the dependancies that are added there as submodules.

## S2OPC repository

```
$ git clone https://gitlab.com/systerel/S2OPC.git --branch S2OPC_Toolkit_1.0.0
$ cd S2OPC
$ git remote rename origin upstream
$ git remote add origin ssh://git@git.trust-in-soft.com:7999/use/s2opc.git
$ git checkout -b master
$ git push -u origin master
```

Now create out `tis` branch and the `tis` directory:

```
$ git checkout -b tis
$ git push -u origin tis
$ mkdir tis
$ cd tis

# Edit this README.md file here
$ git add README.md

$ PREFIX=$PWD/prefix
```

## Install dependencies


The `PREFIX` directory defined above is used as the local installation
directory.
Since S2OPC uses Cmake, it seems easier (mandatory?) to also use Cmake to
compile the dependencies.
Moreover,`CMAKE_EXPORT_COMPILE_COMMANDS` can then be used.

Note: `cmake -LH ..` can be useful to get the configurable variables.

### libcheck

```
$ cd $PREFIX/..
$ git submodule add https://github.com/libcheck/check.git
$ cd check ; git checkout 0.14.0 ; cd ..
$ mkdir build_libcheck && cd build_libcheck
$ cmake ../check -DCMAKE_EXPORT_COMPILE_COMMANDS=On \
                 -DCMAKE_INSTALL_PREFIX=$PREFIX
$ make && make install
$ tis-prepare all-symbol-table -- -64 -cpp-tool gcc
$ tis-prepare clean
```

```
[INFO] Summary: 30+15/45 (100%) [OK+CACHED]   0/45 (0%) [SKIPPED]   0/45 (0%) [FAIL]
```

### mbedtls

```
$ cd $PREFIX/..
$ git submodule add https://github.com/ARMmbed/mbedtls.git
$ cd mbedtls ; git checkout mbedtls-2.12.0 ; cd ..
$ mkdir build_mbedtls && cd build_mbedtls
$ cmake ../mbedtls -DCMAKE_EXPORT_COMPILE_COMMANDS=On \
                   -DCMAKE_INSTALL_PREFIX=$PREFIX
$ make && make install
$ tis-prepare all-symbol-table -- -64 -cpp-tool gcc
$ tis-prepare clean
```

```
[INFO] Summary: 197+0/197 (100%) [OK+CACHED]   0/197 (0%) [SKIPPED]   0/197 (0%) [FAIL]
```

### libexpat

```
$ cd $PREFIX/..
$ git clone https://github.com/libexpat/libexpat.git --branch R_2_2_9
$ mkdir build_expat && cd build_expat
$ cmake ../libexpat/expat -DCMAKE_EXPORT_COMPILE_COMMANDS=On \
                          -DCMAKE_INSTALL_PREFIX=$PREFIX \
                          -DEXPAT_WITH_SYS_GETRANDOM=Off \
                          -DEXPAT_BUILD_TESTS=Off
$ make && make install
$ tis-prepare all-symbol-table -- -64 -cpp-tool gcc
$ tis-prepare clean
```

```
[INFO] Summary: 1+8/9 (100%) [OK+CACHED]   0/9 (0%) [SKIPPED]   0/9 (0%) [FAIL]
```

## S2OPC compilation


```
$ cd $PREFIX/..
$ mkdir build_s2opc && cd build_s2opc
$ cmake ../.. -DCMAKE_EXPORT_COMPILE_COMMANDS=On \
              -DCMAKE_INSTALL_PREFIX=$PREFIX \
              -DCMAKE_PREFIX_PATH=$PREFIX
$ make
$ tis-prepare all-symbol-table -- -64 -cpp-tool gcc
$ tis-prepare clean
```

```
[INFO] Summary: 280+63/345 (99%) [OK+CACHED]   0/345 (0%) [SKIPPED]   2/345 (0%) [FAIL]
```

## S2OPC test configuration
