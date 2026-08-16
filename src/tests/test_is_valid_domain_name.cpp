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

#include <wsjcpp_core.h>

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int found_errors = 0;

  struct local {
    local(const std::string &value, bool expected)
        : value(value), expected(expected) {

          };
    std::string value;
    bool expected;
  };
  std::vector<local> tests;
  tests.push_back(local("google.com", true));
  tests.push_back(local("foo.com", true));
  tests.push_back(local("www.example.com", true));
  // tests.push_back(local("✪df.ws", true));
  tests.push_back(local("example.com", true));
  // tests.push_back(local("➡.ws", true));
  // tests.push_back(local("⌘.ws", true));
  // tests.push_back(local("⌘.ws", true));
  tests.push_back(local("foo.com", true));
  // tests.push_back(local("☺.damowmow.com", true));
  tests.push_back(local("code.google.com", true));
  tests.push_back(local("j.mp", true));
  tests.push_back(local("foo.bar", true));
  tests.push_back(local("foo.barq", true));
  // tests.push_back(local("مثال.إختبار", true));
  // tests.push_back(local("例子.测试", true));
  // tests.push_back(local("उदाहरण.परीक्षा", true));
  tests.push_back(local("example.com", true));
  tests.push_back(local("1337.net", true));
  tests.push_back(local("a.b-c.de", true));

  // incorrect
  tests.push_back(local("foo_bar.example.com", false));
  tests.push_back(local("some", false));
  tests.push_back(local("ABCD", false));
  tests.push_back(local("", false));
  tests.push_back(local(".", false));
  tests.push_back(local("..", false));
  tests.push_back(local("..", false));
  tests.push_back(local("?", false));
  tests.push_back(local("??", false));
  tests.push_back(local("??", false));
  tests.push_back(local("#", false));
  tests.push_back(local("##", false));
  tests.push_back(local("##", false));
  tests.push_back(local("142.42.1.1:88888", false));
  tests.push_back(local("//", false));
  tests.push_back(local("//a", false));
  tests.push_back(local("///a", false));
  tests.push_back(local("///", false));
  tests.push_back(local("http:///a", false));
  tests.push_back(local("foo.com.", false));
  tests.push_back(local("foo..com.", false));
  tests.push_back(local("foo.com..", false));
  tests.push_back(local(".foo.com", false));
  tests.push_back(local("..foo.com", false));
  tests.push_back(local("1234", false));
  tests.push_back(local("1234", false));
  tests.push_back(local("test", false));
  tests.push_back(local(" shouldfail.com", false));
  tests.push_back(local(" should fail", false));
  tests.push_back(local("-error-.invalid", false));
  tests.push_back(local("a.b--c.de", false));
  tests.push_back(local("-a.b.co", false));
  tests.push_back(local("a.b-.co", false));
  tests.push_back(local("1.1.1.1.1", false));
  tests.push_back(local("123.123.123", false));
  tests.push_back(local("3628126748", false));
  tests.push_back(local(".www.foo.bar", false));
  tests.push_back(local("www.foo.bar.", false));
  tests.push_back(local(".www.foo.bar.", false));

  for (int i = 0; i < tests.size(); i++) {
    local t = tests[i];
    std::string sError;
    bool got = wsjcpp::is_valid_domain_name(t.value, sError);
    if (got != t.expected) {
      found_errors++;
      std::cerr << "Expected " << (t.expected ? "true" : "false") << ", but got " << (got ? "true" : "false") << " for "
                << t.value << std::endl;
    }
  }

  if (found_errors > 0) {
    std::cerr << "FAILED" << std::endl;
    return 1;
  }

  std::cout << "OK" << std::endl;
  return 0;
}
