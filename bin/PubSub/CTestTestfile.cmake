# CMake generated Testfile for 
# Source directory: S2OPC_ROOT_DIR/tests/PubSub
# Build directory: S2OPC_ROOT_DIR/tests/PubSub
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(unit::xml_parser_test "S2OPC_ROOT_DIR/bin/xml_parser_test")
set_tests_properties(unit::xml_parser_test PROPERTIES  ENVIRONMENT "CK_TAP_LOG_FILE_NAME=xml_parser_test.tap" WORKING_DIRECTORY "S2OPC_ROOT_DIR/bin")
add_test(unit::pubsub_modules_test "S2OPC_ROOT_DIR/bin/pubsub_modules_test")
set_tests_properties(unit::pubsub_modules_test PROPERTIES  ENVIRONMENT "CK_TAP_LOG_FILE_NAME=pubsub_modules_test.tap" WORKING_DIRECTORY "S2OPC_ROOT_DIR/bin")
add_test(validation::ll_pub_sub_test "python3" "S2OPC_ROOT_DIR/tests/scripts/tap-wrap.py" "python3" "S2OPC_ROOT_DIR/tests/PubSub/scripts/with-publisher.py" "--publisher-cmd" "S2OPC_ROOT_DIR/bin/udp_pub_test" "S2OPC_ROOT_DIR/bin/udp_sub_test")
set_tests_properties(validation::ll_pub_sub_test PROPERTIES  ENVIRONMENT "CK_TAP_LOG_FILE_NAME=ll_pub_sub_test.tap" WORKING_DIRECTORY "S2OPC_ROOT_DIR/bin")
add_test(validation::ll_pub_sub_conf_test "python3" "S2OPC_ROOT_DIR/tests/scripts/tap-wrap.py" "python3" "S2OPC_ROOT_DIR/tests/PubSub/scripts/with-publisher.py" "--publisher-cmd" "S2OPC_ROOT_DIR/bin/udp_pub_conf_test" "S2OPC_ROOT_DIR/bin/udp_sub_test")
set_tests_properties(validation::ll_pub_sub_conf_test PROPERTIES  ENVIRONMENT "CK_TAP_LOG_FILE_NAME=ll_pub_sub_conf_test.tap" WORKING_DIRECTORY "S2OPC_ROOT_DIR/bin")
add_test(validation::ll_pub_sub_xml_test "python3" "S2OPC_ROOT_DIR/tests/scripts/tap-wrap.py" "python3" "S2OPC_ROOT_DIR/tests/PubSub/scripts/with-publisher.py" "--publisher-cmd" "S2OPC_ROOT_DIR/bin/udp_pub_xml_test" "S2OPC_ROOT_DIR/bin/udp_sub_conf_test")
set_tests_properties(validation::ll_pub_sub_xml_test PROPERTIES  ENVIRONMENT "CK_TAP_LOG_FILE_NAME=ll_pub_sub_xml_test.tap" WORKING_DIRECTORY "S2OPC_ROOT_DIR/bin")
add_test(validation::publisher_scheduler_test "python3" "S2OPC_ROOT_DIR/tests/scripts/tap-wrap.py" "python3" "S2OPC_ROOT_DIR/tests/PubSub/scripts/with-publisher.py" "--publisher-cmd" "S2OPC_ROOT_DIR/bin/udp_pub_scheduler_test" "S2OPC_ROOT_DIR/bin/udp_sub_conf_test")
set_tests_properties(validation::publisher_scheduler_test PROPERTIES  ENVIRONMENT "CK_TAP_LOG_FILE_NAME=publisher_scheduler_test.tap" WORKING_DIRECTORY "S2OPC_ROOT_DIR/bin")
add_test(validation::ll_multi_pub_sub_test "python3" "S2OPC_ROOT_DIR/tests/scripts/tap-wrap.py" "python3" "S2OPC_ROOT_DIR/tests/PubSub/scripts/with-publisher.py" "--publisher-cmd" "S2OPC_ROOT_DIR/bin/udp_multi_pub_test" "S2OPC_ROOT_DIR/bin/udp_multi_sub_test")
set_tests_properties(validation::ll_multi_pub_sub_test PROPERTIES  ENVIRONMENT "CK_TAP_LOG_FILE_NAME=ll_multi_pub_sub_test.tap" WORKING_DIRECTORY "S2OPC_ROOT_DIR/bin")
add_test(validation::pubsub_server_test.py "python3" "S2OPC_ROOT_DIR/tests/PubSub/scripts/with-publisher.py" "--publisher-cmd" "S2OPC_ROOT_DIR/bin/pubsub_server" "python3" "S2OPC_ROOT_DIR/tests/PubSub/validation_tools/pubsub_server_test.py")
set_tests_properties(validation::pubsub_server_test.py PROPERTIES  WORKING_DIRECTORY "S2OPC_ROOT_DIR/bin")
add_test(interop::open62541_pub "python3" "S2OPC_ROOT_DIR/tests/scripts/tap-wrap.py" "python3" "S2OPC_ROOT_DIR/tests/PubSub/scripts/with-publisher.py" "--publisher-cmd" "S2OPC_ROOT_DIR/tests/PubSub/bin_interop/open62541_pub" "S2OPC_ROOT_DIR/bin/interop_sub_test")
set_tests_properties(interop::open62541_pub PROPERTIES  ENVIRONMENT "CK_TAP_LOG_FILE_NAME=interop_pub_test.tap" WORKING_DIRECTORY "S2OPC_ROOT_DIR/bin")
add_test(interop::open62541_sub "python3" "S2OPC_ROOT_DIR/tests/scripts/tap-wrap.py" "python3" "S2OPC_ROOT_DIR/tests/PubSub/scripts/with-publisher.py" "--publisher-cmd" "S2OPC_ROOT_DIR/bin/udp_pub_scheduler_test S2OPC_ROOT_DIR/bin/config_pub_interop.xml" "S2OPC_ROOT_DIR/tests/PubSub/bin_interop/open62541_sub")
set_tests_properties(interop::open62541_sub PROPERTIES  ENVIRONMENT "CK_TAP_LOG_FILE_NAME=interop_sub_test.tap" WORKING_DIRECTORY "S2OPC_ROOT_DIR/bin")
