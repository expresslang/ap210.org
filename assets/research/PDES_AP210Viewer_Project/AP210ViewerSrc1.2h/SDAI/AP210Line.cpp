/*
 * $Id: AP210Line.cpp,v 1.1 1999/07/17 19:00:22 keenan Exp keenan $
 * Auth: Michael T. Keenan
 */
#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <stdlib.h>
#include <string.h>

#include "AP210Line.h"
#include "AP210LP.h"
#include "AP210ObjectList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int AP210Line::IdSeed = 0;

AP210Line::AP210Line(PWBDataBase *PWB):
AP210Object(PWB) {
   } 

AP210Line::~AP210Line() {
   }
int AP210Line::DynamicType(int ID) {
   if (ID == typeID) return 1;
   return AP210Object::DynamicType(ID);
   }
#ifdef INSTANCEOF
AP210Line *AP210Line::DirectInstanceOf(AP210Object *s) {
   if (s->GetTypeID() == typeID)
      return(AP210Line *)s;
   return 0;
   }
AP210Line *AP210Line::InstanceOf(AP210Object *s) {
   if (s->DynamicType(typeID))
      return(AP210Line *)s;
   return 0;
   }
#endif