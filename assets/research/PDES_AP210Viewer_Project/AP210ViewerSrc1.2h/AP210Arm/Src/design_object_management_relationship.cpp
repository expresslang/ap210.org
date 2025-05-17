// Source for AP210 application object
//     design_object_management_relationship

// Precompiled include files
#include <StdAfx.h>

#include "design_object_management_relationship.h"

// Classes
#include <ee_product_definition.h>
#include <ee_product_definition.h>

design_object_management_relationship::design_object_management_relationship() {
   initialize();
   }
design_object_management_relationship::~design_object_management_relationship() {
   // Free string attributes
   }
// intialize data members
void design_object_management_relationship::initialize() {
   // Required attributes
   _previous_design = NULL;
   _current_design = NULL;

   // Optional attributes
   }
// Runtime type identification
int design_object_management_relationship::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
design_object_management_relationship *design_object_management_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<design_object_management_relationship *>(s);
      }
   return NULL;
   }
design_object_management_relationship *design_object_management_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<design_object_management_relationship *>(s);
      }
   return NULL;
   }
// construction factory
design_object_management_relationship *design_object_management_relationship::Construct() {
   design_object_management_relationship *result = NULL;

   // create the design_object_management_relationship.
   result = new design_object_management_relationship();
   return result;
   }
bool design_object_management_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: design_object_management_relationship\r\n");

   // Check for the existence of all required attributes
   if (_previous_design == NULL) {
      TRACE("ERROR: _previous_design a required attribute is NULL!\r\n");
      result = false;
      }
   if (_current_design == NULL) {
      TRACE("ERROR: _current_design a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
