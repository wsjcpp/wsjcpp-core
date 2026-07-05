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
      const std::string &filepath,
      const std::string &expected_parent_dirpath
    ) {
      this->filepath = filepath;
      this->expected_parent_dirpath = expected_parent_dirpath;
    };
    std::string filepath;
    std::string expected_parent_dirpath;
  };

  std::vector<LTest> tests;
  tests.push_back(LTest("./bo/file.txt", "./bo"));
  tests.push_back(LTest("./1/bo/../file.txt", "./1"));
  tests.push_back(LTest("./bo/../file.txt", "."));
  tests.push_back(LTest("file.txt", ""));
  tests.push_back(LTest("", ""));
  tests.push_back(LTest("//a/b/c/d/////", "/a/b/c"));

  for (int i = 0; i < tests.size(); i++) {
    LTest test = tests[i];
    std::string got = wsjcpp::parent_dirpath(test.filepath);
    if (got != test.expected_parent_dirpath) {
      found_errors++;
      std::cerr << "Expected'" << test.expected_parent_dirpath << "', but got '" << got << "'" << std::endl;
    }
  }
  if (found_errors > 0) {
    return 1;
  }
  std::cout << "ok" << std::endl;
  return 0;
}