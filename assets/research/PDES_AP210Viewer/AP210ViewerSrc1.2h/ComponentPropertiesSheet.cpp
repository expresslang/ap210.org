// ComponentPropertiesSheet.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "ComponentPropertiesSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComponentPropertiesSheet

IMPLEMENT_DYNAMIC(CComponentPropertiesSheet, CPropertySheet)

CComponentPropertiesSheet::CComponentPropertiesSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage) {

   // Add the pages
   // packaged_component
	AddPage(&m_generalPage);
	AddPage(&m_comppropertiesPage);

   // packaged_part
	AddPage(&m_generalpackagedpartPage);
	AddPage(&m_packagedpartpropertiesPage);

   // package
	AddPage(&m_packagePage);
	AddPage(&m_packagepropertiesPage);
   }

CComponentPropertiesSheet::CComponentPropertiesSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage) {

   // Add the pages
   // packaged_component
	AddPage(&m_generalPage);
	AddPage(&m_comppropertiesPage);

   // packaged_part
	AddPage(&m_generalpackagedpartPage);
	AddPage(&m_packagedpartpropertiesPage);

   // package
	AddPage(&m_packagePage);
	AddPage(&m_packagepropertiesPage);
   }

CComponentPropertiesSheet::~CComponentPropertiesSheet()
{
}


BEGIN_MESSAGE_MAP(CComponentPropertiesSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CComponentPropertiesSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComponentPropertiesSheet message handlers

void CComponentPropertiesSheet::setValues(SdaiModel AP210Model, PackagedComponent *pc) {
   // Packaged Component
   m_generalPage.setValues(AP210Model, pc);
   m_comppropertiesPage.setValues(AP210Model, pc);

   // Packaged Part
   m_generalpackagedpartPage.setValues(AP210Model, pc->PackagedPartRef);
   m_packagedpartpropertiesPage.setValues(AP210Model, pc->PackagedPartRef);

   // Package
   m_packagePage.setValues(AP210Model, pc->PackageRef);
   m_packagepropertiesPage.setValues(AP210Model, pc->PackageRef);
  }

void CComponentPropertiesSheet::setReadOnly(BOOL mode) {
   m_generalPage.setReadOnly(mode);
   }
