// Source for AP210 application object
//     delete_design_object_management_relationship

// Precompiled include files
#include <StdAfx.h>

#include "delete_design_object_management_relationship.h"

// Classes
#include <managed_design_object.h>

delete_design_object_management_relationship::delete_design_object_management_relationship() {
   initialize();
   }
delete_design_object_management_relationship::~delete_design_object_management_relationship() {
   // Free string attributes
   }
// intialize data members
void delete_design_object_management_relationship::initialize() {
   // Required attributes
   _previous_design_object = NULL;

   // Optional attributes
   }
// Runtime type identification
int delete_design_object_management_relationship::DynamicType(int ID) {
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
delete_design_object_management_relationship *delete_design_object_management_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<delete_design_object_management_relationship *>(s);
      }
   return NULL;
   }
delete_design_object_management_relationship *delete_design_object_management_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<delete_design_object_management_relationship *>(s);
      }
   return NULL;
   }
// construction factory
delete_design_object_management_relationship *delete_design_object_management_relationship::Construct() {
   delete_design_object_management_relationship *result = NULL;

   // create the delete_design_object_management_relationship.
   result = new delete_design_object_management_relationship();
   return result;
   }
bool delete_design_object_management_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: delete_design_object_management_relationship\r\n");

   // Check for the existence of all required attributes
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
