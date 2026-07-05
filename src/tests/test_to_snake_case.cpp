/*
 * MIT License
 *
 * Copyright (c) 2019-2026 Evgenii Sopov
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

// original source-code: https://github.com/wsjcpp/wsjcpp-core


#include <vector>
#include <iostream>
#include <wsjcpp_core.h>

int main() {
  int found_errors = 0;
  std::string error;

  struct LTest {
    LTest(
      const std::string &name,
      const std::string &snake_name
    ) {
      this->name = name;
      this->snake_name = snake_name;
    };
    std::string name;
    std::string snake_name;
  };

  std::vector<LTest> tests;
  tests.push_back(LTest("PackageName", "package_name"));
  tests.push_back(LTest("./Bo/file.txt", "bo_file_txt"));
  tests.push_back(LTest("./1/bo/../file.txt", "_1_bo_file_txt"));
  tests.push_back(LTest("./bo/../file.txt", "bo_file_txt"));
  tests.push_back(LTest("file.txt", "file_txt"));
  tests.push_back(LTest("", ""));
  tests.push_back(LTest("A", "a"));
  tests.push_back(LTest("____A", "a"));
  tests.push_back(LTest("A____", "a"));
  tests.push_back(LTest("a", "a"));
  tests.push_back(LTest("//a/b/c/d/////", "a_b_c_d"));
  tests.push_back(LTest("https://github.com/wsjcpp/wsjcpp-core/issues/24", "https_github_com_wsjcpp_wsjcpp_core_issues_24"));

  for (int i = 0; i < tests.size(); i++) {
    LTest test = tests[i];
    std::string got = wsjcpp::to_snake_case(test.name);
    if (got != test.snake_name) {
      found_errors++;
      std::cerr << "Expected '" << test.snake_name << "', but got '" << got << "'" << std::endl;
    }
  }
  if (found_errors > 0) {
    return 1;
  }
  std::cout << "ok" << std::endl;
  return 0;
}