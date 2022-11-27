@echo off
set solution_dir=%~1
set config=%~2
xcopy /e /v /y "%solution_dir%\textures" "%solution_dir%\bin\%config%\textures\"
