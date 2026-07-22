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

  // std::vector<ResourceFile*> &list();
  WsjcppResourceFile* file = WsjcppResourcesManager::get("./src/resources/html/images/favicon.svg");

  if (file == nullptr) {
    std::cerr << "Could not load file from resources" << std::endl;
    return 1;
  }

  int expected_size = 10014;
  if (file->getBufferSize() != expected_size) {
    found_errors++;
    std::cerr << "Expected size " << expected_size << ", but got " << file->getBufferSize() << " " << std::endl;
  }

  std::string expected_filename = "./src/resources/html/images/favicon.svg";
  if (file->getFilename() != expected_filename) {
    found_errors++;
    std::cerr << "Expected '" << expected_filename << "', but got '" << file->getFilename() << "' " << std::endl;
  }

  if (found_errors > 0) {
    return 1;
  }
  std::cout << "ok" << std::endl;
  return found_errors;
}
