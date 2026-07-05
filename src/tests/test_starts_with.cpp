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
      const std::string &str,
      const std::string &start_str,
      bool expected
    ) {
      this->str = str;
      this->start_str = start_str;
      this->expected = expected;
    };
    std::string str;
    std::string start_str;
    bool expected;
  };

  std::vector<LTest> tests;
  tests.push_back(LTest("123456789", "123", true));
  tests.push_back(LTest("122456789", "123", false));
  tests.push_back(LTest("12", "123", false));
  tests.push_back(LTest("12", "abc", false));
  tests.push_back(LTest("^1234567", "123", false));
  tests.push_back(LTest(" 12345", "123", false));

  for (int i = 0; i < tests.size(); i++) {
    LTest test = tests[i];
    bool res = wsjcpp::starts_with(test.str, test.start_str);
    if (res != test.expected) {
      found_errors++;
      if (test.expected) {
        std::cerr << "Expected str '" << test.str << "' starts with '" << test.start_str << "'" << std::endl;
      } else {
        std::cerr << "Unexpected str '" << test.str << "' starts with '" << test.start_str << "'" << std::endl;
      }
    }
  }
  if (found_errors > 0) {
    return 1;
  }
  std::cout << "ok" << std::endl;
  return 0;
}