/*
 * MIT License
 *
 * Copyright (c) 2019-2026 Evgenii Sopov
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

// original source-code: https://github.com/wsjcpp/wsjcpp-core

#include <string.h>
#include <iostream>
#include <algorithm>
#include "wsjcpp_core.h"

int main(int argc, char* argv[]) {
    const std::string TAG = "MAIN";
    std::string appName = "wsjcpp-core"; // std::string(WSJCPP_APP_NAME);
    std::string appVersion = "..."; // std::string(WSJCPP_APP_VERSION);

    // WsjcppLog::setEnableLogFile(false);
    WsjcppLog::setLogDirectory(".logs");
    WsjcppLog::setPrefixLogFile("wsjcpp_core");

    WsjcppLog::info(TAG, "Hello info");
    WsjcppLog::err(TAG, "Hello err");
    WsjcppLog::warn(TAG, "Hello warn");
    WsjcppLog::ok(TAG, "Hello ok");

    WsjcppCore::init(
        argc, argv, 
        std::string(appName),
        std::string(appVersion),
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