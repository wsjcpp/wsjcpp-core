#include "unit_test_test_resources.h"
#include <vector>
#include <wsjcpp_core.h>
#include <wsjcpp_resources_manager.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestTestResources)

UnitTestTestResources::UnitTestTestResources()
    : WsjcppUnitTestBase("UnitTestTestResources") {
}

// ---------------------------------------------------------------------

void UnitTestTestResources::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestTestResources::run() {
    bool bTestSuccess = true;
    // std::vector<ResourceFile*> &list();
    WsjcppResourceFile* pFile = WsjcppResourcesManager::get("html/images/points.svg");
    compareN(bTestSuccess, "getBufferSize", pFile->getBufferSize(), 2979);
    compareS(bTestSuccess, "getFilename", pFile->getFilename(), "html/images/points.svg");
    return bTestSuccess;
}

