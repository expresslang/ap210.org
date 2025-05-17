#if !defined(AFX_PACKAGEDPARTPROPERTIESSHEET_H__D7737644_E773_11D3_8A99_0080AD428934__INCLUDED_)
#define AFX_PACKAGEDPARTPROPERTIESSHEET_H__D7737644_E773_11D3_8A99_0080AD428934__INCLUDED_

#include "PropertiesPage.h"	// Added by ClassView
#include "GeneralPackagedPartPage.h"	// Added by ClassView
#include "GeneralPackagePage.h"	// Added by ClassView
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PackagedPartPropertiesSheet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPackagedPartPropertiesSheet

class CPackagedPartPropertiesSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CPackagedPartPropertiesSheet)

// Construction
public:
	CPackagedPartPropertiesSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CPackagedPartPropertiesSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPackagedPartPropertiesSheet)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
public:
   // packaged part data
	CGeneralPackagedPartPage m_generalpackagedpartPage;
	CPropertiesPage m_packagedpartpropertiesPage;

   // package data
	CGeneralPackagePage m_packagePage;
	CPropertiesPage m_packagepropertiesPage;

	virtual void setValues(SdaiModel AP210Model, PackagedPart *packagedpart);
	virtual ~CPackagedPartPropertiesSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPackagedPartPropertiesSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CPackagedPartPropertiesSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PACKAGEDPARTPROPERTIESSHEET_H__D7737644_E773_11D3_8A99_0080AD428934__INCLUDED_)
