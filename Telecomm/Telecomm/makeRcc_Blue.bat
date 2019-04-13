::set PATH=C:\Qt\Qt5.10.1\5.10.1\msvc2015\bin;%PATH%
rcc -binary openplanet.qrc -o resources_Blue.rcc
copy /y resources_Blue.rcc ..\Win32\Debug
copy /y resources_Blue.rcc ..\Win32\Release
pause