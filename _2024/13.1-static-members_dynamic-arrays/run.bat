@echo off
echo C++ kodu derleniyor...
::g++ 1-dynamic-1Darray.cpp -o program.exe
::g++ 1-dynamic-1DarrayInClass.cpp -o program.exe
::g++ 2-dynamic-2Darray.cpp -o program.exe
::g++ 2-dynamic-2DarrayInClass.cpp -o program.exe
::g++ 3-static-members.cpp -o program.exe
g++ 4-static-functions.cpp -o program.exe
if %errorlevel% neq 0 (
    echo Derleme hatasi...
    pause
    exit /b %errorlevel%
)
echo Derleme tamamlandi. Program calisiyor...
program.exe
del program.exe