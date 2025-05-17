// AP210DocManager.h: interface for the AP210DocManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AP210DOCMANAGER_H__7C4A9161_C098_11D3_8A99_0080AD428934__INCLUDED_)
#define AFX_AP210DOCMANAGER_H__7C4A9161_C098_11D3_8A99_0080AD428934__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Afxwin.h"

class AP210DocManager : public CDocManager  
{
	DECLARE_DYNAMIC(AP210DocManager)
public:
	virtual void OnImportIdf();
	virtual BOOL DoPromptIDFFileName(CString& fileName, UINT nIDSTitle,
			DWORD lFlags, BOOL bOpenFileDialog, CDocTemplate* pTemplate);

	virtual void OnFileOpen();
	virtual void OnFileOpenReadonly();
	AP210DocManager();
	virtual ~AP210DocManager();

// Overrides
	// helper for standard commdlg dialogs
	virtual BOOL DoPromptFileName(CString& fileName, UINT nIDSTitle,
			DWORD lFlags, BOOL bOpenFileDialog, CDocTemplate* pTemplate);
};

#endif // !defined(AFX_AP210DOCMANAGER_H__7C4A9161_C098_11D3_8A99_0080AD428934__INCLUDED_)
