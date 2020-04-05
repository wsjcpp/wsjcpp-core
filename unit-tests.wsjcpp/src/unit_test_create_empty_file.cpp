#include "unit_test_create_empty_file.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestCreateEmptyFile)

UnitTestCreateEmptyFile::UnitTestCreateEmptyFile()
    : WsjcppUnitTestBase("UnitTestCreateEmptyFile") {
}

// ---------------------------------------------------------------------

void UnitTestCreateEmptyFile::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestCreateEmptyFile::run() {
    bool bTestSuccess = true;
    compareB(bTestSuccess, "./data/", WsjcppCore::dirExists("./data/"), true);
    std::string sFilename = "./data/empty.txt";
    if (WsjcppCore::fileExists(sFilename)) {
        WsjcppCore::removeFile(sFilename);
    }
    compareB(bTestSuccess, "fileExists 1: " + sFilename, WsjcppCore::fileExists(sFilename), false);
    compareB(bTestSuccess, "createEmptyFile 1: " + sFilename, WsjcppCore::createEmptyFile(sFilename), true);
    compareB(bTestSuccess, "createEmptyFile 2: " + sFilename, WsjcppCore::createEmptyFile(sFilename), false);
    compareB(bTestSuccess, "fileExists 2: " + sFilename, WsjcppCore::fileExists(sFilename), true);
    return bTestSuccess;
}

