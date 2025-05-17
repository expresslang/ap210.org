#if !defined(AFX_COMPONENTPLACEMENTRESTRICTION_H__E89B2D65_B990_11D4_8A9A_0080AD428934__INCLUDED_)
#define AFX_COMPONENTPLACEMENTRESTRICTION_H__E89B2D65_B990_11D4_8A9A_0080AD428934__INCLUDED_

#include "PWBDataBase.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ComponentPlacementRestriction.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CComponentPlacementRestriction dialog

class CComponentPlacementRestriction : public CDialog
{
// Construction
public:
	void setValues(PWBDataBase *PWB);
	CComponentPlacementRestriction(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CComponentPlacementRestriction)
	enum { IDD = IDD_COMPONENT_PLACEMENT_RESTRICTION };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComponentPlacementRestriction)
	public:
	virtual void OnFinalRelease();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CComponentPlacementRestriction)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CComponentPlacementRestriction)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
private:
	PWBDataBase *Database;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMPONENTPLACEMENTRESTRICTION_H__E89B2D65_B990_11D4_8A9A_0080AD428934__INCLUDED_)
