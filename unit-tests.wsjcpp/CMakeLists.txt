cmake_minimum_required(VERSION 3.0)

project(unit-tests)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${unit-tests_SOURCE_DIR})

set (WSJCPP_LIBRARIES "")
set (WSJCPP_INCLUDE_DIRS "")
set (WSJCPP_SOURCES "")

# Sources

# wsjcpp-core
list (APPEND WSJCPP_SOURCES "../src/wsjcpp_core.h")
list (APPEND WSJCPP_SOURCES "../src/wsjcpp_core.cpp")

# include header dirs
list (APPEND WSJCPP_INCLUDE_DIRS "../src")
list (APPEND WSJCPP_INCLUDE_DIRS "src")


list (APPEND WSJCPP_SOURCES "../src/unit_tests_main.cpp")
list (APPEND WSJCPP_SOURCES "../src/unit_tests.h")
list (APPEND WSJCPP_SOURCES "../src/unit_tests.cpp")
list (APPEND WSJCPP_SOURCES "./src/unit_test_core_extract_filename.h")
list (APPEND WSJCPP_SOURCES "./src/unit_test_core_extract_filename.cpp")
list (APPEND WSJCPP_SOURCES "./src/unit_test_core_normalize_path.h")
list (APPEND WSJCPP_SOURCES "./src/unit_test_core_normalize_path.cpp")
list (APPEND WSJCPP_SOURCES "./src/unit_test_core_uuid.h")
list (APPEND WSJCPP_SOURCES "./src/unit_test_core_uuid.cpp")
list (APPEND WSJCPP_SOURCES "./src/unit_test_ip_v4.h")
list (APPEND WSJCPP_SOURCES "./src/unit_test_ip_v4.cpp")
list (APPEND WSJCPP_SOURCES "./src/unit_test_ip_v6.h")
list (APPEND WSJCPP_SOURCES "./src/unit_test_ip_v6.cpp")

include_directories(${WSJCPP_INCLUDE_DIRS})

add_executable ("unit-tests" ${WSJCPP_SOURCES})

target_link_libraries("unit-tests" -lpthread ${WSJCPP_LIBRARIES} )

install(
    TARGETS
        "unit-tests"
    RUNTIME DESTINATION
        /usr/bin
)