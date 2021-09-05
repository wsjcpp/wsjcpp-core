
#include <wsjcpp_core.h>
#include <wsjcpp_unit_tests.h>

// ---------------------------------------------------------------------
// UnitTestMakeDirsPath

class UnitTestMakeDirsPath : public WsjcppUnitTestBase {
    public:
        UnitTestMakeDirsPath();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

REGISTRY_WSJCPP_UNIT_TEST(UnitTestMakeDirsPath)

UnitTestMakeDirsPath::UnitTestMakeDirsPath()
    : WsjcppUnitTestBase("UnitTestMakeDirsPath") {
}

// ---------------------------------------------------------------------

bool UnitTestMakeDirsPath::doBeforeTest() {
    // do something before test
    return true;
}

// ---------------------------------------------------------------------

void UnitTestMakeDirsPath::executeTest() {

    if (WsjcppCore::dirExists("./data/makedirpaths")) {
        WsjcppCore::recoursiveRemoveDir("./data/makedirpaths");
    }

    struct LTest {
        LTest(
            const std::string &sDir,
            const std::vector<std::string> &vSubPaths
        ) {
            this->sDir = sDir;
            this->vSubPaths = vSubPaths;
        };
        std::string sDir;
        std::vector<std::string> vSubPaths;
    };
    std::vector<LTest> tests;
    tests.push_back(LTest("./data/makedirpaths/dir1/dir2", {
        "./data",
        "./data/makedirpaths",
        "./data/makedirpaths/dir1",
        "./data/makedirpaths/dir1/dir2"
    }));
    tests.push_back(LTest("./data/makedirpaths/dir1/dir3", {
        "./data",
        "./data/makedirpaths",
        "./data/makedirpaths/dir1",
        "./data/makedirpaths/dir1/dir3"
    }));
    tests.push_back(LTest("./data/makedirpaths/dir1/dir4/", {
        "./data",
        "./data/makedirpaths",
        "./data/makedirpaths/dir1",
        "./data/makedirpaths/dir1/dir4"
    }));

    for (int i = 0; i < tests.size(); i++) {
        std::string sPath = tests[i].sDir;
        bool bResult = WsjcppCore::makeDirsPath(sPath);
        std::string sPathMark = "path" + std::to_string(i+1);
        compare("Create " + sPathMark, bResult, true);
        std::vector<std::string> vPaths = tests[i].vSubPaths;
        for (int x = 0; x < vPaths.size(); x++) {
            compare("Check " + sPathMark + " " + vPaths[x], WsjcppCore::dirExists(vPaths[x]), true);
        }
    }
    WsjcppCore::recoursiveRemoveDir("./data/makedirpaths");
}

// ---------------------------------------------------------------------

bool UnitTestMakeDirsPath::doAfterTest() {
    // do somethig after test
    return true;
}


