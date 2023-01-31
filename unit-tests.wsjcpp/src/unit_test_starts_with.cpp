
#include <wsjcpp_core.h>
#include <wsjcpp_unit_tests.h>

// ---------------------------------------------------------------------
// UnitTestStartsWith

class UnitTestStartsWith : public WsjcppUnitTestBase {
    public:
        UnitTestStartsWith();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

REGISTRY_WSJCPP_UNIT_TEST(UnitTestStartsWith)

UnitTestStartsWith::UnitTestStartsWith()
    : WsjcppUnitTestBase("UnitTestStartsWith") {
}

// ---------------------------------------------------------------------

bool UnitTestStartsWith::doBeforeTest() {
    // do something before test
    return true;
}

// ---------------------------------------------------------------------

void UnitTestStartsWith::executeTest() {
    
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
    tests.push_back(LTest("123456789", "123", true));
    tests.push_back(LTest("122456789", "123", false));
    tests.push_back(LTest("12", "123", false));
    tests.push_back(LTest("12", "abc", false));
    tests.push_back(LTest("^1234567", "123", false));
    tests.push_back(LTest(" 12345", "123", false));

     for (int i = 0; i < tests.size(); i++) {
        LTest test = tests[i];
        std::string sPrefix = "test" + std::to_string(i) + "(\"" + test.sStr + "\", \"" + test.sStart + "\")";
        compare(sPrefix + ": size", WsjcppCore::startsWith(test.sStr, test.sStart), test.bExpected);
    }
}

// ---------------------------------------------------------------------

bool UnitTestStartsWith::doAfterTest() {
    // do somethig after test
    return true;
}


