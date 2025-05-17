#if !defined(AFX_GENERALINTERCONNECTMODULEPAGE_H__AA8ED081_F145_11D3_8A99_0080AD428934__INCLUDED_)
#define AFX_GENERALINTERCONNECTMODULEPAGE_H__AA8ED081_F145_11D3_8A99_0080AD428934__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// GeneralInterconnectModulePage.h : header file
//
#include "SDAI/BoardComponent.h"	// Added by ClassView

/////////////////////////////////////////////////////////////////////////////
// CGeneralInterconnectModulePage dialog

class CGeneralInterconnectModulePage : public CPropertyPage
{
	DECLARE_DYNCREATE(CGeneralInterconnectModulePage)

// Construction
public:
	CGeneralInterconnectModulePage();
	~CGeneralInterconnectModulePage();

// Dialog Data
	//{{AFX_DATA(CGeneralInterconnectModulePage)
	enum { IDD = IDD_GENERAL_INTERCONNECT_MODULE };
	CEdit	m_editName;
	CString	m_Name;
	BOOL	m_Transparent;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CGeneralInterconnectModulePage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	void setValues(SdaiModel AP210Module, BoardComponent *bc);
	void setReadOnly(BOOL mode);

protected:
	// Generated message map functions
	//{{AFX_MSG(CGeneralInterconnectModulePage)
	afx_msg void OnGeneralInterconnectModuleTransparentValue();
	afx_msg void OnChangeGeneralInterconnectModuleNameValue();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	BOOL ReadOnly;
	BoardComponent * InterconnectModuleRef;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GENERALINTERCONNECTMODULEPAGE_H__AA8ED081_F145_11D3_8A99_0080AD428934__INCLUDED_)
