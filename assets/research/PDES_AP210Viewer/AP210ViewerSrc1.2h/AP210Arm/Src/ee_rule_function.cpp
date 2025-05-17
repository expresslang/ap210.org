// Source for AP210 application object
//     ee_rule_function

// Precompiled include files
#include <StdAfx.h>

#include "ee_rule_function.h"

// Classes
#include <ee_document.h>
#include <ee_specification.h>

ee_rule_function::ee_rule_function() {
   initialize();
   }
ee_rule_function::~ee_rule_function() {
   // Free string attributes
   if (_identifier != NULL) {
      free(_identifier);
     }
   }
// intialize data members
void ee_rule_function::initialize() {
   // Required attributes
   _identifier = NULL;
   _reference_document = NULL;
   _source_code = NULL;

   // Optional attributes
   }
// Runtime type identification
int ee_rule_function::DynamicType(int ID) {
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
ee_rule_function *ee_rule_function::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_rule_function *>(s);
      }
   return NULL;
   }
ee_rule_function *ee_rule_function::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_rule_function *>(s);
      }
   return NULL;
   }
// construction factory
ee_rule_function *ee_rule_function::Construct() {
   ee_rule_function *result = NULL;

   // create the ee_rule_function.
   result = new ee_rule_function();
   return result;
   }
bool ee_rule_function::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_rule_function\r\n");

   // Check for the existence of all required attributes
   if (_identifier == NULL) {
      TRACE("ERROR: _identifier a required attribute is NULL!\r\n");
      result = false;
      }
   if (_parameter == NULL) {
      TRACE("ERROR: _parameter a required attribute is NULL!\r\n");
      result = false;
      }
   if (_reference_document == NULL) {
      TRACE("ERROR: _reference_document a required attribute is NULL!\r\n");
      result = false;
      }
   if (_source_code == NULL) {
      TRACE("ERROR: _source_code a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
