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
  int found_errors = 0;
  std::string error;

  std::vector<std::string> uuids;
  for (int i = 0; i < 100; i++) {
    std::string _uuid = wsjcpp::generate_uuid();
    // if (i < 3) {
    //   WsjcppLog::info(TAG, "sUuid: " + sUuid);
    // }
    uuids.push_back(_uuid);
  }
  for (int x = 0; x < 100; x++) {
    std::string left_val = uuids[x];
    for (int y = 0; y < 100; y++) {
      std::string right_val = uuids[y];
      if (x != y) {
        if (left_val == right_val) {
          found_errors++;
          std::cerr << "Wrong generation random uuids: '" << left_val + "' by positions left=" << std::to_string(x) << ", right=" + std::to_string(y) << std::endl;
        }
      }
    }
  }

  if (found_errors > 0) {
    return 1;
  }
  std::cout << "ok" << std::endl;
  return 0;
}