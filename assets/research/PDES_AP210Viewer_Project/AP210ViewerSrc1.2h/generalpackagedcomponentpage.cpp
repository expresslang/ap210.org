// GeneralPackagedComponentPage.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "GeneralPackagedComponentPage.h"
#include "Sdai/PackagedComponent.h"
#include "Sdai/AP210MagicStrings.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGeneralPackagedComponentPage property page

IMPLEMENT_DYNCREATE(CGeneralPackagedComponentPage, CPropertyPage)

CGeneralPackagedComponentPage::CGeneralPackagedComponentPage(UINT nIDCaption) :
   CPropertyPage(CGeneralPackagedComponentPage::IDD, nIDCaption) {
	//{{AFX_DATA_INIT(CGeneraPackagedComponentlPage)
	m_PartNumber = _T("");
	m_RefDes = _T("");
	m_Y = 0.0;
	m_X = 0.0;
	m_Rotation = 0.0;
	m_PlacementFixed = FALSE;
	//}}AFX_DATA_INIT

   ReadOnly = TRUE;
   }

CGeneralPackagedComponentPage::~CGeneralPackagedComponentPage()
{
}

void CGeneralPackagedComponentPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGeneralPackagedComponentPage)
	DDX_Control(pDX, IDC_PACKAGED_COMPONENT_SURFACE, m_editSurface);
	DDX_Control(pDX, IDC_PACKAGED_COMPONENT_ROTATION_VALUE, m_editRotation);
	DDX_Text(pDX, IDC_GENERAL_PARTNUMBER_VALUE, m_PartNumber);
	DDX_Text(pDX, IDC_GENERAL_REFDES_VALUE, m_RefDes);
	DDX_Control(pDX, IDC_GENERAL_PLACEMENT_FIXED, m_editPlacementFixed);
	DDX_Check(pDX, IDC_GENERAL_PLACEMENT_FIXED, m_PlacementFixed);
	DDX_Control(pDX, IDC_GENERAL_LOCATION_X_VALUE, m_editX);
	DDX_Control(pDX, IDC_GENERAL_LOCATION_Y_VALUE, m_editY);
	DDX_Text(pDX, IDC_GENERAL_ITEM_FIND_NUMBER_VALUE, m_ItemFindNumber);
	DDV_MinMaxUInt(pDX, m_ItemFindNumber, 0, 4294967295);
	DDX_Text(pDX, IDC_PACKAGED_COMPONENT_ROTATION_VALUE, m_Rotation);
	DDX_CBString(pDX, IDC_PACKAGED_COMPONENT_SURFACE, m_Surface);
	DDX_Text(pDX, IDC_GENERAL_LOCATION_X_VALUE, m_X);
	DDX_Text(pDX, IDC_GENERAL_LOCATION_Y_VALUE, m_Y);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGeneralPackagedComponentPage, CPropertyPage)
	//{{AFX_MSG_MAP(CGeneralPackagedComponentPage)
	ON_BN_CLICKED(IDC_GENERAL_PLACEMENT_FIXED, OnGeneralPlacementFixed)
	ON_EN_CHANGE(IDC_GENERAL_LOCATION_X_VALUE, OnChangeGeneralLocationXValue)
	ON_EN_CHANGE(IDC_GENERAL_LOCATION_Y_VALUE, OnChangeGeneralLocationYValue)
	ON_EN_CHANGE(IDC_PACKAGED_COMPONENT_ROTATION_VALUE, OnChangePackagedComponentRotationValue)
	ON_CBN_SELCHANGE(IDC_PACKAGED_COMPONENT_SURFACE, OnSelchangePackagedComponentSurface)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGeneralPackagedComponentPage message handlers

void CGeneralPackagedComponentPage::setValues(SdaiModel AP210Model, ComponentDefinition *pc) {
   ComponentDefinitionRef = pc;

   if (ComponentDefinitionRef->DynamicType(PackagedComponent::TypeID())) {
      m_PartNumber = getPackagedComponentPartNumber(AP210Model, ComponentDefinitionRef->getComponent());
      }
   else {
      m_PartNumber = "Mechanical Part";
      }
   setValues();
   }

void CGeneralPackagedComponentPage::setValues() {
   // Reference Designator
   m_RefDes = ComponentDefinitionRef->getName();

   // location 
   m_PlacementFixed = ComponentDefinitionRef->getPlacementFixed();
   m_X = ComponentDefinitionRef->getX();
   m_Y = ComponentDefinitionRef->getY();
   m_Rotation = ComponentDefinitionRef->getRotation();
   // set the side
   CString surface = ComponentDefinitionRef->getSurface();
   if (!strcmp(PRIMARY_SURFACE, surface)) {
      m_Surface = "Primary Surface";
      } 
   else if (!strcmp(SECONDARY_SURFACE, surface)) {
      m_Surface = "Secondary Surface";
      }
   else {
      m_Surface = "Unplaced";
      }   
   // For Tom
   m_ItemFindNumber = ComponentDefinitionRef->getItemFindNumber();
   }   

BOOL CGeneralPackagedComponentPage::OnInitDialog() {
	CPropertyPage::OnInitDialog();

	// TODO: Add extra initialization here
   if (ReadOnly == FALSE) {
      // if the placement is fixed you can't edit it.
      m_editX.SetReadOnly(m_PlacementFixed);
      m_editY.SetReadOnly(m_PlacementFixed);
      m_editRotation.SetReadOnly(m_PlacementFixed);
      m_editSurface.EnableWindow(!m_PlacementFixed);
      }
   else {
      // don't allow editing
      m_editPlacementFixed.EnableWindow(FALSE);
      m_editX.SetReadOnly(TRUE);
      m_editY.SetReadOnly(TRUE);
      m_editRotation.SetReadOnly(TRUE);
      m_editSurface.EnableWindow(FALSE);
      }
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
   }

BOOL CGeneralPackagedComponentPage::OnApply() {
   // TODO: Add your specialized code here and/or call the base class
   ComponentDefinitionRef->setPlacementFixed(m_PlacementFixed);

   // Only change the location for unfixed components.
   if (ComponentDefinitionRef->getPlacementFixed() == FALSE) {
      ComponentDefinitionRef->setX(m_X);
      ComponentDefinitionRef->setY(m_Y);
      ComponentDefinitionRef->setRotation(m_Rotation);
      ComponentDefinitionRef->setSurface(m_Surface);
      ComponentDefinitionRef->UpdateAllViews(NULL);
      }
   setValues();

   return CPropertyPage::OnApply();
   }

void CGeneralPackagedComponentPage::OnGeneralPlacementFixed() {
	// TODO: Add your control notification handler code here
   // if the placement is fixed you can't edit it.
   int checked = m_editPlacementFixed.GetCheck();

   // if checked revert location to current values,
   //    or later disable if modified!
   if (checked) {
      CString scratch;
      scratch.Format("%f", ComponentDefinitionRef->getX());
      m_editX.SetWindowText(scratch);
      scratch.Format("%f", ComponentDefinitionRef->getX());
      m_editY.SetWindowText(scratch);
      scratch.Format("%f", ComponentDefinitionRef->getRotation());
      m_editRotation.SetWindowText(scratch);

      // set the side
      CString surface = ComponentDefinitionRef->getSurface();
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

   m_editRotation.SetReadOnly(checked);
   m_editRotation.Invalidate();
   m_editRotation.RedrawWindow();

   m_editSurface.EnableWindow(!checked);
   m_editSurface.Invalidate();
   m_editSurface.RedrawWindow();

   SetModified(TRUE);
   }

void CGeneralPackagedComponentPage::OnChangeGeneralLocationXValue() { 
   // This was not required (MTK 2/26/00)!
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_CHANGE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
   SetModified(TRUE);
   }

void CGeneralPackagedComponentPage::OnChangeGeneralLocationYValue() {
   // This was not required (MTK 2/26/00)!
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_CHANGE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
   SetModified(TRUE);
   }


void CGeneralPackagedComponentPage::OnChangePackagedComponentRotationValue() {
   // This was not required (MTK 3/14/00)!
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_CHANGE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
   SetModified(TRUE);
   }


void CGeneralPackagedComponentPage::OnSelchangePackagedComponentSurface() {
	// TODO: Add your control notification handler code here
TRACE("In CGeneralPackagedComponentPage::OnSelchangePackagedComponentSurface\r\n"); 
   SetModified(TRUE);
   }

void CGeneralPackagedComponentPage::setReadOnly(BOOL mode) {
   ReadOnly = mode;
   } 
