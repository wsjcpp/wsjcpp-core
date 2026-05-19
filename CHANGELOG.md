# Changelog

All notable changes to wsjcpp-core project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/)
and this project adheres to [Semantic Versioning](http://semver.org/).

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

### Added

- New functions: startsWith and endsWith

## [v0.2.2] - 2021-09-04 (2021 Sept 4)

### Added

- Added test for normalize path
- Added test case for replace all
- Added build_simple.bat for windows
- Added WsjcppCore::makeDirsPath
- Added WsjcppCore::extractDirpath

### Changed

- Up c++ to version 17 (need for std::filesystem)
- Redesign getListOfDisrs to using crossplatform std::filesystem

### Fixed

- Fixed setFilePermissions
