@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by AP210VIEWER.HPJ. >"hlp\AP210Viewer.hm"
echo. >>"hlp\AP210Viewer.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\AP210Viewer.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\AP210Viewer.hm"
echo. >>"hlp\AP210Viewer.hm"
echo // Prompts (IDP_*) >>"hlp\AP210Viewer.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\AP210Viewer.hm"
echo. >>"hlp\AP210Viewer.hm"
echo // Resources (IDR_*) >>"hlp\AP210Viewer.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\AP210Viewer.hm"
echo. >>"hlp\AP210Viewer.hm"
echo // Dialogs (IDD_*) >>"hlp\AP210Viewer.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\AP210Viewer.hm"
echo. >>"hlp\AP210Viewer.hm"
echo // Frame Controls (IDW_*) >>"hlp\AP210Viewer.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\AP210Viewer.hm"
REM -- Make help for Project AP210VIEWER


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\AP210Viewer.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\AP210Viewer.hlp" goto :Error
if not exist "hlp\AP210Viewer.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\AP210Viewer.hlp" Debug
if exist Debug\nul copy "hlp\AP210Viewer.cnt" Debug
if exist Release\nul copy "hlp\AP210Viewer.hlp" Release
if exist Release\nul copy "hlp\AP210Viewer.cnt" Release
echo.
goto :done

:Error
echo hlp\AP210Viewer.hpj(1) : error: Problem encountered creating help file

:done
echo.
