// PropertiesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "PropertiesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropertiesDlg dialog


CPropertiesDlg::CPropertiesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPropertiesDlg::IDD, pParent)
{
	EnableAutomation();

	//{{AFX_DATA_INIT(CPropertiesDlg)
	m_name = _T("");
	m_description = _T("");
	m_implementation_level = _T("");
	m_author = _T("");
	m_authorisation = _T("");
	m_organization = _T("");
	m_originating_system = _T("");
	m_preprocessor_version = _T("");
	m_time_stamp = _T("");
	m_schema_name = _T("");
	//}}AFX_DATA_INIT
}


void CPropertiesDlg::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void CPropertiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropertiesDlg)
	DDX_Text(pDX, ID_STEP_HEADER_NAME_NAME, m_name);
	DDV_MaxChars(pDX, m_name, 256);
	DDX_Text(pDX, ID_STEP_HEADER_DESCRIPTION_DESCRIPTION, m_description);
	DDX_Text(pDX, ID_STEP_HEADER_DESCRIPTION_IMPLEMENTATION_LEVEL, m_implementation_level);
	DDX_Text(pDX, ID_STEP_HEADER_NAME_AUTHOR, m_author);
	DDX_Text(pDX, ID_STEP_HEADER_NAME_AUTHORISATION, m_authorisation);
	DDX_Text(pDX, ID_STEP_HEADER_NAME_ORGANIZATION, m_organization);
	DDX_Text(pDX, ID_STEP_HEADER_NAME_ORIGINATING_SYSTEM, m_originating_system);
	DDX_Text(pDX, ID_STEP_HEADER_NAME_PREPROCESSOR_VERSION, m_preprocessor_version);
	DDX_Text(pDX, ID_STEP_HEADER_NAME_TIME_STAMP, m_time_stamp);
	DDX_Text(pDX, ID_STEP_SCHEMA_NAME, m_schema_name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPropertiesDlg, CDialog)
	//{{AFX_MSG_MAP(CPropertiesDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CPropertiesDlg, CDialog)
	//{{AFX_DISPATCH_MAP(CPropertiesDlg)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IPropertiesDlg to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {D3D43881-C68F-11D3-8A99-0080AD428934}
static const IID IID_IPropertiesDlg =
{ 0xd3d43881, 0xc68f, 0x11d3, { 0x8a, 0x99, 0x0, 0x80, 0xad, 0x42, 0x89, 0x34 } };

BEGIN_INTERFACE_MAP(CPropertiesDlg, CDialog)
	INTERFACE_PART(CPropertiesDlg, IID_IPropertiesDlg, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropertiesDlg message handlers
