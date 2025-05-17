// GeneralInterconnectModulePage.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "GeneralInterconnectModulePage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGeneralInterconnectModulePage property page

IMPLEMENT_DYNCREATE(CGeneralInterconnectModulePage, CPropertyPage)

CGeneralInterconnectModulePage::CGeneralInterconnectModulePage() : CPropertyPage(CGeneralInterconnectModulePage::IDD)
{
	//{{AFX_DATA_INIT(CGeneralInterconnectModulePage)
	m_Name = _T("");
	m_Transparent = FALSE;
	//}}AFX_DATA_INIT
}

CGeneralInterconnectModulePage::~CGeneralInterconnectModulePage()
{
}

void CGeneralInterconnectModulePage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGeneralInterconnectModulePage)
	DDX_Control(pDX, IDC_GENERAL_INTERCONNECT_MODULE_NAME_VALUE, m_editName);
	DDX_Text(pDX, IDC_GENERAL_INTERCONNECT_MODULE_NAME_VALUE, m_Name);
	DDX_Check(pDX, IDC_GENERAL_INTERCONNECT_MODULE_TRANSPARENT_VALUE, m_Transparent);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGeneralInterconnectModulePage, CPropertyPage)
	//{{AFX_MSG_MAP(CGeneralInterconnectModulePage)
	ON_EN_CHANGE(IDC_GENERAL_INTERCONNECT_MODULE_NAME_VALUE, OnChangeGeneralInterconnectModuleNameValue)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGeneralInterconnectModulePage message handlers

void CGeneralInterconnectModulePage::setValues(SdaiModel AP210Module, BoardComponent *bc) {
   InterconnectModuleRef = bc;

   m_Name = InterconnectModuleRef->getName();

   m_Transparent = InterconnectModuleRef->getTransparency();
   }

void CGeneralInterconnectModulePage::OnGeneralInterconnectModuleTransparentValue() {
	// TODO: Add your control notification handler code here
   SetModified(TRUE);
   }

BOOL CGeneralInterconnectModulePage::OnApply() {
	// TODO: Add your specialized code here and/or call the base class
   InterconnectModuleRef->setTransparency(m_Transparent);
   InterconnectModuleRef->setName(m_Name);
   InterconnectModuleRef->UpdateAllViews(NULL);
    	
   return CPropertyPage::OnApply();
   }
// set what the readonly mode controls we may wish to edit.
void CGeneralInterconnectModulePage::setReadOnly(BOOL mode) {
   ReadOnly = mode;
   }


void CGeneralInterconnectModulePage::OnChangeGeneralInterconnectModuleNameValue() {
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
   SetModified(TRUE);
   }
