// Source for AP210 application object
//     design_characteristic_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "design_characteristic_occurrence.h"

// Classes

design_characteristic_occurrence::design_characteristic_occurrence() {
   initialize();
   }
design_characteristic_occurrence::~design_characteristic_occurrence() {
   // Free string attributes
   }
// intialize data members
void design_characteristic_occurrence::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int design_characteristic_occurrence::DynamicType(int ID) {
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
design_characteristic_occurrence *design_characteristic_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<design_characteristic_occurrence *>(s);
      }
   return NULL;
   }
design_characteristic_occurrence *design_characteristic_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<design_characteristic_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
design_characteristic_occurrence *design_characteristic_occurrence::Construct() {
   design_characteristic_occurrence *result = NULL;

   // create the design_characteristic_occurrence.
   result = new design_characteristic_occurrence();
   return result;
   }
bool design_characteristic_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: design_characteristic_occurrence\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (ee_requirement_occurrence::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
