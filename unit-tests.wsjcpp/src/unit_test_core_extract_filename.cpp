#include "unit_test_core_extract_filename.h"
#include <vector>
#include <iostream>
#include <wsjcpp_core.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestCoreExtractFilename)

UnitTestCoreExtractFilename::UnitTestCoreExtractFilename()
    : WsjcppUnitTestBase("UnitTestCoreExtractFilename") {
    //
}

// ---------------------------------------------------------------------

bool UnitTestCoreExtractFilename::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestCoreExtractFilename::executeTest() {
    std::map<std::string, std::string> mapPaths;
    mapPaths.insert(std::pair<std::string, std::string>("",""));
    mapPaths.insert(std::pair<std::string, std::string>("/usr/local/bin/some","some"));
    mapPaths.insert(std::pair<std::string, std::string>("./bin/some","some"));
    mapPaths.insert(std::pair<std::string, std::string>(".//../bin/some","some"));
    mapPaths.insert(std::pair<std::string, std::string>(".//../bin/some/../",""));
    mapPaths.insert(std::pair<std::string, std::string>(".//../bin/some/..",".."));
    mapPaths.insert(std::pair<std::string, std::string>("/usr/local/./bin/some","some"));
    mapPaths.insert(std::pair<std::string, std::string>("/usr/local/../bin/some","some"));
    mapPaths.insert(std::pair<std::string, std::string>("/usr/local/..//bin/some","some"));
    mapPaths.insert(std::pair<std::string, std::string>("/usr/local/..//bin/some/.","."));
    mapPaths.insert(std::pair<std::string, std::string>("/usr/local/..//bin/./some/",""));
    mapPaths.insert(std::pair<std::string, std::string>("/usr/local/../../bin/./some/",""));
    mapPaths.insert(std::pair<std::string, std::string>("/usr/local/../../../bin/./some/",""));
    mapPaths.insert(std::pair<std::string, std::string>(".//",""));
    std::map<std::string, std::string>::iterator it;
    for ( it = mapPaths.begin(); it != mapPaths.end(); it++ ) {
        std::string sSource = it->first;
        std::string sExpected = it->second;
        std::string sGot = WsjcppCore::extractFilename(sSource);
        compare(sSource, sGot, sExpected);
    }
}

// ---------------------------------------------------------------------

bool UnitTestCoreExtractFilename::doAfterTest() {
    // nothing
    return true;
}