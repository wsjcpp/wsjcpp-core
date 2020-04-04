#include <string>
#include <wsjcpp_core.h>
#include <wsjcpp_unit_tests.h>

int main(int argc, char** argv) {
    WsjcppCore::initRandom();
    std::string TAG = "UnitTests";
    WsjcppLog::setPrefixLogFile("unit-tests");
    std::string sLogDir = "./logs"; 
    if (!WsjcppCore::dirExists(sLogDir)) {
        WsjcppCore::makeDir(sLogDir);
    }
    WsjcppLog::setLogDirectory(sLogDir);
    if (!WsjcppCore::dirExists(sLogDir)) {
        WsjcppLog::err(TAG, "Directory '" + sLogDir + "' did'not exists");
        return -1;
    }

    if (!WsjcppUnitTests::runUnitTests()) {
        WsjcppLog::err(TAG, "Some unit tests failed");
        return -1;
    }
    return 0;
}