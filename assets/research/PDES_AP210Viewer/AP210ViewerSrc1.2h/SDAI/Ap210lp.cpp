/*
 * $Id: AP210LP.cpp,v 1.1 1999/07/17 19:00:22 keenan Exp keenan $
 * Auth: Michael T. Keenan
 */
#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "MathUtility.h"

#include "AP210Point.h"
#include "AP210LP.h"
#include "../PWBDataBase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

AP210LP::AP210LP(PWBDataBase *PWB, AP210Point *p1, AP210Point *p2):
AP210Line(PWB) {
   Start = p1;
   End = p2;
      }

AP210LP::~AP210LP() {
   }
int AP210LP::DynamicType(int ID) {
   if (ID == typeID) return 1;
   return AP210Line::DynamicType(ID);
   }
#ifdef INSTANCEOF
AP210LP *AP210LP::DirectInstanceOf(AP210Object *s) {
   if (s->GetTypeID() == typeID)
      return(AP210LP *)s;
   return 0;
   }
AP210LP *AP210LP::InstanceOf(AP210Object *s) {
   if (s->DynamicType(typeID))
      return(AP210LP *)s;
   return 0;
   }
#endif
AP210LP *AP210LP::Construct(PWBDataBase *PWB, AP210Point *p1, AP210Point *p2) {
   AP210LP *lp = FindLine(PWB, p1, p2);

   if (lp == NULL) {
      lp = new AP210LP(PWB, p1, p2);
      } 
   return(lp);
   }
AP210LP *AP210LP::FindLine(PWBDataBase *PWB, AP210Point *p1, AP210Point *p2) {
   AP210LP *line;
   AP210ObjectListItor itor(&(PWB->GeomList));

   while((line = (AP210LP *)itor.NextInstanceOf(AP210LP::TypeID())) != NULL)
      {
      if (   ((line->Start == p1) && (line->End == p2))
          || ((line->Start == p2) && (line->End == p1))) {
         break;
         }
      }
   return(line);
   }
void AP210LP::SortEndPoints() {

   if (Start->X < End->X) {
      SwapPoints();
      }
   else if (Start->Y < End->Y) { 
      SwapPoints();
      }
   }
void AP210LP::SwapPoints() {
   AP210Point *tmp = Start;

   Start = End;
   End = tmp;
   }
