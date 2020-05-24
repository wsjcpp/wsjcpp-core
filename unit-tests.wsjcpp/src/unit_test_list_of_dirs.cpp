#include "unit_test_list_of_dirs.h"
#include <vector>
#include <wsjcpp_core.h>
#include <algorithm>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestListOfDirs)

UnitTestListOfDirs::UnitTestListOfDirs()
    : WsjcppUnitTestBase("UnitTestListOfDirs") {
}

// ---------------------------------------------------------------------

void UnitTestListOfDirs::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestListOfDirs::run() {
    bool bTestSuccess = true;
    std::vector<std::string> vDirs = WsjcppCore::getListOfDirs("./data/list_of_dirs");

    compareN(bTestSuccess, "size", vDirs.size(), 4);
    if (vDirs.size() == 4) {
        compareS(bTestSuccess, "name of dir1", vDirs[0], "a1");
        compareS(bTestSuccess, "name of dir2", vDirs[1], "b2");
        compareS(bTestSuccess, "name of dir3", vDirs[2], "c3");
        compareS(bTestSuccess, "name of dir4", vDirs[3], "d4");
    }

    return bTestSuccess;
}

