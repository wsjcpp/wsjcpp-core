#include "unit_test_create_empty_file.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestCreateEmptyFile)

UnitTestCreateEmptyFile::UnitTestCreateEmptyFile()
    : WsjcppUnitTestBase("UnitTestCreateEmptyFile") {
}

// ---------------------------------------------------------------------

bool UnitTestCreateEmptyFile::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestCreateEmptyFile::executeTest() {
    compareB("./data/", WsjcppCore::dirExists("./data/"), true);
    std::string sFilename = "./data/empty.txt";
    if (WsjcppCore::fileExists(sFilename)) {
        WsjcppCore::removeFile(sFilename);
    }
    compareB("fileExists 1: " + sFilename, WsjcppCore::fileExists(sFilename), false);
    compareB("createEmptyFile 1: " + sFilename, WsjcppCore::createEmptyFile(sFilename), true);
    compareB("createEmptyFile 2: " + sFilename, WsjcppCore::createEmptyFile(sFilename), false);
    compareB("fileExists 2: " + sFilename, WsjcppCore::fileExists(sFilename), true);
}

// ---------------------------------------------------------------------

bool UnitTestCreateEmptyFile::doAfterTest() {
    // nothing
    return true;
}