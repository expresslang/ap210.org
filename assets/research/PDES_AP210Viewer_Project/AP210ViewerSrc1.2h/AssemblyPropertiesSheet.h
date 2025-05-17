#if !defined(AFX_ASSEMBLYPROPERTIESSHEET_H__164C1C0B_7C5C_473B_B7FD_3849B27B28BD__INCLUDED_)
#define AFX_ASSEMBLYPROPERTIESSHEET_H__164C1C0B_7C5C_473B_B7FD_3849B27B28BD__INCLUDED_

#include "GeneralAssemblyPage.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AssemblyPropertiesSheet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAssemblyPropertiesSheet

class CAssemblyPropertiesSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CAssemblyPropertiesSheet)

// Construction
public:
	CAssemblyPropertiesSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CAssemblyPropertiesSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAssemblyPropertiesSheet)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAssemblyPropertiesSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CAssemblyPropertiesSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CGeneralAssemblyPage m_generalassemblypage;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASSEMBLYPROPERTIESSHEET_H__164C1C0B_7C5C_473B_B7FD_3849B27B28BD__INCLUDED_)
