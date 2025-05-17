// AssemblyPropertiesSheet.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "AssemblyPropertiesSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAssemblyPropertiesSheet

IMPLEMENT_DYNAMIC(CAssemblyPropertiesSheet, CPropertySheet)

CAssemblyPropertiesSheet::CAssemblyPropertiesSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
   // Add the pages
   AddPage(&m_generalassemblypage);
}

CAssemblyPropertiesSheet::CAssemblyPropertiesSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
   // Add the pages
   AddPage(&m_generalassemblypage);
}

CAssemblyPropertiesSheet::~CAssemblyPropertiesSheet()
{
}


BEGIN_MESSAGE_MAP(CAssemblyPropertiesSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CAssemblyPropertiesSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAssemblyPropertiesSheet message handlers
