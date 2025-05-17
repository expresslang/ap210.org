// Source for AP210 application object
//     land_physical_template

// Precompiled include files
#include <StdAfx.h>

#include "land_physical_template.h"

// Classes
#include <external_definition.h>

land_physical_template::land_physical_template() {
   initialize();
   }
land_physical_template::~land_physical_template() {
   // Free string attributes
   }
// intialize data members
void land_physical_template::initialize() {
   // Required attributes

   // Optional attributes
   _pre_defined_classification_code = NULL;
   }
// Runtime type identification
int land_physical_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = stratum_feature_template::DynamicType(ID);
      }
   return result;
   }
land_physical_template *land_physical_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<land_physical_template *>(s);
      }
   return NULL;
   }
land_physical_template *land_physical_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<land_physical_template *>(s);
      }
   return NULL;
   }
// construction factory
land_physical_template *land_physical_template::Construct() {
   land_physical_template *result = NULL;

   // create the land_physical_template.
   result = new land_physical_template();
   return result;
   }
bool land_physical_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: land_physical_template\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (stratum_feature_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
