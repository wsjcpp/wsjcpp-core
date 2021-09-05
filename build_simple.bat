@echo off

endlocal
setlocal

echo Prepare configuration
cmake -H. -Btmp
if %ERRORLEVEL% GEQ 1 (
    echo "cmake configure"
    EXIT /B 1
)

cmake --build tmp
if %ERRORLEVEL% GEQ 1 (
    echo "cmake build"
    EXIT /B 1
)

endlocal