@echo off
echo Cleaning up previous build artifacts...
del /q build > NUL
echo Compiling openlog.c...
cl /nologo /EHsc openlog.c color.c help.c
echo Moving files...
move openlog.exe build\ > NUL
move openlog.obj build\ > NUL
move color.obj build\ > NUL
move help.obj build\ > NUL
echo Done.
