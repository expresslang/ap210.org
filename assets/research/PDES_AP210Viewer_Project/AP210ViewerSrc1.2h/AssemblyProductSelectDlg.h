#if !defined(AFX_ASSEMBLYPRODUCTSELECTDLG_H__E58C778A_163A_11D5_8A9A_0080AD428934__INCLUDED_)
#define AFX_ASSEMBLYPRODUCTSELECTDLG_H__E58C778A_163A_11D5_8A9A_0080AD428934__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AssemblyProductSelectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAssemblyProductSelectDlg dialog

class CAssemblyProductSelectDlg : public CDialog
{
// Construction
public:
	void setValues(SdaiModel AP210Model, SdaiNPL prods);
	CAssemblyProductSelectDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAssemblyProductSelectDlg)
	enum { IDD = IDD_ASSEMBLY_PRODUCT_SELECT };
	CListBox	m_controlAssemblyProduct;
	CString	m_AssemblyProduct;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAssemblyProductSelectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAssemblyProductSelectDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	SdaiModel ModelRef;
	SdaiNPL products;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASSEMBLYPRODUCTSELECTDLG_H__E58C778A_163A_11D5_8A9A_0080AD428934__INCLUDED_)
