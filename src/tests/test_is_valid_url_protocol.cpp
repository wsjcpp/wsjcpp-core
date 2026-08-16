
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
  tests.push_back(local("some", false));
  tests.push_back(local("http", true));
  tests.push_back(local("https", true));
  tests.push_back(local("ws", true));
  tests.push_back(local("wss", true));
  tests.push_back(local("ftp", true));
  tests.push_back(local("ssl", true));
  tests.push_back(local("file", false));
  tests.push_back(local("mailto", false));
  tests.push_back(local("tel", false));
  tests.push_back(local("data", false));
  tests.push_back(local("blob", false));
  tests.push_back(local("24", false));
  tests.push_back(local("25", false));

  for (int i = 0; i < tests.size(); i++) {
    local t = tests[i];
    std::string sError;
    bool got = wsjcpp::is_valid_url_protocol(t.value, sError);
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
