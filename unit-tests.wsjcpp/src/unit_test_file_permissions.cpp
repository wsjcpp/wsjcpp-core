#include "unit_test_file_permissions.h"
#include <vector>
#include <wsjcpp_core.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestFilePermissions)

UnitTestFilePermissions::UnitTestFilePermissions()
    : WsjcppUnitTestBase("UnitTestFilePermissions") {
}

// ---------------------------------------------------------------------

bool UnitTestFilePermissions::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestFilePermissions::executeTest() {
    WsjcppFilePermissions fp1;
    // default
    compare("file_perm (0) toString",        fp1.toString(), "-rw----r--");
    compare("file_perm (1) toUInt16",        fp1.toUInt16(), 0x0604);
    compare("file_perm (0) owner read",      fp1.getOwnerReadFlag(),    true);
    compare("file_perm (0) owner write",     fp1.getOwnerWriteFlag(),   true);
    compare("file_perm (0) owner execute",   fp1.getOwnerExecuteFlag(), false);
    compare("file_perm (0) group read",      fp1.getGroupReadFlag(),    false);
    compare("file_perm (0) group write",     fp1.getGroupWriteFlag(),   false);
    compare("file_perm (0) group execute",   fp1.getGroupExecuteFlag(), false);
    compare("file_perm (0) other read",      fp1.getOtherReadFlag(),    true);
    compare("file_perm (0) other write",     fp1.getOtherWriteFlag(),   false);
    compare("file_perm (0) other execute",   fp1.getOtherExecuteFlag(), false);

    fp1.setOwnerReadFlag(false);
    fp1.setOwnerWriteFlag(false);
    fp1.setOtherReadFlag(false);
    compare("file_perm (1) toString",        fp1.toString(), "----------");
    compare("file_perm (1) toUInt16",        fp1.toUInt16(), 0x0);
    compare("file_perm (1) owner read",      fp1.getOwnerReadFlag(),    false);
    compare("file_perm (1) owner write",     fp1.getOwnerWriteFlag(),   false);
    compare("file_perm (1) owner execute",   fp1.getOwnerExecuteFlag(), false);
    compare("file_perm (1) group read",      fp1.getGroupReadFlag(),    false);
    compare("file_perm (1) group write",     fp1.getGroupWriteFlag(),   false);
    compare("file_perm (1) group execute",   fp1.getGroupExecuteFlag(), false);
    compare("file_perm (1) other read",      fp1.getOtherReadFlag(),    false);
    compare("file_perm (1) other write",     fp1.getOtherWriteFlag(),   false);
    compare("file_perm (1) other execute",   fp1.getOtherExecuteFlag(), false);

    fp1.setOwnerReadFlag(true);
    compare("file_perm (2) owner read str",  fp1.toString(), "-r--------");
    compare("file_perm (2) toUInt16",        fp1.toUInt16(), 0x0400);
    compare("file_perm (2) owner read",      fp1.getOwnerReadFlag(),    true);
    compare("file_perm (2) owner write",     fp1.getOwnerWriteFlag(),   false);
    compare("file_perm (2) owner execute",   fp1.getOwnerExecuteFlag(), false);
    compare("file_perm (2) group read",      fp1.getGroupReadFlag(),    false);
    compare("file_perm (2) group write",     fp1.getGroupWriteFlag(),   false);
    compare("file_perm (2) group execute",   fp1.getGroupExecuteFlag(), false);
    compare("file_perm (2) other read",      fp1.getOtherReadFlag(),    false);
    compare("file_perm (2) other write",     fp1.getOtherWriteFlag(),   false);
    compare("file_perm (2) other execute",   fp1.getOtherExecuteFlag(), false);

    fp1.setOwnerWriteFlag(true);
    compare("file_perm (3) owner write str", fp1.toString(), "-rw-------");
    compare("file_perm (3) toUInt16",        fp1.toUInt16(), 0x0600);
    compare("file_perm (3) owner read",      fp1.getOwnerReadFlag(),    true);
    compare("file_perm (3) owner write",     fp1.getOwnerWriteFlag(),   true);
    compare("file_perm (3) owner execute",   fp1.getOwnerExecuteFlag(), false);
    compare("file_perm (3) group read",      fp1.getGroupReadFlag(),    false);
    compare("file_perm (3) group write",     fp1.getGroupWriteFlag(),   false);
    compare("file_perm (3) group execute",   fp1.getGroupExecuteFlag(), false);
    compare("file_perm (3) other read",      fp1.getOtherReadFlag(),    false);
    compare("file_perm (3) other write",     fp1.getOtherWriteFlag(),   false);
    compare("file_perm (3) other execute",   fp1.getOtherExecuteFlag(), false);

    fp1.setOwnerExecuteFlag(true);
    compare("file_perm (4) toString",        fp1.toString(), "-rwx------");
    compare("file_perm (4) toUInt16",        fp1.toUInt16(), 0x0700);
    compare("file_perm (4) owner read",      fp1.getOwnerReadFlag(),    true);
    compare("file_perm (4) owner write",     fp1.getOwnerWriteFlag(),   true);
    compare("file_perm (4) owner execute",   fp1.getOwnerExecuteFlag(), true);
    compare("file_perm (4) group read",      fp1.getGroupReadFlag(),    false);
    compare("file_perm (4) group write",     fp1.getGroupWriteFlag(),   false);
    compare("file_perm (4) group execute",   fp1.getGroupExecuteFlag(), false);
    compare("file_perm (4) other read",      fp1.getOtherReadFlag(),    false);
    compare("file_perm (4) other write",     fp1.getOtherWriteFlag(),   false);
    compare("file_perm (4) other execute",   fp1.getOtherExecuteFlag(), false);
    
    fp1.setGroupReadFlag(true);
    compare("file_perm (5) toString",        fp1.toString(), "-rwxr-----");
    compare("file_perm (5) toUInt16",        fp1.toUInt16(), 0x0740);
    compare("file_perm (5) owner read",      fp1.getOwnerReadFlag(),    true);
    compare("file_perm (5) owner write",     fp1.getOwnerWriteFlag(),   true);
    compare("file_perm (5) owner execute",   fp1.getOwnerExecuteFlag(), true);
    compare("file_perm (5) group read",      fp1.getGroupReadFlag(),    true);
    compare("file_perm (5) group write",     fp1.getGroupWriteFlag(),   false);
    compare("file_perm (5) group execute",   fp1.getGroupExecuteFlag(), false);
    compare("file_perm (5) other read",      fp1.getOtherReadFlag(),    false);
    compare("file_perm (5) other write",     fp1.getOtherWriteFlag(),   false);
    compare("file_perm (5) other execute",   fp1.getOtherExecuteFlag(), false);

    fp1.setGroupWriteFlag(true);
    compare("file_perm (6) toString",        fp1.toString(), "-rwxrw----");
    compare("file_perm (6) toUInt16",        fp1.toUInt16(), 0x0760);
    compare("file_perm (6) owner read",      fp1.getOwnerReadFlag(),    true);
    compare("file_perm (6) owner write",     fp1.getOwnerWriteFlag(),   true);
    compare("file_perm (6) owner execute",   fp1.getOwnerExecuteFlag(), true);
    compare("file_perm (6) group read",      fp1.getGroupReadFlag(),    true);
    compare("file_perm (6) group write",     fp1.getGroupWriteFlag(),   true);
    compare("file_perm (6) group execute",   fp1.getGroupExecuteFlag(), false);
    compare("file_perm (6) other read",      fp1.getOtherReadFlag(),    false);
    compare("file_perm (6) other write",     fp1.getOtherWriteFlag(),   false);
    compare("file_perm (6) other execute",   fp1.getOtherExecuteFlag(), false);

    fp1.setGroupExecuteFlag(true);
    compare("file_perm (7) toString",        fp1.toString(), "-rwxrwx---");
    compare("file_perm (7) toUInt16",        fp1.toUInt16(), 0x770);
    compare("file_perm (7) owner read",      fp1.getOwnerReadFlag(),    true);
    compare("file_perm (7) owner write",     fp1.getOwnerWriteFlag(),   true);
    compare("file_perm (7) owner execute",   fp1.getOwnerExecuteFlag(), true);
    compare("file_perm (7) group read",      fp1.getGroupReadFlag(),    true);
    compare("file_perm (7) group write",     fp1.getGroupWriteFlag(),   true);
    compare("file_perm (7) group execute",   fp1.getGroupExecuteFlag(), true);
    compare("file_perm (7) other read",      fp1.getOtherReadFlag(),    false);
    compare("file_perm (7) other write",     fp1.getOtherWriteFlag(),   false);
    compare("file_perm (7) other execute",   fp1.getOtherExecuteFlag(), false);

    fp1.setOtherReadFlag(true);
    compare("file_perm (8) toString",        fp1.toString(), "-rwxrwxr--");
    compare("file_perm (8) toUInt16",        fp1.toUInt16(), 0x774);
    compare("file_perm (8) owner read",      fp1.getOwnerReadFlag(),    true);
    compare("file_perm (8) owner write",     fp1.getOwnerWriteFlag(),   true);
    compare("file_perm (8) owner execute",   fp1.getOwnerExecuteFlag(), true);
    compare("file_perm (8) group read",      fp1.getGroupReadFlag(),    true);
    compare("file_perm (8) group write",     fp1.getGroupWriteFlag(),   true);
    compare("file_perm (8) group execute",   fp1.getGroupExecuteFlag(), true);
    compare("file_perm (8) other read",      fp1.getOtherReadFlag(),    true);
    compare("file_perm (8) other write",     fp1.getOtherWriteFlag(),   false);
    compare("file_perm (8) other execute",   fp1.getOtherExecuteFlag(), false);

    fp1.setOtherWriteFlag(true);
    compare("file_perm (9) toString",        fp1.toString(), "-rwxrwxrw-");
    compare("file_perm (9) toUInt16",        fp1.toUInt16(), 0x0776);
    compare("file_perm (9) owner read",      fp1.getOwnerReadFlag(),    true);
    compare("file_perm (9) owner write",     fp1.getOwnerWriteFlag(),   true);
    compare("file_perm (9) owner execute",   fp1.getOwnerExecuteFlag(), true);
    compare("file_perm (9) group read",      fp1.getGroupReadFlag(),    true);
    compare("file_perm (9) group write",     fp1.getGroupWriteFlag(),   true);
    compare("file_perm (9) group execute",   fp1.getGroupExecuteFlag(), true);
    compare("file_perm (9) other read",      fp1.getOtherReadFlag(),    true);
    compare("file_perm (9) other write",     fp1.getOtherWriteFlag(),   true);
    compare("file_perm (9) other execute",   fp1.getOtherExecuteFlag(), false);

    fp1.setOtherExecuteFlag(true);
    compare("file_perm (10) toString",       fp1.toString(), "-rwxrwxrwx");
    compare("file_perm (10) toUInt16",       fp1.toUInt16(), 0x0777);
    compare("file_perm (10) owner read",     fp1.getOwnerReadFlag(),    true);
    compare("file_perm (10) owner write",    fp1.getOwnerWriteFlag(),   true);
    compare("file_perm (10) owner execute",  fp1.getOwnerExecuteFlag(), true);
    compare("file_perm (10) group read",     fp1.getGroupReadFlag(),    true);
    compare("file_perm (10) group write",    fp1.getGroupWriteFlag(),   true);
    compare("file_perm (10) group execute",  fp1.getGroupExecuteFlag(), true);
    compare("file_perm (10) other read",     fp1.getOtherReadFlag(),    true);
    compare("file_perm (10) other write",    fp1.getOtherWriteFlag(),   true);
    compare("file_perm (10) other execute",  fp1.getOtherExecuteFlag(), true);

    WsjcppFilePermissions fp2(
        true, true, true,
        true, true, true,
        true, true, true
    );
    compare("file_perm (11) toString",       fp2.toString(), "-rwxrwxrwx");
    compare("file_perm (11) toUInt16",       fp2.toUInt16(), 0x0777);
    compare("file_perm (11) owner read",     fp2.getOwnerReadFlag(),    true);
    compare("file_perm (11) owner write",    fp2.getOwnerWriteFlag(),   true);
    compare("file_perm (11) owner execute",  fp2.getOwnerExecuteFlag(), true);
    compare("file_perm (11) group read",     fp2.getGroupReadFlag(),    true);
    compare("file_perm (11) group write",    fp2.getGroupWriteFlag(),   true);
    compare("file_perm (11) group execute",  fp2.getGroupExecuteFlag(), true);
    compare("file_perm (11) other read",     fp2.getOtherReadFlag(),    true);
    compare("file_perm (11) other write",    fp2.getOtherWriteFlag(),   true);
    compare("file_perm (11) other execute",  fp2.getOtherExecuteFlag(), true);

    WsjcppFilePermissions fp3(0x764);
    compare("file_perm (12) toString",       fp3.toString(), "-rwxrw-r--");
    compare("file_perm (12) toUInt16",       fp3.toUInt16(), 0x0764);
    compare("file_perm (12) owner read",     fp3.getOwnerReadFlag(),    true);
    compare("file_perm (12) owner write",    fp3.getOwnerWriteFlag(),   true);
    compare("file_perm (12) owner execute",  fp3.getOwnerExecuteFlag(), true);
    compare("file_perm (12) group read",     fp3.getGroupReadFlag(),    true);
    compare("file_perm (12) group write",    fp3.getGroupWriteFlag(),   true);
    compare("file_perm (12) group execute",  fp3.getGroupExecuteFlag(), false);
    compare("file_perm (12) other read",     fp3.getOtherReadFlag(),    true);
    compare("file_perm (12) other write",    fp3.getOtherWriteFlag(),   false);
    compare("file_perm (12) other execute",  fp3.getOtherExecuteFlag(), false);

    {
        std::string sError;
        WsjcppFilePermissions fp4_(0x0604);
        compare("file_perm (13b) toString", fp4_.toString(), "-rw----r--");
        compare("file_perm (13b) toUInt16", fp4_.toUInt16(), 0x0604);
        bool bRes1 = WsjcppCore::setFilePermissions("./data/file_permissions/file1", fp4_, sError);
        compare("file_perm (13b) setFilePermissions",  bRes1, true);


        WsjcppFilePermissions fp4(0x0);
        bool bRes2 = WsjcppCore::getFilePermissions("./data/file_permissions/file1", fp4, sError);
        compare("file_perm (13a) getFilePermissions",  bRes2, true);
        compare("file_perm (13a) toString", fp4.toString(), "-rw----r--");
        compare("file_perm (13a) toUInt16", fp4.toUInt16(), 0x604);
    }

    {
        WsjcppFilePermissions fp5(0x0);
        std::string sError;
        bool bRes2 = WsjcppCore::getFilePermissions("./data/file_permissions/nofilefile1", fp5, sError);
        compare("file_perm (14) getFilePermissions",  bRes2, false);
        compare("file_perm (14) toUInt16", fp5.toUInt16(), 0x0);
        compare("file_perm (14) error", sError, "File './data/file_permissions/nofilefile1' - not found");
    }
}

// ---------------------------------------------------------------------

bool UnitTestFilePermissions::doAfterTest() {
    // nothing
    return true;
}