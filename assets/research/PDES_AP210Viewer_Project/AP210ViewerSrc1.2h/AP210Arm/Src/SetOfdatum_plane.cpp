// Source for AP210 application object
//     SetOfdatum_plane

// Precompiled include files
#include <StdAfx.h>

#include "SetOfdatum_plane.h"

// Classes
#include <datum_plane.h>

SetOfdatum_plane::SetOfdatum_plane() {
   initialize();
   }
SetOfdatum_plane::~SetOfdatum_plane() {
   // Free string attributes
   }
// intialize data members
void SetOfdatum_plane::initialize() {
   // Required attributes
   _datum_plane = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfdatum_plane::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfdatum_plane *SetOfdatum_plane::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfdatum_plane *>(s);
      }
   return NULL;
   }
SetOfdatum_plane *SetOfdatum_plane::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfdatum_plane *>(s);
      }
   return NULL;
   }
// construction factory
SetOfdatum_plane *SetOfdatum_plane::Construct() {
   SetOfdatum_plane *result = NULL;

   // create the SetOfdatum_plane.
   result = new SetOfdatum_plane();
   return result;
   }
bool SetOfdatum_plane::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfdatum_plane\r\n");

   // Check for the existence of all required attributes
   if (_datum_plane == NULL) {
      TRACE("ERROR: _datum_plane a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
