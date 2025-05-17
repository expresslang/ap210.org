// SingleComponentRestrictionAssignmentPage.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "SingleComponentRestrictionAssignmentPage.h"
#include "PWBDataBase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSingleComponentRestrictionAssignmentPage property page

IMPLEMENT_DYNCREATE(CSingleComponentRestrictionAssignmentPage, CPropertyPage)

CSingleComponentRestrictionAssignmentPage::CSingleComponentRestrictionAssignmentPage() : CPropertyPage(CSingleComponentRestrictionAssignmentPage::IDD)
{
	//{{AFX_DATA_INIT(CSingleComponentRestrictionAssignmentPage)
	m_Height = 0.0;
	//}}AFX_DATA_INIT
}

CSingleComponentRestrictionAssignmentPage::~CSingleComponentRestrictionAssignmentPage()
{
}

void CSingleComponentRestrictionAssignmentPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSingleComponentRestrictionAssignmentPage)
	DDX_Control(pDX, IDC_CRA_HEIGHT_VALUE, m_editHeight);
	DDX_Text(pDX, IDC_CRA_HEIGHT_VALUE, m_Height);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSingleComponentRestrictionAssignmentPage, CPropertyPage)
	//{{AFX_MSG_MAP(CSingleComponentRestrictionAssignmentPage)
	ON_EN_CHANGE(IDC_CRA_HEIGHT_VALUE, OnChangeCraHeightValue)
	ON_BN_CLICKED(IDC_CRA_OPAQUE, OnCraOpaque)
	ON_BN_CLICKED(IDC_CRA_INVISIBLE, OnCraInvisible)
	ON_BN_CLICKED(IDC_CRA_TRANSPARENT, OnCraTransparent)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSingleComponentRestrictionAssignmentPage message handlers

BOOL CSingleComponentRestrictionAssignmentPage::OnApply() {
	// TODO: Add your specialized code here and/or call the base class
   int checkeditem = GetCheckedRadioButton(IDC_CRA_INVISIBLE, IDC_CRA_OPAQUE);

   if (MountingRestrictionAreaRef->getAppearance() != checkeditem) {
      // set the visibility of the MountingRestrictionArea
      MountingRestrictionAreaRef->setAppearance(checkeditem);
      // Update all the views to change component_placement_restriction_areas.
      MountingRestrictionAreaRef->UpdateAllViews(NULL);
      }  
   MountingRestrictionAreaRef->setHeight(m_Height);
   MountingRestrictionAreaRef->UpdateAllViews(NULL);
	return CPropertyPage::OnApply();
   }

void CSingleComponentRestrictionAssignmentPage::setValues(PWBDataBase *PWB, MountingRestrictionArea *mra) {
   MountingRestrictionAreaRef = mra;
   Database = PWB;
   m_Height = MountingRestrictionAreaRef->getHeight();
   }

BOOL CSingleComponentRestrictionAssignmentPage::OnInitDialog() {
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
   // Change the ReadOnly setting of controls we may want to edit
   m_editHeight.SetReadOnly(ReadOnly);

   // set the appearance
   CheckRadioButton(IDC_CRA_INVISIBLE, IDC_CRA_OPAQUE,
                    MountingRestrictionAreaRef->getAppearance());
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
   }

void CSingleComponentRestrictionAssignmentPage::setReadOnly(BOOL mode) {
   ReadOnly = mode;
   }

void CSingleComponentRestrictionAssignmentPage::OnChangeCraHeightValue() {
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
   SetModified(TRUE);
	}

void CSingleComponentRestrictionAssignmentPage::OnCraOpaque() {
	// TODO: Add your control notification handler code here
   SetModified(TRUE);
	}

void CSingleComponentRestrictionAssignmentPage::OnCraInvisible() {
	// TODO: Add your control notification handler code here
   SetModified(TRUE);
   }

void CSingleComponentRestrictionAssignmentPage::OnCraTransparent() {
	// TODO: Add your control notification handler code here
   SetModified(TRUE);
   }
