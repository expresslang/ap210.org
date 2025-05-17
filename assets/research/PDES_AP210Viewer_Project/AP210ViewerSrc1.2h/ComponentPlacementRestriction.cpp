// ComponentPlacementRestriction.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "ComponentPlacementRestriction.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComponentPlacementRestriction dialog


CComponentPlacementRestriction::CComponentPlacementRestriction(CWnd* pParent /*=NULL*/)
	: CDialog(CComponentPlacementRestriction::IDD, pParent) {
	EnableAutomation();

	//{{AFX_DATA_INIT(CComponentPlacementRestriction)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
   }


void CComponentPlacementRestriction::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void CComponentPlacementRestriction::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CComponentPlacementRestriction)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CComponentPlacementRestriction, CDialog)
	//{{AFX_MSG_MAP(CComponentPlacementRestriction)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CComponentPlacementRestriction, CDialog)
	//{{AFX_DISPATCH_MAP(CComponentPlacementRestriction)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IComponentPlacementRestriction to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {E89B2D64-B990-11D4-8A9A-0080AD428934}
static const IID IID_IComponentPlacementRestriction =
{ 0xe89b2d64, 0xb990, 0x11d4, { 0x8a, 0x9a, 0x0, 0x80, 0xad, 0x42, 0x89, 0x34 } };

BEGIN_INTERFACE_MAP(CComponentPlacementRestriction, CDialog)
	INTERFACE_PART(CComponentPlacementRestriction, IID_IComponentPlacementRestriction, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComponentPlacementRestriction message handlers
/*
   CheckRadioButton(IDC_CRA_INVISIBLE, IDC_CRA_OPAQUE, IDC_CRA_INVISIBLE);
*/

void CComponentPlacementRestriction::setValues(PWBDataBase *PWB) {
   Database = PWB;
   }
  

BOOL CComponentPlacementRestriction::OnInitDialog() {
	CDialog::OnInitDialog();
	
   // TODO: Add extra initialization here
   CheckRadioButton(IDC_CRA_INVISIBLE, IDC_CRA_OPAQUE, Database->MountingRestrictionAreaAppearance);

   return TRUE;  // return TRUE unless you set the focus to a control
                 // EXCEPTION: OCX Property Pages should return FALSE
   }

void CComponentPlacementRestriction::OnOK() {
   // TODO: Add extra validation here
   int checkeditem = GetCheckedRadioButton(IDC_CRA_INVISIBLE, IDC_CRA_OPAQUE);

   if (Database->MountingRestrictionAreaAppearance != checkeditem) {
      // set the visibility of the MountingRestrictionAreas
      Database->MountingRestrictionAreaAppearance = checkeditem;
      Database->updateMountingRestrictionAreas();
       // Update all the views to change component_placement_restriction_areas.
      Database->UpdateAllViews(NULL);
      }  
   CDialog::OnOK();
   }
