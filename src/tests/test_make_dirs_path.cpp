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

  if (WsjcppCore::dirExists("./data/makedirpaths")) {
    if (!wsjcpp::recursive_remove_dir("./data/makedirpaths", error)) {
      found_errors++;
      std::cerr << "recursive_remove_dir error (before): '" << error << "'" << std::endl;
    }
  }

  struct LTest {
    LTest(
      const std::string &dirpath,
      const std::vector<std::string> &sub_paths
    ) {
      this->dirpath = dirpath;
      this->sub_paths = sub_paths;
    };
    std::string dirpath;
    std::vector<std::string> sub_paths;
  };
  std::vector<LTest> tests;
  tests.push_back(LTest("./data/makedirpaths/dir1/dir2", {
    "./data",
    "./data/makedirpaths",
    "./data/makedirpaths/dir1",
    "./data/makedirpaths/dir1/dir2"
  }));
  tests.push_back(LTest("./data/makedirpaths/dir1/dir3", {
    "./data",
    "./data/makedirpaths",
    "./data/makedirpaths/dir1",
    "./data/makedirpaths/dir1/dir3"
  }));
  tests.push_back(LTest("./data/makedirpaths/dir1/dir4/", {
    "./data",
    "./data/makedirpaths",
    "./data/makedirpaths/dir1",
    "./data/makedirpaths/dir1/dir4"
  }));

  for (int i = 0; i < tests.size(); i++) {
    std::string dirpath = tests[i].dirpath;
    bool result = WsjcppCore::makeDirsPath(dirpath);
    if (!result) {
      std::cerr << "Could not make dirpath: '" << dirpath << "'" << std::endl;
      found_errors++;
    } else {
      std::vector<std::string> sub_paths = tests[i].sub_paths;
      for (int x = 0; x < sub_paths.size(); x++) {
        if (!WsjcppCore::dirExists(sub_paths[x])) {
          std::cerr << "Dirpath: '" << dirpath << "', but directory not exists: '" << sub_paths[x] << "'" << std::endl;
          found_errors++;
        }
      }
    }
  }
  // cleanup
  if (!wsjcpp::recursive_remove_dir("./data/makedirpaths", error)) {
    found_errors++;
    std::cerr << "recursive_remove_dir error (after): '" << error << "'" << std::endl;
  }

  if (found_errors > 0) {
    return 1;
  }
  std::cout << "ok" << std::endl;
  return 0;
}