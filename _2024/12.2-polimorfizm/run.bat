@echo off
echo C++ kodu derleniyor...
g++ 1.cpp -o program.exe
if %errorlevel% neq 0 (
    echo Derleme hatasi...
    pause
    exit /b %errorlevel%
)
echo Derleme tamamlandi. Program calisiyor...
program.exe
pause