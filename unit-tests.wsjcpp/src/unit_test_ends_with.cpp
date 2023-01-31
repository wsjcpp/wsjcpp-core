
#include <wsjcpp_core.h>
#include <wsjcpp_unit_tests.h>

// ---------------------------------------------------------------------
// UnitTestEndsWith

class UnitTestEndsWith : public WsjcppUnitTestBase {
    public:
        UnitTestEndsWith();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

REGISTRY_WSJCPP_UNIT_TEST(UnitTestEndsWith)

UnitTestEndsWith::UnitTestEndsWith()
    : WsjcppUnitTestBase("UnitTestEndsWith") {
}

// ---------------------------------------------------------------------

bool UnitTestEndsWith::doBeforeTest() {
    // do something before test
    return true;
}

// ---------------------------------------------------------------------

void UnitTestEndsWith::executeTest() {
    
    struct LTest {
        LTest(
            const std::string &sStr,
            const std::string &sStart,
            bool bExpected
        ) {
            this->sStr = sStr;
            this->sStart = sStart;
            this->bExpected = bExpected;
        };
        std::string sStr;
        std::string sStart;
        bool bExpected;
    };

    std::vector<LTest> tests;
    tests.push_back(LTest("123456789", "789", true));
    tests.push_back(LTest("122456779", "789", false));
    tests.push_back(LTest("12", "789", false));
    tests.push_back(LTest("12", "abc", false));
    tests.push_back(LTest("^1234567", "789", false));
    tests.push_back(LTest(" 12345", "789", false));
    tests.push_back(LTest(" 12345", "345", true));

    for (int i = 0; i < tests.size(); i++) {
        LTest test = tests[i];
        std::string sPrefix = "test" + std::to_string(i) + "(\"" + test.sStr + "\", \"" + test.sStart + "\")";
        compare(sPrefix + ": size", WsjcppCore::endsWith(test.sStr, test.sStart), test.bExpected);
    }
}

// ---------------------------------------------------------------------

bool UnitTestEndsWith::doAfterTest() {
    // do somethig after test
    return true;
}


