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
  std::map<std::string, std::string> test_cases;
  test_cases.insert(std::pair<std::string, std::string>("https://github.com/wsjcpp","https"));
  test_cases.insert(std::pair<std::string, std::string>("ftp://test:test@test.com","ftp"));
  test_cases.insert(std::pair<std::string, std::string>("non-existing://test.org","non-existing"));
  test_cases.insert(std::pair<std::string, std::string>("none:test.org",""));
  std::map<std::string, std::string>::iterator it;
  int found_errors = 0;
  for (it = test_cases.begin(); it != test_cases.end(); it++) {
    std::string _source = it->first;
    std::string _expected = it->second;
    std::string _got = wsjcpp::extract_url_protocol(_source);
    if (_got != _expected) {
        found_errors++;
        std::cerr << "ERROR: Expected '" << _expected << "', but got '" << _got << "' from '" << _source << "'" << std::endl;
    }
  }
  if (found_errors > 0) {
    return 1;
  }
  std::cout << "ok" << std::endl;
  return 0;
}
