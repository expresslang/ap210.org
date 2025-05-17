// AssemblyProductSelectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "AssemblyProductSelectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAssemblyProductSelectDlg dialog


CAssemblyProductSelectDlg::CAssemblyProductSelectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAssemblyProductSelectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAssemblyProductSelectDlg)
	m_AssemblyProduct = _T("");
	//}}AFX_DATA_INIT
}


void CAssemblyProductSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAssemblyProductSelectDlg)
	DDX_Control(pDX, IDC_ASSEMBLY_PRODUCT, m_controlAssemblyProduct);
	DDX_LBString(pDX, IDC_ASSEMBLY_PRODUCT, m_AssemblyProduct);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAssemblyProductSelectDlg, CDialog)
	//{{AFX_MSG_MAP(CAssemblyProductSelectDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAssemblyProductSelectDlg message handlers

BOOL CAssemblyProductSelectDlg::OnInitDialog() {
   static SdaiEntity P = sdaiGetEntity(ModelRef, "product");
   static SdaiAttr P_ID = sdaiGetAttrDefinition(P, "id");

   SdaiAppInstance asmp; // assembly product
   SdaiString id;   // product.id
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
   SdaiIterator productItor = sdaiCreateIterator(products);
   sdaiBeginning(productItor);
   while(sdaiNext(productItor)) {
      sdaiGetAggrByIterator(productItor, sdaiINSTANCE, &asmp);
   TRACE("   asmp: %s\r\n", _sdaiGetPart21Description(asmp));
      sdaiGetAttr(asmp, P_ID, sdaiSTRING, &id);
   TRACE("   id: %s\r\n", id);
      m_controlAssemblyProduct.AddString(id);
      }
   sdaiDeleteIterator(productItor);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
   }

void CAssemblyProductSelectDlg::setValues(SdaiModel AP210Model, SdaiNPL prods) {
   ModelRef = AP210Model;
   products = prods;
   }
