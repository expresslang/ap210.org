// AP210ViewerDoc.h : interface of the CAP210ViewerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AP210VIEWERDOC_H__9BE7D70D_0912_11D3_9B0D_0080AD428934__INCLUDED_)
#define AFX_AP210VIEWERDOC_H__9BE7D70D_0912_11D3_9B0D_0080AD428934__INCLUDED_

#include "SDAI\AP210ObjectList.h"	// Added by ClassView
#include "PWBDataBase.h"

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CAP210ViewerDoc :
   public PWBDataBase
{
friend class CAP210ViewerView;

protected: // create from serialization only
	CAP210ViewerDoc();
	DECLARE_DYNCREATE(CAP210ViewerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAP210ViewerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void OnCloseDocument();
	//}}AFX_VIRTUAL


// Implementation
	virtual ~CAP210ViewerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
    // Overides for STEP
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);


// Generated message map functions
protected:
	//{{AFX_MSG(CAP210ViewerDoc)
	afx_msg void OnFileProperties();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Custom Implementation
private:
	void closeAP210Model(CString name);

protected:
	virtual BOOL BuildDisplayModel(LPCTSTR lpszPathName);
	PackagedComponent * BuildPackagedComponent(SdaiAppInstance PWApu, SdaiAppInstance pc);
	ComponentDefinition * BuildMechanicalComponent(SdaiAppInstance PWApu, SdaiAppInstance pc);
	void BuildComponents();
	virtual void SetPartNumber(PackagedComponent *pc);


public:
   virtual BOOL DoSave(LPCTSTR lpszPathName, BOOL bReplace);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AP210VIEWERDOC_H__9BE7D70D_0912_11D3_9B0D_0080AD428934__INCLUDED_)
