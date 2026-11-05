@echo off
REM Build and run script for Windows
REM
REM This script compiles your C++ program using g++ and runs it.
REM Usage: build.bat

setlocal enabledelayedexpansion

REM Navigate to the script's directory (project root when downloaded)
cd /d "%~dp0"

echo === Queue ===
echo.

REM Check for g++ compiler
REM where g++ >nul 2>nul
REM if %ERRORLEVEL% NEQ 0 (
REM     echo [ERROR] g++ compiler not found
REM     echo.
REM     echo Install MinGW-w64:
REM     echo   1. Download from: https://www.mingw-w64.org/downloads/
REM     echo   2. Or use MSYS2: https://www.msys2.org/
REM     echo   3. Add g++ to your PATH
REM     echo.
REM     exit /b 1
REM )

echo [OK] g++ compiler found
echo.

REM Compile the program
echo Compiling main.cpp...
clang++ -std=c++17 -Wall -o queue.exe main.cpp
if %ERRORLEVEL% NEQ 0 (
    echo.
    echo [ERROR] Compilation failed
    exit /b 1
)

echo.
echo === Build Complete! ===
echo.
echo Running: queue.exe
echo ---
echo.

REM Run the program
queue.exe %*
