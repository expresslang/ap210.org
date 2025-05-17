#if !defined(AFX_COMPONENTDEFINITIONSHEET_H__683147A2_9FA4_11D4_8A9A_0080AD428934__INCLUDED_)
#define AFX_COMPONENTDEFINITIONSHEET_H__683147A2_9FA4_11D4_8A9A_0080AD428934__INCLUDED_


#include "PropertiesPage.h"	// Added by ClassView
#include "GeneralPackagedComponentPage.h"	// Added by ClassView
#include "GeneralPackagePage.h"	// Added by ClassView
#include "Sdai/ComponentDefinition.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ComponentDefinitionSheet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CComponentDefinitionSheet

class CComponentDefinitionSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CComponentDefinitionSheet)

// Construction
public:
	CComponentDefinitionSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CComponentDefinitionSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComponentDefinitionSheet)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
public:
	void setReadOnly(BOOL mode);
	virtual void setValues(SdaiModel AP210Model, ComponentDefinition *pc);

    // component definition data
	CGeneralPackagedComponentPage *m_generalPage;
	CPropertiesPage m_comppropertiesPage;

    // physical unit data
	CGeneralPackagePage *m_physicalunitPage;
	CPropertiesPage m_physicalunitpropertiesPage;

	virtual ~CComponentDefinitionSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CComponentDefinitionSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CComponentDefinitionSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMPONENTDEFINITIONSHEET_H__683147A2_9FA4_11D4_8A9A_0080AD428934__INCLUDED_)
