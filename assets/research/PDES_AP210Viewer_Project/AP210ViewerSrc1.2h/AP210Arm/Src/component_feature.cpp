// Source for AP210 application object
//     component_feature

// Precompiled include files
#include <StdAfx.h>

#include "component_feature.h"

// Classes
#include <assembly_component.h>

component_feature::component_feature() {
   initialize();
   }
component_feature::~component_feature() {
   // Free string attributes
   }
// intialize data members
void component_feature::initialize() {
   // Required attributes
   _associated_component = NULL;

   // Optional attributes
   }
// Runtime type identification
int component_feature::DynamicType(int ID) {
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
component_feature *component_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_feature *>(s);
      }
   return NULL;
   }
component_feature *component_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_feature *>(s);
      }
   return NULL;
   }
// construction factory
component_feature *component_feature::Construct() {
   component_feature *result = NULL;

   // create the component_feature.
   result = new component_feature();
   return result;
   }
bool component_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_feature\r\n");

   // Check for the existence of all required attributes
   if (_associated_component == NULL) {
      TRACE("ERROR: _associated_component a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
