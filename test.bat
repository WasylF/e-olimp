@ echo off
:1
echo good
gener.exe
brut.exe
2.exe
fc /L output.txt output_brut.txt 
if %errorlevel% == 0 goto 1
echo NeSovpalo
pause
