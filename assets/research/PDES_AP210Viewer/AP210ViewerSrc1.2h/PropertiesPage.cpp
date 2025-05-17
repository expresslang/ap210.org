// PropertiesPage.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "PropertiesPage.h"
#include "Sdai/SdaiStoredProceedures.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropertiesPage property page

IMPLEMENT_DYNCREATE(CPropertiesPage, CPropertyPage)

CPropertiesPage::CPropertiesPage() : CPropertyPage(CPropertiesPage::IDD) {
   DataSet = 0;   
	//{{AFX_DATA_INIT(CPropertiesPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
   }

CPropertiesPage::~CPropertiesPage(){
   }

void CPropertiesPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropertiesPage)
	DDX_Control(pDX, IDC_PROPERTIES_LIST, m_properties);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPropertiesPage, CPropertyPage)
	//{{AFX_MSG_MAP(CPropertiesPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Application specific functions

// set the property owner of the propery list to be displayed.
void CPropertiesPage::setValues(SdaiModel AP210Model, PackagedPart *packagedpart) {
   ModelRef = AP210Model;
   PropertyOwner = packagedpart->PackagedPartRef;
   }
void CPropertiesPage::setValues(SdaiModel AP210Model, ComponentDefinition *cd) {
   ModelRef = AP210Model;
   PropertyOwner = cd->Component;
   }
void CPropertiesPage::setValues(SdaiModel AP210Model, PhysicalUnit *pu) {
   ModelRef = AP210Model;
   PropertyOwner = pu->PhysicalUnitRef;
   }
/////////////////////////////////////////////////////////////////////////////
// CPropertiesPage message handlers

BOOL CPropertiesPage::OnInitDialog() {
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
   getProperties();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
/*
 * getProperties()
 * 
 * Get the propertes and build display list for them.
 */
void CPropertiesPage::getProperties() {
   static SdaiEntity DRI = sdaiGetEntity(ModelRef, "descriptive_representation_item");
   static SdaiAttr DRI_NAME = sdaiGetAttrDefinition(DRI, "name");
   static SdaiAttr DRI_DESC = sdaiGetAttrDefinition(DRI, "description");
   SdaiNPL PropertyList;

   LV_COLUMN lvc;

   // insert columns
   lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
   lvc.fmt = LVCFMT_LEFT;

   // Name Column
   lvc.iSubItem = 0;
   lvc.pszText = _T("Name");
   lvc.cx = 125;
   m_properties.InsertColumn(0,&lvc);

   // Description Column
   lvc.iSubItem = 1;
   lvc.pszText = _T("Description");
   lvc.cx = 215;
   m_properties.InsertColumn(1,&lvc);

   // Get the define properties and display them.
   PropertyList = getComponentDescriptiveRepresentationItemList(ModelRef, PropertyOwner);

   if (sdaiGetMemberCount(PropertyList) > 0) {
      SdaiAppInstance dri;
      SdaiString name;
      SdaiString description;
      SdaiIterator propitor = sdaiCreateIterator(PropertyList);
      LV_ITEM lvi;

      lvi.mask = LVIF_TEXT;
      lvi.iItem = 0;
// CListCtrl
//      lvi.iSubItem =
//      lvi.state =
//      lvi.stateMask =
//      lvi.pszText =
//      lvi.cchTexMax =
//      lvi.iImage =
//      lvi.lParam =

      while (sdaiNext(propitor)) {
         sdaiGetAggrByIterator(propitor, sdaiINSTANCE, &dri); 
         sdaiGetAttr(dri, DRI_NAME, sdaiSTRING, &name);
         sdaiGetAttr(dri, DRI_DESC, sdaiSTRING, &description);

         // Name Column
         lvi.iSubItem = 0;
         lvi.iItem++;
         lvi.pszText = name;
         lvi.iItem = m_properties.InsertItem(&lvi);

         // Description Column
         lvi.iSubItem = 1;
         lvi.pszText = description;
         m_properties.SetItem(&lvi);
         }
      sdaiDeleteIterator(propitor);
      }
   // created in getPropertyDefinitionList()
   sdaiDeleteNPL(PropertyList);
   }

