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
#include <wsjcpp_core.h>

int main() {
  int found_errors = 0;

  struct LTest {
    LTest(
      const std::string &source,
      char pad_char,
      int pad_left,
      const std::string &expected_pad_left,
      int pad_right,
      const std::string &expected_pad_right
    ) :
      source(source),
      pad_char(pad_char),
      pad_left(pad_left),
      expected_pad_left(expected_pad_left),
      pad_right(pad_right),
      expected_pad_right(expected_pad_right) {
    };
    std::string source;
    char pad_char;
    int pad_left;
    std::string expected_pad_left;
    int pad_right;
    std::string expected_pad_right;
  };
  std::vector<LTest> tests;
  tests.push_back(LTest("some", '_', 6, "__some", 6, "some__"));
  tests.push_back(LTest("some", '_', 3, "some", 4, "some"));

  for (int i = 0; i < tests.size(); i++) {
    LTest test = tests[i];
    std::string got_pad_left = WsjcppCore::doPadLeft(test.source, test.pad_char, test.pad_left);
    if (test.expected_pad_left != got_pad_left) {
      found_errors++;
      std::cerr << "(pad_left) Expected '" << test.expected_pad_left << "', but got '" << got_pad_left << "' from '" << test.source << "'" << std::endl;
    }
    std::string got_pad_right = WsjcppCore::doPadRight(test.source, test.pad_char, test.pad_right);
    if (test.expected_pad_right != got_pad_right) {
      found_errors++;
      std::cerr << "(pad_right) Expected '" << test.expected_pad_right << "', but got '" << got_pad_right << "' from '" << test.source << "'" << std::endl;
    }
  }

  if (found_errors > 0) {
    return 1;
  }
  std::cout << "ok" << std::endl;
  return found_errors;
}
