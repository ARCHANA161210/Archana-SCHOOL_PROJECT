@echo off
set SCRIPTPATH=%~dp0
set SLPATH=%SCRIPTPATH%..\lib\classes.zip
set CLASSPATH=%SLPATH%;.
java simpl %1 %2 %3 %4 %5 %6 %7 %8 %9
