// AP210DocManager.cpp: implementation of the AP210DocManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AP210Viewer.h"
#include "AP210DocManager.h"
#include "PWBDataBase.h"

#include "RoseExtensions/SchemaName.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
/////////////////////////////////////////////////////////////////////////////
// AP210DocManager

// Utility function from CDocMgr in Docmgr.cpp

static void AppendFilterSuffix(CString& filter, OPENFILENAME& ofn,
	CDocTemplate* pTemplate, CString* pstrDefaultExt)
{
	ASSERT_VALID(pTemplate);
	ASSERT_KINDOF(CDocTemplate, pTemplate);

	CString strFilterExt, strFilterName;
	if (pTemplate->GetDocString(strFilterExt, CDocTemplate::filterExt) &&
	 !strFilterExt.IsEmpty() &&
	 pTemplate->GetDocString(strFilterName, CDocTemplate::filterName) &&
	 !strFilterName.IsEmpty())
	{
#ifdef VERBOSE
TRACE("strFilterExt: %s\r\n", strFilterExt);
TRACE("strFilterName: %s\r\n", strFilterName);
#endif
		// a file based document template - add to filter list
#ifndef _MAC
		ASSERT(strFilterExt[0] == '.');
#endif
		if (pstrDefaultExt != NULL)
		{
			// set the default extension
#ifndef _MAC
			*pstrDefaultExt = ((LPCTSTR)strFilterExt) + 1;  // skip the '.'
#else
			*pstrDefaultExt = strFilterExt;
#endif
			ofn.lpstrDefExt = (LPTSTR)(LPCTSTR)(*pstrDefaultExt);
			ofn.nFilterIndex = ofn.nMaxCustFilter + 1;  // 1 based number
		}

		// add to filter
		filter += strFilterName;
		ASSERT(!filter.IsEmpty());  // must have a file type name
		filter += (TCHAR)'\0';  // next string please
#ifndef _MAC
		filter += (TCHAR)'*';
#endif
		filter += strFilterExt;
		filter += (TCHAR)'\0';  // next string please
		ofn.nMaxCustFilter++;
	}
}


IMPLEMENT_DYNAMIC(AP210DocManager, CDocManager)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AP210DocManager::AP210DocManager()
{
set_schema_fn();
}

AP210DocManager::~AP210DocManager()
{

}

BOOL AP210DocManager::DoPromptFileName(CString& fileName, UINT nIDSTitle,
			DWORD lFlags, BOOL bOpenFileDialog, CDocTemplate* pTemplate) {
	// TODO: Add your specialized code here and/or call the base class
   CAP210ViewerApp * app = ((CAP210ViewerApp *)AfxGetApp());
   // from CDocMgr in Docmgr.cpp
	CFileDialog dlgFile(bOpenFileDialog);

	CString title;
	VERIFY(title.LoadString(nIDSTitle));

	dlgFile.m_ofn.Flags |= lFlags;

	CString strFilter;
	CString strDefault;
   if (   pTemplate == app->IDFDocTemplate
       || pTemplate == app->IDFStepDocTemplate) {
		BOOL bFirst = TRUE;
      AppendFilterSuffix(strFilter, dlgFile.m_ofn, app->IDFDocTemplate,
				             bFirst ? &strDefault : NULL);
      bFirst = FALSE;
      AppendFilterSuffix(strFilter, dlgFile.m_ofn, app->IDFStepDocTemplate,
				             bFirst ? &strDefault : NULL);
      AppendFilterSuffix(strFilter, dlgFile.m_ofn, app->AP210ARMDocTemplate,
				             bFirst ? &strDefault : NULL);
      AppendFilterSuffix(strFilter, dlgFile.m_ofn, app->AP210AIMDocTemplate,
				             bFirst ? &strDefault : NULL);
      }
	else {
      if (pTemplate != NULL) { // only current possibility is AP210 AIM templates
         ASSERT_VALID(pTemplate);
         AppendFilterSuffix(strFilter, dlgFile.m_ofn, pTemplate, &strDefault);
         }
      else {
         // do for all doc template
         POSITION pos = m_templateList.GetHeadPosition();
         BOOL bFirst = TRUE;
         while (pos != NULL) {
            CDocTemplate* pTemplate = (CDocTemplate*)m_templateList.GetNext(pos);
            AppendFilterSuffix(strFilter, dlgFile.m_ofn, pTemplate,
                               bFirst ? &strDefault : NULL);
            bFirst = FALSE;
            }
         }

      // append the "*.*" all files filter
      CString allFilter;
      VERIFY(allFilter.LoadString(AFX_IDS_ALLFILTER));
      strFilter += allFilter;
      strFilter += (TCHAR)'\0';   // next string please
#ifdef VERBOSE
TRACE("C: allFilter: %s\r\n", allFilter);
TRACE("C: strFilter: %s\r\n", strFilter);
#endif
#ifndef _MAC
      strFilter += _T("*.*");
#else
      strFilter += _T("****");
#endif
      }
   strFilter += (TCHAR)'\0';   // last string
   dlgFile.m_ofn.nMaxCustFilter++;

   dlgFile.m_ofn.lpstrFilter = strFilter;
#ifndef _MAC
   dlgFile.m_ofn.lpstrTitle = title;
#else
   dlgFile.m_ofn.lpstrPrompt = title;
#endif
#if 1
   // maybe I should strip off the suffix here
   LPTSTR s = fileName.GetBuffer(_MAX_PATH);
   s[fileName.Find('.')] = '\0';
   dlgFile.m_ofn.lpstrFile = s;

#else
   dlgFile.m_ofn.lpstrFile = fileName.GetBuffer(_MAX_PATH);
#endif

   BOOL bResult = dlgFile.DoModal() == IDOK ? TRUE : FALSE;
   fileName.ReleaseBuffer();

	return bResult;
   }

void AP210DocManager::OnFileOpen() {
	// prompt the user (with all document templates)
	CString newName;
	if (!DoPromptFileName(newName, AFX_IDS_OPENFILE_READONLY,
	  OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, TRUE, ((CAP210ViewerApp *)AfxGetApp())->AP210AIMMultiDocTemplate))
		return; // open cancelled

	AfxGetApp()->OpenDocumentFile(newName);
		// if returns NULL, the user has already been alerted
   }
void AP210DocManager::OnFileOpenReadonly() {
	// prompt the user (with all document templates)
	CString newName;
	if (!DoPromptFileName(newName, AFX_IDS_OPENFILE_READONLY,
	  OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, TRUE, ((CAP210ViewerApp *)AfxGetApp())->AP210AIMMultiDocTemplate))
		return; // open cancelled

	PWBDataBase *PWB = ((PWBDataBase *)AfxGetApp()->OpenDocumentFile(newName));
		// if returns NULL, the user has already been alerted
   PWB->ReadOnly = TRUE;
   }

void AP210DocManager::OnImportIdf() {
	// prompt the user (with all document templates)
	CString newName;
	if (!DoPromptIDFFileName(newName, AFX_IDS_IMPORT_IDF,
	  OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, TRUE, ((CAP210ViewerApp *)AfxGetApp())->IDFDocTemplate))
		return; // open cancelled

	AfxGetApp()->OpenDocumentFile(newName);
		// if returns NULL, the user has already been alerted
   }
BOOL AP210DocManager::DoPromptIDFFileName(CString& fileName, UINT nIDSTitle,
			DWORD lFlags, BOOL bOpenFileDialog, CDocTemplate* pTemplate) {
	// TODO: Add your specialized code here and/or call the base class
   CAP210ViewerApp * app = ((CAP210ViewerApp *)AfxGetApp());
   // from CDocMgr in Docmgr.cpp
	CFileDialog dlgFile(bOpenFileDialog);

	CString title;
	VERIFY(title.LoadString(nIDSTitle));

	dlgFile.m_ofn.Flags |= lFlags;

	CString strFilter;
	CString strDefault;
   if (   pTemplate == app->IDFDocTemplate
       || pTemplate == app->IDFStepDocTemplate) {
		BOOL bFirst = TRUE;
      AppendFilterSuffix(strFilter, dlgFile.m_ofn, app->IDFDocTemplate,
				             bFirst ? &strDefault : NULL);
      bFirst = FALSE;
      AppendFilterSuffix(strFilter, dlgFile.m_ofn, app->IDFStepDocTemplate,
				             bFirst ? &strDefault : NULL);
      }
	else {
      if (pTemplate != NULL) { // only current possibility is AP210 AIM templates
         ASSERT_VALID(pTemplate);
         AppendFilterSuffix(strFilter, dlgFile.m_ofn, pTemplate, &strDefault);
         }
      else {
         // do for all doc template
         POSITION pos = m_templateList.GetHeadPosition();
         BOOL bFirst = TRUE;
         while (pos != NULL) {
            CDocTemplate* pTemplate = (CDocTemplate*)m_templateList.GetNext(pos);
            AppendFilterSuffix(strFilter, dlgFile.m_ofn, pTemplate,
                               bFirst ? &strDefault : NULL);
            bFirst = FALSE;
            }
         }
      }
   strFilter += (TCHAR)'\0';   // last string
   dlgFile.m_ofn.nMaxCustFilter++;

   dlgFile.m_ofn.lpstrFilter = strFilter;
#ifndef _MAC
   dlgFile.m_ofn.lpstrTitle = title;
#else
   dlgFile.m_ofn.lpstrPrompt = title;
#endif
#if 1
   // maybe I should strip off the suffix here
   LPTSTR s = fileName.GetBuffer(_MAX_PATH);
   s[fileName.Find('.')] = '\0';
   dlgFile.m_ofn.lpstrFile = s;

#else
   dlgFile.m_ofn.lpstrFile = fileName.GetBuffer(_MAX_PATH);
#endif

   BOOL bResult = dlgFile.DoModal() == IDOK ? TRUE : FALSE;
   fileName.ReleaseBuffer();

	return bResult;
   }
