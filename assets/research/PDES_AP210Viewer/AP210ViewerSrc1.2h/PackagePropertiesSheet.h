#if !defined(AFX_PACKAGEPROPERTIESSHEET_H__D7737642_E773_11D3_8A99_0080AD428934__INCLUDED_)
#define AFX_PACKAGEPROPERTIESSHEET_H__D7737642_E773_11D3_8A99_0080AD428934__INCLUDED_

#include "PropertiesPage.h"	// Added by ClassView
#include "GeneralPackagePage.h"	// Added by ClassView
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PackagePropertiesSheet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPackagePropertiesSheet

class CPackagePropertiesSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CPackagePropertiesSheet)

// Construction
public:
	CPackagePropertiesSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT nPUCaption = 0, UINT iSelectPage = 0);
	CPackagePropertiesSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT nPUCaption = 0, UINT iSelectPage = 0);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPackagePropertiesSheet)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
public:
	CGeneralPackagePage *m_packagePage;
	CPropertiesPage m_packagepropertiesPage;
	void setReadOnly(BOOL mode);
	virtual void setValues(SdaiModel AP210Model, PhysicalUnit *pu);
	virtual ~CPackagePropertiesSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPackagePropertiesSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CPackagePropertiesSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PACKAGEPROPERTIESSHEET_H__D7737642_E773_11D3_8A99_0080AD428934__INCLUDED_)
