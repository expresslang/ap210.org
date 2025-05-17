// Source for AP210 application object
//     non_functional_land

// Precompiled include files
#include <StdAfx.h>

#include "non_functional_land.h"

// Classes
#include <land_physical_template.h>

non_functional_land::non_functional_land() {
   initialize();
   }
non_functional_land::~non_functional_land() {
   // Free string attributes
   }
// intialize data members
void non_functional_land::initialize() {
   // Required attributes

   // Optional attributes
   _alternate_land_definition = NULL;
   }
// Runtime type identification
int non_functional_land::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = stratum_feature_template_component::DynamicType(ID);
      }
   return result;
   }
non_functional_land *non_functional_land::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<non_functional_land *>(s);
      }
   return NULL;
   }
non_functional_land *non_functional_land::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<non_functional_land *>(s);
      }
   return NULL;
   }
// construction factory
non_functional_land *non_functional_land::Construct() {
   non_functional_land *result = NULL;

   // create the non_functional_land.
   result = new non_functional_land();
   return result;
   }
bool non_functional_land::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: non_functional_land\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (stratum_feature_template_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
