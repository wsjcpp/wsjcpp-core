#include "unit_test_list_of_dirs.h"
#include <vector>
#include <wsjcpp_core.h>
#include <algorithm>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestListOfDirs)

UnitTestListOfDirs::UnitTestListOfDirs()
    : WsjcppUnitTestBase("UnitTestListOfDirs") {
}

// ---------------------------------------------------------------------

bool UnitTestListOfDirs::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestListOfDirs::executeTest() {
    std::vector<std::string> vDirs = WsjcppCore::getListOfDirs("./data/list_of_dirs");

    compare("size", vDirs.size(), 4);
    if (vDirs.size() == 4) {
        compare("name of dir1", vDirs[0], "a1");
        compare("name of dir2", vDirs[1], "b2");
        compare("name of dir3", vDirs[2], "c3");
        compare("name of dir4", vDirs[3], "d4");
    }
}

// ---------------------------------------------------------------------

bool UnitTestListOfDirs::doAfterTest() {
    // nothing
    return true;
}