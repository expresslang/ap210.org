// ComponentDefinitionSheet.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "ComponentDefinitionSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComponentDefinitionSheet

IMPLEMENT_DYNAMIC(CComponentDefinitionSheet, CPropertySheet)

CComponentDefinitionSheet::CComponentDefinitionSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage) {
	EnableAutomation();

   // component_definition
   m_generalPage = new CGeneralPackagedComponentPage(ID_COMPONENT_DEFINITION);
	AddPage(m_generalPage);
	AddPage(&m_comppropertiesPage);

   // physical_unit
   m_physicalunitPage = new CGeneralPackagePage(ID_PHYSICAL_UNIT);
	AddPage(m_physicalunitPage);
	AddPage(&m_physicalunitpropertiesPage);
   }

CComponentDefinitionSheet::CComponentDefinitionSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage) {
	EnableAutomation();

   // component_definition
   m_generalPage = new CGeneralPackagedComponentPage(ID_COMPONENT_DEFINITION);
	AddPage(m_generalPage);
	AddPage(&m_comppropertiesPage);

   // physical_unit
   m_physicalunitPage = new CGeneralPackagePage(ID_PHYSICAL_UNIT);
	AddPage(m_physicalunitPage);
	AddPage(&m_physicalunitpropertiesPage);
   }

CComponentDefinitionSheet::~CComponentDefinitionSheet() {
   delete m_generalPage;
   delete m_physicalunitPage;
   }

void CComponentDefinitionSheet::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CPropertySheet::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CComponentDefinitionSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CComponentDefinitionSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CComponentDefinitionSheet, CPropertySheet)
	//{{AFX_DISPATCH_MAP(CComponentDefinitionSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IComponentDefinitionSheet to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {683147A1-9FA4-11D4-8A9A-0080AD428934}
static const IID IID_IComponentDefinitionSheet =
{ 0x683147a1, 0x9fa4, 0x11d4, { 0x8a, 0x9a, 0x0, 0x80, 0xad, 0x42, 0x89, 0x34 } };

BEGIN_INTERFACE_MAP(CComponentDefinitionSheet, CPropertySheet)
	INTERFACE_PART(CComponentDefinitionSheet, IID_IComponentDefinitionSheet, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComponentDefinitionSheet message handlers
/////////////////////////////////////////////////////////////////////////////
// CComponentPropertiesSheet message handlers

void CComponentDefinitionSheet::setValues(SdaiModel AP210Model, ComponentDefinition *cd) {

   // Component_definition
   m_generalPage->setValues(AP210Model, cd);
   m_comppropertiesPage.setValues(AP210Model, cd);

   // Physical_unit
   m_physicalunitPage->setValues(AP210Model, cd->PhysicalUnitRef);
   m_physicalunitpropertiesPage.setValues(AP210Model, cd->PhysicalUnitRef);
   }

void CComponentDefinitionSheet::setReadOnly(BOOL mode) {
   m_generalPage->setReadOnly(mode);
   }