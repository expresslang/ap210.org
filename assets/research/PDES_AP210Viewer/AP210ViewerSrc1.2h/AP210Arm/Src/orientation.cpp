// Source for AP210 application object
//     orientation

// Precompiled include files
#include <StdAfx.h>

#include "orientation.h"

// Classes

orientation::orientation() {
   initialize();
   }
orientation::~orientation() {
   // Free string attributes
   }
// intialize data members
void orientation::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int orientation::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = managed_design_object::DynamicType(ID);
      }
   return result;
   }
orientation *orientation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<orientation *>(s);
      }
   return NULL;
   }
orientation *orientation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<orientation *>(s);
      }
   return NULL;
   }
// construction factory
orientation *orientation::Construct() {
   orientation *result = NULL;

   // create the orientation.
   result = new orientation();
   return result;
   }
bool orientation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: orientation\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
