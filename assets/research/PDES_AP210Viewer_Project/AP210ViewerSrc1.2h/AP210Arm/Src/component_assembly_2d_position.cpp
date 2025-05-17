// Source for AP210 application object
//     component_assembly_2d_position

// Precompiled include files
#include <StdAfx.h>

#include "component_assembly_2d_position.h"

// Classes
#include <assembly_component_2d_shape.h>
#include <component_2d_location.h>
#include <physical_unit_planar_shape.h>
#include <next_higher_assembly_relationship.h>

component_assembly_2d_position::component_assembly_2d_position() {
   initialize();
   }
component_assembly_2d_position::~component_assembly_2d_position() {
   // Free string attributes
   }
// intialize data members
void component_assembly_2d_position::initialize() {
   // Required attributes
   _component_model = NULL;
   _transformation = NULL;
   _assembly_model = NULL;
   _component = NULL;

   // Optional attributes
   }
// Runtime type identification
int component_assembly_2d_position::DynamicType(int ID) {
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
component_assembly_2d_position *component_assembly_2d_position::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_assembly_2d_position *>(s);
      }
   return NULL;
   }
component_assembly_2d_position *component_assembly_2d_position::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_assembly_2d_position *>(s);
      }
   return NULL;
   }
// construction factory
component_assembly_2d_position *component_assembly_2d_position::Construct() {
   component_assembly_2d_position *result = NULL;

   // create the component_assembly_2d_position.
   result = new component_assembly_2d_position();
   return result;
   }
bool component_assembly_2d_position::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_assembly_2d_position\r\n");

   // Check for the existence of all required attributes
   if (_component_model == NULL) {
      TRACE("ERROR: _component_model a required attribute is NULL!\r\n");
      result = false;
      }
   if (_transformation == NULL) {
      TRACE("ERROR: _transformation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_assembly_model == NULL) {
      TRACE("ERROR: _assembly_model a required attribute is NULL!\r\n");
      result = false;
      }
   if (_component == NULL) {
      TRACE("ERROR: _component a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
