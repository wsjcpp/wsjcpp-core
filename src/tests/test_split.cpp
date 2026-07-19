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
  std::string error;

  struct LTest {
    LTest(
      const std::string &source,
      const std::string &sDelim,
      const std::vector<std::string> &expected
    ) : source(source), expected(expected) {
      this->sDelim = sDelim;
    };
    std::string source;
    std::string sDelim;
    std::vector<std::string> expected;
  };
  std::vector<LTest> tests;
  tests.push_back(LTest("1 2 3 4 5", " ", {"1", "2", "3", "4", "5"}));
  tests.push_back(LTest("|1f|2п|3%^|44354|5kdasjfdre|2", "|", {"", "1f", "2п", "3%^", "44354", "5kdasjfdre", "2"}));
  tests.push_back(LTest("|1f|2п|3%^|44354|5kdasjfdre|", "|", {"", "1f", "2п", "3%^", "44354", "5kdasjfdre", ""}));
  tests.push_back(LTest("some1 => some2 => some3", "=>", {"some1 ", " some2 ", " some3"}));
  tests.push_back(LTest("some1 => some2 => some3 =>", "=>", {"some1 ", " some2 ", " some3 ", ""}));
  tests.push_back(LTest("./export-cli", "/", {".", "export-cli"}));
  tests.push_back(LTest("./export-cli/", "/", {".", "export-cli", ""}));

  for (int i = 0; i < tests.size(); i++) {
    LTest test = tests[i];
    std::vector<std::string> tokens = wsjcpp::split(test.source, test.sDelim);
    if (tokens.size() != test.expected.size()) {
      found_errors++;
      std::cerr << "Expected size " << test.expected.size() << ", but got " << tokens.size() << " for '" << test.source << "'" << std::endl;
      continue;
    }
    for (int n = 0; n < test.expected.size(); ++n) {
      if (tokens[n] != test.expected[n]) {
        found_errors++;
        std::cerr << "Expected []" << n << "] '" << test.expected[n] << "', but got '" << tokens[n] << "' for '" << test.source << "'" << std::endl;
      }
    }
  }

  if (found_errors > 0) {
    return 1;
  }
  std::cout << "ok" << std::endl;
  return found_errors;
}
