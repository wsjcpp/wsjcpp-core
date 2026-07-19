# Changelog

## [v0.2.7] - 2026-07-05 (2026 July 19)

- Fixed #43: Renamed `WsjcppCore::dirExists` to `wsjcpp::dir_exists`
- Fixed #44: Renamed `WsjcppCore::fileExists` to `wsjcpp::file_exists`
- Fixed #46: Renamed `WsjcppCore::split` to `wsjcpp::split`
- Renamed `WsjcppCore::join` to `wsjcpp::join`
- Fixed #47: Rename `WsjcppCore::replaceAll` to `wsjcpp::replace_all`

## [v0.2.6] - 2026-07-05 (2026 July 5)

- Redesign normalize path to ctest
- Removed `WsjcppCore::doNormalizePath`
- Fixed code-formatting
- Renamed `WsjcppCore::extractURLProtocol` to `wsjcpp::extract_url_protocol`
- Fixed #38: Added test for extract_url_protocol
- Renamed and redesign `WsjcppCore::recoursiveRemoveDir` to `wsjcpp::recursive_remove_dir`
- Fixed #41: Renamed `WsjcppCore::startsWith` to `wsjcpp::starts_with`
- Renamed `WsjcppCore::endsWith` to `wsjcpp::ends_with`
- Fixed #39: Removed missing implementation `WsjcppCore::listOfDirs`
- Renamed `WsjcppCore::getListOfDirs` to `wsjcpp::directory_list`
- Fixed #40: Missing first character in name of child directory
- Removed definition `WsjcppCore::listOfFiles` because missing implementation
- Fixed #36: Renamed `WsjcppCore::createUuid` to `wsjcpp::generate_uuid()`
- Fixed #33: Added `wsjcpp::parent_dirpath`
- Removed `.travis.yml` and `ci/travis`
- Fixed #24: Added `wsjcpp::to_snake_case`
- Renamed and redesign `WsjcppCore::recoursiveCopyFiles` to `wsjcpp::recursive_copy_files`


## [v0.2.5] - 2026-05-19 (2026 May 19)

- Fixed for path traversal `WsjcppCore::doNormalizePath`
- `WsjcppCore::doNormalizePath` marked as deprecated
- Added symlink `WsjcppCore::doNormalizePath` -> `wsjcpp::normalizeFilePath`

## [v0.2.4] - 2026-02-04 (2026 Feb 4)

- New function: englishAlphabetLowerCase
- New function: englishAlphabetUpperCase
- New function: englishAlphabetBothCase
- New function: englishAlphabetBothCaseAndNumbers
- New function: randomString
- Added define: WSJCPP_CORE_VER_0_2_4
- Added license information to source-code

## [v0.2.3] - 2023-02-01 (2023 Feb 1)

- New functions: startsWith and endsWith

## [v0.2.2] - 2021-09-04 (2021 Sept 4)

- Added test for normalize path
- Added test case for replace all
- Added build_simple.bat for windows
- Added WsjcppCore::makeDirsPath
- Added WsjcppCore::extractDirpath
- Up c++ to version 17 (need for std::filesystem)
- Redesign getListOfDirs to using cross-platform std::filesystem
- Fixed setFilePermissions
