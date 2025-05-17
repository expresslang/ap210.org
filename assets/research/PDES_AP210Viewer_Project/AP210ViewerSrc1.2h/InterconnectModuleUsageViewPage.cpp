// InterconnectModuleUsageViewPage.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "InterconnectModuleUsageViewPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInterconnectModuleUsageViewPage property page

IMPLEMENT_DYNCREATE(CInterconnectModuleUsageViewPage, CPropertyPage)

CInterconnectModuleUsageViewPage::CInterconnectModuleUsageViewPage() : CPropertyPage(CInterconnectModuleUsageViewPage::IDD)
{
	EnableAutomation();
	//{{AFX_DATA_INIT(CInterconnectModuleUsageViewPage)
	m_setMinimumOverMetal = FALSE;
	m_setMaximumOverDielectric = FALSE;
	m_setMaximumOverMetal = FALSE;
	m_setMinimumOverDielectric = FALSE;
	m_setLocatedThickness = FALSE;
	m_LocatedThickness = 0.0;
	m_MaximumOverDialectric = 0.0;
	m_MinimumValueOverMetal = 0.0;
	m_MinimumOverDielectric = 0.0;
	m_MinimumOverMetal = 0.0;
	//}}AFX_DATA_INIT
}

CInterconnectModuleUsageViewPage::~CInterconnectModuleUsageViewPage()
{
}

void CInterconnectModuleUsageViewPage::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CPropertyPage::OnFinalRelease();
}

void CInterconnectModuleUsageViewPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInterconnectModuleUsageViewPage)
	DDX_Control(pDX, IDC_THICKNESS_REQUIREMENTS, m_usedThicknessRequirement);
	DDX_Control(pDX, IDC_MINIMUM_OVER_METAL, m_editsetMinimumOverMetal);
	DDX_Control(pDX, IDC_MINIMUM_OVER_DIELECTRIC, m_editsetMinimumOverDielectric);
	DDX_Control(pDX, IDC_MAXIMUM_OVER_METAL, m_editsetMaximumOverMetal);
	DDX_Control(pDX, IDC_MAXIMUM_OVER_DIELECTRIC, m_editsetMaximumOverDielectric);
	DDX_Control(pDX, IDC_LOCATED_THICKNESS, m_editsetLocatedThickness);
	DDX_Control(pDX, IDC_MINIMUM_OVER_METAL_VALUE, m_editMinimumOverMetal);
	DDX_Control(pDX, IDC_MINIMUM_OVER_DIELECTRIC_VALUE, m_editMinimumOverDielectric);
	DDX_Control(pDX, IDC_MAXIMUM_OVER_METAL_VALUE, m_editMaximumOverMetal);
	DDX_Control(pDX, IDC_MAXIMUM_OVER_DIELECTRIC_VALUE, m_editMaximumOverDielectric);
	DDX_Control(pDX, IDC_LOCATED_THICKNESS_VALUE, m_editLocatedThickness);
	DDX_Check(pDX, IDC_MINIMUM_OVER_METAL, m_setMinimumOverMetal);
	DDX_Check(pDX, IDC_MAXIMUM_OVER_DIELECTRIC, m_setMaximumOverDielectric);
	DDX_Check(pDX, IDC_MAXIMUM_OVER_METAL, m_setMaximumOverMetal);
	DDX_Check(pDX, IDC_MINIMUM_OVER_DIELECTRIC, m_setMinimumOverDielectric);
	DDX_Check(pDX, IDC_LOCATED_THICKNESS, m_setLocatedThickness);
	DDX_Text(pDX, IDC_LOCATED_THICKNESS_VALUE, m_LocatedThickness);
	DDX_Text(pDX, IDC_MAXIMUM_OVER_DIELECTRIC_VALUE, m_MaximumOverDialectric);
	DDX_Text(pDX, IDC_MAXIMUM_OVER_METAL_VALUE, m_MinimumValueOverMetal);
	DDX_Text(pDX, IDC_MINIMUM_OVER_DIELECTRIC_VALUE, m_MinimumOverDielectric);
	DDX_Text(pDX, IDC_MINIMUM_OVER_METAL_VALUE, m_MinimumOverMetal);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInterconnectModuleUsageViewPage, CPropertyPage)
	//{{AFX_MSG_MAP(CInterconnectModuleUsageViewPage)
	ON_EN_CHANGE(IDC_LOCATED_THICKNESS_VALUE, OnChangeLocatedThicknessValue)
	ON_BN_CLICKED(IDC_LOCATED_THICKNESS, OnLocatedThickness)
	ON_BN_CLICKED(IDC_MAXIMUM_OVER_DIELECTRIC, OnMaximumOverDielectric)
	ON_BN_CLICKED(IDC_MAXIMUM_OVER_METAL, OnMaximumOverMetal)
	ON_BN_CLICKED(IDC_MINIMUM_OVER_DIELECTRIC, OnMinimumOverDielectric)
	ON_BN_CLICKED(IDC_MINIMUM_OVER_METAL, OnMinimumOverMetal)
	ON_BN_CLICKED(IDC_USE_LOCATED_THICKNESS, OnUseLocatedThickness)
	ON_BN_CLICKED(IDC_USE_MAXIMUM_OVER_DIELECTRIC, OnUseMaximumOverDielectric)
	ON_BN_CLICKED(IDC_USE_MAXIMUM_OVER_METAL, OnUseMaximumOverMetal)
	ON_BN_CLICKED(IDC_USE_MINIMUM_OVER_DIELECTRIC, OnUseMinimumOverDielectric)
	ON_BN_CLICKED(IDC_USE_MINIMUM_OVER_METAL, OnUseMinimumOverMetal)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CInterconnectModuleUsageViewPage, CPropertyPage)
	//{{AFX_DISPATCH_MAP(CInterconnectModuleUsageViewPage)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IInterconnectModuleUsageViewPage to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {93CD6C81-C561-11D4-8A9A-0080AD428934}
static const IID IID_IInterconnectModuleUsageViewPage =
{ 0x93cd6c81, 0xc561, 0x11d4, { 0x8a, 0x9a, 0x0, 0x80, 0xad, 0x42, 0x89, 0x34 } };

BEGIN_INTERFACE_MAP(CInterconnectModuleUsageViewPage, CPropertyPage)
	INTERFACE_PART(CInterconnectModuleUsageViewPage, IID_IInterconnectModuleUsageViewPage, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInterconnectModuleUsageViewPage message handlers
// set what the readonly mode controls we may wish to edit.
void CInterconnectModuleUsageViewPage::setValues(SdaiModel AP210Module, BoardComponent *bc) {
   InterconnectModuleRef = bc;

   m_LocatedThickness = InterconnectModuleRef->getThickness();
   if (m_LocatedThickness > 0.0) {
      m_setLocatedThickness = TRUE;
      }
   }

void CInterconnectModuleUsageViewPage::setReadOnly(BOOL mode) {
   ReadOnly = mode;
   }

BOOL CInterconnectModuleUsageViewPage::OnInitDialog() {
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
   // set read only based on checkmarks
   m_editLocatedThickness.SetReadOnly(!m_editsetLocatedThickness.GetCheck());
   m_editMaximumOverDielectric.SetReadOnly(!m_editsetMaximumOverDielectric.GetCheck());
   m_editMaximumOverMetal.SetReadOnly(!m_editsetMaximumOverMetal.GetCheck());
   m_editMinimumOverDielectric.SetReadOnly(!m_editsetMinimumOverDielectric.GetCheck());
   m_editMinimumOverMetal.SetReadOnly(!m_editsetMinimumOverMetal.GetCheck());

   // set read only based on design.
   if (ReadOnly) {
      // set all the set widgets
      m_editsetLocatedThickness.EnableWindow(!ReadOnly);
      m_editsetMaximumOverDielectric.EnableWindow(!ReadOnly);
      m_editsetMaximumOverMetal.EnableWindow(!ReadOnly);
      m_editsetMinimumOverDielectric.EnableWindow(!ReadOnly);
      m_editsetMinimumOverMetal.EnableWindow(!ReadOnly);

      // set all the input widgets
      m_editLocatedThickness.SetReadOnly(ReadOnly);
      m_editMaximumOverDielectric.SetReadOnly(ReadOnly);
      m_editMaximumOverMetal.SetReadOnly(ReadOnly);
      m_editMinimumOverDielectric.SetReadOnly(ReadOnly);
      m_editMinimumOverMetal.SetReadOnly(ReadOnly);
	   }
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
   }

BOOL CInterconnectModuleUsageViewPage::OnApply() {
	// TODO: Add your specialized code here and/or call the base class
   InterconnectModuleRef->setThickness(m_LocatedThickness);
   InterconnectModuleRef->UpdateAllViews(NULL);
    	
	return CPropertyPage::OnApply();
   }

void CInterconnectModuleUsageViewPage::OnChangeLocatedThicknessValue() {
   // This was not required (MTK 11/29/00)!
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
   SetModified(TRUE);
  }

void CInterconnectModuleUsageViewPage::OnLocatedThickness() {
   // TODO: Add your control notification handler code here
   setRequirementCheckBox(&m_editsetLocatedThickness, &m_setLocatedThickness);
   m_editLocatedThickness.SetReadOnly(!m_editsetLocatedThickness.GetCheck());
   }


void CInterconnectModuleUsageViewPage::OnMaximumOverDielectric() {
   // TODO: Add your control notification handler code here
   setRequirementCheckBox(&m_editsetMaximumOverDielectric, &m_setMaximumOverDielectric);
   m_editMaximumOverDielectric.SetReadOnly(!m_editsetMaximumOverDielectric.GetCheck());
   }


void CInterconnectModuleUsageViewPage::OnMaximumOverMetal() {
   // TODO: Add your control notification handler code here
   setRequirementCheckBox(&m_editsetMaximumOverMetal, &m_setMaximumOverMetal);
   m_editMaximumOverMetal.SetReadOnly(!m_editsetMaximumOverMetal.GetCheck());
   }


void CInterconnectModuleUsageViewPage::OnMinimumOverDielectric() {
   // TODO: Add your control notification handler code here
   setRequirementCheckBox(&m_editsetMinimumOverDielectric, &m_setMinimumOverDielectric);
   m_editMinimumOverDielectric.SetReadOnly(!m_editsetMinimumOverDielectric.GetCheck());
   }


void CInterconnectModuleUsageViewPage::OnMinimumOverMetal() {
   // TODO: Add your control notification handler code here
   setRequirementCheckBox(&m_editsetMinimumOverMetal, &m_setMinimumOverMetal);
   m_editMinimumOverMetal.SetReadOnly(!m_editsetMinimumOverMetal.GetCheck());
   }


void CInterconnectModuleUsageViewPage::OnUseLocatedThickness() {
   // TODO: Add your control notification handler code here
   }


void CInterconnectModuleUsageViewPage::OnUseMaximumOverDielectric() {
   // TODO: Add your control notification handler code here
   }


void CInterconnectModuleUsageViewPage::OnUseMaximumOverMetal() {
   // TODO: Add your control notification handler code here
   }

void CInterconnectModuleUsageViewPage::OnUseMinimumOverDielectric() {
   // TODO: Add your control notification handler code here
   }


void CInterconnectModuleUsageViewPage::OnUseMinimumOverMetal() {
   // TODO: Add your control notification handler code here
   }


int CInterconnectModuleUsageViewPage::getNumberOfSetThicknesses() {
   int result = 0;

   if (m_setLocatedThickness == TRUE) {
      result++;
      } 
   if (m_setMaximumOverDielectric == TRUE) {
      result++;
      } 
   if (m_setMinimumOverDielectric == TRUE) {
      result++;
      } 
   if (m_setMaximumOverMetal == TRUE) {
      result++;
      } 
   if (m_setMinimumOverMetal == TRUE) {
      result++;
      } 
   return result;
   }

void CInterconnectModuleUsageViewPage::setRequirementCheckBox(CButton *checkbox, BOOL *value) {
   int checked = checkbox->GetCheck();
   if (checked) {
      *value = TRUE;
      }
   else {
      *value = FALSE;
      }      
	if (getNumberOfSetThicknesses() == 0) {
      *value = TRUE;
      checkbox->SetCheck(1);
      }
   }
