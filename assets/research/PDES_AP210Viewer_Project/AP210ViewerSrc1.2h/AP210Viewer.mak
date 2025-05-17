# Microsoft Developer Studio Generated NMAKE File, Based on AP210Viewer.dsp
!IF "$(CFG)" == ""
CFG=AP210Viewer - Win32 Debug
!MESSAGE No configuration specified. Defaulting to AP210Viewer - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "AP210Viewer - Win32 Release" && "$(CFG)" != "AP210Viewer - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "AP210Viewer.mak" CFG="AP210Viewer - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AP210Viewer - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "AP210Viewer - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : ".\Release\AP210Viewer.hlp" "$(OUTDIR)\AP210Viewer.exe"


CLEAN :
	-@erase "$(INTDIR)\ap210_visualizer.obj"
	-@erase "$(INTDIR)\AP210DocManager.obj"
	-@erase "$(INTDIR)\AP210GraphicObject.obj"
	-@erase "$(INTDIR)\AP210Line.obj"
	-@erase "$(INTDIR)\AP210LP.obj"
	-@erase "$(INTDIR)\AP210MagicStrings.obj"
	-@erase "$(INTDIR)\AP210Object.obj"
	-@erase "$(INTDIR)\AP210ObjectList.obj"
	-@erase "$(INTDIR)\AP210Point.obj"
	-@erase "$(INTDIR)\AP210ProdView.obj"
	-@erase "$(INTDIR)\AP210SplitWnd.obj"
	-@erase "$(INTDIR)\AP210Viewer.obj"
	-@erase "$(INTDIR)\AP210Viewer.pch"
	-@erase "$(INTDIR)\AP210Viewer.res"
	-@erase "$(INTDIR)\AP210ViewerDoc.obj"
	-@erase "$(INTDIR)\AP210ViewerView.obj"
	-@erase "$(INTDIR)\AssemblyPropertiesSheet.obj"
	-@erase "$(INTDIR)\BoardComponent.obj"
	-@erase "$(INTDIR)\boardfile.obj"
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\ComponentDefinition.obj"
	-@erase "$(INTDIR)\ComponentDefinitionSheet.obj"
	-@erase "$(INTDIR)\ComponentPlacementRestriction.obj"
	-@erase "$(INTDIR)\ComponentPropertiesSheet.obj"
	-@erase "$(INTDIR)\ExtractGeometry.obj"
	-@erase "$(INTDIR)\GeneralAssemblyPage.obj"
	-@erase "$(INTDIR)\GeneralInterconnectModulePage.obj"
	-@erase "$(INTDIR)\GeneralPackagedComponentPage.obj"
	-@erase "$(INTDIR)\GeneralPackagedPartPage.obj"
	-@erase "$(INTDIR)\GeneralPackagePage.obj"
	-@erase "$(INTDIR)\helpers.obj"
	-@erase "$(INTDIR)\idf2arm.obj"
	-@erase "$(INTDIR)\IDFDoc.obj"
	-@erase "$(INTDIR)\IDFToSdai.obj"
	-@erase "$(INTDIR)\InterconnectModulePropertiesSheet.obj"
	-@erase "$(INTDIR)\InterconnectModuleUsageViewPage.obj"
	-@erase "$(INTDIR)\IOAP210.obj"
	-@erase "$(INTDIR)\LibraryFile.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MathUtility.obj"
	-@erase "$(INTDIR)\MatrixUtilities.obj"
	-@erase "$(INTDIR)\MountingRestrictionArea.obj"
	-@erase "$(INTDIR)\MultiFileMultiDocTemplate.obj"
	-@erase "$(INTDIR)\Package.obj"
	-@erase "$(INTDIR)\PackagedComponent.obj"
	-@erase "$(INTDIR)\PackagedPart.obj"
	-@erase "$(INTDIR)\PackagedPartPropertiesSheet.obj"
	-@erase "$(INTDIR)\PackagePropertiesSheet.obj"
	-@erase "$(INTDIR)\PhysicalUnit.obj"
	-@erase "$(INTDIR)\PopulateBaseCircle.obj"
	-@erase "$(INTDIR)\PropertiesDlg.obj"
	-@erase "$(INTDIR)\PropertiesPage.obj"
	-@erase "$(INTDIR)\PWBDataBase.obj"
	-@erase "$(INTDIR)\RoseDebugErrorReporter.obj"
	-@erase "$(INTDIR)\SchemaName.obj"
	-@erase "$(INTDIR)\SdaiStoredProceedures.obj"
	-@erase "$(INTDIR)\SdaiToIDF.obj"
	-@erase "$(INTDIR)\SdaiUtility.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\Tess.obj"
	-@erase "$(INTDIR)\trackball.obj"
	-@erase "$(INTDIR)\UnitUtility.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\AP210Viewer.exe"
	-@erase ".\Release\AP210Viewer.hlp"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /I "c:\steptools_7.0\include\expx" /I "c:\steptools_7.0\include" /I "c:\steptools_7.0\include\expx\classes" /I "C:\oglsdk\glut-3.7\include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "IDFHEIGHT" /D "DELETECL" /U "TRACKBALL" /Fp"$(INTDIR)\AP210Viewer.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AP210Viewer.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AP210Viewer.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=expx.lib sdai.lib rose.lib opengl32.lib glu32.lib glut32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\AP210Viewer.pdb" /machine:I386 /out:"$(OUTDIR)\AP210Viewer.exe" /libpath:"$(ROSE_LIB)" /libpath:"c:\oglsdk\glut-3.7\lib\glut" 
LINK32_OBJS= \
	"$(INTDIR)\AP210DocManager.obj" \
	"$(INTDIR)\AP210ProdView.obj" \
	"$(INTDIR)\AP210SplitWnd.obj" \
	"$(INTDIR)\AP210Viewer.obj" \
	"$(INTDIR)\AP210ViewerDoc.obj" \
	"$(INTDIR)\AP210ViewerView.obj" \
	"$(INTDIR)\AssemblyPropertiesSheet.obj" \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\ComponentDefinitionSheet.obj" \
	"$(INTDIR)\ComponentPlacementRestriction.obj" \
	"$(INTDIR)\ComponentPropertiesSheet.obj" \
	"$(INTDIR)\GeneralAssemblyPage.obj" \
	"$(INTDIR)\GeneralInterconnectModulePage.obj" \
	"$(INTDIR)\GeneralPackagedComponentPage.obj" \
	"$(INTDIR)\GeneralPackagedPartPage.obj" \
	"$(INTDIR)\GeneralPackagePage.obj" \
	"$(INTDIR)\IDFDoc.obj" \
	"$(INTDIR)\InterconnectModulePropertiesSheet.obj" \
	"$(INTDIR)\InterconnectModuleUsageViewPage.obj" \
	"$(INTDIR)\IOAP210.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MultiFileMultiDocTemplate.obj" \
	"$(INTDIR)\PackagedPartPropertiesSheet.obj" \
	"$(INTDIR)\PackagePropertiesSheet.obj" \
	"$(INTDIR)\PropertiesDlg.obj" \
	"$(INTDIR)\PropertiesPage.obj" \
	"$(INTDIR)\PWBDataBase.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ap210_visualizer.obj" \
	"$(INTDIR)\AP210GraphicObject.obj" \
	"$(INTDIR)\AP210Line.obj" \
	"$(INTDIR)\AP210LP.obj" \
	"$(INTDIR)\AP210MagicStrings.obj" \
	"$(INTDIR)\AP210Object.obj" \
	"$(INTDIR)\AP210ObjectList.obj" \
	"$(INTDIR)\AP210Point.obj" \
	"$(INTDIR)\BoardComponent.obj" \
	"$(INTDIR)\ComponentDefinition.obj" \
	"$(INTDIR)\ExtractGeometry.obj" \
	"$(INTDIR)\MathUtility.obj" \
	"$(INTDIR)\MountingRestrictionArea.obj" \
	"$(INTDIR)\Package.obj" \
	"$(INTDIR)\PackagedComponent.obj" \
	"$(INTDIR)\PackagedPart.obj" \
	"$(INTDIR)\PhysicalUnit.obj" \
	"$(INTDIR)\RoseDebugErrorReporter.obj" \
	"$(INTDIR)\SdaiStoredProceedures.obj" \
	"$(INTDIR)\SdaiUtility.obj" \
	"$(INTDIR)\UnitUtility.obj" \
	"$(INTDIR)\MatrixUtilities.obj" \
	"$(INTDIR)\Tess.obj" \
	"$(INTDIR)\trackball.obj" \
	"$(INTDIR)\IDFToSdai.obj" \
	"$(INTDIR)\helpers.obj" \
	"$(INTDIR)\idf2arm.obj" \
	"$(INTDIR)\PopulateBaseCircle.obj" \
	"$(INTDIR)\boardfile.obj" \
	"$(INTDIR)\LibraryFile.obj" \
	"$(INTDIR)\SdaiToIDF.obj" \
	"$(INTDIR)\SchemaName.obj" \
	"$(INTDIR)\AP210Viewer.res"

"$(OUTDIR)\AP210Viewer.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : ".\Debug\AP210Viewer.hlp" "$(OUTDIR)\AP210Viewer.exe" "$(OUTDIR)\AP210Viewer.bsc"


CLEAN :
	-@erase "$(INTDIR)\ap210_visualizer.obj"
	-@erase "$(INTDIR)\ap210_visualizer.sbr"
	-@erase "$(INTDIR)\AP210DocManager.obj"
	-@erase "$(INTDIR)\AP210DocManager.sbr"
	-@erase "$(INTDIR)\AP210GraphicObject.obj"
	-@erase "$(INTDIR)\AP210GraphicObject.sbr"
	-@erase "$(INTDIR)\AP210Line.obj"
	-@erase "$(INTDIR)\AP210Line.sbr"
	-@erase "$(INTDIR)\AP210LP.obj"
	-@erase "$(INTDIR)\AP210LP.sbr"
	-@erase "$(INTDIR)\AP210MagicStrings.obj"
	-@erase "$(INTDIR)\AP210MagicStrings.sbr"
	-@erase "$(INTDIR)\AP210Object.obj"
	-@erase "$(INTDIR)\AP210Object.sbr"
	-@erase "$(INTDIR)\AP210ObjectList.obj"
	-@erase "$(INTDIR)\AP210ObjectList.sbr"
	-@erase "$(INTDIR)\AP210Point.obj"
	-@erase "$(INTDIR)\AP210Point.sbr"
	-@erase "$(INTDIR)\AP210ProdView.obj"
	-@erase "$(INTDIR)\AP210ProdView.sbr"
	-@erase "$(INTDIR)\AP210SplitWnd.obj"
	-@erase "$(INTDIR)\AP210SplitWnd.sbr"
	-@erase "$(INTDIR)\AP210Viewer.obj"
	-@erase "$(INTDIR)\AP210Viewer.pch"
	-@erase "$(INTDIR)\AP210Viewer.res"
	-@erase "$(INTDIR)\AP210Viewer.sbr"
	-@erase "$(INTDIR)\AP210ViewerDoc.obj"
	-@erase "$(INTDIR)\AP210ViewerDoc.sbr"
	-@erase "$(INTDIR)\AP210ViewerView.obj"
	-@erase "$(INTDIR)\AP210ViewerView.sbr"
	-@erase "$(INTDIR)\AssemblyPropertiesSheet.obj"
	-@erase "$(INTDIR)\AssemblyPropertiesSheet.sbr"
	-@erase "$(INTDIR)\BoardComponent.obj"
	-@erase "$(INTDIR)\BoardComponent.sbr"
	-@erase "$(INTDIR)\boardfile.obj"
	-@erase "$(INTDIR)\boardfile.sbr"
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\ChildFrm.sbr"
	-@erase "$(INTDIR)\ComponentDefinition.obj"
	-@erase "$(INTDIR)\ComponentDefinition.sbr"
	-@erase "$(INTDIR)\ComponentDefinitionSheet.obj"
	-@erase "$(INTDIR)\ComponentDefinitionSheet.sbr"
	-@erase "$(INTDIR)\ComponentPlacementRestriction.obj"
	-@erase "$(INTDIR)\ComponentPlacementRestriction.sbr"
	-@erase "$(INTDIR)\ComponentPropertiesSheet.obj"
	-@erase "$(INTDIR)\ComponentPropertiesSheet.sbr"
	-@erase "$(INTDIR)\ExtractGeometry.obj"
	-@erase "$(INTDIR)\ExtractGeometry.sbr"
	-@erase "$(INTDIR)\GeneralAssemblyPage.obj"
	-@erase "$(INTDIR)\GeneralAssemblyPage.sbr"
	-@erase "$(INTDIR)\GeneralInterconnectModulePage.obj"
	-@erase "$(INTDIR)\GeneralInterconnectModulePage.sbr"
	-@erase "$(INTDIR)\GeneralPackagedComponentPage.obj"
	-@erase "$(INTDIR)\GeneralPackagedComponentPage.sbr"
	-@erase "$(INTDIR)\GeneralPackagedPartPage.obj"
	-@erase "$(INTDIR)\GeneralPackagedPartPage.sbr"
	-@erase "$(INTDIR)\GeneralPackagePage.obj"
	-@erase "$(INTDIR)\GeneralPackagePage.sbr"
	-@erase "$(INTDIR)\helpers.obj"
	-@erase "$(INTDIR)\helpers.sbr"
	-@erase "$(INTDIR)\idf2arm.obj"
	-@erase "$(INTDIR)\idf2arm.sbr"
	-@erase "$(INTDIR)\IDFDoc.obj"
	-@erase "$(INTDIR)\IDFDoc.sbr"
	-@erase "$(INTDIR)\IDFToSdai.obj"
	-@erase "$(INTDIR)\IDFToSdai.sbr"
	-@erase "$(INTDIR)\InterconnectModulePropertiesSheet.obj"
	-@erase "$(INTDIR)\InterconnectModulePropertiesSheet.sbr"
	-@erase "$(INTDIR)\InterconnectModuleUsageViewPage.obj"
	-@erase "$(INTDIR)\InterconnectModuleUsageViewPage.sbr"
	-@erase "$(INTDIR)\IOAP210.obj"
	-@erase "$(INTDIR)\IOAP210.sbr"
	-@erase "$(INTDIR)\LibraryFile.obj"
	-@erase "$(INTDIR)\LibraryFile.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\MathUtility.obj"
	-@erase "$(INTDIR)\MathUtility.sbr"
	-@erase "$(INTDIR)\MatrixUtilities.obj"
	-@erase "$(INTDIR)\MatrixUtilities.sbr"
	-@erase "$(INTDIR)\MountingRestrictionArea.obj"
	-@erase "$(INTDIR)\MountingRestrictionArea.sbr"
	-@erase "$(INTDIR)\MultiFileMultiDocTemplate.obj"
	-@erase "$(INTDIR)\MultiFileMultiDocTemplate.sbr"
	-@erase "$(INTDIR)\Package.obj"
	-@erase "$(INTDIR)\Package.sbr"
	-@erase "$(INTDIR)\PackagedComponent.obj"
	-@erase "$(INTDIR)\PackagedComponent.sbr"
	-@erase "$(INTDIR)\PackagedPart.obj"
	-@erase "$(INTDIR)\PackagedPart.sbr"
	-@erase "$(INTDIR)\PackagedPartPropertiesSheet.obj"
	-@erase "$(INTDIR)\PackagedPartPropertiesSheet.sbr"
	-@erase "$(INTDIR)\PackagePropertiesSheet.obj"
	-@erase "$(INTDIR)\PackagePropertiesSheet.sbr"
	-@erase "$(INTDIR)\PhysicalUnit.obj"
	-@erase "$(INTDIR)\PhysicalUnit.sbr"
	-@erase "$(INTDIR)\PopulateBaseCircle.obj"
	-@erase "$(INTDIR)\PopulateBaseCircle.sbr"
	-@erase "$(INTDIR)\PropertiesDlg.obj"
	-@erase "$(INTDIR)\PropertiesDlg.sbr"
	-@erase "$(INTDIR)\PropertiesPage.obj"
	-@erase "$(INTDIR)\PropertiesPage.sbr"
	-@erase "$(INTDIR)\PWBDataBase.obj"
	-@erase "$(INTDIR)\PWBDataBase.sbr"
	-@erase "$(INTDIR)\RoseDebugErrorReporter.obj"
	-@erase "$(INTDIR)\RoseDebugErrorReporter.sbr"
	-@erase "$(INTDIR)\SchemaName.obj"
	-@erase "$(INTDIR)\SchemaName.sbr"
	-@erase "$(INTDIR)\SdaiStoredProceedures.obj"
	-@erase "$(INTDIR)\SdaiStoredProceedures.sbr"
	-@erase "$(INTDIR)\SdaiToIDF.obj"
	-@erase "$(INTDIR)\SdaiToIDF.sbr"
	-@erase "$(INTDIR)\SdaiUtility.obj"
	-@erase "$(INTDIR)\SdaiUtility.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\Tess.obj"
	-@erase "$(INTDIR)\Tess.sbr"
	-@erase "$(INTDIR)\trackball.obj"
	-@erase "$(INTDIR)\trackball.sbr"
	-@erase "$(INTDIR)\UnitUtility.obj"
	-@erase "$(INTDIR)\UnitUtility.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\AP210Viewer.bsc"
	-@erase "$(OUTDIR)\AP210Viewer.exe"
	-@erase ".\Debug\AP210Viewer.hlp"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /Gm /GX /ZI /Od /I "c:\steptools_7.0\include\expx" /I "c:\steptools_7.0\include" /I "c:\steptools_7.0\include\expx\classes" /I "C:\oglsdk\glut-3.7\include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /U "TRACKBALL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\AP210Viewer.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AP210Viewer.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/o"$(OUTDIR)\AP210Viewer.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\AP210DocManager.sbr" \
	"$(INTDIR)\AP210ProdView.sbr" \
	"$(INTDIR)\AP210SplitWnd.sbr" \
	"$(INTDIR)\AP210Viewer.sbr" \
	"$(INTDIR)\AP210ViewerDoc.sbr" \
	"$(INTDIR)\AP210ViewerView.sbr" \
	"$(INTDIR)\AssemblyPropertiesSheet.sbr" \
	"$(INTDIR)\ChildFrm.sbr" \
	"$(INTDIR)\ComponentDefinitionSheet.sbr" \
	"$(INTDIR)\ComponentPlacementRestriction.sbr" \
	"$(INTDIR)\ComponentPropertiesSheet.sbr" \
	"$(INTDIR)\GeneralAssemblyPage.sbr" \
	"$(INTDIR)\GeneralInterconnectModulePage.sbr" \
	"$(INTDIR)\GeneralPackagedComponentPage.sbr" \
	"$(INTDIR)\GeneralPackagedPartPage.sbr" \
	"$(INTDIR)\GeneralPackagePage.sbr" \
	"$(INTDIR)\IDFDoc.sbr" \
	"$(INTDIR)\InterconnectModulePropertiesSheet.sbr" \
	"$(INTDIR)\InterconnectModuleUsageViewPage.sbr" \
	"$(INTDIR)\IOAP210.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\MultiFileMultiDocTemplate.sbr" \
	"$(INTDIR)\PackagedPartPropertiesSheet.sbr" \
	"$(INTDIR)\PackagePropertiesSheet.sbr" \
	"$(INTDIR)\PropertiesDlg.sbr" \
	"$(INTDIR)\PropertiesPage.sbr" \
	"$(INTDIR)\PWBDataBase.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\ap210_visualizer.sbr" \
	"$(INTDIR)\AP210GraphicObject.sbr" \
	"$(INTDIR)\AP210Line.sbr" \
	"$(INTDIR)\AP210LP.sbr" \
	"$(INTDIR)\AP210MagicStrings.sbr" \
	"$(INTDIR)\AP210Object.sbr" \
	"$(INTDIR)\AP210ObjectList.sbr" \
	"$(INTDIR)\AP210Point.sbr" \
	"$(INTDIR)\BoardComponent.sbr" \
	"$(INTDIR)\ComponentDefinition.sbr" \
	"$(INTDIR)\ExtractGeometry.sbr" \
	"$(INTDIR)\MathUtility.sbr" \
	"$(INTDIR)\MountingRestrictionArea.sbr" \
	"$(INTDIR)\Package.sbr" \
	"$(INTDIR)\PackagedComponent.sbr" \
	"$(INTDIR)\PackagedPart.sbr" \
	"$(INTDIR)\PhysicalUnit.sbr" \
	"$(INTDIR)\RoseDebugErrorReporter.sbr" \
	"$(INTDIR)\SdaiStoredProceedures.sbr" \
	"$(INTDIR)\SdaiUtility.sbr" \
	"$(INTDIR)\UnitUtility.sbr" \
	"$(INTDIR)\MatrixUtilities.sbr" \
	"$(INTDIR)\Tess.sbr" \
	"$(INTDIR)\trackball.sbr" \
	"$(INTDIR)\IDFToSdai.sbr" \
	"$(INTDIR)\helpers.sbr" \
	"$(INTDIR)\idf2arm.sbr" \
	"$(INTDIR)\PopulateBaseCircle.sbr" \
	"$(INTDIR)\boardfile.sbr" \
	"$(INTDIR)\LibraryFile.sbr" \
	"$(INTDIR)\SdaiToIDF.sbr" \
	"$(INTDIR)\SchemaName.sbr"

"$(OUTDIR)\AP210Viewer.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=expx.lib sdai.lib rose.lib opengl32.lib glu32.lib glut32.lib /nologo /subsystem:windows /profile /debug /machine:I386 /nodefaultlib:"MSVCRT" /out:"$(OUTDIR)\AP210Viewer.exe" /libpath:"$(ROSE_LIB)" /libpath:"c:\oglsdk\glut-3.7\lib\glut" 
LINK32_OBJS= \
	"$(INTDIR)\AP210DocManager.obj" \
	"$(INTDIR)\AP210ProdView.obj" \
	"$(INTDIR)\AP210SplitWnd.obj" \
	"$(INTDIR)\AP210Viewer.obj" \
	"$(INTDIR)\AP210ViewerDoc.obj" \
	"$(INTDIR)\AP210ViewerView.obj" \
	"$(INTDIR)\AssemblyPropertiesSheet.obj" \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\ComponentDefinitionSheet.obj" \
	"$(INTDIR)\ComponentPlacementRestriction.obj" \
	"$(INTDIR)\ComponentPropertiesSheet.obj" \
	"$(INTDIR)\GeneralAssemblyPage.obj" \
	"$(INTDIR)\GeneralInterconnectModulePage.obj" \
	"$(INTDIR)\GeneralPackagedComponentPage.obj" \
	"$(INTDIR)\GeneralPackagedPartPage.obj" \
	"$(INTDIR)\GeneralPackagePage.obj" \
	"$(INTDIR)\IDFDoc.obj" \
	"$(INTDIR)\InterconnectModulePropertiesSheet.obj" \
	"$(INTDIR)\InterconnectModuleUsageViewPage.obj" \
	"$(INTDIR)\IOAP210.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MultiFileMultiDocTemplate.obj" \
	"$(INTDIR)\PackagedPartPropertiesSheet.obj" \
	"$(INTDIR)\PackagePropertiesSheet.obj" \
	"$(INTDIR)\PropertiesDlg.obj" \
	"$(INTDIR)\PropertiesPage.obj" \
	"$(INTDIR)\PWBDataBase.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ap210_visualizer.obj" \
	"$(INTDIR)\AP210GraphicObject.obj" \
	"$(INTDIR)\AP210Line.obj" \
	"$(INTDIR)\AP210LP.obj" \
	"$(INTDIR)\AP210MagicStrings.obj" \
	"$(INTDIR)\AP210Object.obj" \
	"$(INTDIR)\AP210ObjectList.obj" \
	"$(INTDIR)\AP210Point.obj" \
	"$(INTDIR)\BoardComponent.obj" \
	"$(INTDIR)\ComponentDefinition.obj" \
	"$(INTDIR)\ExtractGeometry.obj" \
	"$(INTDIR)\MathUtility.obj" \
	"$(INTDIR)\MountingRestrictionArea.obj" \
	"$(INTDIR)\Package.obj" \
	"$(INTDIR)\PackagedComponent.obj" \
	"$(INTDIR)\PackagedPart.obj" \
	"$(INTDIR)\PhysicalUnit.obj" \
	"$(INTDIR)\RoseDebugErrorReporter.obj" \
	"$(INTDIR)\SdaiStoredProceedures.obj" \
	"$(INTDIR)\SdaiUtility.obj" \
	"$(INTDIR)\UnitUtility.obj" \
	"$(INTDIR)\MatrixUtilities.obj" \
	"$(INTDIR)\Tess.obj" \
	"$(INTDIR)\trackball.obj" \
	"$(INTDIR)\IDFToSdai.obj" \
	"$(INTDIR)\helpers.obj" \
	"$(INTDIR)\idf2arm.obj" \
	"$(INTDIR)\PopulateBaseCircle.obj" \
	"$(INTDIR)\boardfile.obj" \
	"$(INTDIR)\LibraryFile.obj" \
	"$(INTDIR)\SdaiToIDF.obj" \
	"$(INTDIR)\SchemaName.obj" \
	"$(INTDIR)\AP210Viewer.res"

"$(OUTDIR)\AP210Viewer.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("AP210Viewer.dep")
!INCLUDE "AP210Viewer.dep"
!ELSE 
!MESSAGE Warning: cannot find "AP210Viewer.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "AP210Viewer - Win32 Release" || "$(CFG)" == "AP210Viewer - Win32 Debug"
SOURCE=.\AP210DocManager.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /I "c:\steptools_7.0\include\expx" /I "c:\steptools_7.0\include" /I "c:\steptools_7.0\include\expx\classes" /I "C:\oglsdk\glut-3.7\include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "IDFHEIGHT" /D "DELETECL" /U "TRACKBALL" /Fp"$(INTDIR)\AP210Viewer.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\AP210DocManager.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"

CPP_SWITCHES=/nologo /MD /W3 /Gm /GX /ZI /Od /I "c:\steptools_7.0\include\expx" /I "c:\steptools_7.0\include" /I "c:\steptools_7.0\include\expx\classes" /I "C:\oglsdk\glut-3.7\include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /U "TRACKBALL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\AP210Viewer.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\AP210DocManager.obj"	"$(INTDIR)\AP210DocManager.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\AP210ProdView.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\AP210ProdView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\AP210ProdView.obj"	"$(INTDIR)\AP210ProdView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\AP210SplitWnd.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\AP210SplitWnd.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\AP210SplitWnd.obj"	"$(INTDIR)\AP210SplitWnd.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\AP210Viewer.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\AP210Viewer.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\AP210Viewer.obj"	"$(INTDIR)\AP210Viewer.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\hlp\AP210Viewer.hpj

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"

OutDir=.\Release
ProjDir=.
TargetName=AP210Viewer
InputPath=.\hlp\AP210Viewer.hpj
USERDEP__AP210="$(ProjDir)\hlp\AfxCore.rtf"	"$(ProjDir)\hlp\AfxPrint.rtf"	

"$(INTDIR)\AP210Viewer.hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)" $(USERDEP__AP210)
	<<tempfile.bat 
	@echo off 
	call "$(ProjDir)\makehelp.bat"
<< 
	

!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"

OutDir=.\Debug
ProjDir=.
TargetName=AP210Viewer
InputPath=.\hlp\AP210Viewer.hpj
USERDEP__AP210="$(ProjDir)\hlp\AfxCore.rtf"	"$(ProjDir)\hlp\AfxPrint.rtf"	

"$(INTDIR)\AP210Viewer.hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)" $(USERDEP__AP210)
	<<tempfile.bat 
	@echo off 
	call "$(ProjDir)\makehelp.bat"
<< 
	

!ENDIF 

SOURCE=.\AP210Viewer.rc

"$(INTDIR)\AP210Viewer.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\AP210ViewerDoc.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\AP210ViewerDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\AP210ViewerDoc.obj"	"$(INTDIR)\AP210ViewerDoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\AP210ViewerView.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\AP210ViewerView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\AP210ViewerView.obj"	"$(INTDIR)\AP210ViewerView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\AssemblyPropertiesSheet.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\AssemblyPropertiesSheet.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\AssemblyPropertiesSheet.obj"	"$(INTDIR)\AssemblyPropertiesSheet.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\ChildFrm.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\ChildFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\ChildFrm.obj"	"$(INTDIR)\ChildFrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\ComponentDefinitionSheet.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\ComponentDefinitionSheet.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\ComponentDefinitionSheet.obj"	"$(INTDIR)\ComponentDefinitionSheet.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\ComponentPlacementRestriction.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\ComponentPlacementRestriction.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\ComponentPlacementRestriction.obj"	"$(INTDIR)\ComponentPlacementRestriction.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\ComponentPropertiesSheet.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\ComponentPropertiesSheet.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\ComponentPropertiesSheet.obj"	"$(INTDIR)\ComponentPropertiesSheet.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\GeneralAssemblyPage.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\GeneralAssemblyPage.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\GeneralAssemblyPage.obj"	"$(INTDIR)\GeneralAssemblyPage.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\GeneralInterconnectModulePage.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\GeneralInterconnectModulePage.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\GeneralInterconnectModulePage.obj"	"$(INTDIR)\GeneralInterconnectModulePage.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\GeneralPackagedComponentPage.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\GeneralPackagedComponentPage.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\GeneralPackagedComponentPage.obj"	"$(INTDIR)\GeneralPackagedComponentPage.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\GeneralPackagedPartPage.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\GeneralPackagedPartPage.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\GeneralPackagedPartPage.obj"	"$(INTDIR)\GeneralPackagedPartPage.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\GeneralPackagePage.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\GeneralPackagePage.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\GeneralPackagePage.obj"	"$(INTDIR)\GeneralPackagePage.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\IDFDoc.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\IDFDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\IDFDoc.obj"	"$(INTDIR)\IDFDoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\InterconnectModulePropertiesSheet.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\InterconnectModulePropertiesSheet.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\InterconnectModulePropertiesSheet.obj"	"$(INTDIR)\InterconnectModulePropertiesSheet.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\InterconnectModuleUsageViewPage.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\InterconnectModuleUsageViewPage.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\InterconnectModuleUsageViewPage.obj"	"$(INTDIR)\InterconnectModuleUsageViewPage.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\IOAP210.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\IOAP210.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\IOAP210.obj"	"$(INTDIR)\IOAP210.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\MultiFileMultiDocTemplate.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\MultiFileMultiDocTemplate.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\MultiFileMultiDocTemplate.obj"	"$(INTDIR)\MultiFileMultiDocTemplate.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\PackagedPartPropertiesSheet.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\PackagedPartPropertiesSheet.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\PackagedPartPropertiesSheet.obj"	"$(INTDIR)\PackagedPartPropertiesSheet.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\PackagePropertiesSheet.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\PackagePropertiesSheet.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\PackagePropertiesSheet.obj"	"$(INTDIR)\PackagePropertiesSheet.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\PropertiesDlg.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\PropertiesDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\PropertiesDlg.obj"	"$(INTDIR)\PropertiesDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\PropertiesPage.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\PropertiesPage.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\PropertiesPage.obj"	"$(INTDIR)\PropertiesPage.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\PWBDataBase.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\PWBDataBase.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\PWBDataBase.obj"	"$(INTDIR)\PWBDataBase.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /I "c:\steptools_7.0\include\expx" /I "c:\steptools_7.0\include" /I "c:\steptools_7.0\include\expx\classes" /I "C:\oglsdk\glut-3.7\include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "IDFHEIGHT" /D "DELETECL" /U "TRACKBALL" /Fp"$(INTDIR)\AP210Viewer.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\AP210Viewer.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"

CPP_SWITCHES=/nologo /MD /W3 /Gm /GX /ZI /Od /I "c:\steptools_7.0\include\expx" /I "c:\steptools_7.0\include" /I "c:\steptools_7.0\include\expx\classes" /I "C:\oglsdk\glut-3.7\include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /U "TRACKBALL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\AP210Viewer.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\AP210Viewer.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Sdai\ap210_visualizer.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\ap210_visualizer.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\ap210_visualizer.obj"	"$(INTDIR)\ap210_visualizer.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Sdai\AP210GraphicObject.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\AP210GraphicObject.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\AP210GraphicObject.obj"	"$(INTDIR)\AP210GraphicObject.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Sdai\AP210Line.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\AP210Line.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\AP210Line.obj"	"$(INTDIR)\AP210Line.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Sdai\AP210LP.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\AP210LP.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\AP210LP.obj"	"$(INTDIR)\AP210LP.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\SDAI\AP210MagicStrings.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\AP210MagicStrings.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\AP210MagicStrings.obj"	"$(INTDIR)\AP210MagicStrings.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Sdai\AP210Object.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\AP210Object.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\AP210Object.obj"	"$(INTDIR)\AP210Object.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Sdai\AP210ObjectList.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\AP210ObjectList.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\AP210ObjectList.obj"	"$(INTDIR)\AP210ObjectList.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Sdai\AP210Point.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\AP210Point.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\AP210Point.obj"	"$(INTDIR)\AP210Point.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Sdai\BoardComponent.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\BoardComponent.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\BoardComponent.obj"	"$(INTDIR)\BoardComponent.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Sdai\ComponentDefinition.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\ComponentDefinition.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\ComponentDefinition.obj"	"$(INTDIR)\ComponentDefinition.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Sdai\ExtractGeometry.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\ExtractGeometry.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\ExtractGeometry.obj"	"$(INTDIR)\ExtractGeometry.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Sdai\MathUtility.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\MathUtility.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\MathUtility.obj"	"$(INTDIR)\MathUtility.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Sdai\MountingRestrictionArea.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\MountingRestrictionArea.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\MountingRestrictionArea.obj"	"$(INTDIR)\MountingRestrictionArea.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Sdai\Package.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\Package.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\Package.obj"	"$(INTDIR)\Package.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Sdai\PackagedComponent.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\PackagedComponent.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\PackagedComponent.obj"	"$(INTDIR)\PackagedComponent.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Sdai\PackagedPart.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\PackagedPart.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\PackagedPart.obj"	"$(INTDIR)\PackagedPart.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Sdai\PhysicalUnit.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\PhysicalUnit.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\PhysicalUnit.obj"	"$(INTDIR)\PhysicalUnit.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Sdai\RoseDebugErrorReporter.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\RoseDebugErrorReporter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\RoseDebugErrorReporter.obj"	"$(INTDIR)\RoseDebugErrorReporter.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Sdai\SdaiStoredProceedures.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\SdaiStoredProceedures.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\SdaiStoredProceedures.obj"	"$(INTDIR)\SdaiStoredProceedures.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Sdai\SdaiUtility.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\SdaiUtility.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\SdaiUtility.obj"	"$(INTDIR)\SdaiUtility.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Sdai\UnitUtility.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\UnitUtility.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\UnitUtility.obj"	"$(INTDIR)\UnitUtility.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\OpenGL\MatrixUtilities.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\MatrixUtilities.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\MatrixUtilities.obj"	"$(INTDIR)\MatrixUtilities.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\OpenGL\Tess.c

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"

CPP_SWITCHES=/nologo /GB /MD /W3 /GX /O2 /I "c:\steptools_7.0\include\expx" /I "c:\steptools_7.0\include" /I "c:\steptools_7.0\include\expx\classes" /I "C:\oglsdk\glut-3.7\include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "IDFHEIGHT" /D "DELETECL" /U "TRACKBALL" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Tess.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"

CPP_SWITCHES=/nologo /GB /MD /W3 /Gm /GX /ZI /Od /I "c:\steptools_7.0\include\expx" /I "c:\steptools_7.0\include" /I "c:\steptools_7.0\include\expx\classes" /I "C:\oglsdk\glut-3.7\include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /U "TRACKBALL" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Tess.obj"	"$(INTDIR)\Tess.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\OpenGL\trackball.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\trackball.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\trackball.obj"	"$(INTDIR)\trackball.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\IDFToSdai\IDFToSdai.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\IDFToSdai.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\IDFToSdai.obj"	"$(INTDIR)\IDFToSdai.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Idf2ap210\helpers.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\helpers.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\helpers.obj"	"$(INTDIR)\helpers.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Idf2ap210\idf2arm.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\idf2arm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\idf2arm.obj"	"$(INTDIR)\idf2arm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Idf2ap210\PopulateBaseCircle.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\PopulateBaseCircle.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\PopulateBaseCircle.obj"	"$(INTDIR)\PopulateBaseCircle.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\SdaiToIDF\boardfile.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\boardfile.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\boardfile.obj"	"$(INTDIR)\boardfile.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\SdaiToIDF\LibraryFile.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\LibraryFile.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\LibraryFile.obj"	"$(INTDIR)\LibraryFile.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\SdaiToIDF\SdaiToIDF.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\SdaiToIDF.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\SdaiToIDF.obj"	"$(INTDIR)\SdaiToIDF.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\RoseExtensions\SchemaName.cpp

!IF  "$(CFG)" == "AP210Viewer - Win32 Release"


"$(INTDIR)\SchemaName.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AP210Viewer - Win32 Debug"


"$(INTDIR)\SchemaName.obj"	"$(INTDIR)\SchemaName.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AP210Viewer.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 


!ENDIF 

