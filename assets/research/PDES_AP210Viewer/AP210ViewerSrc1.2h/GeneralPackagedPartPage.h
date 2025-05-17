#if !defined(AFX_GENERALPACKAGEDPARTPAGE_H__D5171883_E95C_11D3_8A99_0080AD428934__INCLUDED_)
#define AFX_GENERALPACKAGEDPARTPAGE_H__D5171883_E95C_11D3_8A99_0080AD428934__INCLUDED_


#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// GeneralPackagedPartPage.h : header file
//
#include "Sdai/PackagedPart.h"
#include "SDAI\PackagedPart.h"	// Added by ClassView

/////////////////////////////////////////////////////////////////////////////
// CGeneralPackagedPartPage dialog

class CGeneralPackagedPartPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CGeneralPackagedPartPage)

// Construction
public:
	void setValues(SdaiModel AP210Model, PackagedPart *packagedpart);
	CGeneralPackagedPartPage();
	~CGeneralPackagedPartPage();

// Dialog Data
	//{{AFX_DATA(CGeneralPackagedPartPage)
	enum { IDD = IDD_GENERAL_PACKAGED_PART };
	CString	m_PartNumber;
	UINT	m_ItemFindNumber;
	UINT	m_Quantity;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CGeneralPackagedPartPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CGeneralPackagedPartPage)
	afx_msg void OnChangeGeneralHeightValue();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	PackagedPart *PackagedPartRef;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GENERALPACKAGEDPARTPAGE_H__D5171883_E95C_11D3_8A99_0080AD428934__INCLUDED_)
