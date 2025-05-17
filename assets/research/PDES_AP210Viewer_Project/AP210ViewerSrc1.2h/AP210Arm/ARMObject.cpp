/*
 * $Id:$
 * Auth:
 */
#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <stdlib.h>
#include <string.h>

#include "ARMObject.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int ARMObject::BaseOID = 0;

ARMObject::ARMObject() {
   BaseOID++;
   OID = BaseOID;
   } 
ARMObject::~ARMObject() {
   }

int ARMObject::DynamicType(int ID) {
   if (ID == baseID) return 1;
   return 0;
   }
