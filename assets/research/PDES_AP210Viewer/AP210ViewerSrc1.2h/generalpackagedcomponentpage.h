#if !defined(AFX_GENERALPACKAGEDCOMPONENTPAGE_H__7BFC59A7_DBDC_11D3_8A99_0080AD428934__INCLUDED_)
#define AFX_GENERALPACKAGEDCOMPONENTPAGE_H__7BFC59A7_DBDC_11D3_8A99_0080AD428934__INCLUDED_

#include "Sdai/ComponentDefinition.h"
#include "SDAI/PackagedComponent.h"	// Added by ClassView

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// GeneralPackagedComponentPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGeneralPackagedComponentPage dialog

class CGeneralPackagedComponentPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CGeneralPackagedComponentPage)

// Construction
public:
	CGeneralPackagedComponentPage(UINT nIDCaption = 0 );
	~CGeneralPackagedComponentPage();

// Dialog Data
	//{{AFX_DATA(CGeneralPackagedComponentPage)
	enum { IDD = IDD_GENERAL_PACKAGED_COMPONENT };
	CComboBox	m_editSurface;
	CEdit	m_editRotation;
	CString	m_PartNumber;
	CString	m_RefDes;
	CButton	m_editPlacementFixed;
	BOOL	m_PlacementFixed;
	CEdit	m_editX;
	CEdit	m_editY;
	UINT	m_ItemFindNumber;
	double	m_Rotation;
	CString	m_Surface;
	double	m_X;
	double	m_Y;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CGeneralPackagedComponentPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CGeneralPackagedComponentPage)
	afx_msg void OnGeneralPlacementFixed();
	afx_msg void OnChangeGeneralLocationXValue();
	afx_msg void OnChangeGeneralLocationYValue();
	virtual BOOL OnInitDialog();
	afx_msg void OnChangePackagedComponentRotationValue();
	afx_msg void OnSelchangePackagedComponentSurface();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	void setReadOnly(BOOL mode);
	void setValues(SdaiModel AP210Model, ComponentDefinition *pc);
private:
	void setValues();
	BOOL ReadOnly;
	ComponentDefinition *ComponentDefinitionRef;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GENERALPACKAGEDCOMPONENTPAGE_H__7BFC59A7_DBDC_11D3_8A99_0080AD428934__INCLUDED_)
