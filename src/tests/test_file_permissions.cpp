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
  std::string root_dir = wsjcpp::normalize_filepath(WsjcppCore::getCurrentDirectory() + "/../../../../");

  struct LTest {
    LTest(
      const std::string &test_name,
      const std::string &expected_str,
      uint16_t expected_int16
    ) : test_name(test_name),
      expected_str(expected_str),
      expected_int16(expected_int16)
    {
      if (expected_str.length() != 10) {
        throw std::runtime_error("expected_str.length() != 9");
      }
      // is_dir = expected_str[0] == 'd'; // dir
      owner_read_flag = expected_str[1] == 'r';
      owner_write_flag = expected_str[2] == 'w';
      owner_execute_flag = expected_str[3] == 'x';
      group_read_flag = expected_str[4] == 'r';
      group_write_flag = expected_str[5] == 'w';
      group_execute_flag = expected_str[6] == 'x';
      other_read_flag = expected_str[7] == 'r';
      other_write_flag = expected_str[8] == 'w';
      other_execute_flag = expected_str[9] == 'x';
    };
    void check (WsjcppFilePermissions &perm, int &found_errors) {
      if (perm.toString() != expected_str) {
        found_errors++;
        std::cerr << "FAILED permission (" << test_name << ") toString, expected '" << expected_str << "', but got '" << perm.toString() << "'" << std::endl;
      }
      if (perm.toUInt16() != expected_int16) {
        found_errors++;
        std::cerr << "FAILED permission (" << test_name << ") toUInt16" << std::endl;
      }
      if (perm.getOwnerReadFlag() != owner_read_flag) {
        found_errors++;
        std::cerr << "FAILED permission (" << test_name << ") owner read" << std::endl;
      }
      if (perm.getOwnerWriteFlag() != owner_write_flag) {
        found_errors++;
        std::cerr << "FAILED permission (" << test_name << ") owner write" << std::endl;
      }
      if (perm.getOwnerExecuteFlag() != owner_execute_flag) {
        found_errors++;
        std::cerr << "FAILED permission (" << test_name << ") owner execute" << std::endl;
      }
      if (perm.getGroupReadFlag() != group_read_flag) {
        found_errors++;
        std::cerr << "FAILED permission (" << test_name << ") group read" << std::endl;
      }
      if (perm.getGroupWriteFlag() != group_write_flag) {
        found_errors++;
        std::cerr << "FAILED permission (" << test_name << ") group write" << std::endl;
      }
      if (perm.getGroupExecuteFlag() != group_execute_flag) {
        found_errors++;
        std::cerr << "FAILED permission (" << test_name << ") group execute" << std::endl;
      }
      if (perm.getOtherReadFlag() != other_read_flag) {
        found_errors++;
        std::cerr << "FAILED permission (" << test_name << ") other read" << std::endl;
      }
      if (perm.getOtherWriteFlag() != other_write_flag) {
        found_errors++;
        std::cerr << "FAILED permission (" << test_name << ") other write" << std::endl;
      }
      if (perm.getOtherExecuteFlag() != other_execute_flag) {
        found_errors++;
        std::cerr << "FAILED permission (" << test_name << ") other execute" << std::endl;
      }
    }
    std::string test_name;
    std::string expected_str;
    uint16_t expected_int16;
    bool owner_read_flag;
    bool owner_write_flag;
    bool owner_execute_flag;
    bool group_read_flag;
    bool group_write_flag;
    bool group_execute_flag;
    bool other_read_flag;
    bool other_write_flag;
    bool other_execute_flag;
  };

  // default
  WsjcppFilePermissions fp1;
  {
    LTest test("fp1-1", "-rw----r--", 0x0604);
    test.check(fp1, found_errors);
  }

  fp1.setOwnerReadFlag(false);
  fp1.setOwnerWriteFlag(false);
  fp1.setOtherReadFlag(false);
  {
    LTest test("fp1-2", "----------", 0x0);
    test.check(fp1, found_errors);
  }

  fp1.setOwnerReadFlag(true);
  {
    LTest test("fp1-3", "-r--------", 0x0400);
    test.check(fp1, found_errors);
  }

  fp1.setOwnerWriteFlag(true);
  {
    LTest test("fp1-4", "-rw-------", 0x0600);
    test.check(fp1, found_errors);
  }

  fp1.setOwnerExecuteFlag(true);
  {
    LTest test("fp1-5", "-rwx------", 0x0700);
    test.check(fp1, found_errors);
  }

  fp1.setGroupReadFlag(true);
  {
    LTest test("fp1-6", "-rwxr-----", 0x0740);
    test.check(fp1, found_errors);
  }

  fp1.setGroupWriteFlag(true);
  {
    LTest test("fp1-7", "-rwxrw----", 0x0760);
    test.check(fp1, found_errors);
  }

  fp1.setGroupExecuteFlag(true);
  {
    LTest test("fp1-8", "-rwxrwx---", 0x0770);
    test.check(fp1, found_errors);
  }

  fp1.setOtherReadFlag(true);
  {
    LTest test("fp1-9", "-rwxrwxr--", 0x0774);
    test.check(fp1, found_errors);
  }

  fp1.setOtherWriteFlag(true);
  {
    LTest test("fp1-10", "-rwxrwxrw-", 0x0776);
    test.check(fp1, found_errors);
  }
  fp1.setOtherExecuteFlag(true);
  {
    LTest test("fp1-11", "-rwxrwxrwx", 0x0777);
    test.check(fp1, found_errors);
  }
  fp1.setOtherWriteFlag(false);

  WsjcppFilePermissions fp2(
    true, true, true,
    true, true, true,
    true, true, true
  );
  {
    LTest test("fp2", "-rwxrwxrwx", 0x0777);
    test.check(fp2, found_errors);
  }

  WsjcppFilePermissions fp3(0x764);
  {
    LTest test("fp3", "-rwxrw-r--", 0x764);
    test.check(fp3, found_errors);
  }

  {
    WsjcppFilePermissions fp4_set(0x0604);
    LTest test("fp4_set", "-rw----r--", 0x0604);
    test.check(fp4_set, found_errors);
    std::string filepath = wsjcpp::normalize_filepath(root_dir + "/src/tests/data/file_permissions/file1");
    if (WsjcppCore::setFilePermissions(filepath, fp4_set, error) != true) {
      found_errors++;
      std::cerr << "FAILED set permission 0x0604 to file " << filepath << " (ERROR: " << error << ")" << std::endl;
    }

    WsjcppFilePermissions fp4(0x0);
    if (!WsjcppCore::getFilePermissions(filepath, fp4, error)) {
      found_errors++;
      std::cerr << "FAILED get permission for file " << filepath << " (ERROR: " << error << ")" << std::endl;
    }
    test.check(fp4, found_errors);
  }

  {
    WsjcppFilePermissions fp5(0x0);
    std::string filepath = wsjcpp::normalize_filepath(root_dir + "/src/tests/data/file_permissions/nofilefile1");
    if (wsjcpp::file_exists(filepath)) {
      found_errors++;
      std::cerr << "FAILED file must be non exists: " << filepath << std::endl;
      return 1;
    }

    if (WsjcppCore::getFilePermissions(filepath, fp5, error)) {
      found_errors++;
      std::cerr << "FAILED must be non set permission 0x0604 to file " << filepath << " (ERROR: " << error << ")" << std::endl;
    }
    LTest test("fp5", "----------", 0x0);
    test.check(fp5, found_errors);
  }

  if (found_errors > 0) {
    return 1;
  }
  std::cout << "ok" << std::endl;
  return 0;
}