@echo off
echo Building Vajra-Shield (C Implementation)...

if not exist bin mkdir bin

gcc -o bin\vajra_shield.exe src\main.c src\utils.c src\sensor_fusion.c src\activity_classifier.c src\forensic_vault.c src\bluetooth_sweeper.c -Wall -Wextra

if %ERRORLEVEL% == 0 (
    echo Build successful!
    echo Run the simulator with: bin\vajra_shield.exe
) else (
    echo Build failed! Please check if GCC is installed.
)
