// PackagedPartPropertiesSheet.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "PackagedPartPropertiesSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPackagedPartPropertiesSheet

IMPLEMENT_DYNAMIC(CPackagedPartPropertiesSheet, CPropertySheet)

CPackagedPartPropertiesSheet::CPackagedPartPropertiesSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage) {
	EnableAutomation();

   // Add the pages
   // packaged_component
	AddPage(&m_generalpackagedpartPage);
	AddPage(&m_packagedpartpropertiesPage);

   // package
	AddPage(&m_packagePage);
	AddPage(&m_packagepropertiesPage);
   }

CPackagedPartPropertiesSheet::CPackagedPartPropertiesSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage) {
	EnableAutomation();

   // Add the pages
   // packaged_component
	AddPage(&m_generalpackagedpartPage);
	AddPage(&m_packagedpartpropertiesPage);

   // package
	AddPage(&m_packagePage);
	AddPage(&m_packagepropertiesPage);
   }

CPackagedPartPropertiesSheet::~CPackagedPartPropertiesSheet()
{
}

void CPackagedPartPropertiesSheet::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CPropertySheet::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CPackagedPartPropertiesSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CPackagedPartPropertiesSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CPackagedPartPropertiesSheet, CPropertySheet)
	//{{AFX_DISPATCH_MAP(CPackagedPartPropertiesSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IPackagedPartPropertiesSheet to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {D7737643-E773-11D3-8A99-0080AD428934}
static const IID IID_IPackagedPartPropertiesSheet =
{ 0xd7737643, 0xe773, 0x11d3, { 0x8a, 0x99, 0x0, 0x80, 0xad, 0x42, 0x89, 0x34 } };

BEGIN_INTERFACE_MAP(CPackagedPartPropertiesSheet, CPropertySheet)
	INTERFACE_PART(CPackagedPartPropertiesSheet, IID_IPackagedPartPropertiesSheet, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPackagedPartPropertiesSheet message handlers

void CPackagedPartPropertiesSheet::setValues(SdaiModel AP210Model, PackagedPart *packagedpart) {
   // Packaged Part
   m_generalpackagedpartPage.setValues(AP210Model, packagedpart);
   m_packagedpartpropertiesPage.setValues(AP210Model, packagedpart);

   // Package
   m_packagePage.setValues(AP210Model, packagedpart->PackageRef);
   m_packagepropertiesPage.setValues(AP210Model, packagedpart->PackageRef);
   }
