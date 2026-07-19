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

std::vector<std::string> prepare_expected_dirs(int &found_errors, std::vector<std::string> expected_dirs) {
  if (wsjcpp::dir_exists("./data/list_of_dirs")) {
    std::string error;
    if (!wsjcpp::recursive_remove_dir("./data/list_of_dirs", error)) {
      found_errors++;
      std::cerr << "recursive_remove_dir error (before): '" << error << "'" << std::endl;
    }
  }
  for (int i = 0; i < expected_dirs.size(); ++i) {
    WsjcppCore::makeDirsPath("./data/list_of_dirs/" + expected_dirs[i]);
  }
  return expected_dirs;
}

void test_dir_list(int &found_errors, const std::string &path, std::vector<std::string> expected_dirs) {
  std::vector<std::string> dirs = wsjcpp::directory_list(path);
  int dirs_size = dirs.size();
  if (dirs_size != expected_dirs.size()) {
    found_errors++;
    std::cerr << "Expected dirs " << std::to_string(expected_dirs.size()) << " but got " << std::to_string(dirs_size) << std::endl;
  }

  for (int i = 0; i < expected_dirs.size(); ++i) {
    if (i < dirs_size && dirs[i] != expected_dirs[i]) {
      found_errors++;
      std::cerr << "Expected dir '" << expected_dirs[i] << "', but got '" << dirs[i] << "'" << std::endl;
    }
    if (i > dirs_size) {
      std::cerr << "Missing expected dir '" << expected_dirs[i] << "'" << std::endl;
    }
  }
}

int main() {
  int found_errors = 0;
  std::string error;

  std::vector<std::string> expected_dirs = prepare_expected_dirs(found_errors, {
    "a1",
    "b2",
    "c3",
    "d4",
  });

  test_dir_list(found_errors, "./data/list_of_dirs", expected_dirs);

  expected_dirs = prepare_expected_dirs(found_errors, {
    "a11",
    "b22",
    "c33",
    "d44",
    "e50",
  });

  test_dir_list(found_errors, "./data/list_of_dirs", expected_dirs);

  expected_dirs = prepare_expected_dirs(found_errors, {
    "dir1",
    "dir2",
  });

  test_dir_list(found_errors, "./data/list_of_dirs/", expected_dirs);

  if (found_errors > 0) {
    return 1;
  }
  std::cout << "ok" << std::endl;
  return 0;
}