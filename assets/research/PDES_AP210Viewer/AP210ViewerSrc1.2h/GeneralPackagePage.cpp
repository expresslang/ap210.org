// GeneralPackagePage.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "GeneralPackagePage.h"
#include "Sdai/Package.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGeneralPackagePage property page

IMPLEMENT_DYNCREATE(CGeneralPackagePage, CPropertyPage)

CGeneralPackagePage::CGeneralPackagePage(UINT nIDCaption) :
  CPropertyPage(CGeneralPackagePage::IDD, nIDCaption) {
   ReadOnly = TRUE;

	//{{AFX_DATA_INIT(CGeneralPackagePage)
	m_PackageName = _T("");
	m_Height = 0.0;
	//}}AFX_DATA_INIT
   }

CGeneralPackagePage::~CGeneralPackagePage()
{
}

void CGeneralPackagePage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGeneralPackagePage)
	DDX_Control(pDX, IDC_GENERAL_HEIGHT_VALUE, m_editHeight);
	DDX_Text(pDX, IDC_GENERAL_PACKAGE_NAME_VALUE, m_PackageName);
	DDX_Text(pDX, IDC_GENERAL_HEIGHT_VALUE, m_Height);
	DDV_MinMaxDouble(pDX, m_Height, -1.e+029, 1.e+027);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGeneralPackagePage, CPropertyPage)
	//{{AFX_MSG_MAP(CGeneralPackagePage)
	ON_EN_CHANGE(IDC_GENERAL_HEIGHT_VALUE, OnChangeGeneralHeightValue)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGeneralPackagePage message handlers

void CGeneralPackagePage::setValues(SdaiModel AP210Model, PhysicalUnit *pu) {
   PhysicalUnitRef = pu;

   m_PackageName = PhysicalUnitRef->PartNumber;
   m_Height = PhysicalUnitRef->getHeight(); // don't change this
   }

BOOL CGeneralPackagePage::OnInitDialog()  {
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
   // Change the ReadOnly setting of controls we may want to edit
   m_editHeight.SetReadOnly(ReadOnly);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
   }
// set what the readonly mode controls we may wish to edit.
void CGeneralPackagePage::setReadOnly(BOOL mode) {
   ReadOnly = mode;
   }

BOOL CGeneralPackagePage::OnApply() {
   // TODO: Add your specialized code here and/or call the base class
   PhysicalUnitRef->setHeight(m_Height);
   PhysicalUnitRef->UpdateAllViews(NULL);

   return CPropertyPage::OnApply();
   }

void CGeneralPackagePage::OnChangeGeneralHeightValue() {
   // This was not required (MTK 3/6/00)!
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_CHANGE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
   SetModified(TRUE);
	}
