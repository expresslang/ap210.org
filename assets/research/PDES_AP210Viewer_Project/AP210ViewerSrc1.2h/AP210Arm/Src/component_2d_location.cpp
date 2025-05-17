// Source for AP210 application object
//     component_2d_location

// Precompiled include files
#include <StdAfx.h>

#include "component_2d_location.h"

// Classes
#include <cartesian_transformation_operator_2d.h>
#include <interconnect_module_component_surface_feature.h>

component_2d_location::component_2d_location() {
   initialize();
   }
component_2d_location::~component_2d_location() {
   // Free string attributes
   }
// intialize data members
void component_2d_location::initialize() {
   // Required attributes
   _transformation = NULL;

   // Optional attributes
   _mounting_surface = NULL;
   }
// Runtime type identification
int component_2d_location::DynamicType(int ID) {
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
component_2d_location *component_2d_location::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_2d_location *>(s);
      }
   return NULL;
   }
component_2d_location *component_2d_location::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_2d_location *>(s);
      }
   return NULL;
   }
// construction factory
component_2d_location *component_2d_location::Construct() {
   component_2d_location *result = NULL;

   // create the component_2d_location.
   result = new component_2d_location();
   return result;
   }
bool component_2d_location::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_2d_location\r\n");

   // Check for the existence of all required attributes
   if (_placement_fixed == NULL) {
      TRACE("ERROR: _placement_fixed a required attribute is NULL!\r\n");
      result = false;
      }
   if (_transformation == NULL) {
      TRACE("ERROR: _transformation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
