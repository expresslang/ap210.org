// ComponentPlacementRestrictionAreaPage.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "ComponentPlacementRestrictionAreaPage.h"
#include "Sdai/AP210MagicStrings.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComponentPlacementRestrictionAreaPage property page

IMPLEMENT_DYNCREATE(CComponentPlacementRestrictionAreaPage, CPropertyPage)

CComponentPlacementRestrictionAreaPage::CComponentPlacementRestrictionAreaPage() : CPropertyPage(CComponentPlacementRestrictionAreaPage::IDD)
{
	//{{AFX_DATA_INIT(CComponentPlacementRestrictionAreaPage)
	m_X = 0.0;
	m_Y = 0.0;
	m_PlacementFixed = FALSE;
	m_Surface = _T("");
	m_RefDes = _T("");
	//}}AFX_DATA_INIT
}

CComponentPlacementRestrictionAreaPage::~CComponentPlacementRestrictionAreaPage()
{
}

void CComponentPlacementRestrictionAreaPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CComponentPlacementRestrictionAreaPage)
	DDX_Control(pDX, IDC_GENERAL_REFDES_VALUE, m_editRefDes);
	DDX_Control(pDX, IDC_MOUNTING_RESTRICTION_AREA_SURFACE, m_editSurface);
	DDX_Control(pDX, IDC_GENERAL_PLACEMENT_FIXED, m_editPlacementFixed);
	DDX_Control(pDX, IDC_GENERAL_LOCATION_Y_VALUE, m_editY);
	DDX_Control(pDX, IDC_GENERAL_LOCATION_X_VALUE, m_editX);
	DDX_Text(pDX, IDC_GENERAL_LOCATION_X_VALUE, m_X);
	DDX_Text(pDX, IDC_GENERAL_LOCATION_Y_VALUE, m_Y);
	DDX_Check(pDX, IDC_GENERAL_PLACEMENT_FIXED, m_PlacementFixed);
	DDX_CBString(pDX, IDC_MOUNTING_RESTRICTION_AREA_SURFACE, m_Surface);
	DDX_Text(pDX, IDC_GENERAL_REFDES_VALUE, m_RefDes);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CComponentPlacementRestrictionAreaPage, CPropertyPage)
	//{{AFX_MSG_MAP(CComponentPlacementRestrictionAreaPage)
	ON_BN_CLICKED(IDC_GENERAL_PLACEMENT_FIXED, OnGeneralPlacementFixed)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComponentPlacementRestrictionAreaPage message handlers

void CComponentPlacementRestrictionAreaPage::setValues() {
   // Reference Designator
#if 0
   m_RefDes = MountingRestrictionAreaRef->Name;

   // location 
   m_PlacementFixed = MountingRestrictionAreaRef->getPlacementFixed();
#endif
   m_X = MountingRestrictionAreaRef->getX();
   m_Y = MountingRestrictionAreaRef->getY();
#if 0
   m_Rotation = MountingRestrictionAreaRef->getRotation();
#endif
   // set the side
   CString surface = MountingRestrictionAreaRef->getSurface();
   if (!strcmp(PRIMARY_SURFACE, surface)) {
      m_Surface = "Primary Surface";
      } 
   else if (!strcmp(SECONDARY_SURFACE, surface)) {
      m_Surface = "Secondary Surface";
      }
   else {
      m_Surface = "Unplaced";
      }   
   }

void CComponentPlacementRestrictionAreaPage::setValues(SdaiModel AP210Model, MountingRestrictionArea *mra) {
   MountingRestrictionAreaRef = mra;
   setValues();
   }

void CComponentPlacementRestrictionAreaPage::setReadOnly(BOOL mode){
   ReadOnly = mode;
   }

BOOL CComponentPlacementRestrictionAreaPage::OnInitDialog() {
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
   m_editRefDes.SetReadOnly(ReadOnly);

   if (ReadOnly == FALSE) {
      // if the placement is fixed you can't edit it.
      m_editX.SetReadOnly(m_PlacementFixed);
      m_editY.SetReadOnly(m_PlacementFixed);
      m_editSurface.EnableWindow(!m_PlacementFixed);
      }
   else {
      // don't allow editing
      m_editPlacementFixed.EnableWindow(FALSE);
      m_editX.SetReadOnly(TRUE);
      m_editY.SetReadOnly(TRUE);
      m_editSurface.EnableWindow(FALSE);
      }
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
   }

void CComponentPlacementRestrictionAreaPage::OnGeneralPlacementFixed() {
	// TODO: Add your control notification handler code here
   int checked = m_editPlacementFixed.GetCheck();

   // if checked revert location to current values,
   //    or later disable if modified!
   if (checked) {
      CString scratch;
      scratch.Format("%f", MountingRestrictionAreaRef->getX());
      m_editX.SetWindowText(scratch);
      scratch.Format("%f", MountingRestrictionAreaRef->getX());
      m_editY.SetWindowText(scratch);

      // set the side
      CString surface = MountingRestrictionAreaRef->getSurface();
      if (!strcmp(PRIMARY_SURFACE, surface)) {
         m_Surface = "Primary Surface";
         } 
      else if (!strcmp(SECONDARY_SURFACE, surface)) {
         m_Surface = "Secondary Surface";
         }
      else {
         m_Surface = "Unplaced";
         }   
      }
   // set proper state of location edit controls.
   m_editX.SetReadOnly(checked);
   m_editX.Invalidate();
   m_editX.RedrawWindow();

   m_editY.SetReadOnly(checked);
   m_editY.Invalidate();
   m_editY.RedrawWindow();

   m_editSurface.EnableWindow(!checked);
   m_editSurface.Invalidate();
   m_editSurface.RedrawWindow();

   SetModified(TRUE);
   }
