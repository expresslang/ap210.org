// Source for AP210 application object
//     land

// Precompiled include files
#include <StdAfx.h>

#include "land.h"

// Classes
#include <land_physical_template.h>

land::land() {
   initialize();
   }
land::~land() {
   // Free string attributes
   }
// intialize data members
void land::initialize() {
   // Required attributes

   // Optional attributes
   _alternate_land_definition = NULL;
   }
// Runtime type identification
int land::DynamicType(int ID) {
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
land *land::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<land *>(s);
      }
   return NULL;
   }
land *land::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<land *>(s);
      }
   return NULL;
   }
// construction factory
land *land::Construct() {
   land *result = NULL;

   // create the land.
   result = new land();
   return result;
   }
bool land::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: land\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (stratum_feature_template_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
