// Source for AP210 application object
//     ee_rule

// Precompiled include files
#include <StdAfx.h>

#include "ee_rule.h"

// Classes

ee_rule::ee_rule() {
   initialize();
   }
ee_rule::~ee_rule() {
   // Free string attributes
   if (_rule_description != NULL) {
      free(_rule_description);
     }
   }
// intialize data members
void ee_rule::initialize() {
   // Required attributes
   _rule_description = NULL;

   // Optional attributes
   }
// Runtime type identification
int ee_rule::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = library_item::DynamicType(ID);
      }
   return result;
   }
ee_rule *ee_rule::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_rule *>(s);
      }
   return NULL;
   }
ee_rule *ee_rule::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_rule *>(s);
      }
   return NULL;
   }
// construction factory
ee_rule *ee_rule::Construct() {
   ee_rule *result = NULL;

   // create the ee_rule.
   result = new ee_rule();
   return result;
   }
bool ee_rule::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_rule\r\n");

   // Check for the existence of all required attributes
   if (_rule_description == NULL) {
      TRACE("ERROR: _rule_description a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (library_item::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
