#if !defined(AFX_AP210SPLITWND_H__21AA2BE5_BC37_11D3_8A99_0080AD428934__INCLUDED_)
#define AFX_AP210SPLITWND_H__21AA2BE5_BC37_11D3_8A99_0080AD428934__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// AP210SplitWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAP210SplitWnd window

class CAP210SplitWnd : public CSplitterWnd
{
// Construction
public:
	CAP210SplitWnd();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAP210SplitWnd)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAP210SplitWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CAP210SplitWnd)
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AP210SPLITWND_H__21AA2BE5_BC37_11D3_8A99_0080AD428934__INCLUDED_)
