// Source for AP210 application object
//     buried_via

// Precompiled include files
#include <StdAfx.h>

#include "buried_via.h"

// Classes

buried_via::buried_via() {
   initialize();
   }
buried_via::~buried_via() {
   // Free string attributes
   }
// intialize data members
void buried_via::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int buried_via::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = via::DynamicType(ID);
      }
   return result;
   }
buried_via *buried_via::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<buried_via *>(s);
      }
   return NULL;
   }
buried_via *buried_via::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<buried_via *>(s);
      }
   return NULL;
   }
// construction factory
buried_via *buried_via::Construct() {
   buried_via *result = NULL;

   // create the buried_via.
   result = new buried_via();
   return result;
   }
bool buried_via::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: buried_via\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (via::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
