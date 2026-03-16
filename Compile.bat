@echo off
echo Compilation en cours...

:: Crée le dossier bin s'il n'existe pas
if not exist "bin" mkdir bin

:: Lance la compilation
g++ -o bin/DungeonBattle.exe src/*.cpp -I include

:: Vérifie si ça a marché
if %errorlevel% equ 0 (
    echo.
    echo SUCCES ! Lancement du jeu...
    echo ------------------------------------------
    :: Lance le jeu directement après la compilation
    bin\DungeonBattle.exe
) else (
    echo.
    echo ECHEC de la compilation. Verifie tes erreurs au dessus.
)

echo.
pause