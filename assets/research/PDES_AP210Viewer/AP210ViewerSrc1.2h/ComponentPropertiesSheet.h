#if !defined(AFX_COMPONENTPROPERTIESSHEET_H__7BFC59A9_DBDC_11D3_8A99_0080AD428934__INCLUDED_)
#define AFX_COMPONENTPROPERTIESSHEET_H__7BFC59A9_DBDC_11D3_8A99_0080AD428934__INCLUDED_

#include "GeneralPackagedComponentPage.h"	// Added by ClassView
#include "GeneralPackagedPartPage.h"	// Added by ClassView
#include "GeneralPackagePage.h"	// Added by ClassView
#include "PropertiesPage.h"	// Added by ClassView
#include "Sdai/ComponentDefinition.h"

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ComponentPropertiesSheet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CComponentPropertiesSheet

class CComponentPropertiesSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CComponentPropertiesSheet)

// Construction
public:
	CComponentPropertiesSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CComponentPropertiesSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComponentPropertiesSheet)
	//}}AFX_VIRTUAL

// Implementation
public:
	void setReadOnly(BOOL mode);
	virtual void setValues(SdaiModel AP210Model, PackagedComponent *pc);
   // packaged component data
	CGeneralPackagedComponentPage m_generalPage;
	CPropertiesPage m_comppropertiesPage;

   // packaged part data
	CGeneralPackagedPartPage m_generalpackagedpartPage;
	CPropertiesPage m_packagedpartpropertiesPage;

   // package data
	CGeneralPackagePage m_packagePage;
	CPropertiesPage m_packagepropertiesPage;

	virtual ~CComponentPropertiesSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CComponentPropertiesSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMPONENTPROPERTIESSHEET_H__7BFC59A9_DBDC_11D3_8A99_0080AD428934__INCLUDED_)
