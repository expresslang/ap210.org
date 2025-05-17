// NonPlatedThruHoleSheet.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "NonPlatedThruHoleSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNonPlatedThruHoleSheet

IMPLEMENT_DYNAMIC(CNonPlatedThruHoleSheet, CPropertySheet)

CNonPlatedThruHoleSheet::CNonPlatedThruHoleSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage) {
	EnableAutomation();

   // NonPlatedThruHole page
	AddPage(&m_npthPage);
   }

CNonPlatedThruHoleSheet::CNonPlatedThruHoleSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage) {
	EnableAutomation();

   // NonPlatedThruHole page
	AddPage(&m_npthPage);
   }

CNonPlatedThruHoleSheet::~CNonPlatedThruHoleSheet()
{
}

void CNonPlatedThruHoleSheet::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CPropertySheet::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CNonPlatedThruHoleSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CNonPlatedThruHoleSheet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CNonPlatedThruHoleSheet, CPropertySheet)
	//{{AFX_DISPATCH_MAP(CNonPlatedThruHoleSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_INonPlatedThruHoleSheet to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {DD02EDC5-F163-11D4-8A9A-0080AD428934}
static const IID IID_INonPlatedThruHoleSheet =
{ 0xdd02edc5, 0xf163, 0x11d4, { 0x8a, 0x9a, 0x0, 0x80, 0xad, 0x42, 0x89, 0x34 } };

BEGIN_INTERFACE_MAP(CNonPlatedThruHoleSheet, CPropertySheet)
	INTERFACE_PART(CNonPlatedThruHoleSheet, IID_INonPlatedThruHoleSheet, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNonPlatedThruHoleSheet message handlers


void CNonPlatedThruHoleSheet::setValues(SdaiModel AP210Model, NonPlatedThruHole *npth) {
   m_npthPage.setValues(AP210Model, npth);
   }
void CNonPlatedThruHoleSheet::setReadOnly(BOOL mode) {
   m_npthPage.setReadOnly(mode);
   }

BOOL CNonPlatedThruHoleSheet::OnInitDialog() 
{
	CPropertySheet::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
