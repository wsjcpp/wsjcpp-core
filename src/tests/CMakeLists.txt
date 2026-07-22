# MIT License
#
# Copyright (c) 2019-2026 Evgenii Sopov
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#
# original source-code: https://github.com/wsjcpp/wsjcpp-core

file(GLOB ALL_TESTS
  "test_*.cpp"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY tests)

list (APPEND TEST_WSJCPP_CORE_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/../")
list (APPEND TEST_WSJCPP_CORE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/../wsjcpp_core.cpp")
list (APPEND TEST_WSJCPP_CORE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/../resources.wsjcpp/__src_resources_html_images_favicon_svg_pathc6e5e4.cpp")


include_directories(${TEST_WSJCPP_CORE_INCLUDE_DIRS})

foreach(_TEST ${ALL_TESTS})
  get_filename_component(TEST_NAME ${_TEST} NAME_WE)
  add_executable(${TEST_NAME}
    ${_TEST}
    ${TEST_WSJCPP_CORE_SOURCES}
  )
  target_link_libraries(${TEST_NAME} -lpthread ${WSJCPP_LIBRARIES})

  add_test(
    NAME ${TEST_NAME}
    COMMAND $<TARGET_FILE:${TEST_NAME}>
  )
  message(${CMAKE_CURRENT_BINARY_DIR}/tests)
  set_target_properties (${TEST_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY tests)
endforeach()
