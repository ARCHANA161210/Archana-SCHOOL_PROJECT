@echo off
        if "%1"=="" goto usage
        if not "%2"=="" goto usage
	set SCRIPTPATH=%~dp0
        set SLPATH=%SCRIPTPATH%..\lib\classes.zip
        set CLASSPATH=%SLPATH%;.
        java %1
        goto end
:usage
        echo Usage: run "progname"
:end
