#if !defined(AFX_INTERCONNECTMODULEPROPERTIESSHEET_H__AA8ED083_F145_11D3_8A99_0080AD428934__INCLUDED_)
#define AFX_INTERCONNECTMODULEPROPERTIESSHEET_H__AA8ED083_F145_11D3_8A99_0080AD428934__INCLUDED_

#include "GeneralInterconnectModulePage.h"	// Added by ClassView
#include "InterconnectModuleUsageViewPage.h"	// Added by ClassView
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// InterconnectModulePropertiesSheet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInterconnectModulePropertiesSheet

class CInterconnectModulePropertiesSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CInterconnectModulePropertiesSheet)

// Construction
public:
	CInterconnectModulePropertiesSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CInterconnectModulePropertiesSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInterconnectModulePropertiesSheet)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
public:
	void setReadOnly(BOOL mode);
	virtual void setValues(SdaiModel  AP210Model, BoardComponent *bc);
	CGeneralInterconnectModulePage m_generalinterconnectmodulePage;
	CInterconnectModuleUsageViewPage m_interconnectmoduleusageviewPage;
	virtual ~CInterconnectModulePropertiesSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CInterconnectModulePropertiesSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CInterconnectModulePropertiesSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INTERCONNECTMODULEPROPERTIESSHEET_H__AA8ED083_F145_11D3_8A99_0080AD428934__INCLUDED_)
