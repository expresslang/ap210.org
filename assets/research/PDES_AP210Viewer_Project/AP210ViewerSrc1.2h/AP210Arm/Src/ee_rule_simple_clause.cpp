// Source for AP210 application object
//     ee_rule_simple_clause

// Precompiled include files
#include <StdAfx.h>

#include "ee_rule_simple_clause.h"

// Classes
#include <ee_rule_function.h>

ee_rule_simple_clause::ee_rule_simple_clause() {
   initialize();
   }
ee_rule_simple_clause::~ee_rule_simple_clause() {
   // Free string attributes
   if (_identifier != NULL) {
      free(_identifier);
     }
   }
// intialize data members
void ee_rule_simple_clause::initialize() {
   // Required attributes
   _rule_function = NULL;
   _identifier = NULL;

   // Optional attributes
   }
// Runtime type identification
int ee_rule_simple_clause::DynamicType(int ID) {
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
ee_rule_simple_clause *ee_rule_simple_clause::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_rule_simple_clause *>(s);
      }
   return NULL;
   }
ee_rule_simple_clause *ee_rule_simple_clause::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_rule_simple_clause *>(s);
      }
   return NULL;
   }
// construction factory
ee_rule_simple_clause *ee_rule_simple_clause::Construct() {
   ee_rule_simple_clause *result = NULL;

   // create the ee_rule_simple_clause.
   result = new ee_rule_simple_clause();
   return result;
   }
bool ee_rule_simple_clause::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_rule_simple_clause\r\n");

   // Check for the existence of all required attributes
   if (_rule_function == NULL) {
      TRACE("ERROR: _rule_function a required attribute is NULL!\r\n");
      result = false;
      }
   if (_parameter == NULL) {
      TRACE("ERROR: _parameter a required attribute is NULL!\r\n");
      result = false;
      }
   if (_identifier == NULL) {
      TRACE("ERROR: _identifier a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
