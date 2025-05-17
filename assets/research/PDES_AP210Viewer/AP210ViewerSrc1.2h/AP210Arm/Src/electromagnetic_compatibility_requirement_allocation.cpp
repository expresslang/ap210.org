// Source for AP210 application object
//     electromagnetic_compatibility_requirement_allocation

// Precompiled include files
#include <StdAfx.h>

#include "electromagnetic_compatibility_requirement_allocation.h"

// Classes

electromagnetic_compatibility_requirement_allocation::electromagnetic_compatibility_requirement_allocation() {
   initialize();
   }
electromagnetic_compatibility_requirement_allocation::~electromagnetic_compatibility_requirement_allocation() {
   // Free string attributes
   }
// intialize data members
void electromagnetic_compatibility_requirement_allocation::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int electromagnetic_compatibility_requirement_allocation::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = assembly_requirement_allocation::DynamicType(ID);
      }
   return result;
   }
electromagnetic_compatibility_requirement_allocation *electromagnetic_compatibility_requirement_allocation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<electromagnetic_compatibility_requirement_allocation *>(s);
      }
   return NULL;
   }
electromagnetic_compatibility_requirement_allocation *electromagnetic_compatibility_requirement_allocation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<electromagnetic_compatibility_requirement_allocation *>(s);
      }
   return NULL;
   }
// construction factory
electromagnetic_compatibility_requirement_allocation *electromagnetic_compatibility_requirement_allocation::Construct() {
   electromagnetic_compatibility_requirement_allocation *result = NULL;

   // create the electromagnetic_compatibility_requirement_allocation.
   result = new electromagnetic_compatibility_requirement_allocation();
   return result;
   }
bool electromagnetic_compatibility_requirement_allocation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: electromagnetic_compatibility_requirement_allocation\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (assembly_requirement_allocation::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
