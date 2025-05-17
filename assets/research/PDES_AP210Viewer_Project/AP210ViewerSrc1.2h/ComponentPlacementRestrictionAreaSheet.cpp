// ComponentPlacementRestrictionAreaSheet.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "ComponentPlacementRestrictionAreaSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComponentPlacementRestrictionAreaSheet

IMPLEMENT_DYNAMIC(CComponentPlacementRestrictionAreaSheet, CPropertySheet)

CComponentPlacementRestrictionAreaSheet::CComponentPlacementRestrictionAreaSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage) {
   // MountingRestrictionArea page
	AddPage(&m_mraPage);
   // ComponentRestrictionAssignment page
   AddPage(&m_craPage);
   }

CComponentPlacementRestrictionAreaSheet::CComponentPlacementRestrictionAreaSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage) {
   // MountingRestrictionArea page
	AddPage(&m_mraPage);
   // ComponentRestrictionAssignment page
   AddPage(&m_craPage);
   }

CComponentPlacementRestrictionAreaSheet::~CComponentPlacementRestrictionAreaSheet()
{
}


BEGIN_MESSAGE_MAP(CComponentPlacementRestrictionAreaSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CComponentPlacementRestrictionAreaSheet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComponentPlacementRestrictionAreaSheet message handlers

void CComponentPlacementRestrictionAreaSheet::setValues(PWBDataBase *PWB, MountingRestrictionArea *mra) {
   Database = PWB;
   m_mraPage.setValues(PWB->AP210Model, mra);
   m_craPage.setValues(PWB, mra);
   }

void CComponentPlacementRestrictionAreaSheet::setReadOnly(BOOL mode) {
   m_mraPage.setReadOnly(mode);
   m_craPage.setReadOnly(mode);
   }

