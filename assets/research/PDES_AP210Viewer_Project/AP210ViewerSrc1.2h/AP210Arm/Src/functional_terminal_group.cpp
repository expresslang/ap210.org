// Source for AP210 application object
//     functional_terminal_group

// Precompiled include files
#include <StdAfx.h>

#include "functional_terminal_group.h"

// Classes

functional_terminal_group::functional_terminal_group() {
   initialize();
   }
functional_terminal_group::~functional_terminal_group() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   if (_group_description != NULL) {
      free(_group_description);
     }
   if (_group_type != NULL) {
      free(_group_type);
     }
   }
// intialize data members
void functional_terminal_group::initialize() {
   // Required attributes
   _name = NULL;
   _group_description = NULL;
   _group_type = NULL;

   // Optional attributes
   }
// Runtime type identification
int functional_terminal_group::DynamicType(int ID) {
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
functional_terminal_group *functional_terminal_group::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<functional_terminal_group *>(s);
      }
   return NULL;
   }
functional_terminal_group *functional_terminal_group::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<functional_terminal_group *>(s);
      }
   return NULL;
   }
// construction factory
functional_terminal_group *functional_terminal_group::Construct() {
   functional_terminal_group *result = NULL;

   // create the functional_terminal_group.
   result = new functional_terminal_group();
   return result;
   }
bool functional_terminal_group::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: functional_terminal_group\r\n");

   // Check for the existence of all required attributes
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   if (_group_description == NULL) {
      TRACE("ERROR: _group_description a required attribute is NULL!\r\n");
      result = false;
      }
   if (_group_type == NULL) {
      TRACE("ERROR: _group_type a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
