// PWBDataBase.h: interface for the PWBDataBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PWBDATABASE_H__2E12FCE2_5E4F_11D3_9B0E_0080AD428934__INCLUDED_)
#define AFX_PWBDATABASE_H__2E12FCE2_5E4F_11D3_9B0E_0080AD428934__INCLUDED_

#include "SDAI\BoardComponent.h"	 // Added by ClassView
#include "SDAI\AP210ObjectList.h" // Added by ClassView

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CPropertiesDlg;
class PackagedComponent;

class PWBDataBase 
:    public CDocument
  {
  friend class CChildFrame;
   public:
      PWBDataBase();
      virtual ~PWBDataBase();

   public:
	   BOOL ReadOnly;
	   AP210ObjectList GeomList;
	   AP210ObjectList ComponentDefinitions;
	   AP210ObjectList PackagedParts;
	   AP210ObjectList Packages;
	   AP210ObjectList PhysicalUnits;
	   AP210ObjectList MountingRestrictionAreas;
	   BoardComponent *PWB;
	   AP210ObjectList NonPlatedThruHoles;


   protected: 
      CString SelectedRefDes;
      CString SelectedPartNumber;

   private:
      // Used to update packaged_component surface
      SdaiADB primary_surface;
      SdaiADB secondary_surface;

      // enter points into design
      SdaiAppInstance AssemblyModulePhysicalDesign;
      SdaiAppInstance AssemblyModulePhysicalDesignUsage;
      SdaiAppInstance InterconnectModulePhysicalDesign;
      SdaiAppInstance InterconnectModulePhysicalDesignUsage;
      
   protected: 
	   void selectDisplayModel();
      virtual void setFileProperties(CPropertiesDlg *propDlg, RoseDesign *design);
      virtual void setPartNumber(ComponentDefinition *pc);

   public:
	   SdaiAppInstance getInterconnectModulePhysicalDesignUsage();
	   SdaiAppInstance getInterconnectModulePhysicalDesign();
	   SdaiAppInstance getAssemblyModulePhysicalDesignUsage();
	   SdaiAppInstance getAssemblyModulePhysicalDesign();
	   virtual void updateMountingRestrictionAreas();
	   int MountingRestrictionAreaAppearance;
	   SdaiADB  getSecondarySurface();
	   SdaiADB  getPrimarySurface();
	   virtual int assignItemFindNumber();
	   SdaiModel AP210Model;

      // get selected functions
	   virtual int getSelectedPackagedComponents(AP210ObjectList *list);
	   virtual int numComponentsSelected();
	   virtual int getSelectedComponentDefinitions(AP210ObjectList *list);
	   virtual int getSelectedNonPlatedThruHoles(AP210ObjectList *list);
	   virtual int getSelectedMountingRestrictionAreas(AP210ObjectList *list);

      void UnSelectAll();
      void OnSelection();

      // packaged_component Matrix functions.
      int getTransformationMatrix(double m[16],
                                  SdaiAppInstance A2P_LOC,
                                  SdaiAppInstance unit);
      void setTransformationMatrix(double m[16],
                                   SdaiAppInstance A2P_LOC,
                                   SdaiAppInstance unit);
 

      // packaged_component surface functions
      SdaiString getPackagedComponentSurface(SdaiAppInstance cl);
      void setPackagedComponentSurface(SdaiAppInstance cl, const char *surface);
      SdaiADB createPackagedComponentSurface(const char *surface);

      // sdai Procedures
      SdaiAppInstance getPhysicalUnitsProductDefinitionShape(SdaiAppInstance pu);
      SdaiAppInstance getSurfaceShapeAspect(const char *surface);
      void UpdateProdView();
	   SdaiAppInstance getAssembliesInterconnectModuleProduct();

   private:
	   SdaiAppInstance AssemblyModuleProduct;
	   SdaiAppInstance getNamedPhysicalUnit(SdaiNPL puList, SdaiString Name, SdaiString ProductRelationship);
	   SdaiNPL getProductsProductDefinitions(SdaiAppInstance prod,
                                            SdaiNPL resultList);
	   SdaiNPL getDefinedProducts(SdaiNPL resultList,
                                 SdaiString Name,
                                 SdaiString ProductRelationship);
	   SdaiAppInstance getNamedPhysicalUnit(SdaiString Name, SdaiString ProductRelationship);
      int ItemFindNumberSeed;
   };

#endif // !defined(AFX_PWBDATABASE_H__2E12FCE2_5E4F_11D3_9B0E_0080AD428934__INCLUDED_)
