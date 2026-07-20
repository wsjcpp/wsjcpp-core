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
      long value,
      const std::string &expected
    ) : value(value), expected(expected) {
    };
    long value;
    std::string expected;
  };
  std::vector<LTest> tests;
  tests.push_back(LTest(0, "0B"));
  tests.push_back(LTest(30, "30B"));
  tests.push_back(LTest(999, "999B"));
  tests.push_back(LTest(1000, "1KB"));
  tests.push_back(LTest(1400, "1KB"));
  tests.push_back(LTest(1600, "2KB"));
  tests.push_back(LTest(100600, "101KB"));
  tests.push_back(LTest(10123, "10KB"));
  tests.push_back(LTest(10499, "10KB"));
  tests.push_back(LTest(10999, "11KB"));
  tests.push_back(LTest(100999, "101KB"));
  tests.push_back(LTest(1000999, "1MB"));
  tests.push_back(LTest(1001999, "1MB"));
  tests.push_back(LTest(1999999, "2MB"));
  tests.push_back(LTest(1401999, "1MB"));
  tests.push_back(LTest(1501999, "2MB"));
  tests.push_back(LTest(201001999, "201MB"));
  tests.push_back(LTest(2000501999, "2GB"));
  tests.push_back(LTest(2300501999, "2GB"));
  tests.push_back(LTest(2500501999, "3GB"));

  for (int i = 0; i < tests.size(); i++) {
    LTest test = tests[i];
    long val = tests[i].value;
    std::string got = WsjcppCore::getHumanSizeBytes(test.value);
    if (test.expected != got) {
      found_errors++;
      std::cerr << "Expected '" << test.expected << "', but got '" << got << "' from '" << test.value << "'" << std::endl;
    }
  }

  if (found_errors > 0) {
    return 1;
  }
  std::cout << "ok" << std::endl;
  return found_errors;
}
