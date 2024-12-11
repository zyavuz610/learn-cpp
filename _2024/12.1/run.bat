@echo off
echo C++ kodu derleniyor...
g++ shape-rect_inheritence.cpp -o program.exe
if %errorlevel% neq 0 (
    echo Derleme hatasi...
    pause
    exit /b %errorlevel%
)
echo Derleme tamamlandi. Program calisiyor...
program.exe
pause