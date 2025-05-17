// Source for AP210 application object
//     change_design_object_management_relationship

// Precompiled include files
#include <StdAfx.h>

#include "change_design_object_management_relationship.h"

// Classes
#include <managed_design_object.h>
#include <managed_design_object.h>

change_design_object_management_relationship::change_design_object_management_relationship() {
   initialize();
   }
change_design_object_management_relationship::~change_design_object_management_relationship() {
   // Free string attributes
   }
// intialize data members
void change_design_object_management_relationship::initialize() {
   // Required attributes
   _current_design_object = NULL;
   _previous_design_object = NULL;

   // Optional attributes
   }
// Runtime type identification
int change_design_object_management_relationship::DynamicType(int ID) {
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
change_design_object_management_relationship *change_design_object_management_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<change_design_object_management_relationship *>(s);
      }
   return NULL;
   }
change_design_object_management_relationship *change_design_object_management_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<change_design_object_management_relationship *>(s);
      }
   return NULL;
   }
// construction factory
change_design_object_management_relationship *change_design_object_management_relationship::Construct() {
   change_design_object_management_relationship *result = NULL;

   // create the change_design_object_management_relationship.
   result = new change_design_object_management_relationship();
   return result;
   }
bool change_design_object_management_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: change_design_object_management_relationship\r\n");

   // Check for the existence of all required attributes
   if (_current_design_object == NULL) {
      TRACE("ERROR: _current_design_object a required attribute is NULL!\r\n");
      result = false;
      }
   if (_previous_design_object == NULL) {
      TRACE("ERROR: _previous_design_object a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (design_object_management_relationship::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
