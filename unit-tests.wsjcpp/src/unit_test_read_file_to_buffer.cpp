#include "unit_test_read_file_to_buffer.h"
#include <vector>
#include <algorithm>
#include <wsjcpp_core.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestReadFileToBuffer)

UnitTestReadFileToBuffer::UnitTestReadFileToBuffer()
    : WsjcppUnitTestBase("UnitTestReadFileToBuffer") {
}

// ---------------------------------------------------------------------

bool UnitTestReadFileToBuffer::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestReadFileToBuffer::executeTest() {
    std::string sExpected = "1234567890\nqwerty123456";
    char *pBuffer = nullptr;
    int nBufferSize = 0;
    WsjcppCore::readFileToBuffer("./data/readFileToBuffer.txt", &pBuffer, nBufferSize);
    compare("Size of readed", nBufferSize, sExpected.length());
    int nMin = std::min(nBufferSize, (int)sExpected.length());
    for (int i = 0; i < nMin; i++) {
        char c_got = pBuffer[i];
        char c_expected = sExpected[i];
        compare("Check the " + std::to_string(i), c_got, c_expected);
    }
}

// ---------------------------------------------------------------------

bool UnitTestReadFileToBuffer::doAfterTest() {
    // nothing
    return true;
}