/*
 * $Id: ComponentDefinition.cpp,v 1.2 1999/07/17 19:00:22 keenan Exp $
 * Auth: Michael T. Keenan
 * 
 * This class is an artifact of the Material test routine and should be
 * elemenated.
 */
#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <stdlib.h>
#include <string.h>

#include <sdai.h>

#include "AP210MagicStrings.h"

#include "../AP210ViewerDoc.h"
#include "../AP210ViewerView.h"

#include "ComponentDefinition.h"
#include "PhysicalUnit.h"
#include "AP210Point.h"
#include "ExtractGeometry.h"
#include "../PWBDataBase.h"

#include "MathUtility.h"
// OpenGL
#include "../OpenGl/MatrixUtilities.h"
#include "..\OpenGL\Tess.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/*
 * Create a ComponentDefinition for a component_definition
 * (e.g. a mechanical part)
 *
 * Need to use a PhysicalUnit.
 */
ComponentDefinition::ComponentDefinition(PWBDataBase *PWB,
                                         SdaiAppInstance pc,
                                         SdaiAppInstance unit,
                                         SdaiAppInstance A2P_LOC):
AP210GraphicObject(PWB) {
   static SdaiEntity NAUO = sdaiGetEntity(DataBase->AP210Model,
                                          "next_assembly_usage_occurrence");
   static SdaiAttr NAUO_RPD = sdaiGetAttrDefinition(NAUO,
                                                    "related_product_definition");
   static SdaiAttr NAUO_RD = sdaiGetAttrDefinition(NAUO,
                                                   "reference_designator");
   static SdaiEntity CD = sdaiGetEntity(DataBase->AP210Model,
                                                "component_definition");
   static SdaiAttr CD_ID = sdaiGetAttrDefinition(CD, "id");

   SdaiString refdes;
   SdaiString id;

   // NULL out everything!
   PhysicalUnitRef = NULL;
   
   // assign an opengl identifier
   BaseglName++;
   glName = BaseglName;

   // setup transformation matrix
   _glIdentityMatrixd(m);

   Name = NULL;
   Component = pc;
   // save the component_location and unit;
   ComponentLocationRef = A2P_LOC;
   ComponentUnitRef = unit;

#ifdef VERBOSE
TRACE("In ComponentDefinition::ComponentDefinition\r\n");
#endif
   // get the side
   if (ComponentLocationRef != sdaiNULL) {
      char *tempside = strdup(DataBase->getPackagedComponentSurface(ComponentLocationRef));

      if (!strcmp(PRIMARY_SURFACE, tempside)) {
         Side = Top;
         } 
      else if (!strcmp(SECONDARY_SURFACE, tempside)) {
         Side = Bottom;
         }
      else {
         Side = Unplaced;
         }
      free(tempside);
      }
   else {
      Side = Unplaced;
      }
   // get the transformation matrix
   DataBase->getTransformationMatrix(m, ComponentLocationRef, ComponentUnitRef);

/*
 * Part21 Example:
#1645=COMPONENT_DEFINITION('','',#1383,#1722); // a product_definition
#1027=PRODUCT_DEFINITION_RELATIONSHIP('','instantiated part','',#1527,#1645);
#1527=PHYSICAL_UNIT('','',#1383,#1725);
#1383=PRODUCT_DEFINITION_FORMATION('','',#1364);
#1364=PRODUCT('pn-extractor','','',(#1732));
 */
   PhysicalUnitAppRef = getProductDefinitionPhysicalUnit(DataBase->AP210Model, Component);

   PhysicalUnitRef = PhysicalUnit::Construct(PWB, PhysicalUnitAppRef);

   ItemFindNumber = PhysicalUnitRef->ItemFindNumber;

   // get the reference designator 
   NauoRef = _sdaiFindSingleSubTypeInstanceUsedIn(pc, NAUO, NAUO_RPD);
   sdaiGetAttr(NauoRef, NAUO_RD, sdaiSTRING, &refdes);
   Name = strdup(refdes);

   // get Id
   sdaiGetAttr(pc, CD_ID, sdaiSTRING, &id);
   Id = strdup(id);

#ifdef VERBOSE
TRACE("Leaving ComponentDefinition::ComponentDefinition\r\n*******\r\n");
#endif
   } 
/*
 * ComponentDefinition
 *
 * Create a ComponentDefinition for an PackagedComponent.
 */
ComponentDefinition::ComponentDefinition(PWBDataBase *PWB,
                                         SdaiAppInstance component):
AP210GraphicObject(PWB) {
   static SdaiEntity CD = sdaiGetEntity(DataBase->AP210Model,
                                                "component_definition");
   static SdaiAttr CD_ID = sdaiGetAttrDefinition(CD, "id");

   SdaiString id;

   // assign an opengl identifier
   BaseglName++;
   glName = BaseglName;

   // setup transformation matrix
   _glIdentityMatrixd(m);

   // NULL out everything!
   PhysicalUnitRef = NULL;
   Name = NULL;

   // set Component
   Component = component;

   // get Id
   sdaiGetAttr(Component, CD_ID, sdaiSTRING, &id);
   Id = strdup(id);
   } 
/*
 * ComponentDefinition
 *
 * Create a ComponentDefinition for an BoardComponent.
 */
ComponentDefinition::ComponentDefinition(PWBDataBase *PWB,
                                       SdaiAppInstance component,
                                       AP210ObjectList *lines):
AP210GraphicObject(PWB) {
   static SdaiEntity CD = sdaiGetEntity(DataBase->AP210Model,
                                                "component_definition");
   static SdaiAttr CD_ID = sdaiGetAttrDefinition(CD, "id");

   SdaiString id;
   // assign an opengl identifier
   BaseglName++;
   glName = BaseglName;

   // setup transformation matrix
   _glIdentityMatrixd(m);

   // NULL out everything!
   PhysicalUnitRef = NULL;
   Name = NULL;

   // set Component
   Component = component;

   // get Id
   sdaiGetAttr(Component, CD_ID, sdaiSTRING, &id);
   Id = strdup(id);

   // set geometry
   Lines.Append(lines);
   getPoints();
   } 
ComponentDefinition::~ComponentDefinition() {
   if (Id != NULL) {
      free(Id);
      Id = NULL;
      }
   if (Name != NULL) {
      free(Name);
      Name = NULL;
      }
   } 
int ComponentDefinition::DynamicType(int ID) {
   if (ID == typeID) return 1;
   return AP210GraphicObject::DynamicType(ID);
   }
#ifdef INSTANCEOF
ComponentDefinition *ComponentDefinition::DirectInstanceOf(AP210Object *s) {
   if (s->GetTypeID() == typeID)
      return(ComponentDefinition *)s;
   return 0;
   }
ComponentDefinition *ComponentDefinition::InstanceOf(AP210Object *s) {
   if (s->DynamicType(typeID))
      return(ComponentDefinition *)s;
   return 0;
   }
#endif
/*--------------------------------------------------------------------------
 *
 * ComponentDefinition.GetPoints()
 *
 * Extract a list of points inorder that define
 * a polygon.
 */
void ComponentDefinition::getPoints() {
  
   AP210ObjectListItor itor(&Lines);
   AP210LP *line;

   // Put points in order
   sortLines();
   itor.Reset();
   while((line = (AP210LP *)itor.Next()) != NULL) {
      Points.Add(line->StartPoint());
      }
   }
// Warning: This can cause problems with Iterators
// They need to be reset after a call to sortLines.
void ComponentDefinition::sortLines() {
   if (Lines.SizeOf() == 0) {
      TRACE("FATAL ERROR: ComponentDefinition %d [%d] has no lines!\n", GetOID(), GetTypeID());
      return;
//      exit(0);
      }
   // this assumes that the lines are good but not in the correct order.
   AP210LP *match;
   AP210LP *tmp;
   AP210ObjectList newlines;
   AP210ObjectListItor itor(&newlines);
   AP210ObjectListItor lineitor(&Lines);

// need to find a beter way to find the first line.
   AP210LP *firstline = NULL;
   double max = -HUGE_VAL;

   lineitor.Reset();
   while ((tmp = (AP210LP *)lineitor.Next()) != NULL) {
      if (max <= tmp->MaxX()) {
         max = tmp->MaxX();
         if (firstline == NULL) {
            firstline = tmp;
            }
         else {
            if (tmp->MaxY() > firstline->MaxY()) {
               firstline = tmp;
               } 
            }
         }
      }
   firstline->SortEndPoints();

   AP210Point *point = firstline->StartPoint();
   AP210Point *endpoint = firstline->EndPoint();

   firstline->SwapPoints();
   newlines.Add(firstline);
   Lines.Delete(firstline);

   while(Lines.SizeOf() > 0) {
      match = matchLine(point);

      if (match == NULL) {
         TRACE("ERROR: Polygon not closed\r\n");
         break;
         }
      else {
         newlines.Add(match);
         
         // set point for next pass.
         if (match->StartPoint() != point) {
            match->SwapPoints();
            }
         point = match->EndPoint();
         Lines.Delete(match);
         
         if (point == endpoint) {
            
            if (Lines.SizeOf() > 0) {
               TRACE("ERROR: %d lines remaining in contour %d after sorting.\r\n",
                                Lines.SizeOf(), GetOID());
               TRACE("       Lines: ");Lines.ListIds(stdout); TRACE("\r\n");
               }
            break;   
            }                 
         }
      }
   // copy sorted lines from newlines to the contours Lines.                    
   itor.Reset();
   while((tmp = (AP210LP *)itor.Next()) != NULL) {
       Lines.Add(tmp);
       }
   }
AP210LP *ComponentDefinition::matchLine(AP210Point *p) {
   AP210LP *tmp;
   AP210ObjectListItor itor(&Lines);

   while((tmp = (AP210LP *)itor.Next()) != NULL) {
      if (tmp->StartPoint() == p) {
         break;
         }
      if (tmp->EndPoint() == p) {
         break;
         }
      }
   return tmp;
   }
void ComponentDefinition::setSeatingPlane(double base) {
   m[14] = base;
   }

//#define AP210RECPRAC
void ComponentDefinition::applyTranslationMatrix() {
   double mlocation[16];
   double mrotation[16];

   // build the transformation matrix for the packaged
   // component this order is required by the 
   // opengl transformation pipeline:
   //   1) locate the component.
   //   2) handle the secondary surface if required.
   //
   // apply the package components transformation matrix.
   // if the component is on the secondary surface.
   // rotate it 180 degrees about the OpenGL Y axis.
#ifdef AP210RECPRAC
   TRACE("Refdes: %s\r\n", Name);
#endif
   if (Side == Bottom) {
#ifdef VERBOSE
       TRACE("Refdes: %s on bottom\r\n", Name);
       TRACE("Input matrix m\r\n");
       _glTraceMatrixd(m);
       TRACE("180 degrees about Y axis\r\n");
       _glTraceMatrixd(Y180Degrees);
#endif
       // build the location matrix
       _glIdentityMatrixd(mlocation);
       mlocation[12] = m[12];
       mlocation[13] = m[13];
#ifdef VERBOSE
       TRACE("location matrix\r\n");
       _glTraceMatrixd(mlocation);
#endif

       // build the rotation matix;
       _glCopyMatrixd(m, mrotation);
       // Remove the location 
       mrotation[12] = 0.0;
       mrotation[13] = 0.0;
       // Remove mirroring about Y axis;
       mrotation[0] = -mrotation[0];
       mrotation[4] = -mrotation[4];
#ifdef VERBOSE
       TRACE("rotation matrix\r\n");
       _glTraceMatrixd(mrotation);
#endif

#ifdef VERBOSEMATRIX
       // multiply matrix ourselves so we can see
       // the intermediate results.
       double mbottom[16];
       _glMultiplyMatrixd(mlocation, Y180Degrees, mbottom);
#ifdef VERBOSE
   TRACE("After mylocation * Y180Degrees\r\n");
   _glTraceMatrixd(mbottom);
#endif

       _glMultiplyMatrixd(mbottom, mrotation, mbottom);
#ifdef VERBOSE
   TRACE("After mylocation * Y180Degrees * myrotation\r\n");
   _glTraceMatrixd(mbottom);
   TRACE("Original Matrix\r\n");
   _glTraceMatrixd(m);
#endif
       // move to location of component
       glMultMatrixd(mbottom);
#else
#ifdef AP210RECPRAC
       // multiply matrix ourselves so we can see
       // the intermediate results.
       double mbottom[16];
       _glMultiplyMatrixd(mlocation, Y180Degrees, mbottom);
       _glMultiplyMatrixd(mbottom, mrotation, mbottom);
       _glTraceMatrixd(mbottom);
#endif
       // use OpenGL to multiply matrix, this is more efficent.
       glMultMatrixd(mlocation);
       glMultMatrixd(Y180Degrees);
       glMultMatrixd(mrotation);
#endif
      }
   else {
#ifdef AP210RECPRAC
      _glTraceMatrixd(m);
#endif
      // move to location of component
      glMultMatrixd(m);
      }
#ifdef AP210RECPRAC
  TRACE("\r\n");
#endif
}
// These are two tighly coupled functions.
// The intent is that the caller will 
//    First call RenderCaps,
//    then change the color, and
//    then call RenderSides.
void ComponentDefinition::RenderCaps() {
   // save the current transformation matrix
   glPushMatrix();
   
   applyTranslationMatrix();
   // All this checking for the PhysicalUnitRef
   // is require only for the BoardComponent (I think!).
   // Need to set PhysicalUnitRef in BoardComponent latter.
   if (PhysicalUnitRef) {
      PhysicalUnitRef->RenderCaps();
      }
   else {
      AP210GraphicObject::RenderCaps();
      }
   }
void ComponentDefinition::RenderSides() {
   // All this checking for the PhysicalUnitRef
   // is require only for the BoardComponent (I think!).
   // Need to set PhysicalUnitRef in BoardComponent latter.
   if (PhysicalUnitRef) {
      PhysicalUnitRef->RenderSides();
      }
   else {
      AP210GraphicObject::RenderSides();
      }
   // restore the transformation matrix
   glPopMatrix();
   }
/*
An component
A #86=COMPONENT_LOCATION('planar projected shape',(#442,#98,#73),#297);

A #442=DESCRIPTIVE_REPRESENTATION_ITEM('placement fixed','true');

A #98=CARTESIAN_TRANSFORMATION_OPERATOR_2D('','','',#336,#341,#162,1.);
A   #336=DIRECTION('',(-1.,0.));
A   #341=DIRECTION('',(0.,1.));
A   #162=CARTESIAN_POINT('',(0.,0.));

A #73=MAPPED_ITEM('component assembly 2d position',#61,#98);
A  #61=REPRESENTATION_MAP(#214,#219);
A   #214=AXIS2_PLACEMENT_2D('origin',#153,$);
A    #153=CARTESIAN_POINT('',(0.,0.));
   #219=GEOMETRICALLY_BOUNDED_2D_WIREFRAME_REPRESENTATION(
        'planar projected shape',(#214,#54),#297);
     #54=GEOMETRIC_CURVE_SET('',(#52));
      #52=COMPOSITE_CURVE('',(#50),.T.);
       #50=COMPOSITE_CURVE_SEGMENT(.CONTINUOUS.,.T.,#48);
        #48=POLYLINE('',(#174,#175,#176,#177,#178,#179,#180,#181,#182,#183,#184,
                     #185,#186,#187,#188,#189,#190,#191,#192,#193,#194,#195,#196,#197,#198,#199,
                     #200,#201,#202,#203,#204,#205,#206,#207,#208,#209,#210));
  #297=(GEOMETRIC_REPRESENTATION_CONTEXT(2)
        GLOBAL_UNCERTAINTY_ASSIGNED_CONTEXT((#289))
        GLOBAL_UNIT_ASSIGNED_CONTEXT((#295,#290))
        REPRESENTATION_CONTEXT('',''));

A #266=PROPERTY_DEFINITION_REPRESENTATION(#377,#86);
   #377=PRODUCT_DEFINITION_SHAPE('','',#122);
    #122=NEXT_ASSEMBLY_USAGE_OCCURRENCE('','assembly composition','',#421,#323, 'TB0');
    #421=PHYSICAL_UNIT('','assembly module',#222,#451);
    #323=PACKAGED_COMPONENT('','',#223,#447);
     #223=PRODUCT_DEFINITION_FORMATION('','',#227);
      #227=PRODUCT('TRANSISTOR','','',(#456));
       #456=PRODUCT_CONTEXT('',#458,'mechanical');
        #458=APPLICATION_CONTEXT('EM pilot');
     #447=PRODUCT_DEFINITION_CONTEXT('physical occurrence',#458,'as designed');
*/
void ComponentDefinition::createComponentLocationRef() {
   static SdaiEntity CL = sdaiGetEntity(DataBase->AP210Model, "component_location");
   static SdaiAttr CL_ITEMS = sdaiGetAttrDefinition(CL, "items");
   static SdaiAttr CL_NAME  = sdaiGetAttrDefinition(CL, "name");
   static SdaiAttr CL_COI   = sdaiGetAttrDefinition(CL, "context_of_items");

   static SdaiEntity REP = sdaiGetEntity(DataBase->AP210Model, "representation");
   static SdaiAttr REP_ITEMS = sdaiGetAttrDefinition(REP, "items");
   static SdaiAttr REP_COI   = sdaiGetAttrDefinition(REP, "context_of_items");

   static SdaiEntity DRI = sdaiGetEntity(DataBase->AP210Model, "descriptive_representation_item");
   static SdaiAttr DRI_DESC = sdaiGetAttrDefinition(DRI, "description");
   static SdaiAttr DRI_NAME = sdaiGetAttrDefinition(DRI, "name");

   static SdaiEntity CTO2D = sdaiGetEntity(DataBase->AP210Model, "cartesian_transformation_operator_2d");
   static SdaiAttr CTO2D_NAME = sdaiGetAttrDefinition(CTO2D, "name");
   static SdaiAttr CTO2D_DESC = sdaiGetAttrDefinition(CTO2D, "description");
   static SdaiAttr CTO2D_A1   = sdaiGetAttrDefinition(CTO2D, "axis1");
   static SdaiAttr CTO2D_A2   = sdaiGetAttrDefinition(CTO2D, "axis2");
   static SdaiAttr CTO2D_LOC  = sdaiGetAttrDefinition(CTO2D, "local_origin");
   static SdaiAttr CTO2D_S    = sdaiGetAttrDefinition(CTO2D, "scale");

   static SdaiEntity DIR = sdaiGetEntity(DataBase->AP210Model, "direction");
   static SdaiAttr DIR_DR   = sdaiGetAttrDefinition(DIR, "direction_ratios");
   static SdaiAttr DIR_NAME = sdaiGetAttrDefinition(DIR, "name");

   static SdaiEntity CP = sdaiGetEntity(DataBase->AP210Model, "cartesian_point");
   static SdaiAttr CP_NAME = sdaiGetAttrDefinition(CP, "name");
   static SdaiAttr CP_C = sdaiGetAttrDefinition(CP, "coordinates");

   static SdaiEntity MI = sdaiGetEntity(DataBase->AP210Model, "mapped_item");
   static SdaiAttr MI_NAME = sdaiGetAttrDefinition(MI, "name");
   static SdaiAttr MI_MS   = sdaiGetAttrDefinition(MI, "mapping_source");
   static SdaiAttr MI_MT   = sdaiGetAttrDefinition(MI, "mapping_target");

   static SdaiEntity REPMAP = sdaiGetEntity(DataBase->AP210Model, "representation_map");
   static SdaiAttr REPMAP_MO = sdaiGetAttrDefinition(REPMAP, "mapping_origin");
   static SdaiAttr REPMAP_MR = sdaiGetAttrDefinition(REPMAP, "mapped_representation");

   static SdaiEntity A2P2D = sdaiGetEntity(DataBase->AP210Model, "axis2_placement_2d");
   static SdaiAttr A2P2D_NAME = sdaiGetAttrDefinition(A2P2D, "name");
   static SdaiAttr A2P2D_LOC  = sdaiGetAttrDefinition(A2P2D, "location");

   static SdaiEntity PDR = sdaiGetEntity(DataBase->AP210Model, "property_definition_representation");
   static SdaiAttr PDR_DEF = sdaiGetAttrDefinition(PDR, "definition");
   static SdaiAttr PDR_UR  = sdaiGetAttrDefinition(PDR, "used_representation");

   static SdaiAttr PDS = sdaiGetEntity(DataBase->AP210Model, "product_definition_shape");
   static SdaiAttr PDS_NAME = sdaiGetAttrDefinition(PDS, "name");
   static SdaiAttr PDS_DES  = sdaiGetAttrDefinition(PDS, "description");
   static SdaiAttr PDS_DEF  = sdaiGetAttrDefinition(PDS, "definition");

   static SdaiEntity PD = sdaiGetEntity(DataBase->AP210Model, "property_definition");
   static SdaiAttr PD_DEF = sdaiGetAttrDefinition(PD, "definition");

   SdaiSet items = sdaiNULL;
   SdaiAppInstance cl_coi;
   SdaiAppInstance dri;

   SdaiAppInstance cto2d;
   SdaiAppInstance cto2d_a1;
   SdaiAppInstance cto2d_a2;
   SdaiAggr ratios;
   SdaiAppInstance cto2d_lo;
   SdaiAggr coordinates;

   SdaiAppInstance mi;
   SdaiAppInstance mi_ms;
   SdaiAppInstance pdr;
   SdaiAppInstance pds;
   SdaiADB adb;

   SdaiAppInstance pd;
   SdaiAppInstance a2p2d;
   SdaiAppInstance a2p2d_lo;

   ComponentLocationRef = sdaiCreateInstance(DataBase->AP210Model, CL);
#ifdef VERBOSE
TRACE("In ComponentDefinition::createComponentLocationRef()\r\n");
TRACE("ComponentLocationRef: %s\r\n", _sdaiGetPart21Description(ComponentLocationRef));
TRACE("Side: %s\r\n", Side);
#endif
   sdaiPutAttr(ComponentLocationRef, CL_NAME, sdaiSTRING, "planar projected shape");

   // set context_of_items to that of the Package->ShapeRepRef
   sdaiGetAttr(PackageRef->ShapeRepRef, CL_COI, sdaiINSTANCE, &cl_coi);
#ifdef VERBOSE
   TRACE(" cl_coi: %s\r\n", _sdaiGetPart21Description(cl_coi)); 
#endif
   sdaiPutAttr(ComponentLocationRef, CL_COI, sdaiINSTANCE, cl_coi);

   items = sdaiCreateAggr(ComponentLocationRef, CL_ITEMS);

   // create and add "placement fixed" descriptive_representation_item
   // Done
   dri = sdaiCreateInstance(DataBase->AP210Model, DRI);
   sdaiAdd(items, sdaiINSTANCE, dri);
#ifdef VERBOSE
   TRACE(" dri: %s\r\n", _sdaiGetPart21Description(dri)); 
#endif
   sdaiPutAttr(dri, DRI_NAME, sdaiSTRING, "placement fixed");
   sdaiPutAttr(dri, DRI_DESC, sdaiSTRING, "false");

   // create and add cartesian_transformation_operator_2d
   // Done
   cto2d = sdaiCreateInstance(DataBase->AP210Model, CTO2D);
   sdaiAdd(items, sdaiINSTANCE, cto2d);
#ifdef VERBOSE
   TRACE(" cto2d: %s\r\n", _sdaiGetPart21Description(cto2d)); 
#endif
   sdaiPutAttr(cto2d, CTO2D_NAME, sdaiSTRING, "");
   sdaiPutAttr(cto2d, CTO2D_DESC, sdaiSTRING, "");

   sdaiPutAttr(cto2d, CTO2D_S, sdaiREAL, 1.0);

   // axis1
   cto2d_a1 = sdaiCreateInstance(DataBase->AP210Model, DIR);
   sdaiPutAttr(cto2d, CTO2D_A1, sdaiINSTANCE, cto2d_a1);
#ifdef VERBOSE
   TRACE("  cto2d_a1: %s\r\n", _sdaiGetPart21Description(cto2d_a1)); 
#endif
   sdaiPutAttr(cto2d_a1, DIR_NAME, sdaiSTRING, "");
   ratios = sdaiCreateAggr(cto2d_a1, DIR_DR);
   sdaiPutAggrByIndex(ratios, 0, sdaiREAL, 1.0);
   sdaiPutAggrByIndex(ratios, 1, sdaiREAL, 0.0);

   // axis2
   cto2d_a2 = sdaiCreateInstance(DataBase->AP210Model, DIR);
   sdaiPutAttr(cto2d, CTO2D_A2, sdaiINSTANCE, cto2d_a2);
#ifdef VERBOSE
   TRACE("  cto2d_a2: %s\r\n", _sdaiGetPart21Description(cto2d_a2)); 
#endif
   sdaiPutAttr(cto2d_a2, DIR_NAME, sdaiSTRING, "");
   ratios = sdaiCreateAggr(cto2d_a2, DIR_DR);
   sdaiPutAggrByIndex(ratios, 0, sdaiREAL, 0.0);
   sdaiPutAggrByIndex(ratios, 1, sdaiREAL, 1.0);

   // location
   cto2d_lo = sdaiCreateInstance(DataBase->AP210Model, CP);
   sdaiPutAttr(cto2d_lo, CP_NAME, sdaiSTRING, "");
   sdaiPutAttr(cto2d, CTO2D_LOC, sdaiINSTANCE, cto2d_lo);
#ifdef VERBOSE
   TRACE("  cto2d_lo: %s\r\n", _sdaiGetPart21Description(cto2d_lo)); 
#endif
   coordinates = sdaiCreateAggr(cto2d_lo, CP_C);
   sdaiPutAggrByIndex(coordinates, 0, sdaiREAL, 0.0);
   sdaiPutAggrByIndex(coordinates, 1, sdaiREAL, 0.0);

   // create and add "component assembly 2d position" mapped_item
   mi = sdaiCreateInstance(DataBase->AP210Model, MI);
   sdaiAdd(items, sdaiINSTANCE, mi);
#ifdef VERBOSE
   TRACE(" mi: %s\r\n", _sdaiGetPart21Description(mi)); 
#endif
   sdaiPutAttr(mi, MI_NAME, sdaiSTRING, "component assembly 2d position");
   sdaiPutAttr(mi, MI_MT, sdaiINSTANCE, cto2d);

   mi_ms = sdaiCreateInstance(DataBase->AP210Model, REPMAP);
   sdaiPutAttr(mi, MI_MS, sdaiINSTANCE, mi_ms);
#ifdef VERBOSE
   TRACE(" mi_ms: %s\r\n", _sdaiGetPart21Description(mi_ms)); 
#endif
   a2p2d = sdaiCreateInstance(DataBase->AP210Model, A2P2D);

   sdaiPutAttr(mi_ms, REPMAP_MO, sdaiINSTANCE, a2p2d);
   sdaiPutAttr(mi_ms, REPMAP_MR, sdaiINSTANCE, PackageRef->ShapeRepRef);
#ifdef VERBOSE
   TRACE(" a2p2d: %s\r\n", _sdaiGetPart21Description(a2p2d)); 
#endif
   sdaiPutAttr(a2p2d, A2P2D_NAME, sdaiSTRING, "origin");

   // location
   a2p2d_lo = sdaiCreateInstance(DataBase->AP210Model, CP);
   sdaiPutAttr(a2p2d_lo, CP_NAME, sdaiSTRING, "");
   
   sdaiPutAttr(a2p2d, A2P2D_LOC, sdaiINSTANCE, a2p2d_lo);
#ifdef VERBOSE
   TRACE("  a2p2d_lo: %s\r\n", _sdaiGetPart21Description(a2p2d_lo)); 
#endif
   coordinates = sdaiCreateAggr(a2p2d_lo, CP_C);
   sdaiPutAggrByIndex(coordinates, 0, sdaiREAL, 0.0);
   sdaiPutAggrByIndex(coordinates, 1, sdaiREAL, 0.0);


   // create a pdr to relate the cto2d to the nauo.
   pdr = sdaiCreateInstance(DataBase->AP210Model, PDR);
   sdaiPutAttr(pdr, PDR_UR, sdaiINSTANCE, ComponentLocationRef);
#ifdef VERBOSE
   TRACE(" pdr 1: %s\r\n", _sdaiGetPart21Description(pdr));
#endif

   // definition
   pds = sdaiCreateInstance(DataBase->AP210Model, PDS);
   sdaiPutAttr(pdr, PDR_DEF, sdaiINSTANCE, pds);
#ifdef VERBOSE
   TRACE("  pds: %s\r\n", _sdaiGetPart21Description(pds));
#endif
   adb = sdaiCreateADB (sdaiINSTANCE, NauoRef);
   sdaiPutADBTypePath (adb, 1, NAUO_TYPENAMES);
   sdaiPutAttr(pds, PDS_DEF, sdaiADB, adb); 

   sdaiPutAttr(pds, PDS_NAME, sdaiSTRING, "");
   sdaiPutAttr(pds, PDS_DES, sdaiSTRING, "");

   // set the surface of the component_location
   pdr = sdaiCreateInstance(DataBase->AP210Model, PDR);
   sdaiPutAttr(pdr, PDR_UR, sdaiINSTANCE, ComponentLocationRef);
#ifdef VERBOSE
   TRACE(" pdr2: %s\r\n", _sdaiGetPart21Description(pdr));
#endif
   
   pd = sdaiCreateInstance(DataBase->AP210Model, PD);
   sdaiPutAttr(pdr, PDR_DEF, sdaiINSTANCE, pd);
#ifdef VERBOSE
   TRACE("  pd: %s\r\n", _sdaiGetPart21Description(pd));
#endif
   if (Side == Top) {
      sdaiPutAttr(pd, PD_DEF, sdaiADB, DataBase->getPrimarySurface());
      }
   else if (Side == Bottom) {
      sdaiPutAttr(pd, PD_DEF, sdaiADB, DataBase->getSecondarySurface());
      }
   DataBase->SetModifiedFlag(TRUE);
   }
/*
A component
In ComponentDefinition::deleteComponentLocationRef()
D Component Location: #83 a component_location  Value = 0-0
DC item: #446 a descriptive_representation_item  Value = 0-0
DC item: #95 a cartesian_transformation_operator_2d  Value = 0-0
DC   axis1: #333 a direction  Value = 0-0
DC   axis2: #350 a direction  Value = 0-0
DC   local_origin: #159 a cartesian_point  Value = 0-0
DC item: #70 a mapped_item  Value = 0-0
DC   mapping_source: #58 a representation_map  Value = 0-0
    // keep this referenced by other entities
    mapping_origin: #214 a axis2_placement_2d  Value = 0-0
     location: #153 a cartesian_point  Value = 0-0
  context_of_items: #297 a geometric_representation_context_and_global_uncertainty_assigned_context_and_global_unit_assigned_context  Value = 0-0
DC  pdr: #263 a property_definition_representation  Value = 0-0
DC     definition: #381 a product_definition_shape  Value = 0-0
        // keep this is the assembly definition
        definition: #119 a next_assembly_usage_occurrence  Value = 0-0
DC  pdr: #278 a property_definition_representation  Value = 0-0
DC     definition: #245 a property_definition  Value = 0-0
        // keep this is referenced by other entities.
        definition: #358 a component_shape_aspect  Value = 0-0
*/
#define DELETE_CTO2D
//#define DONT_DELETE
void ComponentDefinition::deleteComponentLocationRef() {
   static SdaiEntity REP = sdaiGetEntity(DataBase->AP210Model, "representation");
   static SdaiAttr REP_ITEMS = sdaiGetAttrDefinition(REP, "items");
   static SdaiAttr REP_COI = sdaiGetAttrDefinition(REP, "context_of_items");

   static SdaiEntity DRI = sdaiGetEntity(DataBase->AP210Model, "descriptive_representation_item");

   static SdaiEntity CTO2D = sdaiGetEntity(DataBase->AP210Model, "cartesian_transformation_operator_2d");
   static SdaiAttr CTO2D_A1 = sdaiGetAttrDefinition(CTO2D, "axis1");
   static SdaiAttr CTO2D_A2 = sdaiGetAttrDefinition(CTO2D, "axis2");
   static SdaiAttr CTO2D_LO = sdaiGetAttrDefinition(CTO2D, "local_origin");

   static SdaiEntity MI = sdaiGetEntity(DataBase->AP210Model, "mapped_item");
   static SdaiAttr MI_MS = sdaiGetAttrDefinition(MI, "mapping_source");
#ifdef DONT_DELETE
   static SdaiAttr MI_MT = sdaiGetAttrDefinition(MI, "mapping_target");
#endif

#ifdef DONT_DELETE
   static SdaiEntity REPMAP = sdaiGetEntity(DataBase->AP210Model, "representation_map");
   static SdaiAttr REPMAP_MO = sdaiGetAttrDefinition(REPMAP, "mapping_origin");

   static SdaiEntity A2P2D = sdaiGetEntity(DataBase->AP210Model, "axis2_placement_2d");
   static SdaiAttr A2P2D_LOC = sdaiGetAttrDefinition(A2P2D, "location");
#endif

   static SdaiEntity PDR = sdaiGetEntity(DataBase->AP210Model, "property_definition_representation");
   static SdaiAttr PDR_DEF = sdaiGetAttrDefinition(PDR, "definition");
   static SdaiAttr PDR_UR = sdaiGetAttrDefinition(PDR, "used_representation");

#ifdef DONT_DELETE
   static SdaiEntity PD = sdaiGetEntity(DataBase->AP210Model, "property_definition");
   static SdaiAttr PD_DEF = sdaiGetAttrDefinition(PD, "definition");
#endif

   SdaiIterator itor;
   SdaiAggr items; 
   SdaiAppInstance item;
   SdaiAppInstance cl_coi;
   SdaiAppInstance cto2d_a1;
   SdaiAppInstance cto2d_a2;
   SdaiAppInstance cto2d_lo;
   SdaiAppInstance mi_ms;
#ifdef DONT_DELETE
   SdaiAppInstance mi_mt;
   SdaiAppInstance repmap_mo;
   SdaiAppInstance a2p2d_loc;
#endif
   SdaiNPL resultList = sdaiCreateNPL();
   SdaiNPL domain = sdaiCreateNPL();
   SdaiIterator itor2;
   SdaiInstance pdr;
   SdaiAppInstance pdr_def;
#ifdef DONT_DELETE
   SdaiAppInstance pd_def;
#endif
#ifdef VERBOSE
   TRACE("In ComponentDefinition::deleteComponentLocationRef()\r\n");
   TRACE("D Component Location: %s\r\n", _sdaiGetPart21Description(ComponentLocationRef)); 
#endif
   sdaiGetAttr(ComponentLocationRef, REP_ITEMS, sdaiAGGR, &items);
   itor = sdaiCreateIterator(items);
   while (sdaiNext(itor)) {
      sdaiGetAggrByIterator(itor, sdaiINSTANCE, &item); 
      if (sdaiIsInstanceOf(item, DRI)) {
         // placement fixed and mounting style.
#ifdef VERBOSE
         TRACE("DC item: %s\r\n", _sdaiGetPart21Description(item));
#endif
#ifdef DELETE_CTO2D
         sdaiDeleteInstance(item);
#endif
         }
      else if (sdaiIsInstanceOf(item, CTO2D)) {
#ifdef VERBOSE
        TRACE("DC item: %s\r\n", _sdaiGetPart21Description(item));
#endif

         sdaiGetAttr(item, CTO2D_A1, sdaiINSTANCE, &cto2d_a1);
#ifdef VERBOSE
         TRACE("DC   axis1: %s\r\n", _sdaiGetPart21Description(cto2d_a1));
#endif

         sdaiGetAttr(item, CTO2D_A2, sdaiINSTANCE, &cto2d_a2);
#ifdef VERBOSE
         TRACE("DC   axis2: %s\r\n", _sdaiGetPart21Description(cto2d_a2));
#endif

         sdaiGetAttr(item, CTO2D_LO, sdaiINSTANCE, &cto2d_lo);
#ifdef VERBOSE
         TRACE("DC   local_origin: %s\r\n", _sdaiGetPart21Description(cto2d_lo));
#endif
#ifdef DELETE_CTO2D
         sdaiDeleteInstance(item);
         sdaiDeleteInstance(cto2d_a1);
         sdaiDeleteInstance(cto2d_a2);
         sdaiDeleteInstance(cto2d_lo);
#endif
         }
      else if (sdaiIsInstanceOf(item, MI)) {
#ifdef VERBOSE
         TRACE("DC item: %s\r\n", _sdaiGetPart21Description(item));
#endif

         sdaiGetAttr(item, MI_MS, sdaiINSTANCE, &mi_ms);
#ifdef VERBOSE
         TRACE("DC   mapping_source: %s\r\n", _sdaiGetPart21Description(mi_ms));
#endif

#ifdef DONT_DELETE
         // reference by other entities
         sdaiGetAttr(mi_ms, REPMAP_MO, sdaiINSTANCE, &repmap_mo);
#ifdef VERBOSE
        TRACE("DC    mapping_origin: %s\r\n", _sdaiGetPart21Description(repmap_mo));
#endif

         sdaiGetAttr(repmap_mo, A2P2D_LOC, sdaiINSTANCE, &a2p2d_loc);
#ifdef VERBOSE
         TRACE("DC     location: %s\r\n", _sdaiGetPart21Description(a2p2d_loc));
#endif

         // must delete latter
         sdaiGetAttr(item, MI_MT, sdaiINSTANCE, &mi_mt);
#ifdef VERBOSE
         TRACE("DC   mapping_target: 0x%08x\r\n", mi_mt);
         TRACE("DC   mapping_target: %s\r\n", _sdaiGetPart21Description(mi_mt));
#endif
#endif
#ifdef DELETE_CTO2D
         sdaiDeleteInstance(item);
         sdaiDeleteInstance(mi_ms);
#endif
         }
#ifdef VERBOSE
      else {
         TRACE("  item: %s\r\n", _sdaiGetPart21Description(item));
         }
#endif
      }
   // Referenced by other entities
   sdaiGetAttr(ComponentLocationRef, REP_COI, sdaiINSTANCE, &cl_coi);
#ifdef VERBOSE
   TRACE("  context_of_items: %s\r\n", _sdaiGetPart21Description(cl_coi));
#endif

   sdaiFindInstanceUsedIn(ComponentLocationRef, PDR_UR, domain, resultList);
   if (sdaiGetMemberCount(resultList) > 0) {
     itor2 = sdaiCreateIterator(resultList);

      while(sdaiNext(itor2)) {
         sdaiGetAggrByIterator(itor2, sdaiINSTANCE, &pdr);
#ifdef VERBOSE
         TRACE("DC  pdr: %s\r\n", _sdaiGetPart21Description(pdr));
#endif

         sdaiGetAttr(pdr, PDR_DEF, sdaiINSTANCE, &pdr_def);
#ifdef VERBOSE
         TRACE("DC     definition: %s\r\n", _sdaiGetPart21Description(pdr_def));
#endif
#ifdef DONT_DELETE
         // Referenced by other entities.
         sdaiGetAttr(pdr_def, PD_DEF, sdaiINSTANCE, &pd_def);
#ifdef VERBOSE
         TRACE("       definition: %s\r\n", _sdaiGetPart21Description(pd_def));
#endif
#endif

#ifdef DELETE_CTO2D
         // delete um
         sdaiDeleteInstance(pdr); 
         sdaiDeleteInstance(pdr_def);
#endif
         }
      sdaiDeleteIterator(itor2);
      }
   sdaiDeleteNPL(resultList);
   sdaiDeleteNPL(domain);

   sdaiDeleteIterator(itor);

#ifdef DELETE_CTO2D
   sdaiDeleteInstance(ComponentLocationRef);
   DataBase->SetModifiedFlag(TRUE);
#endif
   ComponentLocationRef = sdaiNULL;
   }
#undef DELETE_CTO2D

double ComponentDefinition::getX() {
   return m[12];
   }

void ComponentDefinition::setX(double x) {

   if (m[12] != x) {
      m[12] = x;
      DataBase->setTransformationMatrix(m, ComponentLocationRef, ComponentUnitRef);
      DataBase->SetModifiedFlag(TRUE);
      }
   }

double ComponentDefinition::getY() {
   return m[13];
   }

void ComponentDefinition::setY(double y) {

   if (m[13] != y) {
      m[13] = y;
      DataBase->setTransformationMatrix(m, ComponentLocationRef, ComponentUnitRef);
      DataBase->SetModifiedFlag(TRUE);
      }
   }
//---------------------------------------------------
double ComponentDefinition::getRotation() {
   double rotation = asin(m[1]);

   if (rotation < 0.0) {
      rotation = rotation + 2*M_PI;
      }
   else {
      if (Side == Bottom) {
         rotation = acos(-m[0]);
         }
      else {
         rotation = acos(m[0]);
         }
      }
   // keep to see if Rotation has changed.
   Rotation = TODEG(rotation);

   return Rotation; 
   }

void ComponentDefinition::setRotation(double rotation) {
#ifdef VERBOSE
TRACE("In ComponentDefinition::setRotation(%f)\r\n", rotation);
#endif
   if (Rotation != rotation) {
      double radian = TORAD(rotation);

      // keep to see if Rotation has changed.
      Rotation = rotation;    
      
      m[0] = cos(radian);
      m[1] = sin(radian);
      m[4] = -sin(radian);
      m[5] = cos(radian);

      // Mirror the component about the Y axis if it is on the bottom.
      if (Side == Bottom) {
#ifdef VERBOSE
TRACE("Mirror about Y axis\r\n");
#endif
         m[0] = -m[0];
         m[4] = -m[4];
#ifdef VERBOSE
TRACE("2D Determinant (m[0]*m[5])-(m[4]*m[1]): %f m[0]*m[5]): %f (m[4]*m[1]): %f\r\n ",
                 (m[0]*m[5])-(m[4]*m[1]), (m[0]*m[5]),(m[4]*m[1]));
_glTraceMatrixd(m);
#endif
         }

#ifdef VERBOSE
TRACE("setRotation() result:\r\n");
_glTraceMatrixd(m);
#endif
      DataBase->setTransformationMatrix(m, ComponentLocationRef, ComponentUnitRef);
      DataBase->SetModifiedFlag(TRUE);
      }
   }
BOOL ComponentDefinition::getPlacementFixed() {
   static SdaiEntity CL = sdaiGetEntity(DataBase->AP210Model, "component_location");
   static SdaiAttr CL_ITEMS = sdaiGetAttrDefinition(CL, "items");

   static SdaiEntity DRI = sdaiGetEntity(DataBase->AP210Model, "descriptive_representation_item");
   static SdaiAttr DRI_NAME = sdaiGetAttrDefinition(DRI, "name");
   static SdaiAttr DRI_DESC = sdaiGetAttrDefinition(DRI, "description");

   SdaiAggr items;
   SdaiIterator itemsitor;
   SdaiAppInstance item;
   SdaiString dri_name;
   SdaiString dri_desc;
   BOOL result = FALSE; // if it's not defined lets assume you can change it

   if (ComponentLocationRef != sdaiNULL) {

      if (sdaiIsInstanceOf(ComponentLocationRef, CL)) {
         if (sdaiGetAttr(ComponentLocationRef, CL_ITEMS, sdaiAGGR, &items) != sdaiNULL) {
         
         itemsitor = sdaiCreateIterator(items);

         while(sdaiNext(itemsitor)) {
            sdaiGetAggrByIterator(itemsitor, sdaiINSTANCE, &item); 
             
            if (sdaiIsInstanceOf(item, DRI)) {
                sdaiGetAttr(item, DRI_NAME, sdaiSTRING, &dri_name);

               if (!strcmp("placement fixed", dri_name)) {
                  sdaiGetAttr(item, DRI_DESC, sdaiSTRING, &dri_desc);

                  if (!strcmp("true", dri_desc)) {          
                     result = TRUE;
                     }
                  else if (!strcmp("false", dri_desc)) {          
                     result = FALSE;
                     }
                  }
               }
               }
            }
         }
      }
   return result;
   }

void ComponentDefinition::setPlacementFixed(BOOL fixed) {
   static SdaiEntity CL = sdaiGetEntity(DataBase->AP210Model, "component_location");
   static SdaiAttr CL_ITEMS = sdaiGetAttrDefinition(CL, "items");

   static SdaiEntity DRI = sdaiGetEntity(DataBase->AP210Model, "descriptive_representation_item");
   static SdaiAttr DRI_NAME = sdaiGetAttrDefinition(DRI, "name");
   static SdaiAttr DRI_DESC = sdaiGetAttrDefinition(DRI, "description");

   SdaiAggr items;
   SdaiIterator itemsitor;
   SdaiAppInstance item;
   SdaiString dri_name;
   SdaiString dri_desc;
   BOOL current = TRUE;

   if (ComponentLocationRef != sdaiNULL) {

      if (sdaiIsInstanceOf(ComponentLocationRef, CL)) {
         sdaiGetAttr(ComponentLocationRef, CL_ITEMS, sdaiAGGR, &items);
         itemsitor = sdaiCreateIterator(items);

         while(sdaiNext(itemsitor)) {
            sdaiGetAggrByIterator(itemsitor, sdaiINSTANCE, &item); 
             
            if (sdaiIsInstanceOf(item, DRI)) {
                sdaiGetAttr(item, DRI_NAME, sdaiSTRING, &dri_name);

               if (!strcmp("placement fixed", dri_name)) {
                  sdaiGetAttr(item, DRI_DESC, sdaiSTRING, &dri_desc);

                  if (!strcmp("true", dri_desc)) {          
                     current = TRUE;
                     }
                  else if (!strcmp("false", dri_desc)) {          
                     current = FALSE;
                     }
                  if (current != fixed) {

                     if (fixed == TRUE) {
                        sdaiPutAttr(item, DRI_DESC, sdaiSTRING, "true");
                        DataBase->SetModifiedFlag(TRUE);
                        }
                     else if (fixed == FALSE) {
                        sdaiPutAttr(item, DRI_DESC, sdaiSTRING, "false");
                        DataBase->SetModifiedFlag(TRUE);
                        }
                     }
                  }
               }
            }
         }
      }
   }
int ComponentDefinition::getReDrawStatus() {
   // All this checking for the PhysicalUnitRef
   // is require only for the BoardComponent (I think!).
   // Need to set PhysicalUnitRef in BoardComponent latter.
   if (PhysicalUnitRef) {
      return PhysicalUnitRef->getReDrawStatus();
      }
   return AP210GraphicObject::getReDrawStatus();
   }

void ComponentDefinition::setReDrawStatus(int status) {
   // All this checking for the PhysicalUnitRef
   // is require only for the BoardComponent (I think!).
   // Need to set PhysicalUnitRef in BoardComponent latter.
   if (PhysicalUnitRef) {
      PhysicalUnitRef->setReDrawStatus(status);
      }
   else {
      AP210GraphicObject::setReDrawStatus(status);
      }
   }

GLuint ComponentDefinition::getCapDisplayList() {
   // All this checking for the PhysicalUnitRef
   // is require only for the BoardComponent (I think!).
   // Need to set PhysicalUnitRef in BoardComponent latter.
   if (PhysicalUnitRef) {
      return PhysicalUnitRef->getCapDisplayList();
      }
   return AP210GraphicObject::getCapDisplayList();
   }

GLuint ComponentDefinition::getSideDisplayList() {
   // All this checking for the PhysicalUnitRef
   // is require only for the BoardComponent (I think!).
   // Need to set PhysicalUnitRef in BoardComponent latter.
   if (PhysicalUnitRef) {
      return PhysicalUnitRef->getSideDisplayList();
      }
   return AP210GraphicObject::getSideDisplayList();
   }

void ComponentDefinition::ReDraw(double Z, double Base) {
   // All this checking for the PhysicalUnitRef
   // is require only for the BoardComponent (I think!).
   // Need to set PhysicalUnitRef in BoardComponent latter.
   if (PhysicalUnitRef) {
      PhysicalUnitRef->ReDraw(Z, Base);
      }
   else {
      AP210GraphicObject::ReDraw(Z, Base);
      }
   }
void ComponentDefinition::Draw(double Z) {
   PhysicalUnitRef->Draw(Z);
   }

void ComponentDefinition::Trace() {
   TRACE("Component: %s\n", _sdaiGetPart21Description(Component));
   }
CString ComponentDefinition::getSurface() {
   return DataBase->getPackagedComponentSurface(ComponentLocationRef);
   }
void ComponentDefinition::setSurface(CString surface) {

   // get the side
   if (!strcmp("Primary Surface", surface)) {

      if (Side != Top) {
         DataBase->SetModifiedFlag(TRUE);

         if (Side == Bottom) {
            // Remove mirroring about Y axis;
            m[0] = -m[0];
            m[4] = -m[4];
            DataBase->setTransformationMatrix(m, ComponentLocationRef, ComponentUnitRef);
            }
         Side = Top;

         if (ComponentLocationRef == sdaiNULL) {
             createComponentLocationRef();
             DataBase->UpdateProdView();
             }
         else {
            DataBase->setPackagedComponentSurface(ComponentLocationRef, PRIMARY_SURFACE); 
            }
         }
      } 
   else if (!strcmp("Secondary Surface", surface)) {

      if (Side != Bottom) {
         DataBase->SetModifiedFlag(TRUE);

         if (Side == Top) {
            // Add mirroring about Y axis;
            m[0] = -m[0];
            m[4] = -m[4];
            DataBase->setTransformationMatrix(m, ComponentLocationRef, ComponentUnitRef);
            }
         Side = Bottom;
 
         if (ComponentLocationRef == sdaiNULL) {
            createComponentLocationRef();
            DataBase->UpdateProdView();
            }
         }
      else {
         DataBase->setPackagedComponentSurface(ComponentLocationRef, SECONDARY_SURFACE); 
         }
      }
   else {
      if (Side != Unplaced) {
         DataBase->SetModifiedFlag(TRUE);
         Side = Unplaced;
         deleteComponentLocationRef();
         DataBase->UpdateProdView();
         }
      }
   }
int ComponentDefinition::getItemFindNumber() {
   return ItemFindNumber;
   }

void ComponentDefinition::setId(CString id) {
   static SdaiEntity CD = sdaiGetEntity(DataBase->AP210Model,
                                                "component_definition");
   static SdaiAttr CD_ID = sdaiGetAttrDefinition(CD, "id");

   if (strcmp(Id, id)) {
      // put Id
      sdaiPutAttr(Component, CD_ID, sdaiSTRING, id);
      free(Id);
      Id = strdup(id);
      DataBase->SetModifiedFlag(TRUE);
      }
   }

char *ComponentDefinition::getId() {
   return Id;
   }

char *ComponentDefinition::getName() {
   return Name;
   }

void ComponentDefinition::setName(CString name) {
   
   if (Name != NULL) {
      free(Name);
      Name = NULL;
      }
   Name = strdup(name);
   }
