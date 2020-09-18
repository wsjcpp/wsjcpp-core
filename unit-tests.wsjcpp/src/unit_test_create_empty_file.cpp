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
    compare("./data/", WsjcppCore::dirExists("./data/"), true);
    std::string sFilename = "./data/empty.txt";
    if (WsjcppCore::fileExists(sFilename)) {
        WsjcppCore::removeFile(sFilename);
    }
    compare("fileExists 1: " + sFilename, WsjcppCore::fileExists(sFilename), false);
    compare("createEmptyFile 1: " + sFilename, WsjcppCore::createEmptyFile(sFilename), true);
    compare("createEmptyFile 2: " + sFilename, WsjcppCore::createEmptyFile(sFilename), false);
    compare("fileExists 2: " + sFilename, WsjcppCore::fileExists(sFilename), true);
}

// ---------------------------------------------------------------------

bool UnitTestCreateEmptyFile::doAfterTest() {
    // nothing
    return true;
}