
#include "wsjcpp_core.h"

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
