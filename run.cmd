@echo off
rem This script just calls the actual OpenLog executable
rem (So you don't have to 'cd build' first) 
cd build
openlog.exe %*
cd ..
