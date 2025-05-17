// Source for AP210 application object
//     ee_rule_conclusion_definition

// Precompiled include files
#include <StdAfx.h>

#include "ee_rule_conclusion_definition.h"

// Classes
#include <ee_rule_definition.h>

ee_rule_conclusion_definition::ee_rule_conclusion_definition() {
   initialize();
   }
ee_rule_conclusion_definition::~ee_rule_conclusion_definition() {
   // Free string attributes
   if (_identifier != NULL) {
      free(_identifier);
     }
   }
// intialize data members
void ee_rule_conclusion_definition::initialize() {
   // Required attributes
   _rule_definition = NULL;
   _identifier = NULL;

   // Optional attributes
   }
// Runtime type identification
int ee_rule_conclusion_definition::DynamicType(int ID) {
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
ee_rule_conclusion_definition *ee_rule_conclusion_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_rule_conclusion_definition *>(s);
      }
   return NULL;
   }
ee_rule_conclusion_definition *ee_rule_conclusion_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_rule_conclusion_definition *>(s);
      }
   return NULL;
   }
// construction factory
ee_rule_conclusion_definition *ee_rule_conclusion_definition::Construct() {
   ee_rule_conclusion_definition *result = NULL;

   // create the ee_rule_conclusion_definition.
   result = new ee_rule_conclusion_definition();
   return result;
   }
bool ee_rule_conclusion_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_rule_conclusion_definition\r\n");

   // Check for the existence of all required attributes
   if (_rule_definition == NULL) {
      TRACE("ERROR: _rule_definition a required attribute is NULL!\r\n");
      result = false;
      }
   if (_identifier == NULL) {
      TRACE("ERROR: _identifier a required attribute is NULL!\r\n");
      result = false;
      }
   if (_conjunctive_content == NULL) {
      TRACE("ERROR: _conjunctive_content a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
