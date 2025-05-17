// PackagePropertiesSheet.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "PackagePropertiesSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPackagePropertiesSheet

IMPLEMENT_DYNAMIC(CPackagePropertiesSheet, CPropertySheet)

CPackagePropertiesSheet::CPackagePropertiesSheet(UINT nIDCaption, CWnd* pParentWnd, UINT nPUCaption, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage) {
	EnableAutomation();
    m_packagePage = new CGeneralPackagePage(nPUCaption);
	AddPage(m_packagePage);
	AddPage(&m_packagepropertiesPage);
   }

CPackagePropertiesSheet::CPackagePropertiesSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT nPUCaption, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage) {
	EnableAutomation();
    m_packagePage = new CGeneralPackagePage(nPUCaption);
	AddPage(m_packagePage);
	AddPage(&m_packagepropertiesPage);
   }

CPackagePropertiesSheet::~CPackagePropertiesSheet() {
   delete m_packagePage;
   }

void CPackagePropertiesSheet::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CPropertySheet::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CPackagePropertiesSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CPackagePropertiesSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CPackagePropertiesSheet, CPropertySheet)
	//{{AFX_DISPATCH_MAP(CPackagePropertiesSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IPackagePropertiesSheet to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {D7737641-E773-11D3-8A99-0080AD428934}
static const IID IID_IPackagePropertiesSheet =
{ 0xd7737641, 0xe773, 0x11d3, { 0x8a, 0x99, 0x0, 0x80, 0xad, 0x42, 0x89, 0x34 } };

BEGIN_INTERFACE_MAP(CPackagePropertiesSheet, CPropertySheet)
	INTERFACE_PART(CPackagePropertiesSheet, IID_IPackagePropertiesSheet, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPackagePropertiesSheet message handlers

void CPackagePropertiesSheet::setValues(SdaiModel AP210Model, PhysicalUnit *pu) {
   m_packagePage->setValues(AP210Model, pu);
   m_packagepropertiesPage.setValues(AP210Model, pu);

   // we want to edit the Height on this sheet
   m_packagePage->setReadOnly(FALSE);
   }
void CPackagePropertiesSheet::setReadOnly(BOOL mode) {
   m_packagePage->setReadOnly(mode);
   }
