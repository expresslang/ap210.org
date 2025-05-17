// InterconnectModulePropertiesSheet.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "InterconnectModulePropertiesSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInterconnectModulePropertiesSheet

IMPLEMENT_DYNAMIC(CInterconnectModulePropertiesSheet, CPropertySheet)

CInterconnectModulePropertiesSheet::CInterconnectModulePropertiesSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage) {
	EnableAutomation();

   // Add the pages
	AddPage(&m_generalinterconnectmodulePage);
	AddPage(&m_interconnectmoduleusageviewPage);

   }

CInterconnectModulePropertiesSheet::CInterconnectModulePropertiesSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage) {
	EnableAutomation();

   // Add the pages
	AddPage(&m_generalinterconnectmodulePage);
	AddPage(&m_interconnectmoduleusageviewPage);
   }

CInterconnectModulePropertiesSheet::~CInterconnectModulePropertiesSheet()
{
}

void CInterconnectModulePropertiesSheet::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CPropertySheet::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CInterconnectModulePropertiesSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CInterconnectModulePropertiesSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CInterconnectModulePropertiesSheet, CPropertySheet)
	//{{AFX_DISPATCH_MAP(CInterconnectModulePropertiesSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IInterconnectModulePropertiesSheet to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {AA8ED082-F145-11D3-8A99-0080AD428934}
static const IID IID_IInterconnectModulePropertiesSheet =
{ 0xaa8ed082, 0xf145, 0x11d3, { 0x8a, 0x99, 0x0, 0x80, 0xad, 0x42, 0x89, 0x34 } };

BEGIN_INTERFACE_MAP(CInterconnectModulePropertiesSheet, CPropertySheet)
	INTERFACE_PART(CInterconnectModulePropertiesSheet, IID_IInterconnectModulePropertiesSheet, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInterconnectModulePropertiesSheet message handlers

void CInterconnectModulePropertiesSheet::setValues(SdaiModel AP210Model, BoardComponent * bc) {
   m_generalinterconnectmodulePage.setValues(AP210Model, bc);
   m_interconnectmoduleusageviewPage.setValues(AP210Model, bc);
   }
void CInterconnectModulePropertiesSheet::setReadOnly(BOOL mode) {
   m_generalinterconnectmodulePage.setReadOnly(mode);
   m_interconnectmoduleusageviewPage.setReadOnly(mode);
   }
