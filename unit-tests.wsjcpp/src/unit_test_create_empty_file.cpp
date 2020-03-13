#include "unit_test_create_empty_file.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_UNIT_TEST(UnitTestCreateEmptyFile)

UnitTestCreateEmptyFile::UnitTestCreateEmptyFile()
    : WSJCppUnitTestBase("UnitTestCreateEmptyFile") {
}

// ---------------------------------------------------------------------

void UnitTestCreateEmptyFile::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestCreateEmptyFile::run() {
    bool bTestSuccess = true;
    compareB(bTestSuccess, "./data/", WSJCppCore::dirExists("./data/"), true);
    std::string sFilename = "./data/empty.txt";
    if (WSJCppCore::fileExists(sFilename)) {
        WSJCppCore::removeFile(sFilename);
    }
    compareB(bTestSuccess, "fileExists 1: " + sFilename, WSJCppCore::fileExists(sFilename), false);
    compareB(bTestSuccess, "createEmptyFile 1: " + sFilename, WSJCppCore::createEmptyFile(sFilename), true);
    compareB(bTestSuccess, "createEmptyFile 2: " + sFilename, WSJCppCore::createEmptyFile(sFilename), false);
    compareB(bTestSuccess, "fileExists 2: " + sFilename, WSJCppCore::fileExists(sFilename), true);
    return bTestSuccess;
}

