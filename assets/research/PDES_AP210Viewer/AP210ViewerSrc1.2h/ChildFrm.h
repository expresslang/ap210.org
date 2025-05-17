// ChildFrm.h : interface of the CChildFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDFRM_H__9BE7D70B_0912_11D3_9B0D_0080AD428934__INCLUDED_)
#define AFX_CHILDFRM_H__9BE7D70B_0912_11D3_9B0D_0080AD428934__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "AP210SplitWnd.h"
#include "AP210ProdView.h"
class CChildFrame : public CMDIChildWnd {
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame();

// Attributes
 protected:
	CAP210SplitWnd m_wndSplitter;
 
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  c_wndStatusBar;
   afx_msg void OnUpdateRefDes(CCmdUI *pCmdUI);
   afx_msg void OnUpdatePartNumber(CCmdUI *pCmdUI);

// Generated message map functions
protected:
	//{{AFX_MSG(CChildFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDFRM_H__9BE7D70B_0912_11D3_9B0D_0080AD428934__INCLUDED_)
