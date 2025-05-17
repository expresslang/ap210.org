// AP210ProdView.cpp : implementation file
//

#include "stdafx.h"
#include "AP210Viewer.h"
#include "AP210ProdView.h"
#include "PWBDataBase.h"
#include "Sdai/PackagedComponent.h"
#include "Sdai/MountingRestrictionArea.h"
#include "Sdai/NonPlatedThruHole.h"

// GUI
#include "ComponentPlacementRestriction.h"

#include "AssemblyPropertiesSheet.h"
#include "InterconnectModulePropertiesSheet.h"
#include "ComponentPropertiesSheet.h"
#include "ComponentDefinitionSheet.h"
#include "PackagePropertiesSheet.h"
#include "PackagedPartPropertiesSheet.h"
#include "NonPlatedThruHoleSheet.h"
#include "ComponentPlacementRestrictionAreaSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CAP210ProdView

IMPLEMENT_DYNCREATE(CAP210ProdView, CTreeView)

CAP210ProdView::CAP210ProdView() {
   pImageList = NULL;
   }

CAP210ProdView::~CAP210ProdView() {
   if (pImageList) {
	   pImageList->DeleteImageList();
	   delete pImageList;
      }
   }


BEGIN_MESSAGE_MAP(CAP210ProdView, CTreeView)
	//{{AFX_MSG_MAP(CAP210ProdView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	ON_WM_RBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_COMPONENT_RESTRICTION_AREA, OnComponentRestrictionArea)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAP210ProdView drawing


/////////////////////////////////////////////////////////////////////////////
// CAP210ProdView diagnostics

#ifdef _DEBUG
void CAP210ProdView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CAP210ProdView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAP210ProdView message handlers

void CAP210ProdView::OnInitialUpdate() {
TRACE("In CAP210ProdView::OnInitialUpdate()\r\n");	
	// TODO: Add your specialized code here and/or call the base class
#if 0
   // This should work some place!
	// fill the view with the specified color
   CDC *pDC = GetDC();
	CRect rect;
	GetClientRect(rect);
	CBrush br(GetSysColor(COLOR_BTNFACE)); // bright grey
	pDC->FillRect(rect, &br);
#endif

   PopulateTree();

   CTreeView::OnInitialUpdate();
   }
/*
 * PopulateTree()
 *
 * Populates the view tree with the assembly, packages and packaged_parts
 *
 * Bitmap Image List
 *   0 - IDB_FULLPARENT
 *   1 - IDB_EMPTYPARENT
 *   2 - IDB_OPENPARENT
 *   3 - IDB_PACKAGED_COMPONENT
 *   4 - IDB_PWB
 *   5 - IDB_PACKAGED_PART
 *   6 - IDB_PACKAGE
 *
 * From resources.h
 *   #define IDB_FULLPARENT                  156
 *   #define IDB_EMPTYPARENT                 157
 *   #define IDB_OPENPARENT                  158
 *   #define IDB_PACKAGED_COMPONENT          159
 *   #define IDB_PWB                         161
 *   #define IDB_PACKAGED_PART               162
 *   #define IDB_PACKAGE                     163
 */
void CAP210ProdView::PopulateTree() {
   // Get the data to display
   PWBDataBase *pDoc = (PWBDataBase *)GetDocument();
 
   // Unselect everything
   pDoc->UnSelectAll();

   // get the tree control
   CTreeCtrl &TreeCtrl = GetTreeCtrl();

   // build the image list.
   pImageList = new CImageList();
   pImageList->Create(16, 15, TRUE, 3, 2);	

   CBitmap bitmap;
   for(UINT iCnt=IDB_FULLPARENT; iCnt<=IDB_PACKAGE; iCnt++)	{
      bitmap.LoadBitmap(iCnt);
      pImageList->Add(&bitmap, (COLORREF)0xFFFFFF);
      bitmap.DeleteObject();
      }      
   TreeCtrl.SetImageList(pImageList, TVSIL_NORMAL);

   // item insert structure
   TV_INSERTSTRUCT tvstruct;

   tvstruct.item.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_TEXT;

   // Create the Assembly Tree
   populateAssemblyTree(pDoc, tvstruct, TreeCtrl);

   // Create the Packaged Part Tree
   populatePackagedPartTree(pDoc, tvstruct, TreeCtrl);

   // Create the Package Tree
   populatePackagesTree(pDoc, tvstruct, TreeCtrl);

   // Create the PhysicalUnit Tree
   populatePhysicalUnitTree(pDoc, tvstruct, TreeCtrl);

   // Create the MountingRestricitonArea Tree
   populateMountingRestrictionAreaTree(pDoc, tvstruct, TreeCtrl);

   // Create the NonPlatedThruHole Tree
   populateNonPlatedThruHoleTree(pDoc, tvstruct, TreeCtrl);
   }

void CAP210ProdView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) {
	// TODO: Add your specialized code here and/or call the base class
TRACE("In CAP210ProdView::OnUpdate()\r\n");
#if 0
   // get the tree control and delete any existing items
   CTreeCtrl &TreeCtrl = GetTreeCtrl();
   VERIFY(TreeCtrl.DeleteAllItems());

   // Repopulate the tree
   PopulateTree();
#endif
   }

BOOL CAP210ProdView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) {
	// TODO: Add your specialized code here and/or call the base class
   // Add the '+' and '-' and line graphics to the tree
	dwStyle |= TVS_HASLINES | TVS_LINESATROOT;	

	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
   }

void CAP210ProdView::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult)  {
	// TODO: Add your control notification handler code here
   // Get the data to display
   PWBDataBase *pDoc = (PWBDataBase *)GetDocument();
   NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;

	// TODO: Add your control notification handler code here
   HTREEITEM SelectedItem = pNMTreeView->itemNew.hItem;

   // get the tree control
   CTreeCtrl &TreeCtrl = GetTreeCtrl();

   // Get the select items Parent
   HTREEITEM ParentItem = TreeCtrl.GetParentItem(SelectedItem);

   if (ParentItem) { 
      AP210ObjectListItor CDitor(&(pDoc->ComponentDefinitions));
      // unselect everything
      pDoc->UnSelectAll();

      // Get the selected items OID
      int SelectedItemOID = TreeCtrl.GetItemData(SelectedItem);

      if (ParentItem == AssemblyTreeItem) { 

         // look to see what was selected
         // Was it the board?
         if (pDoc->PWB->GetOID() == SelectedItemOID) {
            pDoc->PWB->Select();
            }
         else {
            // Search for components 
            ComponentDefinition *cd;
            CDitor.Reset();
            while((cd = (ComponentDefinition *)CDitor.NextInstanceOf(ComponentDefinition::TypeID())) != NULL) {
               if (cd->GetOID() == SelectedItemOID) {
                  cd->Select();
                  break;
                  }
               }
            }
         }
      else if (ParentItem == PackagesTreeItem) {
         // Search for packages
         AP210ObjectListItor Pitor(&(pDoc->Packages));
         Package *p;
         Pitor.Reset();
         while((p = (Package *)Pitor.NextDirectInstanceOf(Package::TypeID())) != NULL) {
            if (p->GetOID() == SelectedItemOID) {
               p->Select(&CDitor);
               break;
               }
            }
         }
      else if (ParentItem == PackagedPartsTreeItem) {
         // Search for packaged_parts
         AP210ObjectListItor PPitor(&(pDoc->PackagedParts));
         PackagedPart *pp;
         PPitor.Reset();
         while((pp = (PackagedPart *)PPitor.NextDirectInstanceOf(PackagedPart::TypeID())) != NULL) {
            if (pp->GetOID() == SelectedItemOID) {
               pp->Select(&CDitor);
               break;
               }
            }
         }
      else if (ParentItem == PhysicalUnitsTreeItem) {
         // Search for packaged_parts
         AP210ObjectListItor PUitor(&(pDoc->PhysicalUnits));
         PhysicalUnit *pu;
         PUitor.Reset();
         while((pu = (PhysicalUnit *)PUitor.NextDirectInstanceOf(PhysicalUnit::TypeID())) != NULL) {
            if (pu->GetOID() == SelectedItemOID) {
               pu->Select(&CDitor);
               break;
               }
            }
         }
      else if (ParentItem == MountingRestrictionAreaItem) {
         // Search for mounting restriction areas
         AP210ObjectListItor MRAitor(&(pDoc->MountingRestrictionAreas));
         MountingRestrictionArea *mra;
         MRAitor.Reset();
         while((mra = (MountingRestrictionArea *)MRAitor.NextDirectInstanceOf(MountingRestrictionArea::TypeID())) != NULL) {
            if (mra->GetOID() == SelectedItemOID) {
               mra->Select();
               break;
               }
            }
         }
      else if (ParentItem == NonPlatedThruHoleItem) {
         // Search for non-plated thru holes
         AP210ObjectListItor NPTHitor(&(pDoc->NonPlatedThruHoles));
         NonPlatedThruHole *npth;
         NPTHitor.Reset();
         while((npth = (NonPlatedThruHole *)NPTHitor.NextDirectInstanceOf(NonPlatedThruHole::TypeID())) != NULL) {
            if (npth->GetOID() == SelectedItemOID) {
               npth->Select();
               break;
               }
            }
         }
      // Have the document handle the selected items.
      pDoc->OnSelection();

      // Update all the views to highlight what was selected.
      pDoc->UpdateAllViews(NULL);
      }
	*pResult = 0;
   }

void CAP210ProdView::OnRButtonDblClk(UINT nFlags, CPoint point)  {
   // TODO: Add your message handler code here and/or call default
   PWBDataBase *pDoc = (PWBDataBase *)GetDocument();

   CTreeCtrl &TreeCtrl = GetTreeCtrl();

   HTREEITEM SelectedItem = TreeCtrl.GetSelectedItem();

   if (SelectedItem && (pDoc->AP210Model != sdaiNULL)) {
      // Get the select items Parent

      if (SelectedItem == AssemblyTreeItem) {
         TRACE("Assembly Item seleted\n");
         // Display properties dialog box
         // create the dialog box
         CAssemblyPropertiesSheet assemblypropDlg("Assembly Properties", this);

         // display the dialog box
         assemblypropDlg.DoModal();
         }
      else {
         HTREEITEM ParentItem = TreeCtrl.GetParentItem(SelectedItem);

         if (ParentItem) { 
            AP210ObjectListItor CDitor(&(pDoc->ComponentDefinitions));

            // Get the selected items OID
            int SelectedItemOID = TreeCtrl.GetItemData(SelectedItem);

            if (ParentItem == AssemblyTreeItem) { 

               // look to see what was selected
               // Was it the board?
               if (pDoc->PWB->GetOID() == SelectedItemOID) {
                  // Display properties dialog box
                  // create the dialog box
                  CInterconnectModulePropertiesSheet interconnectmodulepropDlg("Interconnect Module Properties", this);

                  // set the dialog boxes values
                  interconnectmodulepropDlg.setValues(pDoc->AP210Model, pDoc->PWB);
                  interconnectmodulepropDlg.setReadOnly(pDoc->ReadOnly);

                  // display the dialog box
                  interconnectmodulepropDlg.DoModal();
                  }
               else {
                  // Search for packaged components
                  ComponentDefinition *cd;
                  CDitor.Reset();
                  while((cd = (ComponentDefinition *)CDitor.NextInstanceOf(ComponentDefinition::TypeID())) != NULL) {

                     if (cd->GetOID() == SelectedItemOID) {

                        if (cd->DynamicType(PackagedComponent::TypeID())) {
                           PackagedComponent *pc = (PackagedComponent *)cd;

                           // Display properties dialog box
                           // create the dialog box
                           CComponentPropertiesSheet comppropDlg("Packaged Component Properties", this);

                           // set the dialog boxes values
                           comppropDlg.setValues(pDoc->AP210Model, pc);
                           comppropDlg.setReadOnly(pDoc->ReadOnly);

                           // display the dialog box
                           comppropDlg.DoModal();
                           }
                        else {
                           // Display properties dialog box
                           // create the dialog box
                           CComponentDefinitionSheet comppropDlg("Mechanical Part Properties", this);

                           // set the dialog boxes values
                           comppropDlg.setValues(pDoc->AP210Model, cd);
                           comppropDlg.setReadOnly(pDoc->ReadOnly);

                           // display the dialog box
                           comppropDlg.DoModal();
                           }
                        break;
                        }
                     }
                  }
               }
            else if (ParentItem == UnPlacedComponentTreeItem) {
               // Search for packaged components
               ComponentDefinition *cd;
               CDitor.Reset();
               while((cd = (ComponentDefinition *)CDitor.NextInstanceOf(ComponentDefinition::TypeID())) != NULL) {

                  if (cd->GetOID() == SelectedItemOID) {

                     if (cd->DynamicType(PackagedComponent::TypeID())) {
                        PackagedComponent *pc = (PackagedComponent *)cd;

                        // Display properties dialog box
                        // create the dialog box
                        CComponentPropertiesSheet comppropDlg("Packaged Component Properties", this);

                        // set the dialog boxes values
                        comppropDlg.setValues(pDoc->AP210Model, pc);
                        comppropDlg.setReadOnly(pDoc->ReadOnly);

                        // display the dialog box
                        comppropDlg.DoModal();
                        }
                     else {
                        // Display properties dialog box
                        // create the dialog box
                        CComponentDefinitionSheet comppropDlg("Mechanical Part Properties", this);

                        // set the dialog boxes values
                        comppropDlg.setValues(pDoc->AP210Model, cd);
                        comppropDlg.setReadOnly(pDoc->ReadOnly);

                        // display the dialog box
                        comppropDlg.DoModal();
                        }
                     break;
                     }
                  }
               }
            else if (ParentItem == PackagesTreeItem) {
               // Search for packages
               AP210ObjectListItor Pitor(&(pDoc->Packages));
               Package *p;
               Pitor.Reset();
               while((p = (Package *)Pitor.NextDirectInstanceOf(Package::TypeID())) != NULL) {
                  if (p->GetOID() == SelectedItemOID) {
                        // Display properties dialog box
                        // create the dialog box
                        CPackagePropertiesSheet packagepropDlg("Package Properties", this);

                        // set the dialog boxes values
                        packagepropDlg.setValues(pDoc->AP210Model, p);
                        packagepropDlg.setReadOnly(pDoc->ReadOnly);

                        // display the dialog box
                        packagepropDlg.DoModal();
                     break;
                     }
                  }
               }
            else if (ParentItem == PackagedPartsTreeItem) {
               // Search for packaged_parts
               AP210ObjectListItor PPitor(&(pDoc->PackagedParts));
               PackagedPart *pp;
               PPitor.Reset();
               while((pp = (PackagedPart *)PPitor.NextDirectInstanceOf(PackagedPart::TypeID())) != NULL) {
                  if (pp->GetOID() == SelectedItemOID) {
                        // Display properties dialog box
                        // create the dialog box
                        CPackagedPartPropertiesSheet packagedpartpropDlg("Packaged Part Properties", this);

                        // set the dialog boxes values
                        packagedpartpropDlg.setValues(pDoc->AP210Model, pp);

                        // display the dialog box
                        packagedpartpropDlg.DoModal();
                     break;
                     }
                  }
               }
            else if (ParentItem == PhysicalUnitsTreeItem) {
               // Search for physical_units
               AP210ObjectListItor PUitor(&(pDoc->PhysicalUnits));
               PhysicalUnit *pu;
               PUitor.Reset();
               while((pu = (PhysicalUnit *)PUitor.NextDirectInstanceOf(PhysicalUnit::TypeID())) != NULL) {
                  if (pu->GetOID() == SelectedItemOID) {
                        // Display properties dialog box
                        // create the dialog box
                        CPackagePropertiesSheet packagepropDlg("PhysicalUnit Properties", this, ID_PHYSICAL_UNIT);

                        // set the dialog boxes values
                        packagepropDlg.setValues(pDoc->AP210Model, pu);
                        packagepropDlg.setReadOnly(pDoc->ReadOnly);

                        // display the dialog box
                        packagepropDlg.DoModal();
                     break;
                     }
                  }
               }
            else if (ParentItem == NonPlatedThruHoleItem) {
               // Search for physical_units
               AP210ObjectListItor NPTHitor(&(pDoc->NonPlatedThruHoles));
               NonPlatedThruHole *npth;
               NPTHitor.Reset();
               while((npth = (NonPlatedThruHole *)NPTHitor.NextDirectInstanceOf(NonPlatedThruHole::TypeID())) != NULL) {
                 if (npth->GetOID() == SelectedItemOID) {
                     // Display properties dialog box
                     // create the dialog box
                     CNonPlatedThruHoleSheet npthpropDlg("Non-Plated Thru Hole Properties", this);

                     // set the dialog boxes values
                     npthpropDlg.setValues(pDoc->AP210Model, npth);
                     npthpropDlg.setReadOnly(pDoc->ReadOnly);

                     // display the dialog box
                     npthpropDlg.DoModal();
                     break;
                     }
                  }
               }
            else if (ParentItem == MountingRestrictionAreaItem) {
               // Search for physical_units
               AP210ObjectListItor MRAitor(&(pDoc->MountingRestrictionAreas));
               MountingRestrictionArea *mra;
               MRAitor.Reset();
               while((mra = (MountingRestrictionArea *)MRAitor.NextDirectInstanceOf(MountingRestrictionArea::TypeID())) != NULL) {
                  if (mra->GetOID() == SelectedItemOID) {
                     // Display properties dialog box
                     // create the dialog box
                     CComponentPlacementRestrictionAreaSheet mrapropDlg("Component Placement Restriction Area Properties", this);
                     // set the dialog boxes values
                     mrapropDlg.setValues(pDoc, mra);
                     mrapropDlg.setReadOnly(pDoc->ReadOnly);

                     // display the dialog box
                     mrapropDlg.DoModal();
                     break;
                     }
                  }
               }
            }
         }
      }
	CTreeView::OnRButtonDblClk(nFlags, point);
   }

void CAP210ProdView::OnRButtonDown(UINT nFlags, CPoint point) {
	// TODO: Add your message handler code here and/or call default
   UINT pFlags;
   CTreeCtrl &TreeCtrl = GetTreeCtrl();

   HTREEITEM TreeItem = TreeCtrl.HitTest(point, &pFlags);

   if (TreeItem) {
      TreeCtrl.SelectItem(TreeItem);
      }
	CTreeView::OnRButtonDown(nFlags, point);
   }

void CAP210ProdView::UpdateTree() {
TRACE("CAP210ProdView::UpdateTree\r\n");
   PWBDataBase *pDoc = (PWBDataBase *)GetDocument();
   // get the tree control and delete any existing items
   CTreeCtrl &TreeCtrl = GetTreeCtrl();
   VERIFY(TreeCtrl.DeleteAllItems());

   // Repopulate the tree
   PopulateTree();

   // Update all the views.
   pDoc->UpdateAllViews(NULL);
   }

void CAP210ProdView::populatePackagesTree(PWBDataBase *pDoc,
                                          TV_INSERTSTRUCT tvstruct,
                                          CTreeCtrl &TreeCtrl) {
   HTREEITEM NewTreeItem;
   AP210ObjectListItor Pitor(&(pDoc->Packages));
   Package *p;
   // 
   // Create the root of the Package list
   tvstruct.hParent = NULL;
   tvstruct.item.pszText = _T("Packages");
   tvstruct.hInsertAfter = TVI_LAST;

   // add the items if they are in the list
   if (pDoc->Packages.SizeOf() > 0) {
      tvstruct.item.iImage = 0; // IDB_FULLPARENT
      tvstruct.item.iSelectedImage = 2; // IDB_OPENPARENT
   
      // save this as the parts tree
      PackagesTreeItem = TreeCtrl.InsertItem(&tvstruct);
	
      // all the parts have this has there root.
      // and we want to sort them
      tvstruct.hParent = PackagesTreeItem;
      tvstruct.hInsertAfter = TVI_SORT;

      // Add the parts to the tree
      tvstruct.item.iImage = 6; // IDB_PACKAGE
      tvstruct.item.iSelectedImage = 6; // IDB_PACKAGE
      Pitor.Reset();
      while((p = (Package *)Pitor.NextDirectInstanceOf(Package::TypeID())) != NULL) {
         tvstruct.item.pszText = _T(p->PartNumber);
         tvstruct.item.lParam = p->GetOID();

         // save this in p
         NewTreeItem = TreeCtrl.InsertItem(&tvstruct);
         TreeCtrl.SetItemData(NewTreeItem, p->GetOID());
         }
      }
   else { // use empty icons since the list is empty
      tvstruct.item.iImage = 1; // IDF_EMPTYPARENT
      tvstruct.item.iSelectedImage = 1; // IDF_EMPTYPARENT

      // save this as the parts tree
      PackagesTreeItem = TreeCtrl.InsertItem(&tvstruct);
      }
   }
void CAP210ProdView::populatePhysicalUnitTree(PWBDataBase *pDoc,
                                              TV_INSERTSTRUCT tvstruct,
                                              CTreeCtrl &TreeCtrl) {
   HTREEITEM NewTreeItem;
   AP210ObjectListItor PUitor(&(pDoc->PhysicalUnits));
   PhysicalUnit *pu;
   // 
   // Create the root of the PhysicalUnit list
   tvstruct.hParent = NULL;
   tvstruct.item.pszText = _T("Physical Units");
   tvstruct.hInsertAfter = TVI_LAST;

   // add the items if they are in the list
   if (pDoc->PhysicalUnits.SizeOf() > 0) {
      tvstruct.item.iImage = 0; // IDB_FULLPARENT
      tvstruct.item.iSelectedImage = 2; // IDB_OPENPARENT
   
      // save this as the parts tree
      PhysicalUnitsTreeItem = TreeCtrl.InsertItem(&tvstruct);
	
      // all the parts have this has there root.
      // and we want to sort them
      tvstruct.hParent = PhysicalUnitsTreeItem;
      tvstruct.hInsertAfter = TVI_SORT;
      // Add the physical_units to the tree
      tvstruct.item.iImage = 6; // IDB_PACKAGE
      tvstruct.item.iSelectedImage = 6; // IDB_PACKAGE
      PUitor.Reset();
      while((pu = (PhysicalUnit *)PUitor.NextDirectInstanceOf(PhysicalUnit::TypeID())) != NULL) {
         tvstruct.item.pszText = _T(pu->getPartNumber());
         tvstruct.item.lParam = pu->GetOID();

         // save this in pu
         NewTreeItem = TreeCtrl.InsertItem(&tvstruct);
         TreeCtrl.SetItemData(NewTreeItem, pu->GetOID());
         }
      }
   else { // use empty icons since the list is empty
      tvstruct.item.iImage = 1; // IDF_EMPTYPARENT
      tvstruct.item.iSelectedImage = 1; // IDF_EMPTYPARENT

      PhysicalUnitsTreeItem = TreeCtrl.InsertItem(&tvstruct);
      }
   }
void CAP210ProdView::populatePackagedPartTree(PWBDataBase *pDoc,
                                          TV_INSERTSTRUCT tvstruct,
                                          CTreeCtrl &TreeCtrl) {
   HTREEITEM NewTreeItem;
   AP210ObjectListItor PPitor(&(pDoc->PackagedParts));
   PackagedPart *pp;

   // Create the root of the Packaged Part list
   tvstruct.hParent = NULL;
   tvstruct.item.pszText = _T("Packaged Parts");
   tvstruct.hInsertAfter = TVI_LAST;

   // add the items if they are in the list
   if (pDoc->PackagedParts.SizeOf() > 0) {
      tvstruct.item.iImage = 0; // IDB_FULLPARENT
      tvstruct.item.iSelectedImage = 2; // IDB_OPENPARENT
   
      // save this as the packaged parts tree
      // and we want to sort them
      PackagedPartsTreeItem = TreeCtrl.InsertItem(&tvstruct);
      tvstruct.hInsertAfter = TVI_SORT;
	
      // all the packaged_parts have this has there root.
      tvstruct.hParent = PackagedPartsTreeItem;

      // Add the packaged parts to the tree
      tvstruct.item.iImage = 5; // IDB_PACKAGED_PART
      tvstruct.item.iSelectedImage = 5; // IDB_PACKAGED_PART
      PPitor.Reset();
      while((pp = (PackagedPart *)PPitor.NextDirectInstanceOf(PackagedPart::TypeID())) != NULL) {
         tvstruct.item.pszText = _T(pp->PartNumber);
         tvstruct.item.lParam = pp->GetOID();

         // save this in pc
         NewTreeItem = TreeCtrl.InsertItem(&tvstruct);
         TreeCtrl.SetItemData(NewTreeItem, pp->GetOID());
         }
      }
   else { // use empty icons since the list is empty
      tvstruct.item.iImage = 1; // IDF_EMPTYPARENT
      tvstruct.item.iSelectedImage = 1; // IDF_EMPTYPARENT

      // save this as the packaged parts tree
      PackagedPartsTreeItem = TreeCtrl.InsertItem(&tvstruct);
      }
   }
void CAP210ProdView::populateAssemblyTree(PWBDataBase *pDoc,
                                          TV_INSERTSTRUCT tvstruct,
                                          CTreeCtrl &TreeCtrl) {
   // Setup iteration for assembly
   HTREEITEM NewTreeItem;
   int UnPlacedCount = 0;
   AP210ObjectListItor CDitor(&(pDoc->ComponentDefinitions));
   ComponentDefinition *cd;
   PackagedComponent *pc;

   // Create the root of the tree Assembly.
   tvstruct.hParent = NULL;
   tvstruct.hInsertAfter = TVI_FIRST;
   tvstruct.item.pszText = _T("Assembly");

   // save this as the assembly tree
   tvstruct.item.iImage = 0; // IDB_FULLPARENT
   tvstruct.item.iSelectedImage = 2; // IDB_OPENPARENT
   AssemblyTreeItem = TreeCtrl.InsertItem(&tvstruct);
	
   // all the components have this has there root.
   // and we want to sort them.
   tvstruct.hParent = AssemblyTreeItem;
   tvstruct.hInsertAfter = TVI_SORT;

   // Add the placed components to the tree
   tvstruct.item.iImage = 3; // IDB_COMPONENT
   tvstruct.item.iSelectedImage = 3; // IDB_COMPONENT
   CDitor.Reset();
   while((pc = (PackagedComponent *)CDitor.NextDirectInstanceOf(PackagedComponent::TypeID())) != NULL) {

      if (pc->getComponentLocationRef() != sdaiNULL) {
         tvstruct.item.pszText = _T(pc->getName());
         tvstruct.item.lParam = pc->GetOID();

         // save this in pc
         NewTreeItem = TreeCtrl.InsertItem(&tvstruct);
         TreeCtrl.SetItemData(NewTreeItem, pc->GetOID());
         }
      else {
         UnPlacedCount++;
         }
      }
   // Add the placed Component_Definitons (e.g. Mechanical Parts) to the tree
   CDitor.Reset();
   while((cd = (ComponentDefinition *)CDitor.NextDirectInstanceOf(ComponentDefinition::TypeID())) != NULL) {
      if (cd->getComponentLocationRef() != sdaiNULL) {
         tvstruct.item.pszText = _T(cd->getName());
         tvstruct.item.lParam = cd->GetOID();

         // save this in pc
         NewTreeItem = TreeCtrl.InsertItem(&tvstruct);
         TreeCtrl.SetItemData(NewTreeItem, cd->GetOID());
         }
      else {
         UnPlacedCount++; // Not sure about this?
         }
      }
   // Add the PWB to the start of the list!
   if (pDoc->PWB != NULL) {
      tvstruct.item.iImage = 4; // IDB_PWB
      tvstruct.item.iSelectedImage = 4; // IDB_PWB
      tvstruct.hInsertAfter = TVI_FIRST; // or TVI_FIRST, TVI_SORT
      tvstruct.item.pszText = _T(pDoc->PWB->getName());
      tvstruct.item.lParam = pDoc->PWB->GetOID();

      // save this in pwb
      NewTreeItem = TreeCtrl.InsertItem(&tvstruct);
      TreeCtrl.SetItemData(NewTreeItem, pDoc->PWB->GetOID());

      // Add the placed components to the assembly tree
      // Create the root of the Unplaced Component Tree.
      tvstruct.hInsertAfter = TVI_FIRST; // or TVI_FIRST, TVI_SORT
      tvstruct.item.pszText = _T("Unplaced");
      }

   // save this as the unplaced component tree
   if (UnPlacedCount > 0) {
      tvstruct.item.iImage = 0; // IDB_FULLPARENT
      tvstruct.item.iSelectedImage = 2; // IDB_OPENPARENT

      UnPlacedComponentTreeItem = TreeCtrl.InsertItem(&tvstruct);

      // all the unplaced components have this has there root.
      tvstruct.hParent = UnPlacedComponentTreeItem;
      tvstruct.hInsertAfter = TVI_SORT; // or TVI_FIRST, TVI_SORT

      // Add the unplaced components to the tree
      tvstruct.item.iImage = 3; // IDB_COMPONENT
      tvstruct.item.iSelectedImage = 3; // IDB_COMPONENT
      CDitor.Reset();
      while((pc = (PackagedComponent *)CDitor.NextDirectInstanceOf(PackagedComponent::TypeID())) != NULL) {

         if (pc->getComponentLocationRef() == sdaiNULL) {
            tvstruct.item.pszText = _T(pc->getName());
            tvstruct.item.lParam = pc->GetOID();

            // save this in pc
            NewTreeItem = TreeCtrl.InsertItem(&tvstruct);
            TreeCtrl.SetItemData(NewTreeItem, pc->GetOID());
            }
         }
      }
   else {
      tvstruct.item.iImage = 1; // IDF_EMPTYPARENT
      tvstruct.item.iSelectedImage = 1; // IDF_EMPTYPARENT

      UnPlacedComponentTreeItem = TreeCtrl.InsertItem(&tvstruct);
      }
   }
void CAP210ProdView::populateMountingRestrictionAreaTree(PWBDataBase *pDoc,
                                          TV_INSERTSTRUCT tvstruct,
                                          CTreeCtrl &TreeCtrl) {
   HTREEITEM NewTreeItem;
   AP210ObjectListItor MRAitor(&(pDoc->MountingRestrictionAreas));
   MountingRestrictionArea *mra;

   // Create the root of the Restriction Area list
   tvstruct.hParent = NULL;
   tvstruct.item.pszText = _T("Restriction Areas");
   tvstruct.hInsertAfter = TVI_LAST;

   // add the items if they are in the list
   if (pDoc->MountingRestrictionAreas.SizeOf() > 0) {
      tvstruct.item.iImage = 0; // IDB_FULLPARENT
      tvstruct.item.iSelectedImage = 2; // IDB_OPENPARENT
   
      // save this as the parts tree
      MountingRestrictionAreaItem = TreeCtrl.InsertItem(&tvstruct);

      // all the parts have this has there root.
      // and we want to sort them
      tvstruct.hParent = MountingRestrictionAreaItem;
      tvstruct.hInsertAfter = TVI_SORT;
      // Add the physical_units to the tree
      tvstruct.item.iImage = 6; // IDB_PACKAGE
      tvstruct.item.iSelectedImage = 6; // IDB_PACKAGE
      MRAitor.Reset();
      while((mra = (MountingRestrictionArea *)MRAitor.NextDirectInstanceOf(MountingRestrictionArea::TypeID())) != NULL) {
         tvstruct.item.pszText = _T("MRA");
         tvstruct.item.lParam = mra->GetOID();

         // save this in pu
         NewTreeItem = TreeCtrl.InsertItem(&tvstruct);
         TreeCtrl.SetItemData(NewTreeItem, mra->GetOID());
         }
      }
   else { // use empty icons since the list is empty
      tvstruct.item.iImage = 1; // IDF_EMPTYPARENT
      tvstruct.item.iSelectedImage = 1; // IDF_EMPTYPARENT

      MountingRestrictionAreaItem = TreeCtrl.InsertItem(&tvstruct);
      }
   }
void CAP210ProdView::populateNonPlatedThruHoleTree(PWBDataBase *pDoc,
                                                   TV_INSERTSTRUCT tvstruct,
                                                   CTreeCtrl &TreeCtrl) {
   HTREEITEM NewTreeItem;
   AP210ObjectListItor NPTHitor(&(pDoc->NonPlatedThruHoles));
   NonPlatedThruHole *npth;

   // Create the root of the Non-Plated Thru Hole list
   tvstruct.hParent = NULL;
   tvstruct.item.pszText = _T("Non-Plated Thru-Holes");
   tvstruct.hInsertAfter = TVI_LAST;

   // add the items if they are in the list
   if (pDoc->NonPlatedThruHoles.SizeOf() > 0) {
      tvstruct.item.iImage = 0; // IDB_FULLPARENT
      tvstruct.item.iSelectedImage = 2; // IDB_OPENPARENT
   
      // save this as the non-plated thru-hole tree
      NonPlatedThruHoleItem = TreeCtrl.InsertItem(&tvstruct);

      // all the parts have this has there root.
      // and we want to sort them
      tvstruct.hParent = NonPlatedThruHoleItem;
      tvstruct.hInsertAfter = TVI_SORT;
      // Add the physical_units to the tree
      tvstruct.item.iImage = 6; // IDB_PACKAGE
      tvstruct.item.iSelectedImage = 6; // IDB_PACKAGE
      NPTHitor.Reset();
      while((npth = (NonPlatedThruHole *)NPTHitor.NextDirectInstanceOf(NonPlatedThruHole::TypeID())) != NULL) {
         tvstruct.item.pszText = _T(npth->getId());
         tvstruct.item.lParam = npth->GetOID();

         // save this in pu
         NewTreeItem = TreeCtrl.InsertItem(&tvstruct);
         TreeCtrl.SetItemData(NewTreeItem, npth->GetOID());
         }
      }
   else { // use empty icons since the list is empty
      tvstruct.item.iImage = 1; // IDF_EMPTYPARENT
      tvstruct.item.iSelectedImage = 1; // IDF_EMPTYPARENT

      NonPlatedThruHoleItem = TreeCtrl.InsertItem(&tvstruct);
      }
   }

void CAP210ProdView::OnComponentRestrictionArea() {
	// TODO: Add your command handler code here
   // create the dialog box
   CComponentPlacementRestriction craDlg;


   // display the dialog box
   craDlg.setValues((PWBDataBase *)GetDocument());
   craDlg.DoModal();	
   }
