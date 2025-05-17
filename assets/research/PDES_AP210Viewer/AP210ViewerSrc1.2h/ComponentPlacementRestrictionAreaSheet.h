#if !defined(AFX_COMPONENTPLACEMENTRESTRICTIONAREASHEET_H__4279F622_0015_11D5_8A9A_0080AD428934__INCLUDED_)
#define AFX_COMPONENTPLACEMENTRESTRICTIONAREASHEET_H__4279F622_0015_11D5_8A9A_0080AD428934__INCLUDED_

#include "PWBDataBase.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ComponentPlacementRestrictionAreaSheet.h : header file
//
#include "ComponentPlacementRestrictionAreaPage.h"
#include "SingleComponentRestrictionAssignmentPage.h"
class MountingRestrictionArea;

/////////////////////////////////////////////////////////////////////////////
// CComponentPlacementRestrictionAreaSheet

class CComponentPlacementRestrictionAreaSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CComponentPlacementRestrictionAreaSheet)

// Construction
public:
	CComponentPlacementRestrictionAreaSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CComponentPlacementRestrictionAreaSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComponentPlacementRestrictionAreaSheet)
	public:
	//}}AFX_VIRTUAL

// Implementation
public:
	void setReadOnly(BOOL mode);
	virtual void setValues(PWBDataBase *PWB, MountingRestrictionArea *mra);
  
   // area data
   CComponentPlacementRestrictionAreaPage m_mraPage;
   CSingleComponentRestrictionAssignmentPage m_craPage;

	virtual ~CComponentPlacementRestrictionAreaSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CComponentPlacementRestrictionAreaSheet)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	PWBDataBase *Database;
	MountingRestrictionArea * MountingRestrictionAreaRef;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMPONENTPLACEMENTRESTRICTIONAREASHEET_H__4279F622_0015_11D5_8A9A_0080AD428934__INCLUDED_)
