// Source for AP210 application object
//     component_make_from_relationship

// Precompiled include files
#include <StdAfx.h>

#include "component_make_from_relationship.h"

// Classes
#include <assembly_composition_relationship.h>
#include <assembly_composition_relationship.h>

component_make_from_relationship::component_make_from_relationship() {
   initialize();
   }
component_make_from_relationship::~component_make_from_relationship() {
   // Free string attributes
   }
// intialize data members
void component_make_from_relationship::initialize() {
   // Required attributes
   _reusable_component = NULL;
   _resultant_component = NULL;

   // Optional attributes
   }
// Runtime type identification
int component_make_from_relationship::DynamicType(int ID) {
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
component_make_from_relationship *component_make_from_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_make_from_relationship *>(s);
      }
   return NULL;
   }
component_make_from_relationship *component_make_from_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_make_from_relationship *>(s);
      }
   return NULL;
   }
// construction factory
component_make_from_relationship *component_make_from_relationship::Construct() {
   component_make_from_relationship *result = NULL;

   // create the component_make_from_relationship.
   result = new component_make_from_relationship();
   return result;
   }
bool component_make_from_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_make_from_relationship\r\n");

   // Check for the existence of all required attributes
   if (_reusable_component == NULL) {
      TRACE("ERROR: _reusable_component a required attribute is NULL!\r\n");
      result = false;
      }
   if (_resultant_component == NULL) {
      TRACE("ERROR: _resultant_component a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
