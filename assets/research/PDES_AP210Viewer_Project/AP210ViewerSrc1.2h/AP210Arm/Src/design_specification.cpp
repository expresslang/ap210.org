// Source for AP210 application object
//     design_specification

// Precompiled include files
#include <StdAfx.h>

#include "design_specification.h"

// Classes

design_specification::design_specification() {
   initialize();
   }
design_specification::~design_specification() {
   // Free string attributes
   }
// intialize data members
void design_specification::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int design_specification::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = ee_specification::DynamicType(ID);
      }
   return result;
   }
design_specification *design_specification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<design_specification *>(s);
      }
   return NULL;
   }
design_specification *design_specification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<design_specification *>(s);
      }
   return NULL;
   }
// construction factory
design_specification *design_specification::Construct() {
   design_specification *result = NULL;

   // create the design_specification.
   result = new design_specification();
   return result;
   }
bool design_specification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: design_specification\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (ee_specification::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
