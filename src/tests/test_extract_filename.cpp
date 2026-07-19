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

  std::map<std::string, std::string> tests;
  tests.insert(std::pair<std::string, std::string>("",""));
  tests.insert(std::pair<std::string, std::string>("/usr/local/bin/some","some"));
  tests.insert(std::pair<std::string, std::string>("./bin/some","some"));
  tests.insert(std::pair<std::string, std::string>(".//../bin/some","some"));
  tests.insert(std::pair<std::string, std::string>(".//../bin/some/../",""));
  tests.insert(std::pair<std::string, std::string>(".//../bin/some/..",".."));
  tests.insert(std::pair<std::string, std::string>("/usr/local/./bin/some","some"));
  tests.insert(std::pair<std::string, std::string>("/usr/local/../bin/some","some"));
  tests.insert(std::pair<std::string, std::string>("/usr/local/..//bin/some","some"));
  tests.insert(std::pair<std::string, std::string>("/usr/local/..//bin/some/.","."));
  tests.insert(std::pair<std::string, std::string>("/usr/local/..//bin/./some/",""));
  tests.insert(std::pair<std::string, std::string>("/usr/local/../../bin/./some/",""));
  tests.insert(std::pair<std::string, std::string>("/usr/local/../../../bin/./some/",""));
  tests.insert(std::pair<std::string, std::string>(".//",""));
  for (auto it = tests.begin(); it != tests.end(); it++ ) {
    std::string source = it->first;
    std::string expected = it->second;
    std::string got = wsjcpp::extract_filename(source);
    if (expected != got) {
      found_errors++;
      std::cerr << "Expected '" << expected << "', but got '" << got << "' for '" << source << "'" << std::endl;
    }
  }

  if (found_errors > 0) {
    return 1;
  }
  std::cout << "ok" << std::endl;
  return found_errors;
}
