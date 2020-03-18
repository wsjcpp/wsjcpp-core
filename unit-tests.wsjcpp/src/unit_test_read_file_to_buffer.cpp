#include "unit_test_read_file_to_buffer.h"
#include <vector>
#include <algorithm>
#include <wsjcpp_core.h>

REGISTRY_UNIT_TEST(UnitTestReadFileToBuffer)

UnitTestReadFileToBuffer::UnitTestReadFileToBuffer()
    : WSJCppUnitTestBase("UnitTestReadFileToBuffer") {
}

// ---------------------------------------------------------------------

void UnitTestReadFileToBuffer::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestReadFileToBuffer::run() {
    bool bTestSuccess = true;
    std::string sExpected = "1234567890\nqwerty123456";
    char *pBuffer = nullptr;
    int nBufferSize = 0;
    WSJCppCore::readFileToBuffer("./data/readFileToBuffer.txt", &pBuffer, nBufferSize);
    compareN(bTestSuccess, "Size of readed", nBufferSize, sExpected.length());
    int nMin = std::min(nBufferSize, (int)sExpected.length());
    for (int i = 0; i < nMin; i++) {
        char c_got = pBuffer[i];
        char c_expected = sExpected[i];
        compareN(bTestSuccess, "Check the " + std::to_string(i), c_got, c_expected);
    }
    // compareB(bTestSuccess, "Not implemented", true, false);
    return bTestSuccess;
}

