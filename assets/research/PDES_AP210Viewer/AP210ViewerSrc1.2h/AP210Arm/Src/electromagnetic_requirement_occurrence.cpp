// Source for AP210 application object
//     electromagnetic_requirement_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "electromagnetic_requirement_occurrence.h"

// Classes

electromagnetic_requirement_occurrence::electromagnetic_requirement_occurrence() {
   initialize();
   }
electromagnetic_requirement_occurrence::~electromagnetic_requirement_occurrence() {
   // Free string attributes
   }
// intialize data members
void electromagnetic_requirement_occurrence::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int electromagnetic_requirement_occurrence::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = ee_requirement_occurrence::DynamicType(ID);
      }
   return result;
   }
electromagnetic_requirement_occurrence *electromagnetic_requirement_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<electromagnetic_requirement_occurrence *>(s);
      }
   return NULL;
   }
electromagnetic_requirement_occurrence *electromagnetic_requirement_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<electromagnetic_requirement_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
electromagnetic_requirement_occurrence *electromagnetic_requirement_occurrence::Construct() {
   electromagnetic_requirement_occurrence *result = NULL;

   // create the electromagnetic_requirement_occurrence.
   result = new electromagnetic_requirement_occurrence();
   return result;
   }
bool electromagnetic_requirement_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: electromagnetic_requirement_occurrence\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (ee_requirement_occurrence::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
