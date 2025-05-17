// PWBDataBase.cpp: implementation of the PWBDataBase class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AP210Viewer.h"
#include "PWBDataBase.h"
#include "PropertiesDlg.h"
#include "AP210ProdView.h"

// Sdai
#include "Sdai/AP210SdaiModel.h"
#include "Sdai/PackagedComponent.h"
#include "Sdai/MountingRestrictionArea.h"
#include "Sdai/NonPlatedThruHole.h"
#include "Sdai/AP210MagicStrings.h"
#include "Sdai/SdaiStoredProceedures.h"
#include "Sdai/ExtractGeometry.h"

// OpenGL
#include "OpenGl/MatrixUtilities.h"

// GUI
#include "AssemblyProductSelectDlg.h"

#ifdef ARMSTUFF
#ifdef _DEBUG
// AP210 Arm classes
#include <layer.h>
#include <external_definition.h>
#include <ARMObjectList.h>
#endif
#endif

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PWBDataBase::PWBDataBase() {
   ReadOnly = FALSE;
   PWB = NULL;
   ItemFindNumberSeed = 0;
   primary_surface = sdaiNULL;
   secondary_surface = sdaiNULL;
   MountingRestrictionAreaAppearance = IDC_CRA_INVISIBLE;

   // set design entry points
   AssemblyModulePhysicalDesign = sdaiNULL;
   AssemblyModulePhysicalDesignUsage = sdaiNULL;
   InterconnectModulePhysicalDesign = sdaiNULL;
   InterconnectModulePhysicalDesignUsage = sdaiNULL;

#ifdef _DEBUG
#if 0
   TRACE("About to create an ARM layer object\r\n");
   class layer *tmp = layer::Construct();
#ifdef VERBOSE
   class managed_design_object *tmp2;
   tmp->hasRequiredAttributes();
   TRACE("tmp has an OID of %d\n", tmp->getOID());
   TRACE("Is tmp a layer: %d\r\n", tmp->DynamicType(layer::TypeID()));
   TRACE("Is tmp a managed_design_object: %d\r\n", tmp->DynamicType(managed_design_object::TypeID()));
   TRACE("Is tmp a external_definition: %d\r\n", tmp->DynamicType(external_definition::TypeID()));
   TRACE("\ntmp layer::InstanceOf 0x%08x\n", layer::InstanceOf(tmp));
   TRACE("tmp layer::KindOf 0x%08x\n", layer::KindOf(tmp));
   TRACE("\ntmp managed_design_object::InstanceOf 0x%08x\n", managed_design_object::InstanceOf(tmp));
   TRACE("tmp managed_design_object::KindOf 0x%08x\n", managed_design_object::KindOf(tmp));
   TRACE("\ntmp external_definition::InstanceOf 0x%08x\n", external_definition::InstanceOf(tmp));
   TRACE("tmp external_definition::KindOf 0x%08x\n", external_definition::KindOf(tmp));
   tmp2 = managed_design_object::KindOf(tmp);
   TRACE("\ntmp2 has an OID of %d\n", tmp->getOID());
   TRACE("tmp a layer: %d\r\n", tmp->getTypeID());
   TRACE("tmp2 a layer: %d\r\n", tmp2->getTypeID());
   TRACE("Is tmp2 a layer: %d\r\n", tmp2->DynamicType(layer::TypeID()));
   TRACE("Is tmp2 a managed_design_object: %d\r\n", tmp2->DynamicType(managed_design_object::TypeID()));
   TRACE("Is tmp2 a external_definition: %d\r\n", tmp2->DynamicType(external_definition::TypeID()));
   TRACE("\ntmp2 layer::InstanceOf 0x%08x\n", layer::InstanceOf(tmp2));
   TRACE("tmp2 layer::KindOf 0x%08x\n", layer::KindOf(tmp2));
   TRACE("\ntmp2 managed_design_object::InstanceOf 0x%08x\n", managed_design_object::InstanceOf(tmp2));
   TRACE("tmp2 managed_design_object::KindOf 0x%08x\n", managed_design_object::KindOf(tmp2));
   TRACE("\ntmp2 external_definition::InstanceOf 0x%08x\n", external_definition::InstanceOf(tmp2));
   TRACE("tmp2 external_definition::KindOf 0x%08x\n", external_definition::KindOf(tmp2));
#else
   class managed_design_object *tmp2 = managed_design_object::Construct();

   class ARMObjectList list;
   list.Add(tmp);
   list.Add(tmp2);
   TRACE("List Ids\r\n");
   list.ListIds(); TRACE("\r\n");

   delete tmp2;
#endif
   delete tmp;
#endif
#endif
   }

PWBDataBase::~PWBDataBase() {
   ComponentDefinition *cd;
   AP210ObjectListItor CDitor(&ComponentDefinitions);

   PackagedPart *pp;
   AP210ObjectListItor PPitor(&PackagedParts);

   Package *p;
   AP210ObjectListItor Pitor(&Packages);

   MountingRestrictionArea *mra;
   AP210ObjectListItor MRAitor(&MountingRestrictionAreas);

   NonPlatedThruHole *npth;
   AP210ObjectListItor NPTHitor(&NonPlatedThruHoles);

   AP210Object *obj;
   AP210ObjectListItor itor2(&GeomList);

// more hunches MTK
   SelectedRefDes = "";
   SelectedPartNumber = "";

   // Delete Packaged Components List
   while((cd = (PackagedComponent *)CDitor.Next()) != NULL) {
      ComponentDefinitions.Delete(cd);
      delete cd;
      }
   // Delete Packaged Parts List
   while((pp = (PackagedPart *)PPitor.Next()) != NULL) {
      PackagedParts.Delete(pp);
      delete pp;
      }
   // Delete Package List
   while((p = (Package *)Pitor.Next()) != NULL) {
      Packages.Delete(p);
      delete p;
      }
   // Delete MountingRestrictionArea List
   while((mra = (MountingRestrictionArea *)MRAitor.Next()) != NULL) {
      MountingRestrictionAreas.Delete(mra);
      delete mra;
      }
   // Delete NonPlatedThruHole List
   while((npth = (NonPlatedThruHole *)MRAitor.Next()) != NULL) {
      NonPlatedThruHoles.Delete(npth);
      delete npth;
      }
   // Delete the Board
   if (PWB != NULL) {
      delete PWB;
      PWB = NULL;
      }
   // Delete the Geometry List
   while((obj = itor2.Next()) != NULL) {
      GeomList.Delete(obj);
      delete obj;
      }
   }
void PWBDataBase::OnSelection() {
   // Setup for components 
   AP210ObjectListItor itor(&ComponentDefinitions);
   ComponentDefinition *cd;
   int pccount = 0;
   ComponentDefinition *selectedpc;

   // update refdes pane in the child window
   SelectedRefDes = "";
   if (PWB->isSelected()) {
      SelectedRefDes += PWB->getName();
      SelectedRefDes += " ";
      }
   itor.Reset();
   while((cd = (ComponentDefinition *)itor.NextInstanceOf(ComponentDefinition::TypeID())) != NULL) {
      if (cd->isSelected()) {
         pccount++;
         selectedpc = cd;
         SelectedRefDes += cd->getName();
         SelectedRefDes += " ";
         }
      }
   if (pccount == 1) {
      setPartNumber(selectedpc);
      }
   else {
      SelectedPartNumber = "";
      }
   }

void PWBDataBase::UnSelectAll() {
   // Setup for components 
   AP210ObjectListItor CDitor(&ComponentDefinitions);
   ComponentDefinition *cd;

   // Setup for mounting restriction areas
   AP210ObjectListItor MRAitor(&MountingRestrictionAreas);
   MountingRestrictionArea *mra;

   // Setup for non-plated thru holes
   AP210ObjectListItor NPTHitor(&NonPlatedThruHoles);
   NonPlatedThruHole *npth;

   // unselect PWB
   PWB->unSelect();

   // unselect components
   CDitor.Reset();
   while((cd = (ComponentDefinition *)CDitor.NextInstanceOf(ComponentDefinition::TypeID())) != NULL) {
      cd->unSelect();
      }
   // unselect mounting restriction areas
   MRAitor.Reset();
   while((mra = (MountingRestrictionArea *)MRAitor.NextDirectInstanceOf(MountingRestrictionArea::TypeID())) != NULL) {
      mra->unSelect();
      }
   // unselect non-plated thru holes
   NPTHitor.Reset();
   while((npth = (NonPlatedThruHole *)NPTHitor.NextDirectInstanceOf(NonPlatedThruHole::TypeID())) != NULL) {
      npth->unSelect();
      }
  }
/*
 * SetPartNumber()
 * 
 * Set SelectedPartNumber so that the partnumber will
 * be displayed, how you get the part number varies
 * by document type.
 */
void PWBDataBase::setPartNumber(ComponentDefinition *pc) {
   SelectedPartNumber = "";
   }

void PWBDataBase::setFileProperties(CPropertiesDlg *propDlg, RoseDesign *design) {
   List(RoseDesign) *schemas;
   ListOfString *s;
   unsigned i, sz;
   CString author;
   CString description;
   CString organization;
   CString schema_name;

   TRACE("name: %s\r\n", design->header_name()->name());
   TRACE("description:\r\n");
   s = design->header_description()->description();
   for(i=0, sz=s-> size(); i<sz; i++) {
      description += s->get(i);
      description += "\n";
      TRACE("  %s\r\n", s->get(i));
      }
   TRACE("implementation_level: %s\r\n", design->header_description()->implementation_level());

   TRACE("time_stamp: %s\r\n", design->header_name()->time_stamp());
   TRACE("author:\r\n");
   s = design->header_name()->author();
   for(i=0, sz=s-> size(); i<sz; i++) {
      author += s->get(i);
      author += "\n";
      TRACE("  %s\r\n", s->get(i));
      }
   TRACE("organization:\r\n");
   s = design->header_name()->organization();
   for(i=0, sz=s-> size(); i<sz; i++) {
      organization += s->get(i);
      organization += "\n";
      TRACE("  %s\r\n", s->get(i));
      }
   TRACE("preprocessor_version: %s\r\n", design->header_name()->preprocessor_version());
   TRACE("originating_system: %s\r\n", design->header_name()->originating_system());
   TRACE("authorisation: %s\r\n", design->header_name()->authorisation());
 
    
   schemas = design->schemas();
   for(i=0, sz=schemas->size(); i<sz; i++) {
      schema_name += schemas->get(i)->name();
      schema_name += "\n";
      TRACE("Design contains %s schema\r\n", schemas->get(i)->name());
      }
   // update the dialog box
   propDlg->m_schema_name = schema_name;
   propDlg->m_name = design->header_name()->name();
   propDlg->m_description = description;
   propDlg->m_implementation_level = design->header_description()->implementation_level();

   propDlg->m_time_stamp = design->header_name()->time_stamp();
   propDlg->m_author = author;
   propDlg->m_organization = organization;
   propDlg->m_preprocessor_version = design->header_name()->preprocessor_version();
   propDlg->m_originating_system = design->header_name()->originating_system();
   propDlg->m_authorisation = design->header_name()->authorisation();
}

/*
 * numComponentsSelected()
 *
 * Returns the number of selected components.
 */
int PWBDataBase::numComponentsSelected() {
   int selected = 0;
   // Setup for components 
   AP210ObjectListItor itor(&ComponentDefinitions);
   PackagedComponent *pc;

   // unselect PWB
   selected = PWB->isSelected();

   // unselect components
   itor.Reset();
   while((pc = (PackagedComponent *)itor.NextInstanceOf(ComponentDefinition::TypeID())) != NULL) {
      selected += pc->isSelected();
      }
   return selected;
   }
/*
 * getSelectedPackagedComponents()
 *
 * Returns the number of selected Packaged Components and 
 * adds them to the list passed in.
 */
int PWBDataBase::getSelectedPackagedComponents(AP210ObjectList *list) {
   // initialize the counter
   int selected = 0;

   // Setup for components 
   AP210ObjectListItor itor(&ComponentDefinitions);
   PackagedComponent *pc;

   // components selected?
   itor.Reset();
   while((pc = (PackagedComponent *)itor.NextInstanceOf(PackagedComponent::TypeID())) != NULL) {

      if (pc->isSelected()) {
         selected++;
         list->Add(pc);
         }
      }
   return selected;
   }
/*
 * getSelectedComponentDefinitions()
 *
 * Returns the number of selected Component Definitions and 
 * adds them to the list passed in.
 */
int PWBDataBase::getSelectedComponentDefinitions(AP210ObjectList *list) {
   // initialize the counter
   int selected = 0;

   // Setup for components 
   AP210ObjectListItor itor(&ComponentDefinitions);
   ComponentDefinition *cd;

   // components selected?
   itor.Reset();
   while((cd = (ComponentDefinition *)itor.NextInstanceOf(ComponentDefinition::TypeID())) != NULL) {

      if (cd->isSelected()) {
         selected++;
         list->Add(cd);
         }
      }
   return selected;
   }
/*
 * getSelectedNonPlatedThruHoles()
 *
 * Returns the number of selected non-plated thru-holes and 
 * adds them to the list passed in.
 */
int PWBDataBase::getSelectedNonPlatedThruHoles(AP210ObjectList *list) {
   // initialize the counter
   int selected = 0;

   // Setup for components 
   AP210ObjectListItor itor(&NonPlatedThruHoles);
   NonPlatedThruHole *npth;

   // components selected?
   itor.Reset();
   while((npth = (NonPlatedThruHole *)itor.NextInstanceOf(NonPlatedThruHole::TypeID())) != NULL) {

      if (npth->isSelected()) {
         selected++;
         list->Add(npth);
         }
      }
   return selected;
   }
int PWBDataBase::assignItemFindNumber() {
   ItemFindNumberSeed++;
   return ItemFindNumberSeed;
   }

/*
 * Function getPackagedComponentSurface
 *
 * Given a component location return its Surface on the board.
 *
 * Part21 Example: from flasher.210 R1
 *   #156=COMPONENT_LOCATION('planar projected shape',(#820,#179,#132),#582);
 *   #520=PROPERTY_DEFINITION_REPRESENTATION(#725,#156);
 *   #725=PRODUCT_DEFINITION_SHAPE('','',#225);
 *   #567=PROPERTY_DEFINITION_REPRESENTATION(#485,#156);
 *   #485=PROPERTY_DEFINITION('','',#679);
 *
 *   #679=COMPONENT_SHAPE_ASPECT('',
 *   'interconnect module component surface feature',#681,.F.);
 *   #681=PRODUCT_DEFINITION_SHAPE('','',#742); // shared.
 *   #742=COMPONENT_DEFINITION('','interconnect module',#399,#835);
 *
 *   #41=SHAPE_ASPECT_RELATIONSHIP('instantiated feature','',#676,#679);
 *
 *   #676=SHAPE_ASPECT('','interconnect module primary surface',#694,.F.);
 *   #694=PRODUCT_DEFINITION_SHAPE('','',#623); // shared.
 *   #623=PHYSICAL_UNIT('','interconnect module',#399,#838);
 *
 * Part 21 Example: from cable_db Q1
In getPackagedComponentSide()
cl: #14947 a component_location  Value = 0-0
count: 2
pdr: #14949 a property_definition_representation  Value = 0-0
pd: #14948 a property_definition  Value = 0-0
csa: #12966 a component_shape_aspect  Value = 0-0
sar: #12967 a shape_aspect_relationship  Value = 0-0
sa: #837 a shape_aspect  Value = 0-0
Found a placement side of "interconnect module primary surface"
 *
 */
SdaiString PWBDataBase::getPackagedComponentSurface(SdaiAppInstance cl) {
   SdaiIterator itor;
   SdaiString surface = sdaiNULL;
   SdaiAppInstance pdr = sdaiNULL;
   SdaiAppInstance pd = sdaiNULL;
   SdaiAppInstance csa = sdaiNULL;
   SdaiAppInstance sa = sdaiNULL;
   SdaiNPL domain = sdaiCreateNPL();
   SdaiNPL resultList = sdaiCreateNPL();

   static SdaiEntity PDR = sdaiGetEntity(AP210Model,
                                         "property_definition_representation");
   static SdaiAttr PDR_UR = sdaiGetAttrDefinition(PDR, "used_representation");
   static SdaiAttr PDR_DEF = sdaiGetAttrDefinition(PDR, "definition");

   static SdaiEntity PD = sdaiGetEntity(AP210Model, "property_definition");
   static SdaiAttr PD_DEF = sdaiGetAttrDefinition(PD, "definition");

   static SdaiAttr SA_DESC = sdaiGetAttrDefinitionBN(AP210,
                                                     "shape_aspect",
                                                     "description");
#ifdef VERBOSE
TRACE0("In getPackagedComponentSide()\r\n");
#endif

   if (cl != sdaiNULL) {
#ifdef VERBOSE
TRACE("cl: %s\n", _sdaiGetPart21Description(cl));
#endif
      // return a list of property_definition_representations 
      // with cl as the used_representation .
      sdaiFindInstanceUsedIn(cl, PDR_UR, domain, resultList);

#ifdef VERBOSE
TRACE("count: %d\n", sdaiGetMemberCount(resultList));
#endif
      if (sdaiGetMemberCount(resultList) > 0) {
         itor = sdaiCreateIterator(resultList);
         while (sdaiNext(itor)) {
            sdaiGetAggrByIterator(itor, sdaiINSTANCE, &pdr); 

            if (pdr != sdaiNULL) {
#ifdef VERBOSE
TRACE("pdr: %s\n", _sdaiGetPart21Description(pdr));
#endif
               sdaiGetAttr(pdr, PDR_DEF, sdaiINSTANCE, &pd);

               if (pd != sdaiNULL) {
#ifdef VERBOSE
TRACE("pd: %s\n", _sdaiGetPart21Description(pd));
#endif
                  sdaiGetAttr(pd, PD_DEF, sdaiINSTANCE, &csa);
                  if (csa != sdaiNULL) {
#ifdef VERBOSE
TRACE("csa: %s\n", _sdaiGetPart21Description(csa));
#endif
                     sa = getNamedRelatingShapeAspect(AP210Model, csa, "instantiated feature");
#ifdef VERBOSE
TRACE("sa: 0x%08x\n", sa);
#endif
               
                     if (sa != sdaiNULL) {
#ifdef VERBOSE
TRACE("sa: %s\n", _sdaiGetPart21Description(sa));
#endif
                        sdaiGetAttr(sa, SA_DESC, sdaiSTRING, &surface);
#ifdef VERBOSE
TRACE("Found a placement surface of \"%s\"\n", surface);
#endif
                        if (primary_surface == sdaiNULL) {
                           if (!strcmp(surface, PRIMARY_SURFACE)) {
                              primary_surface = sdaiCreateADB (sdaiINSTANCE, csa);
                              sdaiPutADBTypePath(primary_surface, 1, CSA_TYPENAMES);
#ifdef VERBOSE
TRACE("primary_surface: 0x%08x\r\n", primary_surface);
#endif
                              }
                           }
                        else if (secondary_surface == sdaiNULL) {
                           if (!strcmp(surface, SECONDARY_SURFACE)) {
                              secondary_surface = sdaiCreateADB (sdaiINSTANCE, csa);
                              sdaiPutADBTypePath(secondary_surface, 1, CSA_TYPENAMES);
#ifdef VERBOSE
TRACE("secondary_surface: 0x%08x\r\n", primary_surface);
#endif
                              }
                           }
                        break;
                        }
#ifdef VERBOSE
else {
   TRACE("sa is sdaiNULL!\r\n");
   }
#endif
                     }
                  }
               }
            }
         sdaiDeleteIterator(itor);
         }
      }
   if (surface == sdaiNULL) {
      TRACE("ERROR: No placement surface for %s\n", _sdaiGetPart21Description(cl));
      surface = "";
      }
   sdaiDeleteNPL(domain);
   sdaiDeleteNPL(resultList);
   return surface;
   }
/*
 * Function setPackagedComponentSide
 *
 * Given a component location set its side on the board.
 *
 * NOTE: Since this is redundant data the transformation 
 *       matrix also needs to be updated. THIS NEED TO BE DONE!
 *
 * Part21 Example:
 *   #5327=COMPONENT_LOCATION('',(#5306,#5322,#5326),#5321);
 *   #5334=PROPERTY_DEFINITION_REPRESENTATION(#5333,#5327);
 *   #5333=PROPERTY_DEFINITION('','',#5331);  // not shared!
 *   #5331=COMPONENT_SHAPE_ASPECT('','interconnect module component surface feature',
 *      #5330,.F.);
 *   #5332=SHAPE_ASPECT_RELATIONSHIP('instantiated feature','',#2717,#5331);
 *   #2717=SHAPE_ASPECT('','interconnect module primary surface',#2716,.U.);
 */
void PWBDataBase::setPackagedComponentSurface(SdaiAppInstance cl, const char *surface) {
#ifdef VERBOSE
TRACE0("In PWBDataBase::setPackagedComponentSurface()\r\n");
#endif
   static SdaiEntity PDR = sdaiGetEntity(AP210Model,
                                         "property_definition_representation");
   static SdaiAttr PDR_UR = sdaiGetAttrDefinition(PDR, "used_representation");
   static SdaiAttr PDR_DEF = sdaiGetAttrDefinition(PDR, "definition");

   static SdaiEntity PD = sdaiGetEntity(AP210Model, "property_definition");
   static SdaiAttr PD_DEF = sdaiGetAttrDefinition(PD, "definition");

   static SdaiAttr SA_DESC = sdaiGetAttrDefinitionBN(AP210,
                                                     "shape_aspect",
                                                     "description");
   static SdaiEntity CSA = sdaiGetEntity(AP210Model, "component_shape_aspect");

   SdaiIterator itor;
   SdaiAppInstance pdr = sdaiNULL;
   SdaiAppInstance pd = sdaiNULL;
   SdaiAppInstance csa = sdaiNULL;
   SdaiAppInstance sa = sdaiNULL;
   SdaiNPL domain = sdaiCreateNPL();
   SdaiNPL resultList = sdaiCreateNPL();
   SdaiString csa_description = sdaiNULL;

   if (cl != sdaiNULL) {
#ifdef VERBOSE
TRACE("cl: %s\n", _sdaiGetPart21Description(cl));
#endif
      // return a list of property_definition_representations 
      // with cl as the used_representation .
      sdaiFindInstanceUsedIn(cl, PDR_UR, domain, resultList);

      if (sdaiGetMemberCount(resultList) > 0) {
         itor = sdaiCreateIterator(resultList);

         while (sdaiNext(itor)) {
            sdaiGetAggrByIterator(itor, sdaiINSTANCE, &pdr); 

            if (pdr != sdaiNULL) {
#ifdef VERBOSE
TRACE("pdr: %s\n", _sdaiGetPart21Description(pdr));
#endif
               sdaiGetAttr(pdr, PDR_DEF, sdaiINSTANCE, &pd);
#ifdef VERBOSE
TRACE("pd: %s\n", _sdaiGetPart21Description(pd));
#endif
               if (pd != sdaiNULL) {
                  sdaiGetAttr(pd, PD_DEF, sdaiINSTANCE, &csa);
#ifdef VERBOSE
TRACE("csa: %s\n", _sdaiGetPart21Description(csa));
#endif
                  if ((csa != sdaiNULL) &&
                       sdaiIsInstanceOf(csa, CSA)) {
                     sdaiGetAttr(csa, SA_DESC, sdaiSTRING, &csa_description);
#ifdef VERBOSE
TRACE("csa_description: %s\n", csa_description);
#endif
                     if (csa_description != sdaiNULL) {

                        // is this the csa we are looking for?
                        if (!strcmp(csa_description, COMPONENT_SURFACE)) {

#ifdef VERBOSE
TRACE("surface: %s\r\n", surface);
#endif
                           if (!strcmp(surface, PRIMARY_SURFACE)) {
                              // creating the surface here since I should delete a surface if
                              // it isn't used and that should be done here.
                              sdaiPutAttr(pd, PD_DEF, sdaiADB, getPrimarySurface());
                              break;
                              }
                           else if (!strcmp(surface, SECONDARY_SURFACE)) {
                              // creating the surface here since I should delete a surface if
                              // it isn't used and that should be done here.
                              sdaiPutAttr(pd, PD_DEF, sdaiADB, getSecondarySurface());
                              break;
                              }
                           }
                        }
                     }
                  }
               }
            }
         sdaiDeleteIterator(itor);
         }
      }
   sdaiDeleteNPL(domain);
   sdaiDeleteNPL(resultList);
   }
/*
 *  createPackagedComponentSurface
 *  
  ENTITY shape_aspect;
      name                 : label;
      description          : text;
      of_shape             : product_definition_shape;
      product_definitional : LOGICAL;
  END_ENTITY; -- shape_aspect
  ENTITY shape_aspect_relationship;
      name                  : label;
      description           : text;
      relating_shape_aspect : shape_aspect;
      related_shape_aspect  : shape_aspect;
  END_ENTITY; -- shape_aspect_relationship
 *
 *   from flasher.210 heat R1
 *   #679=COMPONENT_SHAPE_ASPECT('',
 *   'interconnect module component surface feature',#681,.F.);
 *   #41=SHAPE_ASPECT_RELATIONSHIP('instantiated feature','',#676,#679);
 *   #676=SHAPE_ASPECT('','interconnect module primary surface',#694,.F.);
 *
 *   #694=PRODUCT_DEFINITION_SHAPE('','',#623); // shared.
 *   #623=PHYSICAL_UNIT('','interconnect module',#399,#838);
 *
 *   #681=PRODUCT_DEFINITION_SHAPE('','',#742); // shared.
 *   #742=COMPONENT_DEFINITION('','interconnect module',#399,#835);

from cable_db heat sink q1
In getPackagedComponentSide()
cl: #14947 a component_location  Value = 0-0
count: 2
pdr: #14949 a property_definition_representation  Value = 0-0
pd: #14948 a property_definition  Value = 0-0
csa: #12966 a component_shape_aspect  Value = 0-0
sar: #12967 a shape_aspect_relationship  Value = 0-0
sa: #837 a shape_aspect  Value = 0-0
Found a placement surface of "interconnect module primary surface"

#14947=COMPONENT_LOCATION('',(#14939,#14940,#14944,#14946),#14938);
#14949=PROPERTY_DEFINITION_REPRESENTATION(#14948,#14947);
#14948=PROPERTY_DEFINITION('','',#12966);

#12966=COMPONENT_SHAPE_ASPECT('',
   'interconnect module component surface feature',#845,.F.);
#845=PRODUCT_DEFINITION_SHAPE('PCBSEED','Board.Graphics',#844);
#844=PHYSICAL_UNIT('PCBSEED','',#842,#843);

#12967=SHAPE_ASPECT_RELATIONSHIP('instantiated feature','',#837,#12966);

#837=SHAPE_ASPECT('','interconnect module primary surface',#836,.T.);
#836=PRODUCT_DEFINITION_SHAPE('','',#1109);
#1109=STRATUM('PHYSICAL_1','',#1107,#1108);

#839=SHAPE_ASPECT('','interconnect module secondary surface',#838,.T.);
#838=PRODUCT_DEFINITION_SHAPE('','',#1133);
#1133=STRATUM('PHYSICAL_2','',#1131,#1132);

from cable_db_test heat sink Q1
In getPackagedComponentSide()
cl: #4241 a component_location  Value = 0-0
count: 2
pdr: #9149 a property_definition_representation  Value = 0-0
pd: #7911 a property_definition  Value = 0-0
sar: #6639 a shape_aspect_relationship  Value = 0-0
sa: #6893 a component_shape_aspect  Value = 0-0

#6639=SHAPE_ASPECT_RELATIONSHIP('instantiated feature','',#11423,#6893);
#6893=COMPONENT_SHAPE_ASPECT('',
'interconnect module component surface feature',$,.F.);

#11423=SHAPE_ASPECT('','interconnect module secondary surface',#19866,.F.);
#19866=PRODUCT_DEFINITION_SHAPE('PCBSEED','Board.Graphics',#18342);
#18342=PHYSICAL_UNIT('PCBSEED','',#22253,#21148);


from -5
#1069=PRODUCT_DEFINITION_SHAPE('','',#1484);
#1070=SHAPE_ASPECT('','interconnect module primary surface',#1069,.T.);
#1071=PRODUCT_DEFINITION_SHAPE('','',#1548);
#1072=SHAPE_ASPECT('','interconnect module secondary surface',#1071,.T.);
 */
SdaiADB PWBDataBase::createPackagedComponentSurface(const char *surface) {
   static SdaiEntity CSA = sdaiGetEntity(AP210Model, "component_shape_aspect");
   static SdaiAttr CSA_NAME = sdaiGetAttrDefinition(CSA, "name");
   static SdaiAttr CSA_DESC = sdaiGetAttrDefinition(CSA, "description");
   static SdaiAttr CSA_OS = sdaiGetAttrDefinition(CSA, "of_shape");

   static SdaiEntity SAR = sdaiGetEntity(AP210Model, "shape_aspect_relationship");
   static SdaiAttr SAR_NAME = sdaiGetAttrDefinition(SAR, "name");
   static SdaiAttr SAR_DESC = sdaiGetAttrDefinition(SAR, "description");
   static SdaiAttr SAR_ING = sdaiGetAttrDefinition(SAR, "relating_shape_aspect");
   static SdaiAttr SAR_ED = sdaiGetAttrDefinition(SAR, "related_shape_aspect");

   static SdaiEntity SA = sdaiGetEntity(AP210Model, "shape_aspect");
   static SdaiAttr SA_NAME = sdaiGetAttrDefinition(SA, "name");
   static SdaiAttr SA_DESC = sdaiGetAttrDefinition(SA, "description");
   static SdaiAttr SA_OS = sdaiGetAttrDefinition(SA, "of_shape");

   SdaiAppInstance PWBpu = getInterconnectModulePhysicalDesign();
   SdaiADB result = sdaiNULL;

   SdaiAppInstance csa = sdaiCreateInstance(AP210Model, CSA);
   SdaiAppInstance sar = sdaiCreateInstance(AP210Model, SAR);
   SdaiAppInstance sa = getSurfaceShapeAspect(surface);

   // populate shape aspect relationship
   sdaiPutAttr(sar, SAR_NAME, sdaiSTRING, INSTANTIATED_FEATURE);
   sdaiPutAttr(sar, SAR_DESC, sdaiSTRING, "");
   sdaiPutAttr(sar, SAR_ING, sdaiINSTANCE, sa);
   sdaiPutAttr(sar, SAR_ED, sdaiINSTANCE, csa);

   // populate component_shape_aspect
   sdaiPutAttr(csa, CSA_NAME, sdaiSTRING, "");
   sdaiPutAttr(csa, CSA_DESC, sdaiSTRING, COMPONENT_SURFACE);
   // attach component_shape_aspect to interconnect module component_definition
   sdaiPutAttr(csa, CSA_OS, sdaiINSTANCE, getPhysicalUnitsProductDefinitionShape(PWBpu));

   result = sdaiCreateADB (sdaiINSTANCE, csa);
   sdaiPutADBTypePath(result, 1, CSA_TYPENAMES);
   return(result);
   }
/*
 * getPhysicalUnitsProductDefinitionShape()
 *
  ENTITY property_definition;
      name        : label;
      description : text;
      definition  : characterized_definition;
  END_ENTITY; -- property_definition

  ENTITY product_definition_shape
    SUBTYPE OF (property_definition);
    UNIQUE
      ur1 : definition;
    WHERE
      wr1: (NOT ('ELECTRONIC_ASSEMBLY_INTERCONNECT_AND_PACKAGING_DESIGN.SHAPE_DEFINITION' 
               IN TYPEOF(SELF\property_definition.definition)));
  END_ENTITY; -- product_definition_shape

 *   #694=PRODUCT_DEFINITION_SHAPE('','',#623);
 *   #623=PHYSICAL_UNIT('','interconnect module',#399,#838);
 */
SdaiAppInstance PWBDataBase::getPhysicalUnitsProductDefinitionShape(SdaiAppInstance pu) {
   static SdaiEntity PDS = sdaiGetEntity(AP210Model, "product_definition_shape");
   static SdaiAttr PDS_DEF  = sdaiGetAttrDefinition(PDS, "definition");

   SdaiAppInstance pds = _sdaiFindSingleSubTypeInstanceUsedIn(pu, PDS, PDS_DEF);

   return(pds);
   }
/*
 * getSurfaceShapeAspect()
 */
SdaiAppInstance PWBDataBase::getSurfaceShapeAspect(const char *surface) {
   static SdaiEntity SA = sdaiGetEntity(AP210Model, "shape_aspect");
   static SdaiAttr SA_DESC = sdaiGetAttrDefinition(SA, "description");
   static SdaiAttr SA_OS = sdaiGetAttrDefinition(SA, "of_shape");

   SdaiAppInstance sa = sdaiNULL;
   SdaiAppInstance test = sdaiNULL;
   SdaiString desc;
   SdaiIterator itor;

   // get a list of all shape_aspects
   itor = sdaiCreateIterator(sdaiGetEntityExtent(AP210Model, SA));

   while (sdaiNext(itor)) {
      sdaiGetAggrByIterator(itor, sdaiINSTANCE, &test);
      sdaiGetAttr(test, SA_DESC, sdaiSTRING, &desc);
      if (desc != sdaiNULL) {
         if (!strcmp(surface, desc)) {
            sa = test;
            break;
            }
         }
      }
   sdaiDeleteIterator(itor);

   return(sa);
   }

// packaged_component Matrix functions.
int PWBDataBase::getTransformationMatrix(double m[16],
                                         SdaiAppInstance A2P_LOC,
                                         SdaiAppInstance unit) {
   int result;
   // get the transformation matrix
   result = ExtractGeometry::getTransformationMatrix(m, AP210Model, A2P_LOC, unit);

   return result;
   }
void PWBDataBase::setTransformationMatrix(double m[16],
                                          SdaiAppInstance A2P_LOC,
                                          SdaiAppInstance unit) {
   ExtractGeometry::setTransformationMatrix(m, AP210Model, A2P_LOC, unit);
   }


void PWBDataBase::UpdateProdView() {
   CView* pView;
   POSITION pos = GetFirstViewPosition();
TRACE("PWBDataBase::UpdateProdView\r\n");

   while (pos != NULL){
      pView = GetNextView(pos);
      if ( pView->IsKindOf( RUNTIME_CLASS( CAP210ProdView ) ) ) {
         ((CAP210ProdView* )pView)->UpdateTree();
         }
      }   
   }

SdaiADB  PWBDataBase::getPrimarySurface() {
   if (primary_surface == sdaiNULL) {
      primary_surface = createPackagedComponentSurface(PRIMARY_SURFACE);
      }
   return(primary_surface); 
   }

SdaiADB  PWBDataBase::getSecondarySurface() {
   if (secondary_surface == sdaiNULL) {
      secondary_surface = createPackagedComponentSurface(SECONDARY_SURFACE);
      }
   return(secondary_surface);
   }

void PWBDataBase::updateMountingRestrictionAreas() {
   MountingRestrictionArea *mra;
   AP210ObjectListItor MRAitor(&MountingRestrictionAreas);

TRACE("In PWBDataBase::updateMountingRestrictionAreas()\r\n");


   // Update MountingRestrictionArea List
   while((mra = (MountingRestrictionArea *)MRAitor.Next()) != NULL) {
      mra->setAppearance(MountingRestrictionAreaAppearance);
      }
   }

/*
 * getSelectedMountingRestrictionAreas()
 *
 * Returns the number of selected mounting_restriction_areas and 
 * adds them to the list passed in.
 */
int PWBDataBase::getSelectedMountingRestrictionAreas(AP210ObjectList *list) {
   // initialize the counter
   int selected = 0;

   // Setup for components 
   AP210ObjectListItor itor(&MountingRestrictionAreas);
   MountingRestrictionArea *mra;

   // components selected?
   itor.Reset();
   while((mra = (MountingRestrictionArea *)itor.NextInstanceOf(MountingRestrictionArea::TypeID())) != NULL) {

      if (mra->isSelected()) {
         selected++;
         list->Add(mra);
         }
      }
   return selected;
   }

SdaiAppInstance PWBDataBase::getAssemblyModulePhysicalDesign() {
   return AssemblyModulePhysicalDesign;
   }

SdaiAppInstance PWBDataBase::getAssemblyModulePhysicalDesignUsage() {
   return AssemblyModulePhysicalDesignUsage;
   }

SdaiAppInstance PWBDataBase::getInterconnectModulePhysicalDesign() {
   return InterconnectModulePhysicalDesign;
   }

SdaiAppInstance PWBDataBase::getInterconnectModulePhysicalDesignUsage() {
   return InterconnectModulePhysicalDesignUsage;
   }
/*
#1129=PRODUCT('design','','',(#65));
#1139=PRODUCT('test_design','','',(#66));
*/
void PWBDataBase::selectDisplayModel() {
   static SdaiEntity P = sdaiGetEntity(AP210Model, "product");
   static SdaiAttr P_ID = sdaiGetAttrDefinition(P, "id");
   SdaiAppInstance asmp; // assembly product
   SdaiString id;        // product.id
   SdaiAppInstance imp;  // interconnect module product
#ifdef VERBOSE
TRACE("&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*\r\n");
TRACE("In PWBDataBase::selectDisplayModel()\r\n");
#endif
   SdaiNPL products = sdaiCreateNPL();
   SdaiIterator productItor = sdaiCreateIterator(products);

   products = getDefinedProducts(products,
                                 "assembly module",
                                 "physical design");
   // This won't work for ITI files so 
   // lets not use it if we found only one product
   if (sdaiGetMemberCount(products) > 1) {
      // create the assembly module product dialog box
      CAssemblyProductSelectDlg asmpDlg;
      asmpDlg.setValues(AP210Model, products);
      asmpDlg.DoModal();

      sdaiBeginning(productItor);
      while(sdaiNext(productItor)) {
         sdaiGetAggrByIterator(productItor, sdaiINSTANCE, &asmp);
   TRACE("   asmp: %s\r\n", _sdaiGetPart21Description(asmp));
         sdaiGetAttr(asmp, P_ID, sdaiSTRING, &id);
   TRACE("   id: %s\r\n", id);
         if (!strcmp(asmpDlg.m_AssemblyProduct, id)) {
            break;
            }
         }
      AssemblyModuleProduct = asmp;

      SdaiNPL asmpdList = sdaiCreateNPL(); // assemblies product_definitions
#ifdef VERBOSE
   TRACE("   AssemblyModuleProduct: %s\r\n", _sdaiGetPart21Description(AssemblyModuleProduct));
#endif
      asmpdList = getProductsProductDefinitions(AssemblyModuleProduct, asmpdList);
      AssemblyModulePhysicalDesign = getNamedPhysicalUnit(asmpdList, "assembly module", "physical design");
#ifdef VERBOSE
TRACE("AM PD: %s\n", _sdaiGetPart21Description(AssemblyModulePhysicalDesign));
TRACE("AM PD PROD: %s\n",_sdaiGetPart21Description(getPhysicalUnitsProduct(AP210Model, AssemblyModulePhysicalDesign)));
#endif
      AssemblyModulePhysicalDesignUsage = getNamedPhysicalUnit(asmpdList, "assembly module", "physical design usage");
#ifdef VERBOSE
TRACE("AM PDU: %s\n", _sdaiGetPart21Description(AssemblyModulePhysicalDesignUsage));
TRACE("AM PDU PROD: %s\n",_sdaiGetPart21Description(getPhysicalUnitsProduct(AP210Model, AssemblyModulePhysicalDesignUsage)));
#endif
      sdaiDeleteNPL(asmpdList);

      imp = getAssembliesInterconnectModuleProduct();
#ifdef VERBOSE
TRACE("imp: %s\n",_sdaiGetPart21Description(imp));
#endif
      SdaiNPL impdList = sdaiCreateNPL(); // interconnect module's product_definitions
      impdList = getProductsProductDefinitions(imp, impdList);
      InterconnectModulePhysicalDesign = getNamedPhysicalUnit(impdList, "interconnect module", "physical design");
#ifdef VERBOSE
TRACE("IM PD: %s\n", _sdaiGetPart21Description(InterconnectModulePhysicalDesign));
TRACE("IM PD PROD: %s\n",_sdaiGetPart21Description(getPhysicalUnitsProduct(AP210Model, InterconnectModulePhysicalDesign)));
#endif
      InterconnectModulePhysicalDesignUsage = getNamedPhysicalUnit(impdList, "interconnect module", "physical design usage");
#ifdef VERBOSE
TRACE("IM PDU: %s\n", _sdaiGetPart21Description(InterconnectModulePhysicalDesignUsage));
TRACE("IM PDU PROD: %s\n",_sdaiGetPart21Description(getPhysicalUnitsProduct(AP210Model, InterconnectModulePhysicalDesignUsage)));
#endif
      sdaiDeleteNPL(impdList);
#ifdef VERBOSE
      sdaiBeginning(productItor);
      while(sdaiNext(productItor)) {
         SdaiNPL pdList = sdaiCreateNPL();

         sdaiGetAggrByIterator(productItor, sdaiINSTANCE, &product);
         TRACE("   product: %s\r\n", _sdaiGetPart21Description(product));
         getProductsProductDefinitions(product, pdList);
         sdaiDeleteNPL(pdList);
         }
#endif 
      }
   else {
      // get the single asmp
      sdaiBeginning(productItor);
      sdaiNext(productItor);
      sdaiGetAggrByIterator(productItor, sdaiINSTANCE, &AssemblyModuleProduct);

      // Required method for ITI designs
      // select latter for now just collect all the gets.
      AssemblyModulePhysicalDesign = getNamedPhysicalUnit("assembly module", "physical design");
#ifdef VERBOSE
TRACE("AM PD: %s\n", _sdaiGetPart21Description(AssemblyModulePhysicalDesign));
TRACE("AM PD PROD: %s\n",_sdaiGetPart21Description(getPhysicalUnitsProduct(AP210Model, AssemblyModulePhysicalDesign)));
#endif
      AssemblyModulePhysicalDesignUsage = getNamedPhysicalUnit("assembly module", "physical design usage");
#ifdef VERBOSE
TRACE("AM PDU: %s\n", _sdaiGetPart21Description(AssemblyModulePhysicalDesignUsage));
TRACE("AM PDU PROD: %s\n",_sdaiGetPart21Description(getPhysicalUnitsProduct(AP210Model, AssemblyModulePhysicalDesignUsage)));
#endif
      InterconnectModulePhysicalDesign = getNamedPhysicalUnit("interconnect module", "physical design");
#ifdef VERBOSE
TRACE("IM PD: %s\n", _sdaiGetPart21Description(InterconnectModulePhysicalDesign));
TRACE("IM PD PROD: %s\n",_sdaiGetPart21Description(getPhysicalUnitsProduct(AP210Model, InterconnectModulePhysicalDesign)));
#endif
      InterconnectModulePhysicalDesignUsage = getNamedPhysicalUnit("interconnect module", "physical design usage");
#ifdef VERBOSE
TRACE("IM PDU: %s\n", _sdaiGetPart21Description(InterconnectModulePhysicalDesignUsage));
TRACE("IM PDU PROD: %s\n",_sdaiGetPart21Description(getPhysicalUnitsProduct(AP210Model, InterconnectModulePhysicalDesignUsage)));
#endif
      }
   sdaiDeleteNPL(products);
   sdaiDeleteIterator(productItor);
#ifdef VERBOSE
TRACE("&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*\r\n");
#endif
   }
/*
 * Function getNamedPhysicalUnit
 *
 *   Return the FIRST physical_unit with the given
 *   name and product relationship.  Need 
 *   a version that returns a list for the case
 *   where multiple products exist in the database.
 *   Also need to handle the interconnect_module better.
 *   This is really intended to get the root of a design.
 *
 *   Use a Name of "interconnect module" to get the PWB
 *   and "assembly module" to get the PWA.
 *
 *   Use a ProductRelationship of "physical design" or
 *   "physical design usage" to get view you want.
 *
 * Part21 Example:
 */
SdaiAppInstance PWBDataBase::getNamedPhysicalUnit(SdaiString Name, SdaiString ProductRelationship) {
   static SdaiEntity PU = sdaiGetEntity(AP210Model, "physical_unit");
   static SdaiAttr PU_FOR = sdaiGetAttrDefinition(PU, "frame_of_reference");

   static SdaiEntity ID = sdaiGetEntity(AP210Model, "interconnect_definition");

   static SdaiEntity PDC = sdaiGetEntity(AP210Model, "product_definition_context");
   static SdaiAttr PDC_NAME = sdaiGetAttrDefinition(PDC, "name");

   static SdaiAttr PRPC = sdaiGetEntity(AP210Model, "product_related_product_category");
   static SdaiAttr PRPC_NAME = sdaiGetAttrDefinition(PRPC, "name");

   static SdaiEntity PDR = sdaiGetEntity(AP210Model, "product_definition_relationship");
   static SdaiAttr PDR_ING = sdaiGetAttrDefinition(PDR, "relating_product_definition");
   SdaiIterator itor;
   SdaiString name;
   SdaiAppInstance obj = sdaiNULL;     // scratch object
   SdaiAppInstance prpc = sdaiNULL;    // product_related_product_category
   SdaiAppInstance pu = sdaiNULL;      // physical_unit
   SdaiAppInstance dupu = sdaiNULL;    // candidate physical_unit
   SdaiAppInstance test = sdaiNULL;
   SdaiAppInstance pdc;                // physical_unit frame_of_reference

#ifdef VERBOSE
TRACE("In getNamedPhysicalUnit(\"%s\", \"%s\")\r\n", Name, ProductRelationship);
#endif
   // get a list of all physical_units
   itor = sdaiCreateIterator(sdaiGetEntityExtent(AP210Model, PU));

   while (sdaiNext(itor)) {
      sdaiGetAggrByIterator(itor, sdaiINSTANCE, &test);

#ifdef RVERBOSE
TRACE("test PU: %s\r\n", _sdaiGetPart21Description(test));
#endif
     // for ITI and IDF, ID for LKSoft
     if (sdaiIsInstanceOf(test, PU) || sdaiIsInstanceOf(test, ID))
         {
         prpc = getPhysicalUnitsProductRelatedProductCategory(test);
#ifdef RVERBOSE
TRACE("PRPC: %s\r\n", _sdaiGetPart21Description(prpc));
#endif
         /* get the prpc's name */
         sdaiGetAttr(prpc, PRPC_NAME, sdaiSTRING, &name);
#ifdef RVERBOSE
TRACE("Name: %s\r\n", Name);
TRACE("name: %s\r\n", name);
#endif        
         if (!strcmp(Name, name)) {

            sdaiGetAttr(test, PU_FOR, sdaiINSTANCE, &pdc);
            sdaiGetAttr(pdc, PDC_NAME, sdaiSTRING, &name);
#ifdef RVERBOSE
TRACE("ProductRelationship: %s\r\n", ProductRelationship);
TRACE("name: %s\r\n", name);
#endif        
            if (!strcmp(ProductRelationship, name)) {
#ifdef VERBOSE
TRACE("physical_unit: %s\n", _sdaiGetPart21Description(test));
TRACE("product_related_product_category: %s\n", _sdaiGetPart21Description(prpc));
TRACE("ProductRelationship: %s\r\n", ProductRelationship);
TRACE("Name: %s\r\n", name);
TRACE("product_definition_context: %s\n", _sdaiGetPart21Description(pdc));
TRACE("     %s\n\n", name);
#endif
               pu = test;
               break;
               }
            }
         }
      }
   sdaiDeleteIterator(itor);

#ifdef VERBOSE
TRACE("RETURNING pu: %s\n*******************\n", _sdaiGetPart21Description(pu));
#endif
   return(pu);
   }
SdaiNPL PWBDataBase::getDefinedProducts(SdaiNPL resultList,
                                        SdaiString Name,
                                        SdaiString ProductRelationship) {
   static SdaiEntity PU = sdaiGetEntity(AP210Model, "physical_unit");
   static SdaiAttr PU_FOR = sdaiGetAttrDefinition(PU, "frame_of_reference");

   static SdaiEntity ID = sdaiGetEntity(AP210Model, "interconnect_definition");

   static SdaiEntity PDC = sdaiGetEntity(AP210Model, "product_definition_context");
   static SdaiAttr PDC_NAME = sdaiGetAttrDefinition(PDC, "name");

   static SdaiAttr PRPC = sdaiGetEntity(AP210Model, "product_related_product_category");
   static SdaiAttr PRPC_NAME = sdaiGetAttrDefinition(PRPC, "name");
   static SdaiAttr PRPC_DESC = sdaiGetAttrDefinition(PRPC, "description");

   static SdaiEntity PDR = sdaiGetEntity(AP210Model, "product_definition_relationship");
   static SdaiAttr PDR_ING = sdaiGetAttrDefinition(PDR, "relating_product_definition");
   SdaiIterator itor;
   SdaiAppInstance obj = sdaiNULL;     // scratch object

   SdaiAppInstance prpc = sdaiNULL;    // product_related_product_category
   SdaiString name;
   SdaiString description = sdaiNULL;
   bool prpcfound;

   SdaiAppInstance pu = sdaiNULL;      // physical_unit

   SdaiAppInstance pdc;                // physical_unit frame_of_reference

   SdaiIterator nplitor = sdaiCreateIterator(resultList);
   SdaiAppInstance product = sdaiNULL; // product

#ifdef VERBOSE
TRACE("*******************\r\n");
TRACE("In PWBDataBase::getDefinedProducts()\r\n");
#endif
   // get a list of all physical_units
   itor = sdaiCreateIterator(sdaiGetEntityExtent(AP210Model, PU));

   while (sdaiNext(itor)) {
      sdaiGetAggrByIterator(itor, sdaiINSTANCE, &pu);

#ifdef VERBOSE
TRACE("PU: %s\r\n", _sdaiGetPart21Description(pu));
#endif
     // PU for ITI and IDF, ID for LKSoft
     if (sdaiIsInstanceOf(pu, PU) || sdaiIsInstanceOf(pu, ID))
         {
         prpc = getPhysicalUnitsProductRelatedProductCategory(pu);
#ifdef VERBOSE
TRACE("PRPC: %s\r\n", _sdaiGetPart21Description(prpc));
#endif
         /* get the prpc's name */
         sdaiGetAttr(prpc, PRPC_NAME, sdaiSTRING, &name);
#ifdef VERBOSE
TRACE("Name: %s\r\n", Name);
TRACE("name: %s\r\n", name);
#endif        
         if (!strcmp(Name, name)) {
            prpcfound = false;

            if (sdaiTestAttr(prpc, PRPC_DESC) == sdaiTRUE) { 

               /* get the prpc's description */
               sdaiGetAttr(prpc, PRPC_DESC, sdaiSTRING, &description);

               if (!strcmp("pca", description)) {
                  prpcfound = true;
                  }
               }
            else {
               prpcfound = true;
               }
            if (prpcfound == true) {

               sdaiGetAttr(pu, PU_FOR, sdaiINSTANCE, &pdc);
               sdaiGetAttr(pdc, PDC_NAME, sdaiSTRING, &name);
#ifdef VERBOSE
TRACE("ProductRelationship: %s\r\n", ProductRelationship);
TRACE("name: %s\r\n", name);
#endif        
               if (!strcmp(ProductRelationship, name)) {
#ifdef VERBOSE
TRACE("physical_unit: %s\n", _sdaiGetPart21Description(pu));
TRACE("product_related_product_category: %s\n", _sdaiGetPart21Description(prpc));
TRACE("ProductRelationship: %s\r\n", ProductRelationship);
TRACE("Name: %s\r\n", name);
TRACE("product_definition_context: %s\n", _sdaiGetPart21Description(pdc));
TRACE("     %s\n\n", name);
#endif
                  product = getPhysicalUnitsProduct(AP210Model, pu);
                  sdaiEnd(nplitor);
                  sdaiInsertBefore(nplitor, sdaiINSTANCE, product);
                  }
               }
            }
         }
      }
#ifdef VERBOSE
TRACE("Leaving PWBDataBase::getDefinedProducts()\r\n");
TRACE("For Name '%s', ProductRelationship '%s'\r\n", Name, ProductRelationship);
TRACE("  FOUND %d product(s)\r\n", sdaiGetMemberCount(resultList));
sdaiBeginning(nplitor);
while (sdaiNext(nplitor)) {
   SdaiNPL pdList = sdaiCreateNPL();
   sdaiGetAggrByIterator(nplitor, sdaiINSTANCE, &product);
   TRACE("   product: %s\r\n", _sdaiGetPart21Description(product));
   sdaiDeleteNPL(pdList);
   } 
TRACE("*******************\r\n");
#endif
   sdaiDeleteIterator(itor);
   sdaiDeleteIterator(nplitor);
   return resultList;
   }
/*
#1129=PRODUCT('design','','',(#65));
#1152=PRODUCT_DEFINITION_FORMATION('1','',#1129);
#175=PHYSICAL_UNIT('','assembly module',#1152,#77);
#177=PHYSICAL_UNIT('','assembly module',#1152,#78);
*/
SdaiNPL PWBDataBase::getProductsProductDefinitions(SdaiAppInstance product, SdaiNPL resultList) {
   static SdaiEntity PDF = sdaiGetEntity(AP210Model, "product_definition_formation");
   static SdaiAttr PDF_OP = sdaiGetAttrDefinition(PDF, "of_product");

   static SdaiEntity PD = sdaiGetEntity(AP210Model, "product_definition");
   static SdaiAttr PD_F = sdaiGetAttrDefinition(PD, "formation");

   SdaiNPL domain = sdaiCreateNPL();
   SdaiNPL pdfList = sdaiCreateNPL();
   SdaiIterator pdfitor = sdaiCreateIterator(pdfList);
   SdaiIterator pditor = sdaiCreateIterator(resultList);

   SdaiAppInstance pdf;  // product_definition_formation
#ifdef VERBOSE
   SdaiAppInstance pd;   // product_definition

TRACE("*******************\r\n");
TRACE("In PWBDataBase::getProductsProductDefinitions()\r\n");
TRACE("product: %s\r\n", _sdaiGetPart21Description(product));
#endif

   sdaiFindInstanceUsedIn(product, PDF_OP, domain, pdfList);

   sdaiBeginning(pdfitor);
   while (sdaiNext(pdfitor)) {
      sdaiGetAggrByIterator(pdfitor, sdaiINSTANCE, &pdf);
#ifdef VERBOSE
      TRACE("pdf: %s\r\n", _sdaiGetPart21Description(pdf));
#endif
      sdaiFindInstanceUsedIn(pdf, PD_F, domain, resultList);
      } 

   sdaiDeleteNPL(domain);
   sdaiDeleteNPL(pdfList);
   sdaiDeleteIterator(pdfitor);
#ifdef VERBOSE
TRACE("Leaving PWBDataBase::getProductsProductDefinitions()\r\n");
sdaiBeginning(pditor);
while (sdaiNext(pditor)) {
   sdaiGetAggrByIterator(pditor, sdaiINSTANCE, &pd);
   TRACE("product_definition: %s\r\n", _sdaiGetPart21Description(pd));
   } 
TRACE("*******************\r\n");
#endif
   return resultList;
   }

SdaiAppInstance PWBDataBase::getNamedPhysicalUnit(SdaiNPL puList, SdaiString Name, SdaiString ProductRelationship) {
   static SdaiEntity PU = sdaiGetEntity(AP210Model, "physical_unit");
   static SdaiAttr PU_FOR = sdaiGetAttrDefinition(PU, "frame_of_reference");

   static SdaiEntity ID = sdaiGetEntity(AP210Model, "interconnect_definition");

   static SdaiEntity PDC = sdaiGetEntity(AP210Model, "product_definition_context");
   static SdaiAttr PDC_NAME = sdaiGetAttrDefinition(PDC, "name");

   static SdaiAttr PRPC = sdaiGetEntity(AP210Model, "product_related_product_category");
   static SdaiAttr PRPC_NAME = sdaiGetAttrDefinition(PRPC, "name");

   static SdaiEntity PDR = sdaiGetEntity(AP210Model, "product_definition_relationship");
   static SdaiAttr PDR_ING = sdaiGetAttrDefinition(PDR, "relating_product_definition");
   SdaiIterator itor;
   SdaiString name;
   SdaiAppInstance obj = sdaiNULL;     // scratch object
   SdaiAppInstance prpc = sdaiNULL;    // product_related_product_category
   SdaiAppInstance pu = sdaiNULL;      // physical_unit
   SdaiAppInstance dupu = sdaiNULL;    // candidate physical_unit
   SdaiAppInstance test = sdaiNULL;
   SdaiAppInstance pdc;                // physical_unit frame_of_reference

#ifdef VERBOSE
TRACE("In getNamedPhysicalUnit(\"%s\", \"%s\")\r\n", Name, ProductRelationship);
#endif
   // get a list of all physical_units
   itor = sdaiCreateIterator(puList);

   while (sdaiNext(itor)) {
      sdaiGetAggrByIterator(itor, sdaiINSTANCE, &test);

#ifdef RVERBOSE
TRACE("test PU: %s\r\n", _sdaiGetPart21Description(test));
#endif
     // for ITI and IDF, ID for LKSoft
     if (sdaiIsInstanceOf(test, PU) || sdaiIsInstanceOf(test, ID))
         {
         prpc = getPhysicalUnitsProductRelatedProductCategory(test);
#ifdef RVERBOSE
TRACE("PRPC: %s\r\n", _sdaiGetPart21Description(prpc));
#endif
         /* get the prpc's name */
         sdaiGetAttr(prpc, PRPC_NAME, sdaiSTRING, &name);
#ifdef RVERBOSE
TRACE("Name: %s\r\n", Name);
TRACE("name: %s\r\n", name);
#endif        
         if (!strcmp(Name, name)) {

            sdaiGetAttr(test, PU_FOR, sdaiINSTANCE, &pdc);
            sdaiGetAttr(pdc, PDC_NAME, sdaiSTRING, &name);
#ifdef RVERBOSE
TRACE("ProductRelationship: %s\r\n", ProductRelationship);
TRACE("name: %s\r\n", name);
#endif        
            if (!strcmp(ProductRelationship, name)) {
#ifdef VERBOSE
TRACE("physical_unit: %s\n", _sdaiGetPart21Description(test));
TRACE("product_related_product_category: %s\n", _sdaiGetPart21Description(prpc));
TRACE("ProductRelationship: %s\r\n", ProductRelationship);
TRACE("Name: %s\r\n", name);
TRACE("product_definition_context: %s\n", _sdaiGetPart21Description(pdc));
TRACE("     %s\n\n", name);
#endif
               pu = test;
               break;
               }
            }
         }
      }
   sdaiDeleteIterator(itor);

#ifdef VERBOSE
TRACE("RETURNING pu: %s\n*******************\n", _sdaiGetPart21Description(pu));
#endif
   return(pu);
   }
/*
#177=PHYSICAL_UNIT('','assembly module',#1152,#78);
#1744=NEXT_ASSEMBLY_USAGE_OCCURRENCE('','assembly composition','',#177,#270, $);
#270=COMPONENT_DEFINITION('','interconnect module',#1151,#74);
#1151=PRODUCT_DEFINITION_FORMATION('1','',#1128);
#1128=PRODUCT('design_interconnect','','',(#65));
*/
#define VERBOSE
SdaiAppInstance PWBDataBase::getAssembliesInterconnectModuleProduct() {
   static SdaiEntity NAUO = sdaiGetEntity(AP210Model, "next_assembly_usage_occurrence");
   // component_definition
   static SdaiAttr NAUO_ED = sdaiGetAttrDefinition(NAUO, "related_product_definition");
   // AssemblyModulePhysicalDesign
   static SdaiAttr NAUO_ING = sdaiGetAttrDefinition(NAUO, "relating_product_definition");

   static SdaiEntity PD = sdaiGetEntity(AP210Model, "product_definition");
   static SdaiAttr PD_DESC = sdaiGetAttrDefinition(PD, "description");
   static SdaiAttr PD_FORM = sdaiGetAttrDefinition(PD, "formation");

   SdaiIterator itor;
   SdaiAppInstance nauo; // next_assembly_usage_occurance
   SdaiAppInstance pd;   // product_definition
   SdaiString pd_desc;   // product_definition.description
   SdaiAppInstance product = sdaiNULL; // interconnect modules product
   SdaiNPL domain = sdaiCreateNPL();
   SdaiNPL resultList = sdaiCreateNPL();
#ifdef VERBOSE
TRACE("In gPWBDataBase::getAssembliesInterconnectModuleProduct()\r\n");
#endif

   if (AssemblyModulePhysicalDesign != sdaiNULL) {
      // create an iterator for all the AssemblyModulePhysicalDesign's components
      sdaiFindInstanceUsedIn(AssemblyModulePhysicalDesign, NAUO_ING, domain, resultList);
#ifdef VERBOSE
TRACE("count: %d\r\n", sdaiGetMemberCount(resultList));
#endif
      if (sdaiGetMemberCount(resultList) > 0) {
         itor = sdaiCreateIterator(resultList);
         while (sdaiNext(itor)) {
            sdaiGetAggrByIterator(itor, sdaiINSTANCE, &nauo); 
            sdaiGetAttr(nauo, NAUO_ED, sdaiINSTANCE, &pd);
#ifdef VERBOSE
TRACE("nauo: %s\r\n", _sdaiGetPart21Description(nauo));
TRACE("pd: %s\r\n", _sdaiGetPart21Description(pd));
#endif
            
            if (pd != sdaiNULL) {
               sdaiGetAttr(pd, PD_DESC, sdaiSTRING, &pd_desc);
#ifdef VERBOSE
TRACE("pd_desc: %s\r\n", pd_desc);
#endif

               if (!strcmp(pd_desc, "interconnect module")) {
                  product = getProductDefinitionProduct(AP210Model, pd);
#ifdef VERBOSE
TRACE("nauo: %s\r\n", _sdaiGetPart21Description(nauo));
TRACE("pd: %s\r\n", _sdaiGetPart21Description(pd));
TRACE("product: %s\r\n", _sdaiGetPart21Description(product));
#endif
                  break; 
                  }
               }
            }
         }
      }
   sdaiDeleteNPL(domain);
   sdaiDeleteNPL(resultList);

   return product;
   }
#undef VERBOSE