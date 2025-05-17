// Source for AP210 application object
//     shield_allocation

// Precompiled include files
#include <StdAfx.h>

#include "shield_allocation.h"

// Classes

shield_allocation::shield_allocation() {
   initialize();
   }
shield_allocation::~shield_allocation() {
   // Free string attributes
   }
// intialize data members
void shield_allocation::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int shield_allocation::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = electromagnetic_compatibility_requirement_allocation::DynamicType(ID);
      }
   return result;
   }
shield_allocation *shield_allocation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<shield_allocation *>(s);
      }
   return NULL;
   }
shield_allocation *shield_allocation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<shield_allocation *>(s);
      }
   return NULL;
   }
// construction factory
shield_allocation *shield_allocation::Construct() {
   shield_allocation *result = NULL;

   // create the shield_allocation.
   result = new shield_allocation();
   return result;
   }
bool shield_allocation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: shield_allocation\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (electromagnetic_compatibility_requirement_allocation::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
