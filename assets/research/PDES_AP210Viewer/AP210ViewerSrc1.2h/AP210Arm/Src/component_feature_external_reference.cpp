// Source for AP210 application object
//     component_feature_external_reference

// Precompiled include files
#include <StdAfx.h>

#include "component_feature_external_reference.h"

// Classes
#include <component_external_reference.h>

component_feature_external_reference::component_feature_external_reference() {
   initialize();
   }
component_feature_external_reference::~component_feature_external_reference() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void component_feature_external_reference::initialize() {
   // Required attributes
   _associated_component = NULL;
   _name = NULL;

   // Optional attributes
   }
// Runtime type identification
int component_feature_external_reference::DynamicType(int ID) {
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
component_feature_external_reference *component_feature_external_reference::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_feature_external_reference *>(s);
      }
   return NULL;
   }
component_feature_external_reference *component_feature_external_reference::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_feature_external_reference *>(s);
      }
   return NULL;
   }
// construction factory
component_feature_external_reference *component_feature_external_reference::Construct() {
   component_feature_external_reference *result = NULL;

   // create the component_feature_external_reference.
   result = new component_feature_external_reference();
   return result;
   }
bool component_feature_external_reference::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_feature_external_reference\r\n");

   // Check for the existence of all required attributes
   if (_associated_component == NULL) {
      TRACE("ERROR: _associated_component a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
