#if !defined(AFX_COMPONENTPLACEMENTRESTRICTIONAREAPAGE_H__4279F624_0015_11D5_8A9A_0080AD428934__INCLUDED_)
#define AFX_COMPONENTPLACEMENTRESTRICTIONAREAPAGE_H__4279F624_0015_11D5_8A9A_0080AD428934__INCLUDED_

#include "SDAI\MountingRestrictionArea.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ComponentPlacementRestrictionAreaPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CComponentPlacementRestrictionAreaPage dialog

class CComponentPlacementRestrictionAreaPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CComponentPlacementRestrictionAreaPage)

// Construction
public:
	void setReadOnly(BOOL mode);
	void setValues(SdaiModel AP210Model, MountingRestrictionArea *mra);
	CComponentPlacementRestrictionAreaPage();
	~CComponentPlacementRestrictionAreaPage();

// Dialog Data
	//{{AFX_DATA(CComponentPlacementRestrictionAreaPage)
	enum { IDD = IDD_COMPONENT_PLACEMENT_RESTRICTION_PAGE };
	CEdit	m_editRefDes;
	CComboBox	m_editSurface;
	CButton	m_editPlacementFixed;
	CEdit	m_editY;
	CEdit	m_editX;
	double	m_X;
	double	m_Y;
	BOOL	m_PlacementFixed;
	CString	m_Surface;
	CString	m_RefDes;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CComponentPlacementRestrictionAreaPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CComponentPlacementRestrictionAreaPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnGeneralPlacementFixed();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	BOOL ReadOnly;
	MountingRestrictionArea *MountingRestrictionAreaRef;
	void setValues();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMPONENTPLACEMENTRESTRICTIONAREAPAGE_H__4279F624_0015_11D5_8A9A_0080AD428934__INCLUDED_)
