cmake_minimum_required(VERSION 3.0)

project(wsjcpp-core)

include(${CMAKE_CURRENT_SOURCE_DIR}/src.wsjcpp/CMakeLists.txt)

#### BEGIN_WSJCPP_APPEND
#### END_WSJCPP_APPEND

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${wsjcpp-core_SOURCE_DIR})

# Sources

# include header dirs
list (APPEND WSJCPP_INCLUDE_DIRS "src")

list (APPEND WSJCPP_SOURCES "src/wsjcpp_core.h")
list (APPEND WSJCPP_SOURCES "src/wsjcpp_core.cpp")

list (APPEND WSJCPP_SOURCES "src/main.cpp")

include_directories(${WSJCPP_INCLUDE_DIRS})

add_executable ("wsjcpp-core" ${WSJCPP_SOURCES})

target_link_libraries("wsjcpp-core" -lpthread ${WSJCPP_LIBRARIES} )

install(
    TARGETS
        "wsjcpp-core"
    RUNTIME DESTINATION
        /usr/bin
)


