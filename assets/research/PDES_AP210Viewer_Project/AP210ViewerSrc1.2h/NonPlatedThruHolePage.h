#if !defined(AFX_NONPLATEDTHRUHOLEPAGE_H__DD02EDCA_F163_11D4_8A9A_0080AD428934__INCLUDED_)
#define AFX_NONPLATEDTHRUHOLEPAGE_H__DD02EDCA_F163_11D4_8A9A_0080AD428934__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NonPlatedThruHolePage.h : header file
//
#include "sdai\NonPlatedThruHole.h"

/////////////////////////////////////////////////////////////////////////////
// CNonPlatedThruHolePage dialog

class CNonPlatedThruHolePage : public CPropertyPage
{
	DECLARE_DYNCREATE(CNonPlatedThruHolePage)

// Construction
public:
	void setValues(SdaiModel AP210Model, NonPlatedThruHole *npth);
	void setReadOnly(BOOL mode);
	CNonPlatedThruHolePage();
	~CNonPlatedThruHolePage();

// Dialog Data
	//{{AFX_DATA(CNonPlatedThruHolePage)
	enum { IDD = IDD_NON_PLATED_THRU_HOLE };
	CEdit	m_editRefDes;
	CButton	m_editPlacementFixed;
	CEdit	m_editY;
	CEdit	m_editX;
	double	m_X;
	double	m_Y;
	BOOL	m_PlacementFixed;
	CString	m_RefDes;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CNonPlatedThruHolePage)
	public:
	virtual void OnFinalRelease();
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CNonPlatedThruHolePage)
	afx_msg void OnChangeGeneralLocationXValue();
	afx_msg void OnChangeGeneralLocationYValue();
	afx_msg void OnChangeGeneralRefdesValue();
	afx_msg void OnGeneralPlacementFixed();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CNonPlatedThruHolePage)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
private:
	void setValues();
	NonPlatedThruHole *NonPlatedThruHoleRef;
	BOOL ReadOnly;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NONPLATEDTHRUHOLEPAGE_H__DD02EDCA_F163_11D4_8A9A_0080AD428934__INCLUDED_)
