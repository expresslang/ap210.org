// Source for AP210 application object
//     default_land_physical_template

// Precompiled include files
#include <StdAfx.h>

#include "default_land_physical_template.h"

// Classes
#include <stratum_technology.h>

default_land_physical_template::default_land_physical_template() {
   initialize();
   }
default_land_physical_template::~default_land_physical_template() {
   // Free string attributes
   }
// intialize data members
void default_land_physical_template::initialize() {
   // Required attributes
   _of_stratum_technology = NULL;

   // Optional attributes
   }
// Runtime type identification
int default_land_physical_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = land_physical_template::DynamicType(ID);
      }
   return result;
   }
default_land_physical_template *default_land_physical_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<default_land_physical_template *>(s);
      }
   return NULL;
   }
default_land_physical_template *default_land_physical_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<default_land_physical_template *>(s);
      }
   return NULL;
   }
// construction factory
default_land_physical_template *default_land_physical_template::Construct() {
   default_land_physical_template *result = NULL;

   // create the default_land_physical_template.
   result = new default_land_physical_template();
   return result;
   }
bool default_land_physical_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: default_land_physical_template\r\n");

   // Check for the existence of all required attributes
   if (_of_stratum_technology == NULL) {
      TRACE("ERROR: _of_stratum_technology a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (land_physical_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
