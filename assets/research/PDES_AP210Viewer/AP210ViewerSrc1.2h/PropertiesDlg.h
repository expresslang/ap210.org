#if !defined(AFX_PROPERTIESDLG_H__D3D43882_C68F_11D3_8A99_0080AD428934__INCLUDED_)
#define AFX_PROPERTIESDLG_H__D3D43882_C68F_11D3_8A99_0080AD428934__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PropertiesDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropertiesDlg dialog

class CPropertiesDlg : public CDialog
{
// Construction
public:
	CPropertiesDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPropertiesDlg)
	enum { IDD = IDD_PROPERTIESBOX };
	CString	m_name;
	CString	m_description;
	CString	m_implementation_level;
	CString	m_author;
	CString	m_authorisation;
	CString	m_organization;
	CString	m_originating_system;
	CString	m_preprocessor_version;
	CString	m_time_stamp;
	CString	m_schema_name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropertiesDlg)
	public:
	virtual void OnFinalRelease();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPropertiesDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CPropertiesDlg)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPERTIESDLG_H__D3D43882_C68F_11D3_8A99_0080AD428934__INCLUDED_)
