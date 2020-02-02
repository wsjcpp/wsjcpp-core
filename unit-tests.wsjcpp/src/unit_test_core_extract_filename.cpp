#include "unit_test_core_extract_filename.h"
#include <vector>
#include <iostream>
#include <wsjcpp_core.h>

REGISTRY_UNIT_TEST(UnitTestCoreExtractFilename)

UnitTestCoreExtractFilename::UnitTestCoreExtractFilename()
    : WSJCppUnitTestBase("UnitTestCoreExtractFilename") {
    //
}

// ---------------------------------------------------------------------

void UnitTestCoreExtractFilename::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestCoreExtractFilename::run() {
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

    int nCounter = 0;
    for ( it = mapPaths.begin(); it != mapPaths.end(); it++ ) {
        std::string sSource = it->first;
        std::string sExpected = it->second;
        std::string sGot = WSJCppCore::extractFilename(sSource);
        if (sGot != sExpected) {
            nCounter++;
            WSJCppLog::err(TAG, "Wrong extract filename for: '" + sSource + "'.\n\t Got: '" + sGot + "', but expected: '" + sExpected + "'");
        }
        
    }
    return nCounter == 0;
}