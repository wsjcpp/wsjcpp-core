#include "unit_test_split.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_UNIT_TEST(UnitTestSplit)

UnitTestSplit::UnitTestSplit()
    : WSJCppUnitTestBase("UnitTestSplit") {
}

// ---------------------------------------------------------------------

void UnitTestSplit::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestSplit::run() {
bool bTestSuccess = true;

    struct LTest {
        LTest(
            const std::string &sStr,
            const std::string &sDelim,
            const std::vector<std::string> &vExpectedVector
        ) {
            this->sStr = sStr;
            this->sDelim = sDelim;
            this->vExpectedVector = vExpectedVector;
        };
        std::string sStr;
        std::string sDelim;
        std::vector<std::string> vExpectedVector;
    };
    std::vector<LTest> tests;
    tests.push_back(LTest("1 2 3 4 5", " ", {"1", "2", "3", "4", "5"}));
    tests.push_back(LTest("|1f|2п|3%^|44354|5kdasjfdre|2", "|", {"", "1f", "2п", "3%^", "44354", "5kdasjfdre", "2"}));
    tests.push_back(LTest("|1f|2п|3%^|44354|5kdasjfdre|", "|", {"", "1f", "2п", "3%^", "44354", "5kdasjfdre", ""}));
    tests.push_back(LTest("some1 => some2 => some3", "=>", {"some1 ", " some2 ", " some3"}));
    tests.push_back(LTest("some1 => some2 => some3 =>", "=>", {"some1 ", " some2 ", " some3 ", ""}));

    for (int i = 0; i < tests.size(); i++) {
        LTest test = tests[i];
        std::string sPrefix = "test" + std::to_string(i) + "(\"" + test.sStr + "\")";
        std::vector<std::string> vSplitted = WSJCppCore::split(test.sStr, test.sDelim);
        compareN(bTestSuccess, sPrefix + ": size", vSplitted.size(), test.vExpectedVector.size());
        int nMin = std::min(vSplitted.size(), test.vExpectedVector.size());
        for (int n = 0; n < nMin; n++) {
            compareS(bTestSuccess, sPrefix + ", element: " + std::to_string(n), vSplitted[n], test.vExpectedVector[n]);
        }
    }

    return bTestSuccess;
}

