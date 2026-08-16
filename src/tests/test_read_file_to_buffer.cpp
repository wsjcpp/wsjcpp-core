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

#include <iostream>
#include <vector>
#include <wsjcpp_core.h>

int main() {
  int found_errors = 0;
  std::string sExpected = "1234567890\nqwerty123456";
  char *pBuffer = nullptr;
  int nBufferSize = 0;
  std::string root_dir = wsjcpp::normalize_filepath(WsjcppCore::getCurrentDirectory() + "/../../../../");

  // test for read unexitsing file
  std::string unexitsing_filepath = wsjcpp::normalize_filepath(root_dir + "/src/tests/data/read_file_to_buffer2.txt");
  if (wsjcpp::file_exists(unexitsing_filepath)) {
    std::cerr << "FAILED File unexpected by path: " << unexitsing_filepath << " " << std::endl;
    return 1;
  }
  nBufferSize = 15;
  if (WsjcppCore::readFileToBuffer(unexitsing_filepath, &pBuffer, nBufferSize)) {
    std::cerr << "FAILED what a read??? unexpected by path: " << unexitsing_filepath << " " << std::endl;
    return 1;
  }

  if (nBufferSize != 15) {
    found_errors++;
    std::cerr << "FAILED returned buffer size must be not modified for " << unexitsing_filepath << " " << std::endl;
  }

  nBufferSize = 0;
  std::string filepath = wsjcpp::normalize_filepath(root_dir + "/src/tests/data/read_file_to_buffer.txt");
  if (!WsjcppCore::readFileToBuffer(filepath, &pBuffer, nBufferSize)) {
    std::cout << "Current directory: " << WsjcppCore::getCurrentDirectory() << std::endl;
    std::cerr << "FAILED Could not read file by path: " << filepath << " " << std::endl;
    return 1;
  }
  if (nBufferSize != sExpected.length()) {
    found_errors++;
    std::cerr << "FAILED Size of read expected: " << sExpected.length() << ", but got " << nBufferSize << " "
              << std::endl;
  }
  int nMin = std::min(nBufferSize, (int)sExpected.length());
  for (int i = 0; i < nMin; i++) {
    char c_got = pBuffer[i];
    char c_expected = sExpected[i];
    if (c_expected != c_got) {
      found_errors++;
      std::cerr << "FAILED Char of position " + std::to_string(i) + ", expected: '" << c_expected << "', but got '"
                << c_got << "' " << std::endl;
    }
  }

  if (found_errors > 0) {
    return 1;
  }
  std::cout << "ok" << std::endl;
  return 0;
}