# wsjcpp-core

[![Build Status](https://api.travis-ci.org/wsjcpp/wsjcpp-core.svg?branch=master)](https://travis-ci.org/wsjcpp/wsjcpp-core) [![Github Stars](https://img.shields.io/github/stars/wsjcpp/wsjcpp-core.svg?label=github%20%E2%98%85)](https://github.com/wsjcpp/wsjcpp-core/stargazers) [![Github Stars](https://img.shields.io/github/contributors/wsjcpp/wsjcpp-core.svg)](https://github.com/wsjcpp/wsjcpp-core/) [![Github Forks](https://img.shields.io/github/forks/wsjcpp/wsjcpp-core.svg?label=github%20forks)](https://github.com/wsjcpp/wsjcpp-core/network/members)

Basic utils for wsjcpp

*included helpers functions, logger and etc.*

## Integrate to your project

```
$ wsjcpp install https://github.com/wsjcpp/wsjcpp-core:master
```

Or include files:

* `src/wsjcpp_core.h`
* `src/wsjcpp_core.cpp`

## List of static function:

### createUUID

generation uuid but before you need call once `WSJCppCore::initRandom();` (for example in main function)

```
std::string sUuid = WSJCppCore::createUuid();
```

### readTextFile

Reading text files to std::string
```
std::string sContent;
if (WSJCppCore::readTextFile("./file.txt", sContent)) {
    std::cout << sContent;
}
```