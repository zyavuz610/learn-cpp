@echo off
echo C++ kodu derleniyor...
::g++ 1-template-functions.cpp -o program.exe
::g++ 1-template-functions2.cpp -o program.exe
::g++ 1-template-functions3.cpp -o program.exe
::g++ 2-template-class.cpp -o program.exe
::g++ 3-stl-vector.cpp -o program.exe
::g++ 4-stl-list.cpp -o program.exe
::g++ 5-stl-stack.cpp -o program.exe
::g++ 6-stl-queue.cpp -o program.exe
::g++ 7-stl-map.cpp -o program.exe
g++ 8-stl-set.cpp -o program.exe
if %errorlevel% neq 0 (
    echo Derleme hatasi...
    pause
    exit /b %errorlevel%
)
echo Derleme tamamlandi. Program calisiyor...
program.exe
del program.exe