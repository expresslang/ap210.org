// Source for AP210 application object
//     default_via_based_land_physical_template

// Precompiled include files
#include <StdAfx.h>

#include "default_via_based_land_physical_template.h"

// Classes

default_via_based_land_physical_template::default_via_based_land_physical_template() {
   initialize();
   }
default_via_based_land_physical_template::~default_via_based_land_physical_template() {
   // Free string attributes
   }
// intialize data members
void default_via_based_land_physical_template::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int default_via_based_land_physical_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = default_passage_based_land_physical_template::DynamicType(ID);
      }
   return result;
   }
default_via_based_land_physical_template *default_via_based_land_physical_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<default_via_based_land_physical_template *>(s);
      }
   return NULL;
   }
default_via_based_land_physical_template *default_via_based_land_physical_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<default_via_based_land_physical_template *>(s);
      }
   return NULL;
   }
// construction factory
default_via_based_land_physical_template *default_via_based_land_physical_template::Construct() {
   default_via_based_land_physical_template *result = NULL;

   // create the default_via_based_land_physical_template.
   result = new default_via_based_land_physical_template();
   return result;
   }
bool default_via_based_land_physical_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: default_via_based_land_physical_template\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (default_passage_based_land_physical_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
