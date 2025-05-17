// Source for AP210 application object
//     purpose_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "purpose_occurrence.h"

// Classes

purpose_occurrence::purpose_occurrence() {
   initialize();
   }
purpose_occurrence::~purpose_occurrence() {
   // Free string attributes
   }
// intialize data members
void purpose_occurrence::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int purpose_occurrence::DynamicType(int ID) {
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
purpose_occurrence *purpose_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<purpose_occurrence *>(s);
      }
   return NULL;
   }
purpose_occurrence *purpose_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<purpose_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
purpose_occurrence *purpose_occurrence::Construct() {
   purpose_occurrence *result = NULL;

   // create the purpose_occurrence.
   result = new purpose_occurrence();
   return result;
   }
bool purpose_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: purpose_occurrence\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (ee_requirement_occurrence::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
