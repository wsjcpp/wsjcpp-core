
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
  tests.push_back(local("127.0.0.1", true));
  tests.push_back(local("10.0.0.1", true));
  tests.push_back(local("0.0.0.0", true));
  tests.push_back(local("300.200.100.100", false));
  tests.push_back(local("223.255.255.254", true));

  tests.push_back(local("aaaa", false));
  tests.push_back(local("100.0.0.x", false));
  tests.push_back(local("10033.1289.0.0", false));
  tests.push_back(local("10033.1289.0.0.0.0.0", false));

  for (int i = 0; i < tests.size(); i++) {
    local t = tests[i];
    std::string sError;
    bool got = wsjcpp::is_valid_ip4(t.value, sError);
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
