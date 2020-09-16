#include <string.h>
#include <iostream>
#include <algorithm>
#include "wsjcpp_core.h"

int main(int argc, char* argv[]) {
    const std::string TAG = "MAIN";
    std::string appName = std::string(WSJCPP_APP_NAME);
    std::string appVersion = std::string(WSJCPP_APP_VERSION);

    // WsjcppLog::setEnableLogFile(false);
    WsjcppLog::setLogDirectory(".logs");
    WsjcppLog::setPrefixLogFile("wsjcpp_core");

    WsjcppLog::info(TAG, "Hello info");
    WsjcppLog::err(TAG, "Hello err");
    WsjcppLog::warn(TAG, "Hello warn");
    WsjcppLog::ok(TAG, "Hello ok");

    WsjcppCore::init(
        argc, argv, 
        std::string(WSJCPP_APP_NAME),
        std::string(WSJCPP_APP_VERSION),
        "Evgenii Sopov",
        ""
    );
    if (WsjcppCore::dirExists("./tmp2")) {
        WsjcppCore::recoursiveRemoveDir("./tmp2");
    }
    WsjcppCore::recoursiveCopyFiles("./tmp", "./tmp2");
    WsjcppCore::recoursiveRemoveDir("./tmp2");

    WsjcppCore::getThreadId();

    return 0;
}