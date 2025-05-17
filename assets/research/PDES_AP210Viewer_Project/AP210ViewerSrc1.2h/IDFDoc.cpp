// IDFDoc.cpp : implementation file
//

#include "stdafx.h"
#include <math.h>
// required for copy of OnSaveDocument delete if removed
#define DELETE_EXCEPTION(e) do { e->Delete(); } while (0)
#include "AP210Viewer.h"
#include "PropertiesDlg.h"
#include "IOAP210.h"
#include "Sdai/PackagedComponent.h"
#include "OpenGL/MatrixUtilities.h"

#include "IDFDoc.h"

// IDF Specific
#include "IDFToSdai/IDFToSdai.h"
#include "IDF2AP210/PopulateBaseCircle.h"

// ExpressX Stuff
#include "IDF2AP210/idf2arm.h"

//These should be in an include file!
int WriteIDF(SdaiModel myModel, char *dir, char *name);
int WriteIDFStep(SdaiModel myModel, char *dir, char *name);
int WriteAP210AimFile(RoseDesign *AP210AimModel, char *dir, char *name);
int WriteAP210ArmFile(RoseDesign *AP210ArmModel, char *dir, char *name);
int CreateAP210Aim(SdaiModel IDFModel, SdaiModel *AP210Model, char *dir, char *name);

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define IDF "IDF_V2"
/////////////////////////////////////////////////////////////////////////////
// CIDFDoc

IMPLEMENT_DYNCREATE(CIDFDoc, CDocument)

CIDFDoc::CIDFDoc() {
   }

BOOL CIDFDoc::OnNewDocument() {
   if (!CDocument::OnNewDocument())
      return FALSE;
   return TRUE;
   }

CIDFDoc::~CIDFDoc() {
   }


BEGIN_MESSAGE_MAP(CIDFDoc, CDocument)
	//{{AFX_MSG_MAP(CIDFDoc)
	ON_COMMAND(ID_FILE_PROPERTIES, OnFileProperties)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIDFDoc diagnostics

#ifdef _DEBUG
void CIDFDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CIDFDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


/////////////////////////////////////////////////////////////////////////////
// CIDFDoc commands

BOOL CIDFDoc::OnOpenDocument(LPCTSTR lpszPathName) {
   SdaiErrorCode sdaiError;
   char *suffix;
   char *designname = strdup(lpszPathName);

   TRACE("CIDFDoc::OnOpenDocument: %s\n", lpszPathName);

   if (IsModified())
      TRACE0("Warning: OnOpenDocument replaces an unsaved document.\n");
	
   // TODO: Add your specialized creation code here
   // extract the directory and name from lpszPathName
   if ((suffix = strrchr(designname, '.')) != NULL) {
      *suffix = '\0';
       suffix++;
 TRACE("CIDFDoc::OnOpenDocument designname: %s\n", designname);
 TRACE("CIDFDoc::OnOpenDocument suffix: %s\n", suffix);
      }
   else {
      ReportSaveLoadException(lpszPathName, NULL,
        TRUE, AFX_IDP_FAILED_TO_SAVE_DOC);
      free(designname);
      return false;
      }
   // clear the error code.
   sdaiErrorQuery();

   if (!strcmp(suffix, IDFBRDEXT)) {
      // Open the documents IDFModel
      // Make sure the rose files have been installed
      IDFModel = sdaiCreateModelBN (myRepository, designname, IDF);
      if((sdaiError = sdaiErrorQuery())) {
         TRACE("Cannot access model, Did you install the rose files?\n");
         TRACE("SDAI Error: %s.\n", _sdaiGetErrorName(sdaiError));
         ReportSaveLoadException(lpszPathName, NULL,
           FALSE, AFX_IDP_FAILED_TO_OPEN_DOC);
         free(designname);
         return FALSE;
         }
      // Parse IDF files
      if (IDFToSdai::parseIDF(designname, IDFModel)) {
         // error on parsing
         ReportSaveLoadException(lpszPathName, NULL,
            FALSE, AFX_IDP_FAILED_TO_OPEN_DOC);
         free(designname);
         return FALSE;
         }
      }
   else if (!strcmp(suffix, IDFSTEPEXT)) {
      // Load IDF Step file.
      IDFModel = sdaiAccessModelBN (myRepository, (char *)lpszPathName, sdaiRW);
      if((sdaiError = sdaiErrorQuery())) {
         TRACE("Cannot access model, Did you install the rose files?\n");
         TRACE("SDAI Error: %s.\n", _sdaiGetErrorName(sdaiError));
         ReportSaveLoadException(lpszPathName, NULL,
            FALSE, AFX_IDP_FAILED_TO_OPEN_DOC);
         free(designname);
         return FALSE;
         }
      }
   else {
      TRACE("Cannot access model, %s is not a recognized suffix.\r\n", suffix);
      ReportSaveLoadException(lpszPathName, NULL,
        FALSE, AFX_IDP_FAILED_TO_OPEN_DOC);
      free(designname);
      return FALSE;
      }
   // Done with designname
   free(designname);

   // start run on ExpressX
   // this should be a member function
   // and set the aim and arm target ROSE designs.
   {
   // run the IDF to AP210 conversion.
   char *name;
   char *suffix;
   char *dir = strdup(lpszPathName);

   TRACE("In CAP210ViewerDoc::OnSaveDocument(%s)\r\n", lpszPathName);
 
   // extract the directory and name from lpszPathName
   if ((name = strrchr(dir, '\\')) != NULL) {
      *name = '\0';
      name++;
      if ((suffix = strrchr(name, '.')) != NULL) {
         *suffix = '\0';
         suffix++;
         }
      }
//   if (CreateAP210Aim(IDFModel, &AP210Model, dir, name) == 0) {
   if (CreateAP210Aim(dir, name) == 0) {
      // success.
      }
   }
// end run on ExpressX

#if 1
    // Build Display Model
   BuildDisplayModel(lpszPathName);
#else
   if (buildPWB() == NULL) {
      ReportSaveLoadException(lpszPathName, NULL,
         FALSE, AFX_IDP_FAILED_TO_OPEN_DOC);
      return FALSE;
      }
   buildComponents();
#endif
   // Idf files read only.
   ReadOnly = TRUE;
   return TRUE;
   }

void CIDFDoc::OnCloseDocument() {
	// TODO: Add your specialized code here and/or call the base class
   TRACE0("CIDFDoc::OnCloseDocument()\r\n") ;

   // clear the error code.
   sdaiErrorQuery();
#if 0
   // remove the model from memory.
   sdaiRemoveModel(sdaiGetSchemaInstance(IDF, myRepository), IDFModel);
#else
   // This is a major KLUDGE sdaiDeleteModel will remove
   // the model so _sdaiFindModelBN won't find it but, it
   // deletes the model from the repository (ie. deletes the part21 file)
   // so we have to make the file read only while this sdaiDeleteModel is called!
   CFileStatus rStatus;
   // get the files status
   CFile::GetStatus(GetPathName(), rStatus);

   // save the attribute byte
   BYTE m_attribute = rStatus.m_attribute;

   if (!(m_attribute & 0x01)) {
      // make the file readonly. 
      rStatus.m_attribute = 0x01;//readOnly; doesn't work because readOnly is in an 
                                 //          MGC enumeration named Attribute in CFile.
      CFile::SetStatus(GetPathName(), rStatus);
      }
   // Remove the model, it won't be deleted because it is now readonly
   sdaiDeleteModel(IDFModel);

    if (!(m_attribute & 0x01)) {
       // restore attribute byte
       rStatus.m_attribute = m_attribute;
       CFile::SetStatus(GetPathName(), rStatus);
       }
#endif
   // This appears to be a bad error message.
   SdaiErrorCode sdaiError;
   if ((sdaiError = sdaiErrorQuery())) {
      TRACE("Cannot remove the IDF model\n");
      TRACE("SDAI Error: %s.\n", _sdaiGetErrorName(sdaiError));
      }
   // Rescan the repository inorder to get the removed model out.
   _sdaiRescanRepository(myRepository);

   // delete rose designs
   delete arm_targ;

   // delete aim_targ 
   CAP210ViewerDoc::OnCloseDocument();
   }

BOOL CIDFDoc::OnSaveDocument(LPCTSTR lpszPathName) {
   // TODO: Add your specialized code here and/or call the base class
   // extract the directory and name from lpszPathName
   char *name;
   char *suffix;
   char *dir = strdup(lpszPathName);

#ifdef VERBOSE
TRACE("CIDFDoc::OnSaveDocument()\r\n");
TRACE("  lpszPathName: %s\r\n", lpszPathName);
#endif

   if ((name = strrchr(dir, '\\')) != NULL) {
      *name = '\0';
	   name++;

      if ((suffix = strrchr(name, '.')) != NULL) {
         *suffix = '\0';
         suffix++;
#ifdef VERBOSE
TRACE("  suffix: %s\r\n", suffix);
#endif
         }
      }
   else {
      ReportSaveLoadException(lpszPathName, NULL,
        TRUE, AFX_IDP_FAILED_TO_SAVE_DOC);
      free(dir);
      return false;
      }
   if (!strcmp(suffix, IDFSTEPEXT)) {
      // write int IDF data out in Step format.
      // should only do this if file not modified
      WriteIDFStep(IDFModel, dir, name);
      }
   else if (!strcmp(suffix, AP210ARMEXT)) {
      // Write the IDF data out in AP210 ARM format.
      WriteAP210ArmFile(arm_targ, dir, name);
      }
   else if (!strcmp(suffix, AP210EXT)) {
      // Write the IDF data out in AP210 format.
      WriteAP210AimFile(aim_targ, dir, name);
      }
   else if (!strcmp(suffix, IDFBRDEXT)) {
      // Write the IDF data out in IDF format.
      // should only do this if file not modified
      WriteIDF(IDFModel, dir, name);
      }
   else {
      // Write the IDF data out in AP210 format.
      WriteAP210AimFile(aim_targ, dir, name);
      }
   // done with dir so free it.
   free(dir);
   dir = NULL;

   SetModifiedFlag(FALSE);     // back to unmodified

	return TRUE;        // success
   }


void CIDFDoc::OnFileProperties() {
	// TODO: Add your command handler code here
TRACE("In CIDFDoc::OnFileProperties()\r\n");	

   // get the rose design
   RoseDesign *idf = _sdaiGetRoseDesign(IDFModel);

   // create the dialog box
   CPropertiesDlg propDlg;

   // set the dialog boxes values
   setFileProperties(&propDlg, idf);

   // display the dialog box
   propDlg.DoModal();
   }
BOOL CIDFDoc::DoSave(LPCTSTR lpszPathName, BOOL bReplace)
	// Save the document data to a file
	// lpszPathName = path name where to save document file
	// if lpszPathName is NULL then the user will be prompted (SaveAs)
	// note: lpszPathName can be different than 'm_strPathName'
	// if 'bReplace' is TRUE will change file name if successful (SaveAs)
	// if 'bReplace' is FALSE will not change path name (SaveCopyAs)
{
	CString newName = lpszPathName;

	if (newName.IsEmpty())
	{
		CDocTemplate* pTemplate = GetDocTemplate();
		ASSERT(pTemplate != NULL);

		newName = m_strPathName;
		if (bReplace && newName.IsEmpty())
		{
			newName = m_strTitle;
#ifndef _MAC
			// check for dubious filename
			int iBad = newName.FindOneOf(_T(" #%;/\\"));
#else
			int iBad = newName.FindOneOf(_T(":"));
#endif
			if (iBad != -1)
				newName.ReleaseBuffer(iBad);

#ifndef _MAC
#ifdef ORG_FROM_CDOCUMENT
			// append the default suffix if there is one
			CString strExt;
			if (pTemplate->GetDocString(strExt, CDocTemplate::filterExt) &&
			  !strExt.IsEmpty())
			{
				ASSERT(strExt[0] == '.');
				newName += strExt;
			}
#else
            // append the default suffix if there is one
            CString strExt;
            if (pTemplate->GetDocString(strExt, CDocTemplate::filterExt) &&
                !strExt.IsEmpty())
               {
               ASSERT(strExt[0] == '.');
               int nSemi;                       //added
               if(nSemi = strExt.Find(';')) {}; //added why is there a NULL statement on this 
               strExt = strExt.Left(nSemi);     //added

               newName += strExt;
               } 
#endif
#endif
		}

		if (!AfxGetApp()->DoPromptFileName(newName,
		  bReplace ? AFX_IDS_SAVEFILE : AFX_IDS_SAVEFILECOPY,
		  OFN_HIDEREADONLY | OFN_PATHMUSTEXIST, FALSE, pTemplate))
			return FALSE;       // don't even attempt to save
	}

	CWaitCursor wait;

	if (!OnSaveDocument(newName))
	{
		if (lpszPathName == NULL)
		{
			// be sure to delete the file
			TRY
			{
				CFile::Remove(newName);
			}
#ifdef ORG_FROM_CDOCUMENT
			CATCH_ALL(e)
			{
				TRACE0("Warning: failed to delete file after failed SaveAs.\n");
				DELETE_EXCEPTION(e);
			}
#else
            CATCH_ALL(e)
             {
             TRACE0("Warning: failed to delete file after failed SaveAs.\n");
             e->Delete();     //modified
             } 
#endif
			END_CATCH_ALL
		}
		return FALSE;
	}

	// reset the title and change the document name
	if (bReplace)
#if 1
		SetPathName(newName, TRUE);
#else
      {
      // Use Rose to change model name and directory
      // would prefer to do this with Sdai.
      RoseDesign *rose = _sdaiGetRoseDesign(IDFModel);
      char *pathname = (char *)calloc(1,  strlen(rose->fileDirectory())
                                        + strlen(rose->name())
                                        + strlen(rose->format())
                                        + 2);
      strcpy(pathname, rose->fileDirectory());
//      strcat(pathname, "/");
      strcat(pathname, rose->name());
      strcat(pathname, ".");
      strcat(pathname, rose->format());
TRACE("IDF pathname: %s\r\n", pathname);
TRACE("IDF newName: %s\r\n", newName);
 
#if 1
		SetPathName(newName, TRUE);
#else
   SetPathName(pathname, TRUE );
#endif
   }
#endif
	return TRUE;        // success
   }

int CIDFDoc::CreateAP210Aim(char * dir, char * name) {
   long flag;
   HKEY hKey;
   TCHAR ARMToAIM[512];
   DWORD dwKeyDataType;
   DWORD dwDataBufSize = sizeof(ARMToAIM);

   int result = 0;

   CreateAP210Arm(dir, name);

   // Get the names of the IDF translator ExpressX schemas from the registry
   if ((flag = RegOpenKeyEx(HKEY_LOCAL_MACHINE,  _T(AP210VIEWER_MACHINE_REGISTRY),
               0, KEY_QUERY_VALUE, &hKey)) == ERROR_SUCCESS) {
      // Create AP210 AIM
      TRACE0("Loading ARM to AIM mapping...\n");
       if ((flag = RegQueryValueEx(hKey, _T("AP210ARMToAP210AIM"), NULL, &dwKeyDataType,
                    (LPBYTE) &ARMToAIM, &dwDataBufSize)) == ERROR_SUCCESS) {

         sm_arm2aim = initialize_system(ARMToAIM);  // JDV
         if (!sm_arm2aim) {
            TRACE("Cannot find schema map '%s'\n", ARMToAIM);
            exit(1);
            }
         TRACE0("Running ARM to AIM mapping...\n");
         run_mapping(sm_arm2aim, 100);
         }
      RegCloseKey(hKey);
      }
   if (flag != ERROR_SUCCESS) {
      LPVOID lpMsgBuf;

      // set the result.
      result = 1;

      FormatMessage( 
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
            NULL,
            flag,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
            (LPTSTR) &lpMsgBuf,
            0,
            NULL 
            );
      // Display the string.
      MessageBox( NULL, (const char *)lpMsgBuf, "IDF To AP210 Translator", MB_OK|MB_ICONINFORMATION );

      // Free the buffer.
      LocalFree( lpMsgBuf );
      }
   AP210Model = _sdaiGetModel(aim_targ);
   sdaiAccessModel (AP210Model, sdaiRW);
#ifdef VERBOSE
TRACE("AP210Model: 0x%08x\r\n", AP210Model);
TRACE("dir: %s\r\n", dir);
TRACE("name: %s\r\n", name);
#endif
   return(result);
   }
int CIDFDoc::CreateAP210Arm(char *dir, char *name) {
   int result = 0;
    long flag;
   HKEY hKey;
   TCHAR IDFToARM[512];
   DWORD dwKeyDataType;
   DWORD dwDataBufSize = sizeof(IDFToARM);

   char *arm_model = (char *)calloc(1, strlen(name)+strlen(AP210ARMEXT)+1);
   char *aim_model = (char *)calloc(1, strlen(name)+strlen(AP210EXT)+1);

   // Build arm model name
   strcpy(arm_model, name);
   strcat(arm_model, AP210ARMEXT);
TRACE("arm_model: %s\r\n", arm_model);

   // Build aim model name.
   strcpy(aim_model, name);
   strcat(aim_model, AP210EXT);
TRACE("aim_model: %s\r\n", aim_model);

  // Get the names of the IDF translator ExpressX schemas from the registry
   if ((flag = RegOpenKeyEx(HKEY_LOCAL_MACHINE,  _T(AP210VIEWER_MACHINE_REGISTRY),
               0, KEY_QUERY_VALUE, &hKey)) == ERROR_SUCCESS) {
	
      if ((flag = RegQueryValueEx(hKey, _T("IDFToAP210ARM"), NULL, &dwKeyDataType,
                  (LPBYTE) &IDFToARM, &dwDataBufSize)) == ERROR_SUCCESS) {
         }
      // Get source schema instance. IDF MODEL PER DOC
      src = _sdaiGetRoseDesign(IDFModel);

      // JDV
      // What does this do should it be called more than once?
      express_parse_schema_force_load();
      entity_defined_ignore load_ignorestruct_code;

      // Supress ROSE messages.
      // ROSE.error_reporter()->report_threshold(ROSE_SEV_FATAL);


      // Get mapping schemas. On initial int for IDF Doc
      TRACE("Loading IDF to ARM mapping %s\n", IDFToARM);
      sm_idf2arm = initialize_system(IDFToARM);   // JDV
      if (!sm_idf2arm) {
         TRACE("cannot find schema map '%s'\n", IDFToARM);
         exit(1);
         }
     
      // Assign the RoseDesigns from above to the schema instance
      // variables in the schema map2.

      // WARNING: This assumes schema instances in mapping schemas
      // are identical and in the following order:
      //   idf schema instance
      //   210 aim schema instance
      //   210 arm schema instance
      ListOfString * instances;
      instances = sm_idf2arm->schemaInstanceTypes();
      aim_targ = ROSE.newDesign(aim_model, instances->_element(1));
      // build header
      aim_targ->initialize_header();

      arm_targ = ROSE.newDesign(arm_model, instances->_element(2));
      // build header
      arm_targ->initialize_header();

      // Run the maps. ON DOC SAVE
      // NOTE: The expx library gets confused if there is more than
      // one schema map in memory, so delete the IDF to ARM mapping schema
      // after running it and before loading the ARM to AIM mapping schema.
      TRACE0("Running IDF to ARM mapping...\n");
      run_mapping(sm_idf2arm,30);
      delete sm_idf2arm;
      }

   if (flag != ERROR_SUCCESS) {
      LPVOID lpMsgBuf;

      // set the result.
      result = 1;

      FormatMessage( 
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
            NULL,
            flag,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
            (LPTSTR) &lpMsgBuf,
            0,
            NULL 
            );

      // Display the string.
      MessageBox( NULL, (const char *)lpMsgBuf, "IDF To AP210 Translator", MB_OK|MB_ICONINFORMATION );

      // Free the buffer.
      LocalFree( lpMsgBuf );
      }
   // free memory
   free(arm_model);
   free(aim_model);

   return (result);
   }
void CIDFDoc::run_mapping(SchemaMap * the_sm, int view_cnt) {
  TRACE( "Max of %d views/composes will be run\n", view_cnt - 1 );

  sm = the_sm;

  // Bind the schema instances.
  sm->bindSchemaInstance(0, src);
  sm->bindSchemaInstance(1, aim_targ);
  sm->bindSchemaInstance(2, arm_targ);
  
  // Bind external functions.
  bind_external_functions();

  // Execute the VIEWs and then COMPOSEs.
  sm->verbose(TRUE);  // Turns on warm fuzzies.
  sm->instantiateGlobals();

//  sm->executeView();
//  sm->executeCompose();

  // These will have to do until the next version of EXP-X comes along
  for( int i=1 ; i<view_cnt ; i++ )
    sm->executeView(i);
  for( int j=1 ; j<view_cnt ; j++ )
    sm->executeCompose(j);
}
