@echo off
echo C++ kodu derleniyor...
g++ set-params_inheritance.cpp -o program.exe
if %errorlevel% neq 0 (
    echo Derleme hatasi...
    pause
    exit /b %errorlevel%
)
echo Derleme tamamlandi. Program calisiyor...
echo ------------------------------
program.exe
echo ------------------------------
::pause