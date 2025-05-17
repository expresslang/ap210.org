// Source for AP210 application object
//     requirement_group_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "requirement_group_occurrence.h"

// Classes

requirement_group_occurrence::requirement_group_occurrence() {
   initialize();
   }
requirement_group_occurrence::~requirement_group_occurrence() {
   // Free string attributes
   }
// intialize data members
void requirement_group_occurrence::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int requirement_group_occurrence::DynamicType(int ID) {
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
requirement_group_occurrence *requirement_group_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<requirement_group_occurrence *>(s);
      }
   return NULL;
   }
requirement_group_occurrence *requirement_group_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<requirement_group_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
requirement_group_occurrence *requirement_group_occurrence::Construct() {
   requirement_group_occurrence *result = NULL;

   // create the requirement_group_occurrence.
   result = new requirement_group_occurrence();
   return result;
   }
bool requirement_group_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: requirement_group_occurrence\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (ee_requirement_occurrence::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
