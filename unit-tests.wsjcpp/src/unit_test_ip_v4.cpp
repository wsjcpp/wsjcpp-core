#include "unit_test_ip_v4.h"
#include <vector>
#include <iostream>
#include <wsjcpp_core.h>

REGISTRY_UNIT_TEST(UnitTestIPv4)


UnitTestIPv4::UnitTestIPv4()
: WSJCppUnitTestBase("UnitTestIPv4") {
    //
}

void UnitTestIPv4::init() {
    // nothing
}

bool UnitTestIPv4::run() {
    struct TestIPv4 {
        TestIPv4(const std::string &sIPv4, bool bYes) :
            m_sIPv4(sIPv4), m_bYes(bYes) {

            };
        std::string m_sIPv4;
        bool m_bYes;
        
    };
    std::vector<TestIPv4> vIPv4s;
    vIPv4s.push_back(TestIPv4("127.0.0.1", true));
    vIPv4s.push_back(TestIPv4("10.0.0.1", true));
    vIPv4s.push_back(TestIPv4("0.0.0.0", true));
    vIPv4s.push_back(TestIPv4("300.200.100.100", false));
    vIPv4s.push_back(TestIPv4("aaaa", false));
    vIPv4s.push_back(TestIPv4("100.0.0.x", false));
    vIPv4s.push_back(TestIPv4("10033.1289.0.0", false));
    vIPv4s.push_back(TestIPv4("10033.1289.0.0.0.0.0", false));
    
    bool bTestSuccess = true;
    for (int i = 0; i < vIPv4s.size(); i++) {
        TestIPv4 t = vIPv4s[i];
        compareB(bTestSuccess, "Test[" + t.m_sIPv4 + "]", WSJCppCore::isIPv4(t.m_sIPv4), t.m_bYes);
    }
    return bTestSuccess;
}