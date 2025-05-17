// AP210ViewerDoc.cpp : implementation of the CAP210ViewerDoc class
//

#include "stdafx.h"

// required for copy of OnSaveDocument delete if removed
#define DELETE_EXCEPTION(e) do { e->Delete(); } while (0)
#include "AP210Viewer.h"

#include "AP210ViewerDoc.h"
#include "Sdai/ExtractGeometry.h"
#include "Sdai/ap210_visualizer.h"
#include "Sdai/PackagedComponent.h"

// GUI
#include "PropertiesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAP210ViewerDoc

IMPLEMENT_DYNCREATE(CAP210ViewerDoc, CDocument)

BEGIN_MESSAGE_MAP(CAP210ViewerDoc, CDocument)
	//{{AFX_MSG_MAP(CAP210ViewerDoc)
	ON_COMMAND(ID_FILE_PROPERTIES, OnFileProperties)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAP210ViewerDoc construction/destruction

CAP210ViewerDoc::CAP210ViewerDoc() {
   TRACE0("CAP210ViewerDoc\r\n") ;
   // TODO: add one-time construction code here
   }

CAP210ViewerDoc::~CAP210ViewerDoc() {
   }

BOOL CAP210ViewerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
    // MTK:  Here is where you would intialize the ap210 environment.
	TRACE0("OnNewDocument\r\n") ;

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAP210ViewerDoc diagnostics

#ifdef _DEBUG
void CAP210ViewerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAP210ViewerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAP210ViewerDoc commands

// Added to handle step.

BOOL CAP210ViewerDoc::OnOpenDocument(LPCTSTR lpszPathName) {
   SdaiErrorCode sdaiError;
   CString path(lpszPathName);
   CString filename(path.Right(path.GetLength()-path.ReverseFind('\\')-1));
   CString modelname(filename.Left(filename.ReverseFind('.')));
   TRACE("CAP210ViewerDoc::OnOpenDocument: %s\n", lpszPathName);
   TRACE("path: %s\r\n", path);
   TRACE("filename: %s\r\n", filename);
   TRACE("Modelname: %s\r\n", modelname);

   TRACE("GetPathName: %s\r\n", GetPathName());

   if (IsModified())
      TRACE0("Warning: OnOpenDocument replaces an unsaved document.\n");

   // clear the error code.
   sdaiErrorQuery();

   // Check to see if the model is already loaded.
// MTKLOAD
TRACE("ROSE LOOKING to find: %s\r\n", (char *)LPCTSTR(modelname));
   if (ROSE.findDesignInWorkspace((char *)LPCTSTR(modelname)) != NULL) {
      AP210Model = sdaiNULL;
      LPVOID lpMsgBuf;

      FormatMessage( 
         FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
         NULL,
         NULL, // flag,
         MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
         (LPTSTR) &lpMsgBuf,
         0,
         NULL 
         );

      // Display the string.
      MessageBox(NULL,
                 "A model named "+modelname+" has already been opened.",
                 "Model Already Loaded",
                 MB_OK|MB_ICONEXCLAMATION|MB_HELP|MB_TOPMOST);

      // Free the buffer.
      LocalFree( lpMsgBuf );
      return FALSE;
      }

   // clear the error code.
   sdaiErrorQuery();

   // Open the documents AP210Model
// MTKLOAD
TRACE("Accessing: %s\r\n", (char *)lpszPathName);

   AP210Model = sdaiAccessModelBN (myRepository, (char *)lpszPathName, sdaiRW);

   if((sdaiError = sdaiErrorQuery())) {
      TRACE("Cannot access model, Did you install the rose files?\n");
      TRACE("SDAI Error: %s.\n", _sdaiGetErrorName(sdaiError));
      ReportSaveLoadException(lpszPathName, NULL,
        FALSE, AFX_IDP_FAILED_TO_OPEN_DOC);
      return FALSE;
      }
	SetModifiedFlag(FALSE);     // start off with unmodified

    // Build Display Model
   if (BuildDisplayModel(lpszPathName) == FALSE) {
       closeAP210Model(path);
       return FALSE;
      }
   return TRUE;
   }

// Build Display Model
// NOTE: Need to look into how to build the lines, arc etc for OpenGl
//       Still using AP210 structures which aren't Ideal.
// Build Board This should be a member function.
BOOL CAP210ViewerDoc::BuildDisplayModel(LPCTSTR lpszPathName) {
   selectDisplayModel();
   SdaiAppInstance PWBpu = getInterconnectModulePhysicalDesign();

   // Build the board component
   if (PWBpu != sdaiNULL) {
      PWB = BoardComponent::Construct(this, AP210Model, PWBpu);

      if (PWB == NULL) {
          ReportSaveLoadException(lpszPathName, NULL,
             FALSE, AFX_IDP_FAILED_TO_OPEN_DOC);
          return FALSE;
         }
       }
    else {
       ReportSaveLoadException(lpszPathName, NULL,
          FALSE, AFX_IDP_FAILED_TO_OPEN_DOC);
       return FALSE;
       }
   // Build Components
   BuildComponents();

   return TRUE;
   }

BOOL CAP210ViewerDoc::OnSaveDocument(LPCTSTR lpszPathName) {
   SdaiErrorCode sdaiError;
   char *name;
   char *suffix;
   char *dir = strdup(lpszPathName);

   TRACE("In CAP210ViewerDoc::OnSaveDocument(%s)\r\n", lpszPathName);
 
   // extract the directory and name from lpszPathName
   if ((name = strrchr(dir, '\\')) != NULL) {
      name++;
      if ((suffix = strrchr(name, '.')) != NULL) {
         *suffix = '\0';
         suffix++;
         }
      }
   else {
      ReportSaveLoadException(lpszPathName, NULL,
        TRUE, AFX_IDP_FAILED_TO_SAVE_DOC);
      free(dir);
      return false;
      }
#if 1
   // Use Rose to change model name and directory
   // would prefer to do this with Sdai.
   RoseDesign *rose = _sdaiGetRoseDesign(AP210Model);
   rose->name(name);
   *name = '\0';
   rose->fileDirectory(dir);
   char *pathname = (char *)calloc(1,  strlen(rose->fileDirectory())
                                     + strlen(rose->name())
                                     + strlen(rose->format())
                                     + 2);
   strcpy(pathname, rose->fileDirectory());
   strcat(pathname, rose->name());
   strcat(pathname, ".");
   strcat(pathname, rose->format());
TRACE("pathname: %s\r\n", pathname);
 
   SetPathName(pathname, TRUE );
#else
   // Doesn't seem to work, need to see an example
   // before trying again.  How would you change the 
   // directory?
   sdaiRenameModel(AP210Model, "test");   
#endif
   // done with dir so free it.
   free(dir);
   dir = NULL;

   // clear the error code.
   sdaiErrorQuery();
   
   // Save Model
   sdaiSaveChanges(AP210Model);

   if((sdaiError = sdaiErrorQuery())) {
      TRACE("Cannot save model\n");
      TRACE("SDAI Error: %s.\n", _sdaiGetErrorName(sdaiError));
      ReportSaveLoadException(lpszPathName, NULL,
        TRUE, AFX_IDP_FAILED_TO_SAVE_DOC);
      return FALSE;
      }
	SetModifiedFlag(FALSE);     // back to unmodified

	return TRUE;        // success
   }

void CAP210ViewerDoc::OnCloseDocument() {
   // TODO: Add your specialized code here and/or call the base class
   TRACE0("CAP210ViewerDoc::OnCloseDocument()\r\n") ;

   // close the AP210 Model
   closeAP210Model(GetPathName());

   CDocument::OnCloseDocument();
   }

PackagedComponent * CAP210ViewerDoc::BuildPackagedComponent(SdaiAppInstance PWApu, SdaiAppInstance pc) {
   static SdaiEntity PC = sdaiGetEntity(AP210Model, "packaged_component");

   static SdaiEntity NAUO = sdaiGetEntity(AP210Model, "next_assembly_usage_occurrence");
#ifdef VERBOSE
   static SdaiAttr NAUO_RD = sdaiGetAttrDefinition(NAUO, "reference_designator");
#endif

   static SdaiAttr NAUO_DESC = sdaiGetAttrDefinition(NAUO, "description");
   static SdaiAttr NAUO_ED = sdaiGetAttrDefinition(NAUO, "related_product_definition");
   static SdaiAttr NAUO_ING = sdaiGetAttrDefinition(NAUO, "relating_product_definition");

   SdaiAppInstance pcasr = sdaiNULL; // packaged_component analysis shape_representation
   SdaiAppInstance A2P_LOC; // packaged_component location

   SdaiAppInstance nauo;  // next_assembly_usage_occurance
#ifdef VERBOSE
   SdaiString refdes;     // reference designator
#endif
   SdaiAppInstance unit;
   PackagedComponent *mpc = NULL;
   SdaiAppInstance nauo_ing;

   // really need to go thru the assemblies physical_unit.
   if (sdaiIsInstanceOf(pc, PC)) {
#ifdef VERBOSE
TRACE("\r\npackaged_component: %s\r\n", _sdaiGetPart21Description(pc));
#endif
      // get the pc's reference designator*/
      nauo = _sdaiFindSingleSubTypeInstanceUsedIn(pc, NAUO, NAUO_ED);
#ifdef VERBOSE
TRACE("nauo: %s\r\n", _sdaiGetPart21Description(nauo));
#endif

      sdaiGetAttr(nauo, NAUO_ING, sdaiINSTANCE, &nauo_ing);
#ifdef VERBOSE
TRACE("nauo_ing: %s\r\n", _sdaiGetPart21Description(nauo_ing));
#endif
      if (nauo_ing == PWApu) { // this seems redundant, should pass in the nauo

#ifdef VERBOSE
         sdaiGetAttr(nauo, NAUO_RD, sdaiSTRING, &refdes);
TRACE("refdes: %s\r\n", refdes);
#endif
         /* get component specific information */ 
         A2P_LOC = getPackagedComponentLocation(AP210Model, pc);
#ifdef VERBOSE
TRACE("component_location: %s\r\n", _sdaiGetPart21Description(A2P_LOC));
#endif
         // Get the packaged_components shape_representation.
         pcasr = sdaiNULL;  // required only if you comment out the line below.
         pcasr = getComponentGeometry(AP210Model, pc);
#ifdef VERBOSE
TRACE("pcasr 1: %s\r\n", _sdaiGetPart21Description(pcasr));
#endif
         if (pcasr == sdaiNULL) {
            // Look for rockwell shape_representations here.
            pcasr = getComponentDefinitionShapeRepresentation(AP210Model, pc);
#ifdef VERBOSE
TRACE("pcasr 2: %s\r\n", _sdaiGetPart21Description(pcasr));
#endif
            }

         if (pcasr != sdaiNULL) {
            // get the shape representations length units
            // this unit is used A2P_LOC, it might not be correct!!!!
            if ((unit = getRepresentationLengthUnit(AP210Model, pcasr)) == sdaiNULL) {
               TRACE("ERROR: &s\r\n       has no units.\r\n", _sdaiGetPart21Description(pcasr));
               }     
#ifdef VERBOSE
TRACE("unit: %s\r\n", _sdaiGetPart21Description(unit));
#endif
            mpc = new PackagedComponent(this, pc, unit, A2P_LOC);
            }
         }
      }
   return mpc;
   }
/*
#425=NEXT_ASSEMBLY_USAGE_OCCURRENCE
     ('','assembly composition','',#1542,#1659,'norefdes');
#1659=COMPONENT_DEFINITION('','',#1397,#1736);

BuildMechanicalParts

Exclude the interconnect module. But that is a bit of a kludge
need to look at the recproc for interconnect module physical design usage view.
*/
ComponentDefinition *CAP210ViewerDoc::BuildMechanicalComponent(SdaiAppInstance PWApu, SdaiAppInstance cd) {
   static SdaiEntity CD = sdaiGetEntity(AP210Model, "component_definition");
#ifdef VERBOSE
   static SdaiAttr CD_DESC = sdaiGetAttrDefinition(CD, "description");
#endif

   static SdaiEntity NAUO = sdaiGetEntity(AP210Model, "next_assembly_usage_occurrence");
#ifdef VERBOSE
   static SdaiAttr NAUO_RD = sdaiGetAttrDefinition(NAUO, "reference_designator");
#endif

   static SdaiAttr NAUO_ED = sdaiGetAttrDefinition(NAUO, "related_product_definition");
   static SdaiAttr NAUO_ING = sdaiGetAttrDefinition(NAUO, "relating_product_definition");

   static SdaiAttr PRPC_NAME = sdaiGetAttrDefinitionBN(AP210,
                                                       "product_related_product_category",
                                                       "name");

   SdaiAppInstance pcasr = sdaiNULL; // packaged_component analysis shape_representation
   SdaiAppInstance A2P_LOC; // packaged_component location

   SdaiAppInstance nauo;  // next_assembly_usage_occurance
#ifdef VERBOSE
   SdaiString refdes;     // reference designator
   SdaiString cd_desc;    // component_definition type?
#endif
   SdaiAppInstance unit;
   ComponentDefinition *mpc = NULL;
   SdaiAppInstance nauo_ing;

   SdaiAppInstance cd_pu;
   SdaiAppInstance prpc;
   SdaiString prpc_name;

   if (sdaiIsInstanceOf(cd, CD)) {
#ifdef VERBOSE
       sdaiGetAttr(cd, CD_DESC, sdaiSTRING, &cd_desc);
       TRACE("component_definition.description: %s\n", cd_desc);
TRACE("\r\ncomponent_definition: %s\r\n", _sdaiGetPart21Description(cd));
#endif

      cd_pu = getProductDefinitionPhysicalUnit(AP210Model, cd);
      prpc = getPhysicalUnitsProductRelatedProductCategory(cd_pu);
      /* get the prpc's name */
      sdaiGetAttr(prpc, PRPC_NAME, sdaiSTRING, &prpc_name);

      if (prpc_name == NULL || strcmp(prpc_name, "interconnect module")) {
         // get the pc's reference designator*/
         nauo = _sdaiFindSingleSubTypeInstanceUsedIn(cd, NAUO, NAUO_ED);
#ifdef VERBOSE
TRACE("nauo: %s\r\n", _sdaiGetPart21Description(nauo));
#endif

         sdaiGetAttr(nauo, NAUO_ING, sdaiINSTANCE, &nauo_ing);
#ifdef VERBOSE
TRACE("nauo_ing: %s\r\n", _sdaiGetPart21Description(nauo_ing));
#endif
         if (nauo_ing == PWApu) { // this seems redundant, should pass in the nauo

#ifdef VERBOSE
            sdaiGetAttr(nauo, NAUO_RD, sdaiSTRING, &refdes);
TRACE("pc2 refdes: %s\r\n", refdes);
#endif
            /* get component specific information */ 
            A2P_LOC = getPackagedComponentLocation(AP210Model, cd);
#ifdef VERBOSE
TRACE("component_location: %s\r\n", _sdaiGetPart21Description(A2P_LOC));
#endif
            if (A2P_LOC != sdaiNULL) {
               // Get the component_definitions shape_representation.
               pcasr = getComponentDefinitionShapeRepresentation(AP210Model, cd);
#ifdef VERBOSE
TRACE("pcasr: %s\r\n", _sdaiGetPart21Description(pcasr));
#endif

               if (pcasr != sdaiNULL) {
                  // get the shape representations length units
                  // this unit is used A2P_LOC, it might not be correct!!!!
                  if ((unit = getRepresentationLengthUnit(AP210Model, pcasr)) == sdaiNULL) {
                     TRACE("ERROR: &s\r\n       has no units.\r\n", _sdaiGetPart21Description(pcasr));
                     }     
#ifdef VERBOSE
TRACE("unit: %s\r\n", _sdaiGetPart21Description(unit));
#endif
                  mpc = new ComponentDefinition(this, cd, unit, A2P_LOC);
                  }
               }
#ifdef VERBOSE
            else {
               TRACE("WARNING: %s has no component_location\r\n", refdes);
               TRACE0("         It will be considered an unplaced component\r\n");
               }
#endif
            }
         }
      }
   return mpc;
   }
/*
 * BuildComponents()
 *
 * Build the Electrical and Mechanical Components
 */
 void CAP210ViewerDoc::BuildComponents() {
   static SdaiEntity PC = sdaiGetEntity(AP210Model, "packaged_component");

   static SdaiEntity NAUO = sdaiGetEntity(AP210Model, "next_assembly_usage_occurrence");

   // component
   static SdaiAttr NAUO_ED = sdaiGetAttrDefinition(NAUO, "related_product_definition");
   // PWApu
   static SdaiAttr NAUO_ING = sdaiGetAttrDefinition(NAUO, "relating_product_definition");

   SdaiNPL domain = sdaiCreateNPL();
   SdaiNPL resultList = sdaiCreateNPL();
   SdaiAppInstance nauo;

   SdaiIterator itor;
   SdaiAggr all_objects;
   SdaiAppInstance obj = sdaiNULL; // scratch object

   SdaiAppInstance pc;    // packaged_component
   PackagedComponent *mpc;
   SdaiAppInstance PWApu = getAssemblyModulePhysicalDesign();

   ComponentDefinition *mc; // mechanical part

   // get a list of all instances
   sdaiGetAttrBN ((SdaiAppInstance) AP210Model, "contents", sdaiINSTANCE, &obj);
   sdaiGetAttrBN (obj, "instances", sdaiAGGR, &all_objects);
#ifdef VERBOSE
TRACE0("In CAP210ViewerDoc::BuildComponents()\r\n");
TRACE("PWApu: %s\r\n", _sdaiGetPart21Description(PWApu));
#endif
   // create an iterator for all the PWApu's components
   sdaiFindInstanceUsedIn(PWApu, NAUO_ING, domain, resultList);

#ifdef VERBOSE
TRACE("count: %d\n", sdaiGetMemberCount(resultList));
#endif
   if (sdaiGetMemberCount(resultList) > 0) {
      itor = sdaiCreateIterator(resultList);
      while (sdaiNext(itor)) {
         sdaiGetAggrByIterator(itor, sdaiINSTANCE, &nauo); 
         sdaiGetAttr(nauo, NAUO_ED, sdaiINSTANCE, &pc);

         if (sdaiIsInstanceOf(pc, PC)) {
            // Build Electrical Component
            mpc = BuildPackagedComponent(PWApu, pc);
            if (mpc != NULL) {
               ComponentDefinitions.Add(mpc);
               }
            }
         else {
            // Build Mechanical Component
            mc = BuildMechanicalComponent(PWApu, pc);

            if (mc != NULL) {
               ComponentDefinitions.Add(mc);
               }
            }
         }   
      sdaiDeleteIterator(itor);
      }
   sdaiDeleteNPL(domain);
   sdaiDeleteNPL(resultList);
   }
BOOL CAP210ViewerDoc::DoSave(LPCTSTR lpszPathName, BOOL bReplace)
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
#if 0
		SetPathName(newName, TRUE);
#else
      {
      // Use Rose to change model name and directory
      // would prefer to do this with Sdai.
      RoseDesign *rose = _sdaiGetRoseDesign(AP210Model);
      char *pathname = (char *)calloc(1,  strlen(rose->fileDirectory())
                                        + strlen(rose->name())
                                        + strlen(rose->format())
                                        + 2);
      strcpy(pathname, rose->fileDirectory());
      strcat(pathname, rose->name());
      strcat(pathname, ".");
      strcat(pathname, rose->format());
TRACE("pathname: %s\r\n", pathname);
 
   SetPathName(pathname, TRUE );
   }
#endif
	return TRUE;        // success
   }
/*
 * SetPartNumber()
 * 
 * Set SelectedPartNumber so that the partnumber will
 * be displayed.
 */
void CAP210ViewerDoc::SetPartNumber(PackagedComponent *pc) {
   ASSERT(pc);
   SelectedPartNumber = getPackagedComponentPartNumber(AP210Model, pc->Component);
   }

void CAP210ViewerDoc::OnFileProperties() {
	// TODO: Add your command handler code here
   // get the rose design
   RoseDesign *ap210 = _sdaiGetRoseDesign(AP210Model);

   // create the dialog box
   CPropertiesDlg propDlg;

   // set the dialog boxes values
   setFileProperties(&propDlg, ap210);

   // display the dialog box
   propDlg.DoModal();
   }

/*
 *  closeAP210Model
 *
 *  Close the ap210 model completely removing it from memory
 *  but without deleting the part21 file
 *
 */
void CAP210ViewerDoc::closeAP210Model(CString name) {
   // clear the error code.
   sdaiErrorQuery();

/// MTKLOAD
   // remove the model from memory.
   if (AP210Model != sdaiNULL) {
      SdaiErrorCode sdaiError;
TRACE("Removing Model in %s\r\n", AP210);
#if 0
      sdaiRenameModel(AP210Model, "rjunk");
      // This leaves the model to still be found by _sdaiFindModelBN in OnOpenDocument.
      sdaiRemoveModel(sdaiGetSchemaInstance(AP210, myRepository), AP210Model);
#else
      // This is a major KLUDGE sdaiDeleteModel will remove
      // the model so _sdaiFindModelBN won't find it but, it
      // deletes the model from the repository (ie. deletes the part21 file)
      // so we have to make the file read only while this sdaiDeleteModel is called!
      CFileStatus rStatus;
      // get the files status
   RoseDesign *rose = _sdaiGetRoseDesign(AP210Model);
TRACE("Rose Name: %s\r\n", rose->name());
TRACE("Rose Format: %s\r\n", rose->format());
      if (CFile::GetStatus(name, rStatus) == TRUE) {
TRACE("GetStatus True\r\n");         

         // save the attribute byte
         BYTE m_attribute = rStatus.m_attribute;

         if (!(m_attribute & 0x01)) {
            // make the file readonly. 
            rStatus.m_attribute = 0x01;//readOnly; doesn't work because readOnly is in an 
                                    //          MGC enumeration named Attribute in CFile.
            CFile::SetStatus(name, rStatus);
            }
         // Remove the model, it won't be deleted because it is now readonly
         sdaiDeleteModel(AP210Model);

         if (!(m_attribute & 0x01)) {
            // restore attribute byte
            rStatus.m_attribute = m_attribute;
            CFile::SetStatus(name, rStatus);
            }
         }
    // else couldn't remove the design since the named file doesn't exist

      // This appears to be a bad error message.
      if ((sdaiError = sdaiErrorQuery())) {
          TRACE("Cannot remove the AP210 model\n");
          TRACE("SDAI Error: %s.\n", _sdaiGetErrorName(sdaiError));
          }
      // Rescan the repository inorder to get the removed model out.
      _sdaiRescanRepository(myRepository);

      // set AP210Model to null so we don't try to close it again.
      AP210Model = sdaiNULL;
      }
#endif
   }
