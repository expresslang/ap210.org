// Source for AP210 application object
//     ee_rule_premise_definition

// Precompiled include files
#include <StdAfx.h>

#include "ee_rule_premise_definition.h"

// Classes
#include <ee_rule_definition.h>

ee_rule_premise_definition::ee_rule_premise_definition() {
   initialize();
   }
ee_rule_premise_definition::~ee_rule_premise_definition() {
   // Free string attributes
   if (_identifier != NULL) {
      free(_identifier);
     }
   }
// intialize data members
void ee_rule_premise_definition::initialize() {
   // Required attributes
   _rule_definition = NULL;
   _identifier = NULL;

   // Optional attributes
   }
// Runtime type identification
int ee_rule_premise_definition::DynamicType(int ID) {
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
ee_rule_premise_definition *ee_rule_premise_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_rule_premise_definition *>(s);
      }
   return NULL;
   }
ee_rule_premise_definition *ee_rule_premise_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_rule_premise_definition *>(s);
      }
   return NULL;
   }
// construction factory
ee_rule_premise_definition *ee_rule_premise_definition::Construct() {
   ee_rule_premise_definition *result = NULL;

   // create the ee_rule_premise_definition.
   result = new ee_rule_premise_definition();
   return result;
   }
bool ee_rule_premise_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_rule_premise_definition\r\n");

   // Check for the existence of all required attributes
   if (_rule_definition == NULL) {
      TRACE("ERROR: _rule_definition a required attribute is NULL!\r\n");
      result = false;
      }
   if (_identifier == NULL) {
      TRACE("ERROR: _identifier a required attribute is NULL!\r\n");
      result = false;
      }
   if (_disjunctive_content == NULL) {
      TRACE("ERROR: _disjunctive_content a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
