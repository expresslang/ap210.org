// GeneralAssemblyPage.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "GeneralAssemblyPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGeneralAssemblyPage property page

IMPLEMENT_DYNCREATE(CGeneralAssemblyPage, CPropertyPage)

CGeneralAssemblyPage::CGeneralAssemblyPage() : CPropertyPage(CGeneralAssemblyPage::IDD)
{
	//{{AFX_DATA_INIT(CGeneralAssemblyPage)
	m_Id = _T("");
	//}}AFX_DATA_INIT
}

CGeneralAssemblyPage::~CGeneralAssemblyPage()
{
}

void CGeneralAssemblyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGeneralAssemblyPage)
	DDX_Control(pDX, IDC_ID, m_editId);
	DDX_Text(pDX, IDC_ID, m_Id);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGeneralAssemblyPage, CPropertyPage)
	//{{AFX_MSG_MAP(CGeneralAssemblyPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGeneralAssemblyPage message handlers
