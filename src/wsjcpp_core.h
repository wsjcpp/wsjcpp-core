#ifndef WSJCPP_CORE_H
#define WSJCPP_CORE_H

#include <string>
#include <vector>
#include <map>
#include <mutex>
#include <deque>
#include <iostream>

class WSJCppCore {
    public:
        static bool init(
            int argc, char** argv, 
            const std::string &sApplicationName,
            const std::string &sApplicationVersion,
            const std::string &sApplicationAuthor,
            const std::string &sLibraryNameForExports
        );

        static std::string doNormalizePath(const std::string & sPath);
        static std::string getCurrentDirectory();

        static long currentTime_milliseconds();
        static long currentTime_seconds();
        static std::string currentTime_forFilename();
        static std::string currentTime_logformat();
        static std::string threadId();
        static std::string formatTimeForWeb(long nTimeInSec);
        static std::string formatTimeForFilename(long nTimeInSec);
        static std::string formatTimeUTC(int nTimeInSec);

        static bool dirExists(const std::string &sFilename);
        static bool fileExists(const std::string &sFilename);
        static std::vector<std::string> listOfDirs(const std::string &sDirname);
        static std::vector<std::string> listOfFiles(const std::string &sDirname);     
        static bool makeDir(const std::string &sDirname);
        static bool writeFile(const std::string &sFilename, const std::string &sContent);
        static bool writeFile(const std::string &sFilename, const char *pBuffer, const int nBufferSize);

        static std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ");
        static std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ");
        static std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ");
        static std::string& to_lower(std::string& str);

        static void initRandom();
        static std::string createUuid();
};


// ---------------------------------------------------------------------

enum WSJCppColorCode {
    FG_RED      = 31,
    FG_GREEN    = 32,
    FG_YELLOW   = 93,
    FG_BLUE     = 34,
    FG_DEFAULT  = 39,
    BG_RED      = 41,
    BG_GREEN    = 42,
    BG_BLUE     = 44,
    BG_DEFAULT  = 49
};

// ---------------------------------------------------------------------

class WSJCppColorModifier {
    WSJCppColorCode code;
    public:
        WSJCppColorModifier(WSJCppColorCode pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const WSJCppColorModifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
};

// ---------------------------------------------------------------------

class WSJCppLog {
    public:
        static std::string g_LOG_DIR;
        static std::string g_PREFIX_LOG_FILE;
        static std::string g_LOG_FILE;
        static long g_LOG_START_TIME;
        static void doLogRotateUpdateFilename(bool bForce = false);

        static void info(const std::string &sTag, const std::string &sMessage);
        static void err(const std::string &sTag, const std::string &sMessage);
        static void throw_err(const std::string &sTag, const std::string &sMessage);
        static void warn(const std::string &sTag, const std::string &sMessage);
        static void ok(const std::string &sTag, const std::string &sMessage);
        static void setLogDirectory(const std::string &sDirectoryPath);
        static void setPrefixLogFile(const std::string &sPrefixLogFile);
        // static nlohmann::json getLastLogs();
        static void initGlobalVariables();

    private:
        static void add(WSJCppColorModifier &clr, const std::string &sType, const std::string &sTag, const std::string &sMessage);
};

#endif // WSJCPP_CORE_H