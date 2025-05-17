#if !defined(AFX_SINGLECOMPONENTRESTRICTIONASSIGNMENTPAGE_H__EEC532C1_1940_11D5_8A9A_0080AD428934__INCLUDED_)
#define AFX_SINGLECOMPONENTRESTRICTIONASSIGNMENTPAGE_H__EEC532C1_1940_11D5_8A9A_0080AD428934__INCLUDED_

#include "SDAI\MountingRestrictionArea.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SingleComponentRestrictionAssignmentPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSingleComponentRestrictionAssignmentPage dialog

class CSingleComponentRestrictionAssignmentPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CSingleComponentRestrictionAssignmentPage)

// Construction
public:
	CSingleComponentRestrictionAssignmentPage();
	~CSingleComponentRestrictionAssignmentPage();

// Dialog Data
	//{{AFX_DATA(CSingleComponentRestrictionAssignmentPage)
	enum { IDD = IDD_SINGLE_COMPONENT_PLACEMENT_RESTRICTION };
	CEdit	m_editHeight;
	double	m_Height;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSingleComponentRestrictionAssignmentPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	void setReadOnly(BOOL mode);
	void setValues(PWBDataBase *PWB, MountingRestrictionArea *mra);
protected:
	// Generated message map functions
	//{{AFX_MSG(CSingleComponentRestrictionAssignmentPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeCraHeightValue();
	afx_msg void OnCraOpaque();
	afx_msg void OnCraInvisible();
	afx_msg void OnCraTransparent();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL ReadOnly;
	MountingRestrictionArea *MountingRestrictionAreaRef;
	PWBDataBase *Database;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGLECOMPONENTRESTRICTIONASSIGNMENTPAGE_H__EEC532C1_1940_11D5_8A9A_0080AD428934__INCLUDED_)
