
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
  tests.push_back(local("O2Rrc2Y7YXNsa2RmMQ==", true));
  tests.push_back(local("O2Rrc2Y7YXNsa2Rm", true));
  tests.push_back(local("O2Rrc2Y7YXNsa2Rm==", false));
  tests.push_back(local("1898-01-01", false));
  tests.push_back(local("+/11", true));
  tests.push_back(local("%$", false));

  for (int i = 0; i < tests.size(); i++) {
    local t = tests[i];
    std::string sError;
    bool got = wsjcpp::is_valid_base64(t.value, sError);
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
