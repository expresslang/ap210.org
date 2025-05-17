/*
 * $Id: AP210Point.cpp,v 1.4 1999/07/25 16:44:20 keenan Exp keenan $
 * Auth: Michael T. Keenan
 */
#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "MathUtility.h"

#include "AP210ObjectList.h"
#include "AP210Point.h"
#include "../PWBDataBase.h"
#include "AP210SdaiModel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

AP210Point::AP210Point(PWBDataBase *PWB, double x, double y):
AP210Object(PWB) {
   X = x;
   Y = y;
   } 

AP210Point::~AP210Point() {
   }
int AP210Point::DynamicType(int ID) {
   if (ID == typeID) return 1;
   return AP210Object::DynamicType(ID);
   }
#ifdef INSTANCEOF
AP210Point *AP210Point::DirectInstanceOf(AP210Object *s) {
   if (s->GetTypeID() == typeID)
      return(AP210Point *)s;
   return 0;
   }
AP210Point *AP210Point::InstanceOf(AP210Object *s) {
   if (s->DynamicType(typeID))
      return(AP210Point *)s;
   return 0;
   }
#endif
/*
 * Construct
 *
 * Construct a AP210Point from a cartesian_point.
 */
AP210Point *AP210Point::Construct(PWBDataBase *PWB,
                                  SdaiAppInstance p,
                                  double Factor,
                                  double DeltaX, double DeltaY,
                                  double U11, double U12,
                                  double U21, double U22) {
   static SdaiAttr coordinates = sdaiGetAttrDefinitionBN(AP210, "cartesian_point", "coordinates");

   AP210Point *mp;
   SdaiAggr coords;
   SdaiReal orgx;
   SdaiReal orgy;
 
   // Get the coordinates LIST
   sdaiGetAttr(p, coordinates, sdaiAGGR, &coords);

   sdaiGetAggrByIndex(coords, 0, sdaiREAL, &orgx);
   sdaiGetAggrByIndex(coords, 1, sdaiREAL, &orgy);

   // construct the point.
   mp = Construct(PWB, orgx, orgy, Factor, DeltaX, DeltaY, U11, U12, U21, U22);

   return(mp);
   }
AP210Point *AP210Point::Construct(PWBDataBase *PWB,
                                  double orgx, double orgy,
                                  double Factor,
                                  double DeltaX, double DeltaY,
                                  double U11, double U12,
                                  double U21, double U22) {
   AP210Point *mp;
   double x;
   double y;

   // scale input
   orgx = orgx * Factor;
   orgy = orgy * Factor;

   // Rotate, Mirror and Translate
   x = orgx * U11 + orgy * U12 + DeltaX;
   y = orgx * U21 + orgy * U22 + DeltaY;

   // look for an existing point
   mp = FindPoint(PWB, x, y);

   // if no existing point create one.
   if (mp == NULL) {
      mp = new AP210Point(PWB, x, y);
      }
   return(mp);
   }
AP210Point *AP210Point::FindPoint(PWBDataBase *PWB, double x, double y) {
   AP210Point *p = NULL;
   AP210ObjectListItor itor(&(PWB->GeomList));
   AP210Point *obj;

   itor.Reset();
   while((obj = (AP210Point *)itor.NextInstanceOf(AP210Point::TypeID())) != NULL) {
      if (NearZero(obj->X-x) && NearZero(obj->Y-y)) { 
         p = obj;
         break;
         }
      }
   return(p);
   }
