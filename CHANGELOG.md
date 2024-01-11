# Changelog

All notable changes to wsjcpp-core project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/)
and this project adheres to [Semantic Versioning](http://semver.org/).

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
