// NonPlatedThruHolePage.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "NonPlatedThruHolePage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNonPlatedThruHolePage property page

IMPLEMENT_DYNCREATE(CNonPlatedThruHolePage, CPropertyPage)

CNonPlatedThruHolePage::CNonPlatedThruHolePage() : CPropertyPage(CNonPlatedThruHolePage::IDD) {
	EnableAutomation();
	//{{AFX_DATA_INIT(CNonPlatedThruHolePage)
	m_X = 0.0;
	m_Y = 0.0;
	m_PlacementFixed = FALSE;
	m_RefDes = _T("");
	//}}AFX_DATA_INIT

   ReadOnly = TRUE;
   }

CNonPlatedThruHolePage::~CNonPlatedThruHolePage()
{
}

void CNonPlatedThruHolePage::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CPropertyPage::OnFinalRelease();
}

void CNonPlatedThruHolePage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNonPlatedThruHolePage)
	DDX_Control(pDX, IDC_GENERAL_REFDES_VALUE, m_editRefDes);
	DDX_Control(pDX, IDC_GENERAL_PLACEMENT_FIXED, m_editPlacementFixed);
	DDX_Control(pDX, IDC_GENERAL_LOCATION_Y_VALUE, m_editY);
	DDX_Control(pDX, IDC_GENERAL_LOCATION_X_VALUE, m_editX);
	DDX_Text(pDX, IDC_GENERAL_LOCATION_X_VALUE, m_X);
	DDX_Text(pDX, IDC_GENERAL_LOCATION_Y_VALUE, m_Y);
	DDX_Check(pDX, IDC_GENERAL_PLACEMENT_FIXED, m_PlacementFixed);
	DDX_Text(pDX, IDC_GENERAL_REFDES_VALUE, m_RefDes);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNonPlatedThruHolePage, CPropertyPage)
	//{{AFX_MSG_MAP(CNonPlatedThruHolePage)
	ON_EN_CHANGE(IDC_GENERAL_LOCATION_X_VALUE, OnChangeGeneralLocationXValue)
	ON_EN_CHANGE(IDC_GENERAL_LOCATION_Y_VALUE, OnChangeGeneralLocationYValue)
	ON_EN_CHANGE(IDC_GENERAL_REFDES_VALUE, OnChangeGeneralRefdesValue)
	ON_BN_CLICKED(IDC_GENERAL_PLACEMENT_FIXED, OnGeneralPlacementFixed)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CNonPlatedThruHolePage, CPropertyPage)
	//{{AFX_DISPATCH_MAP(CNonPlatedThruHolePage)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_INonPlatedThruHolePage to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {DD02EDC9-F163-11D4-8A9A-0080AD428934}
static const IID IID_INonPlatedThruHolePage =
{ 0xdd02edc9, 0xf163, 0x11d4, { 0x8a, 0x9a, 0x0, 0x80, 0xad, 0x42, 0x89, 0x34 } };

BEGIN_INTERFACE_MAP(CNonPlatedThruHolePage, CPropertyPage)
	INTERFACE_PART(CNonPlatedThruHolePage, IID_INonPlatedThruHolePage, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNonPlatedThruHolePage message handlers

void CNonPlatedThruHolePage::setValues(SdaiModel AP210Model, NonPlatedThruHole *npth){
   NonPlatedThruHoleRef = npth;
   setValues();
   }
void CNonPlatedThruHolePage::setValues() {
   // Reference Designator
   m_RefDes = NonPlatedThruHoleRef->getId();

   // location 
   m_PlacementFixed = NonPlatedThruHoleRef->getPlacementFixed();
   m_X = NonPlatedThruHoleRef->getX();
   m_Y = NonPlatedThruHoleRef->getY();
   }   
void CNonPlatedThruHolePage::setReadOnly(BOOL mode) {
   ReadOnly = mode;
   }


void CNonPlatedThruHolePage::OnChangeGeneralLocationXValue() {
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
   SetModified(TRUE);
   }

void CNonPlatedThruHolePage::OnChangeGeneralLocationYValue() {
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
   SetModified(TRUE);
   }

void CNonPlatedThruHolePage::OnChangeGeneralRefdesValue() {
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
   SetModified(TRUE);
   }

void CNonPlatedThruHolePage::OnGeneralPlacementFixed() {
	// TODO: Add your control notification handler code here
   int checked = m_editPlacementFixed.GetCheck();

   // if checked revert location to current values,
   //    or later disable if modified!
   if (checked) {
      CString scratch;
      scratch.Format("%f", NonPlatedThruHoleRef->getX());
      m_editX.SetWindowText(scratch);
      scratch.Format("%f", NonPlatedThruHoleRef->getX());
      m_editY.SetWindowText(scratch);
      }
   // set proper state of location edit controls.
   m_editX.SetReadOnly(checked);
   m_editX.Invalidate();
   m_editX.RedrawWindow();

   m_editY.SetReadOnly(checked);
   m_editY.Invalidate();
   m_editY.RedrawWindow();

   SetModified(TRUE);	
   }

BOOL CNonPlatedThruHolePage::OnInitDialog() {
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	// TODO: Add extra initialization here
   if (ReadOnly == FALSE) {
      // if the placement is fixed you can't edit it.
      m_editX.SetReadOnly(m_PlacementFixed);
      m_editY.SetReadOnly(m_PlacementFixed);
      }
   else {
      // don't allow editing
      m_editPlacementFixed.EnableWindow(FALSE);
      m_editX.SetReadOnly(TRUE);
      m_editY.SetReadOnly(TRUE);
      m_editRefDes.SetReadOnly(TRUE);
      }	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
   }

BOOL CNonPlatedThruHolePage::OnApply() {
	// TODO: Add your specialized code here and/or call the base class
   NonPlatedThruHoleRef->setPlacementFixed(m_PlacementFixed);
   NonPlatedThruHoleRef->setId(m_RefDes);

   // Only change the location for unfixed components.
   if (NonPlatedThruHoleRef->getPlacementFixed() == FALSE) {
      NonPlatedThruHoleRef->setX(m_X);
      NonPlatedThruHoleRef->setY(m_Y);
      NonPlatedThruHoleRef->UpdateAllViews(NULL);
      }
   setValues();
	
	return CPropertyPage::OnApply();
   }
