#include <string.h>
#include <iostream>
#include <algorithm>
#include "wsjcpp_core.h"

int main(int argc, char* argv[]) {
    std::string TAG = "MAIN";
    std::string appName = std::string(WSJCPP_NAME);
    std::string appVersion = std::string(WSJCPP_VERSION);
    WSJCppLog::setPrefixLogFile("wsjcpp_core");
    WSJCppLog::info(TAG, "Hello");

    WSJCppCore::init(
        argc, argv, 
        std::string(WSJCPP_NAME),
        std::string(WSJCPP_VERSION),
        "Evgenii Sopov",
        ""
    );
    
    return 0;
}