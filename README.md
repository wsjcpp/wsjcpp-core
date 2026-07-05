# wsjcpp-core

<p align="center">
    <a href="https://github.com/wsjcpp/wsjcpp-core/pulse" alt="Activity">
        <img src="https://img.shields.io/github/commit-activity/m/wsjcpp/wsjcpp-core" />
    </a>
</p>

[![Github Stars](https://img.shields.io/github/stars/wsjcpp/wsjcpp-core.svg?label=github%20%E2%98%85)](https://github.com/wsjcpp/wsjcpp-core/stargazers) [![Github Stars](https://img.shields.io/github/contributors/wsjcpp/wsjcpp-core.svg)](https://github.com/wsjcpp/wsjcpp-core/) [![Github Forks](https://img.shields.io/github/forks/wsjcpp/wsjcpp-core.svg?label=github%20forks)](https://github.com/wsjcpp/wsjcpp-core/network/members)

Basic utils for wsjcpp

*include helper functions, logger and etc.*

## Integrate to your project

```
$ wsjcpp install https://github.com/wsjcpp/wsjcpp-core:master
```

Or include files:

* `src/wsjcpp_core.h`
* `src/wsjcpp_core.cpp`

## Logger (WsjcppLog)

* Output will be colored for console, but color will be missing for files.
* Functions are safe thread.
* Logger supports a log rotation (every 51000 seconds / every day)
* WsjcppLog::throw_err - will be generate `throw std::runtime_error(sMessage);`
* std::vector<std::string> WsjcppLog::getLastLogMessages() - last 50 records from log

In main() you need to init logger first.

```
#include <wsjcpp_core.h>

int main(int argc, char* argv[]) {
    std::string TAG = "MAIN";
    WsjcppLog::setLogDirectory(".logs");
    WsjcppLog::setPrefixLogFile("app");
    // disable log file
    // WsjcppLog::setEnableLogFile(false);
    // ... 
    return 0;
}
```

And then you can call static functions anywhere in your code:

```
#include <wsjcpp_core.h>

...
const std::string TAG = "MAIN";
WsjcppLog::info(TAG, "Hello info");
WsjcppLog::err(TAG, "Hello err");
WsjcppLog::warn(TAG, "Hello warn");
WsjcppLog::ok(TAG, "Hello ok");
```

Example output
```
2020-02-25 16:56:07.373, 0x0x10ac51dc0 [INFO] MAIN: Hello info
2020-02-25 16:56:07.374, 0x0x10ac51dc0 [ERR] MAIN: Hello err
2020-02-25 16:56:07.375, 0x0x10ac51dc0 [WARN] MAIN: Hello warn
2020-02-25 16:56:07.376, 0x0x10ac51dc0 [OK] MAIN: Hello ok
```

## List of static function:

| function | description | code-example |
| -------- | ----------- | ------- |
| `wsjcpp::normalize_filepath` | Normalize paths. (For example: `.//../bin/some/../` -> `./../bin/`) | [Code-Example](#wsjcppnormalize_filepath) |
| `wsjcpp::recursive_remove_dir` | *Please will be careful*. Recursive remove directory with sub-directories and sub-files | [Code-Example](#wsjcpprecursive_remove_dir) |
| `wsjcpp::starts_with` | Test string starts with substring | [Code-Example](#wsjcppstarts_with) |
| `wsjcpp::ends_with` | Test string ends with substring | [Code-Example](#wsjcppends_with) |
| `wsjcpp::directory_list` | Return list of child directories | [Code-Example](#wsjcppdirectory_list) |
| `wsjcpp::generate_uuid` | Generate uuid, but you need to call `WsjcppCore::initRandom();` before it (for example in main() function) | [Code-Example](#wsjcppgenerate_uuid) |
| `wsjcpp::parent_dirpath` | Extract dirpath from filepath | [Code-Example](#wsjcppparent_dirpath) |

### wsjcpp::normalize_filepath

Normalize paths. For example: ".//../bin/some/../" -> "./../bin/"

```
std::string _path = wsjcpp::normalize_filepath(".//../bin/some/../");
```

### extractFilename

Extract base filename from fullpath.

```
std::string sFilename = WsjcppCore::extractFilename(".//../bin/some/../file.txt");
```

Variable `sFilename` will has value `file.txt`

### extractDirpath

Extract base dir path from fullpath.

```
std::string sDirpath = WsjcppCore::extractDirpath(".//../bin/some/../file.txt");
```

Variable `sDirpath` will has value `.//../bin/some/..`

### getCurrentDirectory

```
static std::string getCurrentDirectory();
```

### getCurrentTimeInMilliseconds

```
static long getCurrentTimeInMilliseconds();
```

### getCurrentTimeInSeconds

```
static long getCurrentTimeInSeconds();
```

### getCurrentTimeForFilename

```
static std::string getCurrentTimeForFilename();
```

will be like this: `?`

### getCurrentTimeForLogFormat

```
static std::string getCurrentTimeForLogFormat();
```

will be like this: `2020-09-17 02:22:40.755`

### getThreadId

```
static std::string getThreadId();
```

will be like this: `0x00007fa9c6a96740`

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

### makeDir

Create a new directory
```
std::string sDirname = ".logs";
if (WsjcppCore::makeDir(sDirname)) {
    std::cout << " Created '" << sDirname << "'" << std::endl;
}
```

### makeDirsPath

Create a new directories full path
```
std::string sDirsPath = "./data/dir1/dir1/dir3";
if (WsjcppCore::makeDirsPath(sDirname)) {
    std::cout << " Created '" << sDirsPath << "'" << std::endl;
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
if (WsjcppCore::readTextFile("./file.txt", sContent)) {
    std::cout << sContent;
}
```

### readFileToBuffer

Read file binary content to buffer

```
char *pBuffer = nullptr;
int nBufferSize = 0;
if (WsjcppCore::readFileToBuffer("./data/readFileToBuffer.txt", &pBuffer, nBufferSize)) {
    // your can work with buffer here
}
```

### removeFile

```
if (WsjcppCore::removeFile("./file.txt")) {
    std::cout << "File removed" << std::endl;
}
```

### copyFile

```
if (WsjcppCore::copyFile("./file.txt", "./file1.txt")) {
    std::cout << "File copied!" << std::endl;
}
```

### createEmptyFile

Creating empty file. Will return true if file not exists and do created

```
if (WsjcppCore::createEmptyFile("./file.txt")) {
    std::cout << "Empty file created" << std::endl;
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
WsjcppCore::replaceAll(std::string& str, const std::string& from, const std::string& to);
```

### split

```
std::string sWhat = "|1a|2b|3c|4d|";
std::vector<std::string> vSplitted = WsjcppCore::split(sWhat, "|");
for (int i = 0; i < vSplitted.size(); i++) {
    std::cout << vSplitted[i] << std::endl;
}
```

Example output:
```

1a
2b
3c
4d

```

### join

```
std::vector<std::string> vWhat;
vJoin.push("1a");
vJoin.push("2b");
vJoin.push("3c");
vJoin.push("4d");
std::string sJoined = WsjcppCore::join(vWhat, ",");
std::cout << sJoined << std::endl;
```

Example output:
```
1a,2b,3c,4d
```

### wsjcpp::generate_uuid

Generate uuid, but you need to call `WsjcppCore::initRandom();` before it (for example in main() function)

```
WsjcppCore::initRandom(); // once in main on start
std::string _uuid = wsjcpp::generate_uuid();
std::cout << _uuid << std::endl;
```

Example output:

```
b49d92ae-f11c-f8bc-3a94-e7519e341927
```

### uint2hexString
`unsigned int` to hex string (lowercase)

```
std::cout << WsjcppCore::uint2hexString(1) << std::endl;
std::cout << WsjcppCore::uint2hexString(3000) << std::endl;
std::cout << WsjcppCore::uint2hexString(4123123123) << std::endl;
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
unsigned long nPointer = WsjcppCore::convertVoidToULong((void *)&s);
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
std::string sPointerHex = WsjcppCore::getPointerAsHex((void *)&s);
std::cout << sPointerHex << std::endl;
```

Example output:
```
0x7ffee8b04940
```

### wsjcpp::extract_url_protocol

```
std::string proto = wsjcpp::extract_url_protocol("https://github.com/wsjcpp");
```

`proto` will be contains `https`

### getEnv

Get the value of a system environment variable
```
std::string sValue;
if (WsjcppCore::getEnv("PATH", sValue)) {
    std::cout << sValue << std::endl;
}
```

Example output:
```
/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin
```

### encodeUriComponent

Similar a js function `encodeURIComponent`

```
static std::string encodeUriComponent(const std::string& sValue);
```

### decodeUriComponent

Similar a js function `decodeURIComponent`

```
static std::string decodeUriComponent(const std::string& sValue);
```

### getHumanSizeBytes

Human size for sizes in bytes

```
std::string sResult = WsjcppCore::getHumanSizeBytes(12012);
std::cout << "Size: " << sResult << std::endl;
```

Example output:
```
Size: 12K
```

### recoursiveCopyFiles

Recoursive copy files
*If target folders does not exists then it will be created*

```
if (WsjcppCore::recoursiveCopyFiles("./folder1", "./folder2")) {
    // everything ok
}
```

### wsjcpp::recursive_remove_dir

*Please will be careful*
Recursive remove directory with sub-directories and sub-files

```
std::string error;
if (!wsjcpp::recursive_remove_dir("./folder2", error)) {
    // everything removed
}
```

### wsjcpp::starts_with

Test string starts with substring

```
if (wsjcpp::starts_with("123456", "123")) {
    // true
}
```

### wsjcpp::ends_with

Test string ends with substring

```
if (wsjcpp::ends_with("123456", "456")) {
    // true
}
```

### wsjcpp::directory_list

```
std::vector<std::string> dirs = wsjcpp::directory_list("./");
```

### wsjcpp::parent_dirpath

Extracted normalize dirpath from filepath

```cpp
std::string parent_dir = wsjcpp::directory_list("./bo/test.txt");
// parent_dir will be contains './bo'
```
