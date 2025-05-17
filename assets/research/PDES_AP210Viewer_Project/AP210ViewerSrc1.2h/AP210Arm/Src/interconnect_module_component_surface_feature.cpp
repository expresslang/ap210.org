// Source for AP210 application object
//     interconnect_module_component_surface_feature

// Precompiled include files
#include <StdAfx.h>

#include "interconnect_module_component_surface_feature.h"

// Classes

interconnect_module_component_surface_feature::interconnect_module_component_surface_feature() {
   initialize();
   }
interconnect_module_component_surface_feature::~interconnect_module_component_surface_feature() {
   // Free string attributes
   }
// intialize data members
void interconnect_module_component_surface_feature::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int interconnect_module_component_surface_feature::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = component_feature::DynamicType(ID);
      }
   return result;
   }
interconnect_module_component_surface_feature *interconnect_module_component_surface_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interconnect_module_component_surface_feature *>(s);
      }
   return NULL;
   }
interconnect_module_component_surface_feature *interconnect_module_component_surface_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interconnect_module_component_surface_feature *>(s);
      }
   return NULL;
   }
// construction factory
interconnect_module_component_surface_feature *interconnect_module_component_surface_feature::Construct() {
   interconnect_module_component_surface_feature *result = NULL;

   // create the interconnect_module_component_surface_feature.
   result = new interconnect_module_component_surface_feature();
   return result;
   }
bool interconnect_module_component_surface_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interconnect_module_component_surface_feature\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (component_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
