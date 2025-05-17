#if !defined(AFX_PROPERTIESPAGE_H__7BFC59A8_DBDC_11D3_8A99_0080AD428934__INCLUDED_)
#define AFX_PROPERTIESPAGE_H__7BFC59A8_DBDC_11D3_8A99_0080AD428934__INCLUDED_

#include "SDAI\PackagedComponent.h"	// Added by ClassView
#include "SDAI\PackagedPart.h"	// Added by ClassView

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PropertiesPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropertiesPage dialog

class CPropertiesPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CPropertiesPage)

// Construction
public:
	CPropertiesPage();
	~CPropertiesPage();

// Dialog Data
	//{{AFX_DATA(CPropertiesPage)
	enum { IDD = IDD_PROPERTIES };
	CListCtrl	m_properties;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPropertiesPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPropertiesPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	void setValues(SdaiModel AP210Model, PhysicalUnit *pu);
	void setValues(SdaiModel AP210Model, ComponentDefinition *cd);
	void setValues(SdaiModel AP210Model, PackagedPart *packagedpart);
protected:
	void getProperties();
	SdaiAppInstance PropertyOwner;
	SdaiModel ModelRef;
	BOOL DataSet;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPERTIESPAGE_H__7BFC59A8_DBDC_11D3_8A99_0080AD428934__INCLUDED_)
