#include "unit_test_date_time_format.h"
#include <vector>
#include <wsjcpp_core.h>
#include <regex>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestDateTimeFormat)

UnitTestDateTimeFormat::UnitTestDateTimeFormat()
    : WsjcppUnitTestBase("UnitTestDateTimeFormat") {
}

// ---------------------------------------------------------------------

bool UnitTestDateTimeFormat::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestDateTimeFormat::executeTest() {

    // format like '2020-09-17 02:22:40.755'
    {
        std::string sNow = WsjcppCore::getCurrentTimeForLogFormat();
        std::string sRegexp = "^\\d{4}-\\d{2}-\\d{2} \\d{2}:\\d{2}:\\d{2}\\.\\d{3}$";
        std::regex rx(sRegexp);
        bool bResult = std::regex_match(sNow, rx);
        compare("now for log format: " + sNow + ", regexp: " + sRegexp, bResult, true);
    }

    // like this '20200917_023347'
    {
        std::string sNow = WsjcppCore::getCurrentTimeForFilename();
        // std::cout << sNow << std::endl;
        std::string sRegexp = "^\\d{8}_\\d{6}$";
        std::regex rx(sRegexp);
        bool bResult = std::regex_match(sNow, rx);
        compare("now for filename: " + sNow + ", regexp: " + sRegexp, bResult, true);
    }

    {
        long nMs = WsjcppCore::getCurrentTimeInMilliseconds();
        long nSec = WsjcppCore::getCurrentTimeInSeconds();
        // std::cout << nMs << std::endl;
        // std::cout << nSec << std::endl;
        long nMsToSec = nMs / 1000;
        compare("now sec and ms", nMsToSec, nSec);
    }

    // like this '20200917_023347'
    {
        long nNow = WsjcppCore::getCurrentTimeInSeconds();
        std::string sNow = WsjcppCore::formatTimeForFilename(nNow);
        std::string sRegexp = "^\\d{8}_\\d{6}$";
        std::regex rx(sRegexp);
        bool bResult = std::regex_match(sNow, rx);
        compare("now for filename (2): " + sNow + ", regexp: " + sRegexp, bResult, true);
    }

    // like 'Thu, 17 Sep 2020 02:39:52 GMT'
    {
        std::map<long, std::string> mapTimes;
        
        // monthes
        // 2592000 - 30 days
        mapTimes[1578105758] = "Sat, 04 Jan 2020 02:42:38 GMT";
        mapTimes[1580697758] = "Mon, 03 Feb 2020 02:42:38 GMT";
        mapTimes[1583289758] = "Wed, 04 Mar 2020 02:42:38 GMT";
        mapTimes[1585881758] = "Fri, 03 Apr 2020 02:42:38 GMT";
        mapTimes[1588473758] = "Sun, 03 May 2020 02:42:38 GMT";
        mapTimes[1591065758] = "Tue, 02 Jun 2020 02:42:38 GMT";
        mapTimes[1593657758] = "Thu, 02 Jul 2020 02:42:38 GMT";
        mapTimes[1596249758] = "Sat, 01 Aug 2020 02:42:38 GMT";
        mapTimes[1598841758] = "Mon, 31 Aug 2020 02:42:38 GMT";
        mapTimes[1601433758] = "Wed, 30 Sep 2020 02:42:38 GMT";
        mapTimes[1604025758] = "Fri, 30 Oct 2020 02:42:38 GMT";
        mapTimes[1606617758] = "Sun, 29 Nov 2020 02:42:38 GMT";
        mapTimes[1609209758] = "Tue, 29 Dec 2020 02:42:38 GMT";

        // week days
        mapTimes[1599964958] = "Sun, 13 Sep 2020 02:42:38 GMT";
        mapTimes[1600051358] = "Mon, 14 Sep 2020 02:42:38 GMT";
        mapTimes[1600137758] = "Tue, 15 Sep 2020 02:42:38 GMT";
        mapTimes[1600224158] = "Wed, 16 Sep 2020 02:42:38 GMT";
        mapTimes[1600310558] = "Thu, 17 Sep 2020 02:42:38 GMT";
        mapTimes[1600396958] = "Fri, 18 Sep 2020 02:42:38 GMT";
        mapTimes[1600483358] = "Sat, 19 Sep 2020 02:42:38 GMT";
        
        std::map<long, std::string>::iterator it;
        for (it = mapTimes.begin(); it != mapTimes.end(); ++it) {
            long nTime = it->first;
            std::string sTime = WsjcppCore::formatTimeForWeb(nTime);
            // std::cout << sTime << std::endl;
            // std::string sRegexp = "^(Sun|Mon|Tue|Wed|Thu|Fri|Sat){1}, \\d{1,2} .* \\d{1,4} GMT$";
            std::string sRegexp = "^(Sun|Mon|Tue|Wed|Thu|Fri|Sat){1}, \\d{2} "
                "(Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec) "
                "\\d{1,4} \\d{2}:\\d{2}:\\d{2} GMT$";
            std::regex rx(sRegexp);
            bool bResult = std::regex_match(sTime, rx);
            compare("now for web: " + sTime + ", regexp: " + sRegexp, bResult, true);
            compare("now for web str:", sTime, it->second);
        }
    }
    
    // like "2020-09-17 02:39:52"
    {
        long nNow = WsjcppCore::getCurrentTimeInSeconds();
        std::string sNow = WsjcppCore::formatTimeUTC(nNow);
        std::string sRegexp = "^\\d{4}-\\d{2}-\\d{2} \\d{2}:\\d{2}:\\d{2}$";
        std::regex rx(sRegexp);
        bool bResult = std::regex_match(sNow, rx);
        compare("now for time utc: " + sNow + ", regexp: " + sRegexp, bResult, true);
    }
}

// ---------------------------------------------------------------------

bool UnitTestDateTimeFormat::doAfterTest() {
    // nothing
    return true;
}
