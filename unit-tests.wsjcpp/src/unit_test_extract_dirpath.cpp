
#include <wsjcpp_core.h>
#include <wsjcpp_unit_tests.h>

// ---------------------------------------------------------------------
// UnitTestExtractDirpath

class UnitTestExtractDirpath : public WsjcppUnitTestBase {
    public:
        UnitTestExtractDirpath();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

REGISTRY_WSJCPP_UNIT_TEST(UnitTestExtractDirpath)

UnitTestExtractDirpath::UnitTestExtractDirpath()
    : WsjcppUnitTestBase("UnitTestExtractDirpath") {
}

// ---------------------------------------------------------------------

bool UnitTestExtractDirpath::doBeforeTest() {
    // do something before test
    return true;
}

// ---------------------------------------------------------------------

void UnitTestExtractDirpath::executeTest() {
    struct LTest {
        LTest(
            const std::string &sFullpath,
            const std::string &sDirpath
        ) {
            this->sFullpath = sFullpath;
            this->sDirpath = sDirpath;
        };
        std::string sFullpath;
        std::string sDirpath;
    };
    std::vector<LTest> tests;
    tests.push_back(LTest(".//../bin/some/../file.txt", ".//../bin/some/.."));

    for (int i = 0; i < tests.size(); i++) {
        LTest t = tests[i];
        std::string sTestId = "test" + std::to_string(i);
        
        compare(sTestId, WsjcppCore::extractDirpath(t.sFullpath), t.sDirpath);
    }
}

// ---------------------------------------------------------------------

bool UnitTestExtractDirpath::doAfterTest() {
    // do somethig after test
    return true;
}


