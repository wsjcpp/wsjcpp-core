#include "unit_test_test_resources.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestTestResources)

UnitTestTestResources::UnitTestTestResources()
    : WsjcppUnitTestBase("UnitTestTestResources") {
}

// ---------------------------------------------------------------------

bool UnitTestTestResources::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestTestResources::executeTest() {
    // std::vector<ResourceFile*> &list();
    WsjcppResourceFile* pFile = WsjcppResourcesManager::get("html/images/points.svg");
    compare("getBufferSize", pFile->getBufferSize(), 2979);
    compare("getFilename", pFile->getFilename(), "html/images/points.svg");
}

// ---------------------------------------------------------------------

bool UnitTestTestResources::doAfterTest() {
    // nothing
    return true;
}