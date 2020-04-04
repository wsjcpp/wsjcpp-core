#include "wsjcpp_unit_tests.h"

WsjcppUnitTestBase::WsjcppUnitTestBase(const std::string &sTestName) {
    m_sTestName = sTestName;
    TAG = m_sTestName;
    WsjcppUnitTests::addUnitTest(sTestName, this);
}

// ---------------------------------------------------------------------

std::string WsjcppUnitTestBase::name() {
    return m_sTestName;
}

// ---------------------------------------------------------------------

void WsjcppUnitTestBase::compareS(bool &bTestSuccess, const std::string &sPoint,
    const std::string &sValue, const std::string &sExpected) {
    if (sValue != sExpected) {
        WsjcppLog::err(TAG, " {" + sPoint + "} Expected '" + sExpected + "', but got '" + sValue + "'");
        bTestSuccess = false;
    }
}

// ---------------------------------------------------------------------

bool WsjcppUnitTestBase::compareN(bool &bTestSuccess, const std::string &sPoint, int nValue, int nExpected) {
    if (nValue != nExpected) {
        WsjcppLog::err(TAG, " {" + sPoint + "} Expected '" + std::to_string(nExpected) + "', but got '" + std::to_string(nValue) + "'");
        bTestSuccess = false;
        return false;
    }
    return true;
}

// ---------------------------------------------------------------------

bool WsjcppUnitTestBase::compareD(bool &bTestSuccess, const std::string &sPoint, double nValue, double nExpected) {
    if (nValue != nExpected) {
        WsjcppLog::err(TAG, " {" + sPoint + "} Expected '" + std::to_string(nExpected) + "', but got '" + std::to_string(nValue) + "'");
        bTestSuccess = false;
        return false;
    }
    return true;
}

// ---------------------------------------------------------------------

void WsjcppUnitTestBase::compareB(bool &bTestSuccess, const std::string &sPoint, bool bValue, bool bExpected) {
    if (bValue != bExpected) {
        WsjcppLog::err(TAG, " {" + sPoint + "} Expected '" + (bExpected ? "true" : "false") + "', but got '" + (bValue ? "true" : "false") + "'");
        bTestSuccess = false;
    }
}

// ---------------------------------------------------------------------

std::vector<WsjcppUnitTestBase*> *g_pUnitTests = NULL;

void WsjcppUnitTests::initGlobalVariables() {
    if (g_pUnitTests == NULL) {
        // WsjcppLog::info(std::string(), "Create handlers map");
        g_pUnitTests = new std::vector<WsjcppUnitTestBase*>();
    }
}

// ---------------------------------------------------------------------

void WsjcppUnitTests::addUnitTest(const std::string &sTestName, WsjcppUnitTestBase* pUnitTest) {
    WsjcppUnitTests::initGlobalVariables();
    bool bFound = false;
    for (int i = 0; i < g_pUnitTests->size(); i++) {
        WsjcppUnitTestBase* p = g_pUnitTests->at(i);
        if (p->name() == sTestName) {
            bFound = true;
        }
    }
    
    if (bFound) {
        WsjcppLog::err(sTestName, "Already registered");
    } else {
        g_pUnitTests->push_back(pUnitTest);
        // Log::info(sCmd, "Registered");
    }
}

// ---------------------------------------------------------------------

bool WsjcppUnitTests::runUnitTests() {
    WsjcppUnitTests::initGlobalVariables();
    int nAll = g_pUnitTests->size();
    WsjcppLog::info("runUnitTests",  "All tests count " + std::to_string(nAll));
    int nSuccess = 0;
    for (int i = 0; i < g_pUnitTests->size(); i++) {
        WsjcppUnitTestBase* pUnitTest = g_pUnitTests->at(i);
        std::string sTestName = pUnitTest->name();
        WsjcppLog::info("runUnitTests",  "Run test " + sTestName);
        if (pUnitTest->run()) {
            WsjcppLog::ok(sTestName,  "Test passed");
            nSuccess++;
        } else {
            WsjcppLog::err(sTestName,  "Test failed");
        }
    }
    WsjcppLog::info("WsjcppUnitTests::runUnitTests",  "Passed tests " + std::to_string(nSuccess) + " / " + std::to_string(nAll));
    return nSuccess == nAll;
}

// ---------------------------------------------------------------------