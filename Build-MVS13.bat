RMDIR .\Build /s /q

mkdir .\Build

cd .\Build
 
..\Windows-cmake\Cmake\bin\cmake.exe ..\Windows-cmake\Cmake\bin\cmake ..\Gate2158 -G "Visual Studio 12 2013"

PAUSE