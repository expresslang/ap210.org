#if !defined(AFX_GENERALPACKAGEPAGE_H__5066CC83_ED2A_11D3_8A99_0080AD428934__INCLUDED_)
#define AFX_GENERALPACKAGEPAGE_H__5066CC83_ED2A_11D3_8A99_0080AD428934__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// GeneralPackagePage.h : header file
//
#include "Sdai/Package.h"

/////////////////////////////////////////////////////////////////////////////
// CGeneralPackagePage dialog

class CGeneralPackagePage : public CPropertyPage
{
	DECLARE_DYNCREATE(CGeneralPackagePage)

// Construction
public:
	virtual void setReadOnly(BOOL mode);
	virtual void setValues(SdaiModel AP210Model, PhysicalUnit *pu);
	CGeneralPackagePage(UINT nIDCaption = 0);
	~CGeneralPackagePage();

// Dialog Data
	//{{AFX_DATA(CGeneralPackagePage)
	enum { IDD = IDD_GENERAL_PACKAGE };
	CEdit	m_editHeight;
	CString	m_PackageName;
	double	m_Height;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CGeneralPackagePage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CGeneralPackagePage)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeGeneralHeightValue();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	PhysicalUnit *PhysicalUnitRef;
	BOOL ReadOnly;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GENERALPACKAGEPAGE_H__5066CC83_ED2A_11D3_8A99_0080AD428934__INCLUDED_)
