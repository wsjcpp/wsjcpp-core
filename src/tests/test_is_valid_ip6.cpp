
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
  tests.push_back(local("3FFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF", true));
  tests.push_back(local("FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF", true));
  tests.push_back(local("2607:f8b0:4002:c08::8b", true));
  tests.push_back(local("2607:f8b0:4002:c08:0:0:0:8b", true));
  tests.push_back(local("2000::", true));
  tests.push_back(local("::1", true));
  tests.push_back(local("aaaa", false));
  tests.push_back(local("100.0.0.1", false));
  tests.push_back(local("100.0.0.x", false));
  tests.push_back(local("10033.1289.0.0", false));
  tests.push_back(local("10033.1289.0.0.0.0.0", false));

  for (int i = 0; i < tests.size(); i++) {
    local t = tests[i];
    std::string sError;
    bool got = wsjcpp::is_valid_ip6(t.value, sError);
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
