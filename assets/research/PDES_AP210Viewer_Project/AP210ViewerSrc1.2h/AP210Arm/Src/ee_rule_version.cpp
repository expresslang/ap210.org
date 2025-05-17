// Source for AP210 application object
//     ee_rule_version

// Precompiled include files
#include <StdAfx.h>

#include "ee_rule_version.h"

// Classes
#include <ee_rule.h>

ee_rule_version::ee_rule_version() {
   initialize();
   }
ee_rule_version::~ee_rule_version() {
   // Free string attributes
   if (_version_identifier != NULL) {
      free(_version_identifier);
     }
   }
// intialize data members
void ee_rule_version::initialize() {
   // Required attributes
   _configuration_managed_rule = NULL;
   _version_identifier = NULL;

   // Optional attributes
   }
// Runtime type identification
int ee_rule_version::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = managed_design_object::DynamicType(ID);
      }
   return result;
   }
ee_rule_version *ee_rule_version::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_rule_version *>(s);
      }
   return NULL;
   }
ee_rule_version *ee_rule_version::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_rule_version *>(s);
      }
   return NULL;
   }
// construction factory
ee_rule_version *ee_rule_version::Construct() {
   ee_rule_version *result = NULL;

   // create the ee_rule_version.
   result = new ee_rule_version();
   return result;
   }
bool ee_rule_version::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_rule_version\r\n");

   // Check for the existence of all required attributes
   if (_configuration_managed_rule == NULL) {
      TRACE("ERROR: _configuration_managed_rule a required attribute is NULL!\r\n");
      result = false;
      }
   if (_version_identifier == NULL) {
      TRACE("ERROR: _version_identifier a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
