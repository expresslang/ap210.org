// AP210Viewer.h : main header file for the AP210VIEWER application
//

#if !defined(AFX_AP210VIEWER_H__9BE7D705_0912_11D3_9B0D_0080AD428934__INCLUDED_)
#define AFX_AP210VIEWER_H__9BE7D705_0912_11D3_9B0D_0080AD428934__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// SDAI 
#include "rose.h"
#include "sdai.h"
// In HKEY_LOCAL_MACHINE
#define AP210VIEWER_MACHINE_REGISTRY "SOFTWARE\\EMPilot\\AP210 Viewer\\1.1"

// In HKEY_CURRENT_USER
#define AP210VIEWER_CURRENT_USER "SOFTWARE\\EMPilot\\AP210 Viewer"

/////////////////////////////////////////////////////////////////////////////
// CAP210ViewerApp:
// See AP210Viewer.cpp for the implementation of this class
//

class CAP210ViewerApp : public CWinApp
{
public:
	CAP210ViewerApp();
	~CAP210ViewerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAP210ViewerApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL InitApplication();
	//}}AFX_VIRTUAL

// Implementation
   CMultiDocTemplate* AP210AIMMultiDocTemplate;
   CMultiDocTemplate* AP210AIMDocTemplate;
   CMultiDocTemplate* AP210ARMDocTemplate;
	CMultiDocTemplate* IDFDocTemplate;
	CMultiDocTemplate* IDFStepDocTemplate;

   
	//{{AFX_MSG(CAP210ViewerApp)
	afx_msg void OnAppAbout();
	afx_msg void OnReadmefile();
	afx_msg void OnFilePreferences();
	afx_msg void OnFileOpenReadonly();
	afx_msg void OnImportIdf();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AP210VIEWER_H__9BE7D705_0912_11D3_9B0D_0080AD428934__INCLUDED_)
