@echo off
echo C++ kodu derleniyor...
::g++ 1-template-functions.cpp -o program.exe
::g++ 1-template-functions2.cpp -o program.exe
::g++ 2-template-class.cpp -o program.exe
g++ 3-stl-vector.cpp -o program.exe
if %errorlevel% neq 0 (
    echo Derleme hatasi...
    pause
    exit /b %errorlevel%
)
echo Derleme tamamlandi. Program calisiyor...
program.exe