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
  if (!wsjcpp::dir_exists("./data/")) {
    std::cerr << "Missing './data/' dir" << std::endl;
    return 1;
  }

  std::string filepath = "./data/empty.txt";
  if (wsjcpp::file_exists(filepath)) {
    WsjcppCore::removeFile(filepath);
  }

  if (wsjcpp::file_exists(filepath)) {
    std::cerr << "Could not remove file '" << filepath << "'" << std::endl;
    return 1;
  }

  if (!wsjcpp::create_empty_file(filepath)) {
    std::cerr << "Could not create file '" << filepath << "'" << std::endl;
    return 1;
  }

  if (wsjcpp::create_empty_file(filepath)) {
    std::cerr << "Must could not create file '" << filepath << "'" << std::endl;
    return 1;
  }

  if (!wsjcpp::file_exists(filepath)) {
    std::cerr << "Missing expected file '" << filepath << "'" << std::endl;
    return 1;
  }

  std::cout << "ok" << std::endl;
  return 0;
}
