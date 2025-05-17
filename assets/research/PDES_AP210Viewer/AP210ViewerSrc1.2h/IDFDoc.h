#if !defined(AFX_IDFDOC_H__891B4424_5E4B_11D3_9B0E_0080AD428934__INCLUDED_)
#define AFX_IDFDOC_H__891B4424_5E4B_11D3_9B0E_0080AD428934__INCLUDED_

#include "AP210ViewerDoc.h"

// ExpressX stuff
#include <expx/expx.h>
#include "express_parse_schema_ROSE_LOAD.h"
#include "ignorestruct.h"

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// IDFDoc.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIDFDoc document

class CIDFDoc :
   public CAP210ViewerDoc
{
protected:
	CIDFDoc();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CIDFDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIDFDoc)
	public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
   virtual ~CIDFDoc();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CIDFDoc)
	afx_msg void OnFileProperties();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Custom Implementation
private:
	SdaiModel IDFModel;

// ExpressX stuff
private:
   SchemaMap *sm_idf2arm;
   SchemaMap *sm_arm2aim;
   RoseDesign *arm_targ;
   RoseDesign *aim_targ;

public:
	int CreateAP210Aim(char *dir, char *name);
   int CreateAP210Arm(char *dir, char *name);
   void run_mapping(SchemaMap * the_sm, int view_cnt);


public:   
   virtual BOOL DoSave(LPCTSTR lpszPathName, BOOL bReplace);
   };

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IDFDOC_H__891B4424_5E4B_11D3_9B0E_0080AD428934__INCLUDED_)
