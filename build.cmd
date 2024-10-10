@echo off
echo Cleaning up previous build artifacts...
del /q build > NUL
rmdir build > NUL
mkdir build > NUL
cd src
echo Compiling OpenLog...
cl /nologo /EHsc openlog.c color.c help.c util.c
echo Moving files...
move openlog.exe ..\build\ > NUL
move openlog.obj ..\build\ > NUL
move color.obj ..\build\ > NUL
move help.obj ..\build\ > NUL
move util.obj ..\build\ > NUL
cd ..
copy LICENSE build\ > NUL
copy README.md build\ > NUL
echo Done.
