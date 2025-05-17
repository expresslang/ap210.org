/*
 * $Id: AP210Object.cpp,v 1.2 1999/07/17 19:00:22 keenan Exp $
 * Auth: Michael T. Keenan
 */
#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <stdlib.h>
#include <string.h>

#include "AP210Object.h"
#include "AP210ObjectList.h"
#include "../PWBDataBase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int AP210Object::BaseOID = 0;

AP210Object::AP210Object(PWBDataBase *PWB) {
   DataBase = PWB;
#ifdef VERBOSE
TRACE("About to add to DataBase\r\n");
#endif
   DataBase->GeomList.Add(this);
#ifdef VERBOSE
TRACE("Added to DataBase\r\n");
#endif
   BaseOID++;
   OID = BaseOID;
   } 
AP210Object::~AP210Object() {
   DataBase->GeomList.Delete(this);
#ifdef VERBOSE
TRACE("sizeof: %d\r\n", DataBase->GeomList.SizeOf());   
#endif
   }

int AP210Object::DynamicType(int ID) {
   if (ID == baseID) return 1;
   return 0;
   }
