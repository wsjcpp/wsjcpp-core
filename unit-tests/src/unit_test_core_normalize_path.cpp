#include "unit_test_core_normalize_path.h"
#include <vector>
#include <iostream>
#include <wsjcpp_core.h>

REGISTRY_UNIT_TEST(UnitTestCoreNormalizePath)

UnitTestCoreNormalizePath::UnitTestCoreNormalizePath()
    : UnitTestBase("UnitTestFallenNormalizePath") {
    //
}

// ---------------------------------------------------------------------

void UnitTestCoreNormalizePath::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestCoreNormalizePath::run() {
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

    int nCounter = 0;
    for ( it = mapPaths.begin(); it != mapPaths.end(); it++ ) {
        std::string sSource = it->first;
        std::string sExpected = it->second;
        std::string sGot = WSJCppCore::doNormalizePath(sSource);
        if (sGot != sExpected) {
            nCounter++;
            WSJCppLog::err(TAG, "Wrong normalize path for: '" + sSource + "'.\n\t Got: '" + sGot + "', but expected: '" + sExpected + "'");
        }
        
    }
    return nCounter == 0;
}