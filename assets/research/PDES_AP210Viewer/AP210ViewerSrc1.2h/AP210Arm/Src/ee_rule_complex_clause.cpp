// Source for AP210 application object
//     ee_rule_complex_clause

// Precompiled include files
#include <StdAfx.h>

#include "ee_rule_complex_clause.h"

// Classes

ee_rule_complex_clause::ee_rule_complex_clause() {
   initialize();
   }
ee_rule_complex_clause::~ee_rule_complex_clause() {
   // Free string attributes
   if (_identifier != NULL) {
      free(_identifier);
     }
   }
// intialize data members
void ee_rule_complex_clause::initialize() {
   // Required attributes
   _identifier = NULL;

   // Optional attributes
   }
// Runtime type identification
int ee_rule_complex_clause::DynamicType(int ID) {
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
ee_rule_complex_clause *ee_rule_complex_clause::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_rule_complex_clause *>(s);
      }
   return NULL;
   }
ee_rule_complex_clause *ee_rule_complex_clause::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_rule_complex_clause *>(s);
      }
   return NULL;
   }
// construction factory
ee_rule_complex_clause *ee_rule_complex_clause::Construct() {
   ee_rule_complex_clause *result = NULL;

   // create the ee_rule_complex_clause.
   result = new ee_rule_complex_clause();
   return result;
   }
bool ee_rule_complex_clause::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_rule_complex_clause\r\n");

   // Check for the existence of all required attributes
   if (_conjunctive_content == NULL) {
      TRACE("ERROR: _conjunctive_content a required attribute is NULL!\r\n");
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
