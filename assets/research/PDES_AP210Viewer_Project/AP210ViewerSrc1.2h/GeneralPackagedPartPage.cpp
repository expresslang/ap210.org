// GeneralPackagedPartPage.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "GeneralPackagedPartPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGeneralPackagedPartPage property page

IMPLEMENT_DYNCREATE(CGeneralPackagedPartPage, CPropertyPage)

CGeneralPackagedPartPage::CGeneralPackagedPartPage() : CPropertyPage(CGeneralPackagedPartPage::IDD)
{
	//{{AFX_DATA_INIT(CGeneralPackagedPartPage)
	m_PartNumber = _T("");
	m_ItemFindNumber = 0;
	m_Quantity = 0;
	//}}AFX_DATA_INIT
}

CGeneralPackagedPartPage::~CGeneralPackagedPartPage()
{
}

void CGeneralPackagedPartPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGeneralPackagedPartPage)
	DDX_Text(pDX, IDC_GENERAL_PARTNUMBER_VALUE, m_PartNumber);
	DDX_Text(pDX, IDC_GENERAL_ITEM_FIND_NUMBER_VALUE, m_ItemFindNumber);
	DDV_MinMaxUInt(pDX, m_ItemFindNumber, 1, 4294967295);
	DDX_Text(pDX, IDC_GENERAL_QUANTITY_VALUE, m_Quantity);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGeneralPackagedPartPage, CPropertyPage)
	//{{AFX_MSG_MAP(CGeneralPackagedPartPage)
	ON_EN_CHANGE(IDC_GENERAL_HEIGHT_VALUE, OnChangeGeneralHeightValue)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Application specific functions

// set the values to be displayed
void CGeneralPackagedPartPage::setValues(SdaiModel AP210Model, PackagedPart *packagedpart) {
   PackagedPartRef = packagedpart;

   m_Quantity = PackagedPartRef->getPackagedComponentCount();

   m_ItemFindNumber = PackagedPartRef->ItemFindNumber;

   m_PartNumber = PackagedPartRef->PartNumber;
   }
/////////////////////////////////////////////////////////////////////////////
// CGeneralPackagedPartPage message handlers


void CGeneralPackagedPartPage::OnChangeGeneralHeightValue() {
   // This was not required (MTK 2/26/00)!
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_CHANGE flag ORed into the lParam mask.
	
   // TODO: This would require changed the display list for the packaged part.

	// TODO: Add your control notification handler code here
   SetModified(TRUE);
   }
