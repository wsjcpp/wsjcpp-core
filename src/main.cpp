#include <string.h>
#include <iostream>
#include <algorithm>
#include "wsjcpp_core.h"

int main(int argc, char* argv[]) {
    const std::string TAG = "MAIN";
    std::string appName = std::string(WSJCPP_NAME);
    std::string appVersion = std::string(WSJCPP_VERSION);

    if (!WsjcppCore::dirExists(".logs")) {
        WsjcppCore::makeDir(".logs");
    }
    WsjcppLog::setLogDirectory(".logs");
    WsjcppLog::setPrefixLogFile("wsjcpp_core");

    WsjcppLog::info(TAG, "Hello info");
    WsjcppLog::err(TAG, "Hello err");
    WsjcppLog::warn(TAG, "Hello warn");
    WsjcppLog::ok(TAG, "Hello ok");

    WsjcppCore::init(
        argc, argv, 
        std::string(WSJCPP_NAME),
        std::string(WSJCPP_VERSION),
        "Evgenii Sopov",
        ""
    );
    return 0;
}