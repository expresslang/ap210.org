// Source for AP210 application object
//     design_requirement_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "design_requirement_occurrence.h"

// Classes

design_requirement_occurrence::design_requirement_occurrence() {
   initialize();
   }
design_requirement_occurrence::~design_requirement_occurrence() {
   // Free string attributes
   }
// intialize data members
void design_requirement_occurrence::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int design_requirement_occurrence::DynamicType(int ID) {
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
design_requirement_occurrence *design_requirement_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<design_requirement_occurrence *>(s);
      }
   return NULL;
   }
design_requirement_occurrence *design_requirement_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<design_requirement_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
design_requirement_occurrence *design_requirement_occurrence::Construct() {
   design_requirement_occurrence *result = NULL;

   // create the design_requirement_occurrence.
   result = new design_requirement_occurrence();
   return result;
   }
bool design_requirement_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: design_requirement_occurrence\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (ee_requirement_occurrence::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
