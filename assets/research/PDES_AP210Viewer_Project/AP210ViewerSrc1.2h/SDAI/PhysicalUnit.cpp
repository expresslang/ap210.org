// PhysicalUnit.cpp: implementation of the PhysicalUnit class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PhysicalUnit.h"
#include "../PWBDataBase.h"

#include "ExtractGeometry.h"
#include "ap210_visualizer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
PhysicalUnit *PhysicalUnit::Construct(PWBDataBase *PWB, SdaiAppInstance physical_unit) {
   PhysicalUnit *pu;
   AP210ObjectListItor itor(&(PWB->PhysicalUnits));

   // look for an existing PhysicalUnit
   while((pu = (PhysicalUnit *)itor.NextDirectInstanceOf(PhysicalUnit::TypeID())) != NULL) {
      if (pu->PhysicalUnitRef == physical_unit) {
         return pu;
         }
      }
   // create a new PhysicalUnit
   pu = new PhysicalUnit(PWB, physical_unit);
   pu->ItemFindNumber = pu->DataBase->assignItemFindNumber();
   PWB->PhysicalUnits.Add(pu);
   return pu;
   }

PhysicalUnit::PhysicalUnit(PWBDataBase *PWB,
                           SdaiAppInstance pu):
   AP210GraphicObject(PWB) {
   static SdaiEntity PU = sdaiGetEntity(DataBase->AP210Model, "physical_unit");
	   
   SdaiAppInstance unit; // unit for psr
   ItemFindNumber = 0;
   PhysicalUnitRef = pu;

#ifdef VERBOSE
TRACE0("In PhysicalUnit::PhysicalUnit()\r\n");
#endif
   if (sdaiIsKindOf(PhysicalUnitRef, PU)) {
      // Need to figure this out for the physical unit.
      PartNumber = strdup(getPhysicalUnitsPartNumber(DataBase->AP210Model, PhysicalUnitRef)); 

      if ((ShapeRepRef = getShape(DataBase->AP210Model)) != sdaiNULL) {
#ifdef VERBOSE
TRACE("ShapeRef: %s\r\n", _sdaiGetPart21Description(ShapeRepRef));
#endif
        if ((unit = getRepresentationLengthUnit(DataBase->AP210Model, ShapeRepRef)) == sdaiNULL) {
            TRACE("ERROR: %s\r\n       has no units.\r\n", _sdaiGetPart21Description(ShapeRepRef));
            }     
         // get the lines from the shape rep
         AP210ObjectList *lines = ExtractGeometry::getLines(DataBase->AP210Model, PWB, 
                                                            getGeometryFromShapeRep(DataBase->AP210Model, ShapeRepRef),
                                                            unit);
         // create a listof points
         getPoints(lines);
         }
#ifdef VERBOSE
      else {
TRACE("ERROR: no psr found for a PhysicalUnit\r\n");   
         }
#endif
      }
#ifdef VERBOSE
   else {
      TRACE("ERROR: #%s is not a PhysicalUnit\n",
              _sdaiGetPart21Description(PhysicalUnitRef));
      PartNumber = strdup(_sdaiGetPart21Description(PhysicalUnitRef));
      }
TRACE("Leaving PhysicalUnit::PhysicalUnit()\r\n*******\r\n");
#endif
   }

PhysicalUnit::~PhysicalUnit() {
   free(PartNumber);
  }

int PhysicalUnit::DynamicType(int ID) {
   if (ID == typeID) return 1;
   return AP210GraphicObject::DynamicType(ID);
   }
#ifdef INSTANCEOF
PhysicalUnit *PhysicalUnit::DirectInstanceOf(AP210Object *s) {
   if (s->GetTypeID() == typeID)
      return(PhysicalUnit *)s;
   return 0;
   }
PhysicalUnit *PhysicalUnit::InstanceOf(AP210Object *s) {
   if (s->DynamicType(typeID))
      return(PhysicalUnit *)s;
   return 0;
   }
#endif
/*--------------------------------------------------------------------------
 *
 * PhysicalUnit.getPoints()
 *
 * Extract a list of points inorder that define
 * a polygon.
 */
void PhysicalUnit::getPoints(AP210ObjectList *lines) {
  
   AP210ObjectListItor itor(lines);
   AP210LP *line;

   // Put points in order
   SortLines(lines);
   itor.Reset();
   while((line = (AP210LP *)itor.Next()) != NULL) {
      Points.Add(line->StartPoint());
      }
   }
// Warning: This can cause problems with Iterators
// They need to be reset after a call to SortLines.
void PhysicalUnit::SortLines(AP210ObjectList *lines) {
   if (lines->SizeOf() == 0) {
      TRACE("FATAL ERROR: PhysicalUnit %d [%d] has no lines!\n", GetOID(), GetTypeID());
//      exit(0);
      return;
      }
   // this assumes that the lines are good but not in the correct order.
   AP210LP *match;
   AP210LP *tmp;
   AP210ObjectList newlines;
   AP210ObjectListItor itor(&newlines);
   AP210ObjectListItor lineitor(lines);

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
   lines->Delete(firstline);

   while(lines->SizeOf() > 0) {
      match = MatchLine(lines, point);

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
         lines->Delete(match);
         
         if (point == endpoint) {
            
            if (lines->SizeOf() > 0) {
               TRACE("ERROR: %d lines remaining in contour %d after sorting.\r\n",
                                lines->SizeOf(), GetOID());
               TRACE("       Lines: ");lines->ListIds(stdout); TRACE("\r\n");
               }
            break;   
            }                 
         }
      }
   // copy sorted lines from newlines to the contours Lines.                    
   itor.Reset();
   while((tmp = (AP210LP *)itor.Next()) != NULL) {
       lines->Add(tmp);
       }
   }
AP210LP *PhysicalUnit::MatchLine(AP210ObjectList *lines, AP210Point *p) {
   AP210LP *tmp;
   AP210ObjectListItor itor(lines);

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
/*--------------------------------------------------------------------------
 *
 * PhysicalUnit::Draw()
 *
 * Build the OpenGL display lists for the PhysicalUnit.
 */
void PhysicalUnit::Draw(double Base) {
   AP210GraphicObject::Draw(getConstructionHeight(), Base);
   }
/*--------------------------------------------------------------------------
 *
 * PhysicalUnit::ReDraw()
 *
 * Rebuild the OpenGL display lists for the PhysicalUnit.
 */
void PhysicalUnit::ReDraw(double Z, double Base) {
   AP210GraphicObject::ReDraw(getConstructionHeight(), Base);
   }
double PhysicalUnit::getConstructionHeight() {
   double height = getHeight();
#ifdef VERBOSE
TRACE("In Package::getConstructionHeight()\r\n");
TRACE(" height: %f\r\n", height);
#endif

   if (height < 0.001) {
      // Using a height to 0.001 is a bit of a kludge until I figure out
      // how to draw a coplanar polygon.
      return 0.001;
      }
   return height;
   }
SdaiAppInstance PhysicalUnit::getShape(SdaiModel AP210Model) {
   SdaiAppInstance psr = sdaiNULL; // package  shape_representation
   psr = getPackageGeometry(AP210Model, PhysicalUnitRef);
#ifdef VERBOSE
TRACE("In Package::getShape()\r\n");
TRACE(" PackageRef: %s\r\n", _sdaiGetPart21Description(PhysicalUnitRef));
TRACE(" psr 1: %s\r\n", _sdaiGetPart21Description(psr));
#endif
   if (psr == sdaiNULL) {
      psr = getComponentDefinitionShapeRepresentation(AP210Model, PhysicalUnitRef);
 
#ifdef VERBOSE
TRACE("psr 2: %s\r\n", _sdaiGetPart21Description(psr));
#endif
      }
  return psr; 
  }

char *PhysicalUnit::getPartNumber() {
  return PartNumber;
  }

void PhysicalUnit::Select(AP210ObjectListItor *CDitor) {
TRACE("Selected %s\r\n", PartNumber);
   // Search for components 
   ComponentDefinition *cd;
   CDitor->Reset();
   while((cd = (ComponentDefinition *)CDitor->NextDirectInstanceOf(ComponentDefinition::TypeID())) != NULL) {
      if (cd->PhysicalUnitRef == this) {
TRACE("  Selected %s\r\n", cd->Name);
         cd->Select();
         }
      }
   }
// Height functionality
void PhysicalUnit::setHeight(double height) {
   if (getHeight() != height) {
      setPhysicalUnitsHeight(DataBase->AP210Model, PhysicalUnitRef, height);
      setReDrawStatus();
      DataBase->SetModifiedFlag(TRUE);
      }
   }
double PhysicalUnit::getHeight() {
#ifdef VERBOSE
TRACE("In PhysicalUnit::getHeight()\r\n");
TRACE(" PhysicalUnit: 0x%08x\r\n", PhysicalUnitRef);
#endif
   return getPhysicalUnitsHeight(DataBase->AP210Model, PhysicalUnitRef);
   }
