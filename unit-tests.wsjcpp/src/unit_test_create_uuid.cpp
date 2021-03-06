#include "unit_test_create_uuid.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestCreateUuid)

UnitTestCreateUuid::UnitTestCreateUuid()
    : WsjcppUnitTestBase("UnitTestCreateUuid") {
}

// ---------------------------------------------------------------------

bool UnitTestCreateUuid::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestCreateUuid::executeTest() {
    std::vector<std::string> vUuids;
    for (int i = 0; i < 100; i++) {
        std::string sUuid = WsjcppCore::createUuid();
        // if (i < 3) {
        //     WsjcppLog::info(TAG, "sUuid: " + sUuid);
        // }
        vUuids.push_back(sUuid);
    }
    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            if (x != y) {
                if (vUuids[x] == vUuids[y]) {
                    fail("Wrong generation random uuids: \nvUuids[" + std::to_string(x)+ "] == vUuids[" + std::to_string(y) + "] == '" + vUuids[x] + "'");
                }
            }
        } 
    }
}

// ---------------------------------------------------------------------

bool UnitTestCreateUuid::doAfterTest() {
    // nothing
    return true;
}