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
      const std::string &sFrom,
      const std::string &sTo,
      const std::string &expected
    ) : source(source), expected(expected) {
      this->sFrom = sFrom;
      this->sTo = sTo;
      this->expected = expected;
    };
    std::string source;
    std::string sFrom;
    std::string sTo;
    std::string expected;
  };
  std::vector<LTest> tests;
  tests.push_back(LTest("Some long string", "o", "00", "S00me l00ng string"));
  tests.push_back(LTest("S00me l00ng string", "00", "o", "Some long string"));
  tests.push_back(LTest("dddng.string", ".", "_", "dddng_string"));

  for (int i = 0; i < tests.size(); i++) {
    LTest test = tests[i];
    std::string source = test.source;
    wsjcpp::replace_all_in(source, test.sFrom, test.sTo);
    if (source != test.expected) {
      found_errors++;
      std::cerr << "Expected '" << test.expected << "', but got '" << source << "' for '" << test.source << "'" << std::endl;
      continue;
    }
  }

  if (found_errors > 0) {
    return 1;
  }
  std::cout << "ok" << std::endl;
  return found_errors;
}
