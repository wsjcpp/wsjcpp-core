# wsjcpp-core

[![Build Status](https://api.travis-ci.org/wsjcpp/wsjcpp-core.svg?branch=master)](https://travis-ci.org/wsjcpp/wsjcpp-core) [![Github Stars](https://img.shields.io/github/stars/wsjcpp/wsjcpp-core.svg?label=github%20%E2%98%85)](https://github.com/wsjcpp/wsjcpp-core/stargazers) [![Github Stars](https://img.shields.io/github/contributors/wsjcpp/wsjcpp-core.svg)](https://github.com/wsjcpp/wsjcpp-core/) [![Github Forks](https://img.shields.io/github/forks/wsjcpp/wsjcpp-core.svg?label=github%20forks)](https://github.com/wsjcpp/wsjcpp-core/network/members)

Basic utils for wsjcpp

*include helper functions, logger and etc.*

## Integrate to your project

```
$ wsjcpp install https://github.com/wsjcpp/wsjcpp-core:master
```

Or include files:

* `src/wsjcpp_core.h`
* `src/wsjcpp_core.cpp`

## Logger (WSJCppLog)

* Output will be collored for console, but color will be missing for files.
* Functions are safe thread.
* Logger supports a log rotation (every 51000 seconds / every day)
* WSJCppLog::throw_err - will be generate `throw std::runtime_error(sMessage);`
* std::vector<std::string> WSJCppLog::getLastLogMessages() - last 50 records from log

In main() you need to init logger first.

```
#include <wsjcpp_core.h>

int main(int argc, char* argv[]) {
    std::string TAG = "MAIN";
    if (!WSJCppCore::dirExists(".logs")) {
        WSJCppCore::makeDir(".logs");
    }
    WSJCppLog::setLogDirectory(".logs");
    WSJCppLog::setPrefixLogFile("app");

    // ... 
    return 0;
}
```

And then you can call static functions anywhere in your code:

```
#include <wsjcpp_core.h>

...
const std::string TAG = "MAIN";
WSJCppLog::info(TAG, "Hello info");
WSJCppLog::err(TAG, "Hello err");
WSJCppLog::warn(TAG, "Hello warn");
WSJCppLog::ok(TAG, "Hello ok");
```

Example output
```
2020-02-25 16:56:07.373, 0x0x10ac51dc0 [INFO] MAIN: Hello info
2020-02-25 16:56:07.374, 0x0x10ac51dc0 [ERR] MAIN: Hello err
2020-02-25 16:56:07.375, 0x0x10ac51dc0 [WARN] MAIN: Hello warn
2020-02-25 16:56:07.376, 0x0x10ac51dc0 [OK] MAIN: Hello ok
```

## List of static function (WSJCppCore):

### doNormalizePath

Normalize paths. For example: ".//../bin/some/../" -> "./../bin/"

```
std::string sPath = WSJCppCore::doNormalizePath(".//../bin/some/../");
```

### extractFilename

Extract base filename from fullpath.

```
std::string sFilename = WSJCppCore::doNormalizePath(".//../bin/some/../file.txt");
```

### getCurrentDirectory

```
static std::string getCurrentDirectory();
```

### currentTime_milliseconds

```
static long currentTime_milliseconds();
```

### currentTime_seconds

```
static long currentTime_seconds();
```

### currentTime_forFilename

```
static std::string currentTime_forFilename();
```

### currentTime_logformat

```
static std::string currentTime_logformat();
```

### threadId

```
static std::string threadId();
```

### formatTimeForWeb

```
static std::string formatTimeForWeb(long nTimeInSec);
```

### formatTimeForFilename

```
static std::string formatTimeForFilename(long nTimeInSec);
```

### formatTimeUTC

```
static std::string formatTimeUTC(int nTimeInSec);
```

### dirExists

```
static bool dirExists(const std::string &sFilename);
```

### fileExists

```
static bool fileExists(const std::string &sFilename);
```

### listOfDirs

```
static std::vector<std::string> listOfDirs(const std::string &sDirname);
```

### listOfFiles

```
static std::vector<std::string> listOfFiles(const std::string &sDirname);     
```

### makeDir

Create a new directory
```
std::string sDirname = ".logs";
if (WSJCppCore::makeDir(sDirname)) {
    std::cout << " Created '" << sDirname << "'" << std::endl;
}
```

### writeFile

```
static bool writeFile(const std::string &sFilename, const std::string &sContent);
static bool writeFile(const std::string &sFilename, const char *pBuffer, const int nBufferSize);
```

### readTextFile

Read text files into std::string
```
std::string sContent;
if (WSJCppCore::readTextFile("./file.txt", sContent)) {
    std::cout << sContent;
}
```

### removeFile

```
if (WSJCppCore::removeFile("./file.txt")) {
    std::cout << "File removed" << std::endl;
}
```

### trim

```
static std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ");
static std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ");
static std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ");
```

### toLower

```
static std::string toLower(const std::string& str);
```

Convert text to lower charaters, like "ABc" -> "abc". Worked only with latin alphabet.

### toUpper

```
static std::string toUpper(const std::string& str);
```

Convert text to upper charaters like "abC" -> "ABC". Worked only with latin alphabet.

### replaceAll

```
WSJCppCore::replaceAll(std::string& str, const std::string& from, const std::string& to);
```

### createUuid

Generate uuid, but you need to call `WSJCppCore::initRandom();` before it (for example in main() function)

```
WSJCppCore::initRandom(); // once in main on start
std::string sUuid = WSJCppCore::createUuid();
std::cout << sUuid << std::endl;
```

Example output:

```
b49d92ae-f11c-f8bc-3a94-e7519e341927
```

### uint2hexString
`unsigned int` to hex string (lowercase)

```
std::cout << WSJCppCore::uint2hexString(1) << std::endl;
std::cout << WSJCppCore::uint2hexString(3000) << std::endl;
std::cout << WSJCppCore::uint2hexString(4123123123) << std::endl;
```

Example output
```
00000001
00000bb8
f5c1ddb3
```
### convertVoidToULong

```
std::string s = "dddd";
unsigned long nPointer = WSJCppCore::convertVoidToULong((void *)&s);
std::cout << sPointerHex << std::endl;
static unsigned long convertVoidToULong(void *p);
```

Example output:
```
140732802287936
```

### getPointerAsHex

```
std::string s = "dddd";
std::string sPointerHex = WSJCppCore::getPointerAsHex((void *)&s);
std::cout << sPointerHex << std::endl;
```

Example output:
```
0x7ffee8b04940
```

### extractURLProtocol

```
std::string sProtocol = WSJCppCore::extractURLProtocol("https://github.com/wsjcpp");
```

### getEnv

Get the value of a system environment variable
```
std::string sValue;
if (WSJCppCore::getEnv("PATH", sValue)) {
    std::cout << sValue << std::endl;
}
```

Example output:
```
/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin
```

### encodeUriComponent

Simular a js function `encodeURIComponent`

```
static std::string encodeUriComponent(const std::string& sValue);
```

### decodeUriComponent

Simular a js function `decodeURIComponent`

```
static std::string decodeUriComponent(const std::string& sValue);
```
