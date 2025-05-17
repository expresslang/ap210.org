#if !defined(AFX_AP210PRODVIEW_H__2621DC81_BBE3_11D3_8A99_0080AD428934__INCLUDED_)
#define AFX_AP210PRODVIEW_H__2621DC81_BBE3_11D3_8A99_0080AD428934__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// AP210ProdView.h : header file
//
#include <afxcview.h>

/////////////////////////////////////////////////////////////////////////////
// CAP210ProdView view
class PWBDataBase;

class CAP210ProdView : public CTreeView
{
protected:
	CAP210ProdView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CAP210ProdView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAP210ProdView)
	public:
	virtual void OnInitialUpdate();
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CAP210ProdView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CAP210ProdView)
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnComponentRestrictionArea();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void populatePackagesTree(PWBDataBase *pDoc,
                             TV_INSERTSTRUCT tvstruct,
                             CTreeCtrl &TreeCtrl);
	void populatePhysicalUnitTree(PWBDataBase *pDoc,
                                 TV_INSERTSTRUCT tvstruct,
                                 CTreeCtrl &TreeCtrl);
	void populatePackagedPartTree(PWBDataBase *pDoc,
                                 TV_INSERTSTRUCT tvstruct,
                                 CTreeCtrl &TreeCtrl);
	void populateAssemblyTree(PWBDataBase *pDoc,
                             TV_INSERTSTRUCT tvstruct,
                             CTreeCtrl &TreeCtrl);
	void populateMountingRestrictionAreaTree(PWBDataBase *pDoc,
                                            TV_INSERTSTRUCT tvstruct,
                                            CTreeCtrl &TreeCtrl);
	void populateNonPlatedThruHoleTree(PWBDataBase *pDoc,
                                      TV_INSERTSTRUCT tvstruct,
                                      CTreeCtrl &TreeCtrl);
	CImageList *pImageList;
	HTREEITEM PackagesTreeItem;
	HTREEITEM PackagedPartsTreeItem;
	HTREEITEM AssemblyTreeItem;
	HTREEITEM UnPlacedComponentTreeItem;
	HTREEITEM PhysicalUnitsTreeItem;
	HTREEITEM MountingRestrictionAreaItem;
	HTREEITEM NonPlatedThruHoleItem;
public:
	void UpdateTree();
	void PopulateTree();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AP210PRODVIEW_H__2621DC81_BBE3_11D3_8A99_0080AD428934__INCLUDED_)
