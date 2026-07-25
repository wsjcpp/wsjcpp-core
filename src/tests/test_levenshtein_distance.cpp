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
  struct LineTest {
    LineTest(std::string s1, std::string s2, int nExpectedDistance) 
        : s1(s1), s2(s2), nExpectedDistance(nExpectedDistance) {}
    std::string s1;
    std::string s2;
    int nExpectedDistance;
  };

  std::vector<LineTest> vTestLines;
  vTestLines.push_back(LineTest("test", "test", 0));
  vTestLines.push_back(LineTest("tttt", "aaaa", 4));
  vTestLines.push_back(LineTest("ta", "t0", 1));
  vTestLines.push_back(LineTest("taf", "t0", 2));
  vTestLines.push_back(LineTest("111111111111111", "1111111112111111", 1));
  vTestLines.push_back(LineTest("!@#$%^&*()_+", "!@#%$^&*()+", 3));

  for (unsigned int i = 0; i < vTestLines.size(); i++) {
    LineTest test = vTestLines[i];
    int got_distance = wsjcpp::levenshtein_distance(test.s1, test.s2);
    if (got_distance != test.nExpectedDistance) {
      found_errors++;
      std::cerr << "Expected " << test.nExpectedDistance << ", but got " << got_distance << " for '" << test.s1 << "' and '" << test.s2 << "'" << std::endl;
    }
  }

  if (found_errors > 0) {
    return 1;
  }
  std::cout << "ok" << std::endl;
  return found_errors;
}
