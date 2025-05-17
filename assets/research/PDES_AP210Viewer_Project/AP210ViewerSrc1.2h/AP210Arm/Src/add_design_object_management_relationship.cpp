// Source for AP210 application object
//     add_design_object_management_relationship

// Precompiled include files
#include <StdAfx.h>

#include "add_design_object_management_relationship.h"

// Classes
#include <managed_design_object.h>

add_design_object_management_relationship::add_design_object_management_relationship() {
   initialize();
   }
add_design_object_management_relationship::~add_design_object_management_relationship() {
   // Free string attributes
   }
// intialize data members
void add_design_object_management_relationship::initialize() {
   // Required attributes
   _current_design_object = NULL;

   // Optional attributes
   }
// Runtime type identification
int add_design_object_management_relationship::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = design_object_management_relationship::DynamicType(ID);
      }
   return result;
   }
add_design_object_management_relationship *add_design_object_management_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<add_design_object_management_relationship *>(s);
      }
   return NULL;
   }
add_design_object_management_relationship *add_design_object_management_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<add_design_object_management_relationship *>(s);
      }
   return NULL;
   }
// construction factory
add_design_object_management_relationship *add_design_object_management_relationship::Construct() {
   add_design_object_management_relationship *result = NULL;

   // create the add_design_object_management_relationship.
   result = new add_design_object_management_relationship();
   return result;
   }
bool add_design_object_management_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: add_design_object_management_relationship\r\n");

   // Check for the existence of all required attributes
   if (_current_design_object == NULL) {
      TRACE("ERROR: _current_design_object a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (design_object_management_relationship::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
