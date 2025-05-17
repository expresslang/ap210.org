// Source for AP210 application object
//     assembly_component_2d_shape

// Precompiled include files
#include <StdAfx.h>

#include "assembly_component_2d_shape.h"

// Classes
#include <assembly_component.h>

assembly_component_2d_shape::assembly_component_2d_shape() {
   initialize();
   }
assembly_component_2d_shape::~assembly_component_2d_shape() {
   // Free string attributes
   }
// intialize data members
void assembly_component_2d_shape::initialize() {
   // Required attributes
   _shape_characterized_component = NULL;

   // Optional attributes
   }
// Runtime type identification
int assembly_component_2d_shape::DynamicType(int ID) {
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
assembly_component_2d_shape *assembly_component_2d_shape::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<assembly_component_2d_shape *>(s);
      }
   return NULL;
   }
assembly_component_2d_shape *assembly_component_2d_shape::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<assembly_component_2d_shape *>(s);
      }
   return NULL;
   }
// construction factory
assembly_component_2d_shape *assembly_component_2d_shape::Construct() {
   assembly_component_2d_shape *result = NULL;

   // create the assembly_component_2d_shape.
   result = new assembly_component_2d_shape();
   return result;
   }
bool assembly_component_2d_shape::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: assembly_component_2d_shape\r\n");

   // Check for the existence of all required attributes
   if (_shape_characterized_component == NULL) {
      TRACE("ERROR: _shape_characterized_component a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
