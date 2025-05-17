// Source for AP210 application object
//     datum_plane

// Precompiled include files
#include <StdAfx.h>

#include "datum_plane.h"

// Classes

datum_plane::datum_plane() {
   initialize();
   }
datum_plane::~datum_plane() {
   // Free string attributes
   }
// intialize data members
void datum_plane::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int datum_plane::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = datum::DynamicType(ID);
      }
   return result;
   }
datum_plane *datum_plane::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_plane *>(s);
      }
   return NULL;
   }
datum_plane *datum_plane::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_plane *>(s);
      }
   return NULL;
   }
// construction factory
datum_plane *datum_plane::Construct() {
   datum_plane *result = NULL;

   // create the datum_plane.
   result = new datum_plane();
   return result;
   }
bool datum_plane::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_plane\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (datum::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
