#include "unit_test_core_normalize_path.h"
#include <vector>
#include <iostream>
#include <wsjcpp_core.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestCoreNormalizePath)

UnitTestCoreNormalizePath::UnitTestCoreNormalizePath()
    : WsjcppUnitTestBase("UnitTestCoreNormalizePath") {
    //
}

// ---------------------------------------------------------------------

bool UnitTestCoreNormalizePath::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestCoreNormalizePath::executeTest() {
    std::map<std::string, std::string> mapPaths;
    mapPaths.insert(std::pair<std::string, std::string>("",""));
    mapPaths.insert(std::pair<std::string, std::string>("/usr/local/bin/some","/usr/local/bin/some"));
    mapPaths.insert(std::pair<std::string, std::string>("./bin/some","./bin/some"));
    mapPaths.insert(std::pair<std::string, std::string>(".//../bin/some","./../bin/some"));
    mapPaths.insert(std::pair<std::string, std::string>(".//../bin/some/../","./../bin/"));
    mapPaths.insert(std::pair<std::string, std::string>(".//../bin/some/..","./../bin"));
    mapPaths.insert(std::pair<std::string, std::string>("/usr/local/./bin/some","/usr/local/bin/some"));
    mapPaths.insert(std::pair<std::string, std::string>("/usr/local/../bin/some","/usr/bin/some"));
    mapPaths.insert(std::pair<std::string, std::string>("/usr/local/..//bin/some","/usr/bin/some"));
    mapPaths.insert(std::pair<std::string, std::string>("/usr/local/..//bin/some/","/usr/bin/some/"));
    mapPaths.insert(std::pair<std::string, std::string>("/usr/local/..//bin/./some/","/usr/bin/some/"));
    mapPaths.insert(std::pair<std::string, std::string>("/usr/local/../../bin/./some/","/bin/some/"));
    mapPaths.insert(std::pair<std::string, std::string>("/usr/local/../../../bin/./some/","../bin/some/"));
    mapPaths.insert(std::pair<std::string, std::string>(".//","./"));
    std::map<std::string, std::string>::iterator it;

    for ( it = mapPaths.begin(); it != mapPaths.end(); it++ ) {
        std::string sSource = it->first;
        std::string sExpected = it->second;
        std::string sGot = WsjcppCore::doNormalizePath(sSource);
        compare(sSource, sGot, sExpected);
    }
}

// ---------------------------------------------------------------------

bool UnitTestCoreNormalizePath::doAfterTest() {
    // nothing
    return true;
}
