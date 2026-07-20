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
      unsigned int source,
      const std::string &expected
    ) : source(source), expected(expected) {
    };
    unsigned int source;
    std::string expected;
  };
  std::vector<LTest> tests;
  tests.push_back(LTest(1, "00000001"));
  tests.push_back(LTest(3000, "00000bb8"));
  tests.push_back(LTest(4123123123, "f5c1ddb3"));

  for (int i = 0; i < tests.size(); i++) {
      LTest test = tests[i];
      std::string got = WsjcppCore::uint2hexString(test.source);
      if (test.expected != got) {
        found_errors++;
        std::cerr << "Expected '" << test.expected << "', but got '" << got << "' from '" << test.source << "'" << std::endl;
      }
  }

  if (found_errors > 0) {
    return 1;
  }
  std::cout << "ok" << std::endl;
  return found_errors;
}
