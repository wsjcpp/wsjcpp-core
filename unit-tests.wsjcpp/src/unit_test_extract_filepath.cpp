
#include <wsjcpp_core.h>
#include <wsjcpp_unit_tests.h>

// ---------------------------------------------------------------------
// UnitTestExtractFilepath

class UnitTestExtractFilepath : public WsjcppUnitTestBase {
    public:
        UnitTestExtractFilepath();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

REGISTRY_WSJCPP_UNIT_TEST(UnitTestExtractFilepath)

UnitTestExtractFilepath::UnitTestExtractFilepath()
    : WsjcppUnitTestBase("UnitTestExtractFilepath") {
}

// ---------------------------------------------------------------------

bool UnitTestExtractFilepath::doBeforeTest() {
    // do something before test
    return true;
}

// ---------------------------------------------------------------------

void UnitTestExtractFilepath::executeTest() {
    struct LTest {
        LTest(
            const std::string &sFullpath,
            const std::string &sFilename
        ) {
            this->sFullpath = sFullpath;
            this->sFilename = sFilename;
        };
        std::string sFullpath;
        std::string sFilename;
    };
    std::vector<LTest> tests;
    tests.push_back(LTest(".//../bin/some/../file.txt", "file.txt"));

    for (int i = 0; i < tests.size(); i++) {
        LTest t = tests[i];
        std::string sTestId = "test" + std::to_string(i);
        
        compare(sTestId, WsjcppCore::extractFilename(t.sFullpath), t.sFilename);
    }
}

// ---------------------------------------------------------------------

bool UnitTestExtractFilepath::doAfterTest() {
    // do somethig after test
    return true;
}


