#if !defined(AFX_NONPLATEDTHRUHOLESHEET_H__DD02EDC6_F163_11D4_8A9A_0080AD428934__INCLUDED_)
#define AFX_NONPLATEDTHRUHOLESHEET_H__DD02EDC6_F163_11D4_8A9A_0080AD428934__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NonPlatedThruHoleSheet.h : header file
//
#include "NonPlatedThruHolePage.h"
#include "sdai\NonPlatedThruHole.h"

/////////////////////////////////////////////////////////////////////////////
// CNonPlatedThruHoleSheet

class CNonPlatedThruHoleSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CNonPlatedThruHoleSheet)

// Construction
public:
	CNonPlatedThruHoleSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CNonPlatedThruHoleSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNonPlatedThruHoleSheet)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual void setValues(SdaiModel AP210Model, NonPlatedThruHole *npth);
	void setReadOnly(BOOL mode);
  
   // hole data
   CNonPlatedThruHolePage m_npthPage;
	virtual ~CNonPlatedThruHoleSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CNonPlatedThruHoleSheet)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CNonPlatedThruHoleSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NONPLATEDTHRUHOLESHEET_H__DD02EDC6_F163_11D4_8A9A_0080AD428934__INCLUDED_)
