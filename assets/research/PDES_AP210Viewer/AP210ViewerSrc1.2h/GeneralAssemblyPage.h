#if !defined(AFX_GENERALASSEMBLYPAGE_H__94E6ED31_655F_4E09_AD18_BC4381B30AF9__INCLUDED_)
#define AFX_GENERALASSEMBLYPAGE_H__94E6ED31_655F_4E09_AD18_BC4381B30AF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GeneralAssemblyPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGeneralAssemblyPage dialog

class CGeneralAssemblyPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CGeneralAssemblyPage)

// Construction
public:
	CGeneralAssemblyPage();
	~CGeneralAssemblyPage();

// Dialog Data
	//{{AFX_DATA(CGeneralAssemblyPage)
	enum { IDD = IDD_GENERAL_ASSEMBLY };
	CEdit	m_editId;
	CString	m_Id;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CGeneralAssemblyPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CGeneralAssemblyPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GENERALASSEMBLYPAGE_H__94E6ED31_655F_4E09_AD18_BC4381B30AF9__INCLUDED_)
