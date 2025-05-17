#if !defined(AFX_INTERCONNECTMODULEUSAGEVIEWPAGE_H__93CD6C82_C561_11D4_8A9A_0080AD428934__INCLUDED_)
#define AFX_INTERCONNECTMODULEUSAGEVIEWPAGE_H__93CD6C82_C561_11D4_8A9A_0080AD428934__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InterconnectModuleUsageViewPage.h : header file
//
#include "SDAI/BoardComponent.h"	// Added by ClassView

/////////////////////////////////////////////////////////////////////////////
// CInterconnectModuleUsageViewPage dialog

class CInterconnectModuleUsageViewPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CInterconnectModuleUsageViewPage)

// Construction
public:
	CInterconnectModuleUsageViewPage();
	~CInterconnectModuleUsageViewPage();

// Dialog Data
	//{{AFX_DATA(CInterconnectModuleUsageViewPage)
	enum { IDD = IDD_INTERCONNECT_MODULE_USAGE_VIEW };
	CButton	m_usedThicknessRequirement;
	CButton	m_editsetMinimumOverMetal;
	CButton	m_editsetMinimumOverDielectric;
	CButton	m_editsetMaximumOverMetal;
	CButton	m_editsetMaximumOverDielectric;
	CButton	m_editsetLocatedThickness;
	CEdit	m_editMinimumOverMetal;
	CEdit	m_editMinimumOverDielectric;
	CEdit	m_editMaximumOverMetal;
	CEdit	m_editMaximumOverDielectric;
	CEdit	m_editLocatedThickness;
	BOOL	m_setMinimumOverMetal;
	BOOL	m_setMaximumOverDielectric;
	BOOL	m_setMaximumOverMetal;
	BOOL	m_setMinimumOverDielectric;
	BOOL	m_setLocatedThickness;
	double	m_LocatedThickness;
	double	m_MaximumOverDialectric;
	double	m_MinimumValueOverMetal;
	double	m_MinimumOverDielectric;
	double	m_MinimumOverMetal;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CInterconnectModuleUsageViewPage)
	public:
	virtual void OnFinalRelease();
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	void setReadOnly(BOOL mode);
	void setValues(SdaiModel AP210Module, BoardComponent *bc);

protected:
	// Generated message map functions
	//{{AFX_MSG(CInterconnectModuleUsageViewPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeLocatedThicknessValue();
	afx_msg void OnLocatedThickness();
	afx_msg void OnMaximumOverDielectric();
	afx_msg void OnMaximumOverMetal();
	afx_msg void OnMinimumOverDielectric();
	afx_msg void OnMinimumOverMetal();
	afx_msg void OnUseLocatedThickness();
	afx_msg void OnUseMaximumOverDielectric();
	afx_msg void OnUseMaximumOverMetal();
	afx_msg void OnUseMinimumOverDielectric();
	afx_msg void OnUseMinimumOverMetal();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CInterconnectModuleUsageViewPage)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

private:
	void setRequirementCheckBox(CButton *checkbox, BOOL *value);
	int getNumberOfSetThicknesses();
	BoardComponent * InterconnectModuleRef;
	BOOL ReadOnly;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INTERCONNECTMODULEUSAGEVIEWPAGE_H__93CD6C82_C561_11D4_8A9A_0080AD428934__INCLUDED_)
