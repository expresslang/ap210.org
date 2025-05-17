// NonPlatedThruHole.cpp: implementation of the NonPlatedThruHole class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "../AP210Viewer.h"
#include "../PWBDataBase.h"
#include "NonPlatedThruHole.h"

// AP210
#include "AP210MagicStrings.h"

// Geometry
#include "ExtractGeometry.h"

// OpenGL
#include "../OpenGl/MatrixUtilities.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
#define VERBOSE
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
void NonPlatedThruHole::Construct(PWBDataBase *PWB,
                                  SdaiNPL npthList) {
#ifdef VERBOSE
   TRACE("In NonPlatedThruHole::Construct\r\n");
   TRACE("%d NPTHs\r\n", sdaiGetMemberCount(npthList));
#endif
   if (sdaiGetMemberCount(npthList) > 0) {
      NonPlatedThruHole *newnpth;
      SdaiInstance npth;   // non-plated thru-hole
      SdaiIterator npth_itor = sdaiCreateIterator(npthList);

      while (sdaiNext(npth_itor)) {
         sdaiGetAggrByIterator(npth_itor, sdaiINSTANCE, &npth); 
#ifdef VERBOSE
         TRACE("non-plated thru-hole: %s\r\n", _sdaiGetPart21Description(npth));
#endif
         if ((newnpth = Construct(PWB, npth)) != sdaiNULL) {
            PWB->NonPlatedThruHoles.Add(newnpth);
#ifdef VERBOSE
            TRACE("%d NonPlatedThruHoles\r\n", PWB->NonPlatedThruHoles.SizeOf()); 
#endif
            }
         }
      sdaiDeleteIterator(npth_itor);
      }
   }
// need to add some validity checking here.
NonPlatedThruHole *NonPlatedThruHole::Construct(PWBDataBase *PWB,
                                                SdaiAppInstance npth) {
   return new NonPlatedThruHole(PWB, npth);
   }

NonPlatedThruHole::NonPlatedThruHole(PWBDataBase *PWB, SdaiAppInstance npth):
   AP210GraphicObject(PWB) {
   static SdaiEntity GRP = sdaiGetEntity(DataBase->AP210Model, "grouped_requirements_property");
   static SdaiAttr GRP_DEF = sdaiGetAttrDefinition(GRP, "definition");

   static SdaiEntity DRI = sdaiGetEntity(DataBase->AP210Model, "descriptive_representation_item");
   static SdaiAttr DRI_DESC = sdaiGetAttrDefinition(DRI, "description");

   static SdaiEntity RR = sdaiGetEntity(DataBase->AP210Model, "representation_relationship");
   static SdaiAttr RR_REP2 = sdaiGetAttrDefinition(RR, "rep_2");


   SdaiAppInstance grp;  // grouped_requirements_property
   SdaiAppInstance cpra; // component_placement_restriction_assignment ARM AO
   SdaiAppInstance cp;   // components_premitted
   SdaiAppInstance sr;   // shape_representation
   SdaiAppInstance mpch; // maximum positive component height
   SdaiString permission;

   ComponentDefinition = npth;
#ifdef VERBOSE
   TRACE("In NonPlatedThruHole::NonPlatedThruHole\r\n");
   TRACE("non-plated thru-hole: %s\r\n", _sdaiGetPart21Description(ComponentDefinition));
#endif

   // setup transformation matrix
   _glIdentityMatrixd(m);

   // These should always be transparent
   setTransparency(TRUE);
   Alpha = 0.0;

   // set default, could be in an intialization function;
   MaximumPositiveComponentHeight = sdaiNULL;

   // Set the restriction areas side
   char *tempside = strdup(getSurface());

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

   // get the grouped_requirements_property with a definition
   // that is the mounting_restriction_area.
   grp = _sdaiFindSingleSubTypeInstanceUsedIn(ComponentDefinition, GRP, GRP_DEF);
#ifdef VERBOSE
   TRACE("grp: %s\r\n", _sdaiGetPart21Description(grp));
#endif

   if (grp != sdaiNULL) {
      cpra = getNamedRepresentation(DataBase->AP210Model, ComponentDefinition,
             "component placement restriction assignment");
#ifdef VERBOSE
      TRACE("cpra: %s\r\n", _sdaiGetPart21Description(cpra));
#endif
      if (cpra != sdaiNULL) {
         // get the components permitted premission
         cp = getNamedRepresentationItem(DataBase->AP210Model, cpra, "components permitted");
#ifdef VERBOSE
         TRACE("cp: %s\r\n", _sdaiGetPart21Description(cp));
#endif
         if (cp != sdaiNULL) {
            sdaiGetAttr(cp, DRI_DESC, sdaiSTRING, &permission);
#ifdef VERBOSE
            TRACE("permission: %s\r\n", permission);
#endif
            if (!strcmp(permission, "false")) {
               ComponentsPermitted = FALSE;
               }
            else if (!strcmp(permission, "true")) {
               ComponentsPermitted = TRUE;
               }
            }
         // get the maximum positive component height 
         mpch = getNamedRepresentationRelationship(DataBase->AP210Model,
                                                   cpra,
                                                   RR_REP2,
                                                   "maximum positive component height");
#ifdef VERBOSE
         TRACE("mpch: %s\r\n", _sdaiGetPart21Description(mpch));
#endif
         if (mpch != sdaiNULL) {
            MaximumPositiveComponentHeight = getNamedRepresentationItem(DataBase->AP210Model,
                                                                        mpch, "measure");
#ifdef VERBOSE
            TRACE("MaximumPositiveComponentHeight: %s\r\n",
                  _sdaiGetPart21Description(MaximumPositiveComponentHeight));
            TRACE("height: %f\n", getHeight());
#endif
            }
         } 
      // Get the restriction geometry
#ifdef VERBOSE
   TRACE("Looking for restriction geometry\r\n");
#endif
   // NEED TO GET THE SHAPE_REP CORRECTLY
      sr = getShape();

      if (sr != sdaiNULL) { 
          AP210ObjectList *lines;

          lines = ExtractGeometry::getLines(DataBase->AP210Model, DataBase,
                                            getGeometryFromShapeRep(DataBase->AP210Model, sr),
                                            getRepresentationLengthUnit(DataBase->AP210Model, sr)
                                            );
          Lines.Append(lines);
          getPoints();
          }
      }
   }

NonPlatedThruHole::~NonPlatedThruHole() {
   } 

int NonPlatedThruHole::DynamicType(int ID) {
   if (ID == typeID) return 1;
   return AP210GraphicObject::DynamicType(ID);
   }
#ifdef INSTANCEOF
NonPlatedThruHole *NonPlatedThruHole::DirectInstanceOf(AP210Object *s) {
   if (s->GetTypeID() == typeID)
      return(NonPlatedThruHole *)s;
   return 0;
   }
NonPlatedThruHole *NonPlatedThruHole::InstanceOf(AP210Object *s) {
   if (s->DynamicType(typeID))
      return(NonPlatedThruHole *)s;
   return 0;
   }
#endif
double NonPlatedThruHole::getHeight() {
   if (MaximumPositiveComponentHeight != sdaiNULL) {
      return getLengthMeasureWithUnit(DataBase->AP210Model, MaximumPositiveComponentHeight);
      }
   else {
      return 0.0;
      }
   }

/*--------------------------------------------------------------------------
 *
 * NonPlatedThruHole.GetPoints()
 *
 * Extract a list of points inorder that define
 * a polygon.
 */
void NonPlatedThruHole::getPoints() {
  
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
void NonPlatedThruHole::sortLines() {
   if (Lines.SizeOf() == 0) {
      TRACE("FATAL ERROR: NonPlatedThruHole %d [%d] has no lines!\n", GetOID(), GetTypeID());
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

AP210LP *NonPlatedThruHole::matchLine(AP210Point *p) {
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

void NonPlatedThruHole::setSeatingPlane(double base) {
   m[14] = base;
   }
//#define AP210RECPRAC
void NonPlatedThruHole::applyTranslationMatrix() {
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
   if (Side == Bottom) {
       // build the location matrix
       _glIdentityMatrixd(mlocation);
       mlocation[12] = m[12];
       mlocation[13] = m[13];

       // build the rotation matix;
       _glCopyMatrixd(m, mrotation);
       // Remove the location 
       mrotation[12] = 0.0;
       mrotation[13] = 0.0;
       // Remove mirroring about Y axis;
       mrotation[0] = -mrotation[0];
       mrotation[4] = -mrotation[4];

       // use OpenGL to multiply matrix, this is more efficent.
       glMultMatrixd(mlocation);
       glMultMatrixd(Y180Degrees);
       glMultMatrixd(mrotation);
      }
   else {
      // move to location of component
      glMultMatrixd(m);
      }
   }
void NonPlatedThruHole::Draw(double Base) {
	AP210GraphicObject::Draw(getHeight(), Base);
   }
// These are two tighly coupled functions.
// The intent is that the caller will 
//    First call RenderCaps,
//    then change the color, and
//    then call RenderSides.
void NonPlatedThruHole::RenderCaps() {
   // save the current transformation matrix
   glPushMatrix();
   
   applyTranslationMatrix();
   AP210GraphicObject::RenderCaps();
   }
void NonPlatedThruHole::RenderSides() {
   AP210GraphicObject::RenderSides();
   // restore the transformation matrix
   glPopMatrix();
   }

SdaiAppInstance NonPlatedThruHole::getShape(){
   static SdaiEntity MI = sdaiGetEntity(DataBase->AP210Model, "mapped_item");
   static SdaiAttr MI_MS = sdaiGetAttrDefinition(MI, "mapping_source");

   static SdaiEntity RM = sdaiGetEntity(DataBase->AP210Model, "representation_map");
   static SdaiAttr RM_MR = sdaiGetAttrDefinition(RM, "mapped_representation");

   SdaiAppInstance sr1; // shape_representation
   SdaiAppInstance sr2 = sdaiNULL; // shape_representation
   SdaiAppInstance mi; // mapped_item
   SdaiAppInstance rm; // representation_map;
   sr1 = getNamedRepresentation(DataBase->AP210Model, ComponentDefinition, "");
#ifdef VERBOSE
   TRACE("sr1: %s\r\n", _sdaiGetPart21Description(sr1));
#endif
   if (sr1 != sdaiNULL) {
      mi = _sdaiGetSingleRepresentationItemOfType(sr1, MI);
#ifdef VERBOSE
      TRACE("mi: %s\r\n", _sdaiGetPart21Description(mi));
#endif
      if (mi != sdaiNULL) {      
         sdaiGetAttr(mi, MI_MS, sdaiINSTANCE, &rm);
#ifdef VERBOSE
         TRACE("rm: %s\r\n", _sdaiGetPart21Description(rm));
#endif
         if (rm != sdaiNULL) {
            sdaiGetAttr(rm, RM_MR, sdaiINSTANCE, &sr2);
            }  
         }
      }
#ifdef VERBOSE
   TRACE("sr2: %s\r\n", _sdaiGetPart21Description(sr2));
#endif 
   return sr2;
   }

CString NonPlatedThruHole::getSurface() {
   static SdaiAttr SA_DESC = sdaiGetAttrDefinitionBN(AP210,
                                                     "shape_aspect",
                                                     "description");
   SdaiAppInstance csa;
   SdaiAppInstance sa;
   SdaiString surface = sdaiNULL;

   csa = getNamedRelatedShapeAspect(DataBase->AP210Model, ComponentDefinition, "mounting surface");
#ifdef VERBOSE
   TRACE("csa: %s\r\n", _sdaiGetPart21Description(csa));
#endif
   sa = getNamedRelatingShapeAspect(DataBase->AP210Model, csa, "instantiated feature");
#ifdef VERBOSE
   TRACE("sa: %s\r\n", _sdaiGetPart21Description(sa));
#endif
   sdaiGetAttr(sa, SA_DESC, sdaiSTRING, &surface);
   return surface;
   }
