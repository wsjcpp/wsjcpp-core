#include <string.h>
#include <iostream>
#include <algorithm>
#include "wsjcpp_core.h"

int main(int argc, char* argv[]) {
    const std::string TAG = "MAIN";
    std::string appName = std::string(WSJCPP_NAME);
    std::string appVersion = std::string(WSJCPP_VERSION);

    if (!WSJCppCore::dirExists(".logs")) {
        WSJCppCore::makeDir(".logs");
    }
    WSJCppLog::setLogDirectory(".logs");
    WSJCppLog::setPrefixLogFile("wsjcpp_core");

    WSJCppLog::info(TAG, "Hello info");
    WSJCppLog::err(TAG, "Hello err");
    WSJCppLog::warn(TAG, "Hello warn");
    WSJCppLog::ok(TAG, "Hello ok");

    WSJCppCore::init(
        argc, argv, 
        std::string(WSJCPP_NAME),
        std::string(WSJCPP_VERSION),
        "Evgenii Sopov",
        ""
    );
    return 0;
}