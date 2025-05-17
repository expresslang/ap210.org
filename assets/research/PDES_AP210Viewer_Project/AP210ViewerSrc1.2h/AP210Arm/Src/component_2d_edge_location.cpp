// Source for AP210 application object
//     component_2d_edge_location

// Precompiled include files
#include <StdAfx.h>

#include "component_2d_edge_location.h"

// Classes
#include <assembly_joint.h>

component_2d_edge_location::component_2d_edge_location() {
   initialize();
   }
component_2d_edge_location::~component_2d_edge_location() {
   // Free string attributes
   }
// intialize data members
void component_2d_edge_location::initialize() {
   // Required attributes
   _reference_terminal_assembly_joint = NULL;

   // Optional attributes
   }
// Runtime type identification
int component_2d_edge_location::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = component_2d_location::DynamicType(ID);
      }
   return result;
   }
component_2d_edge_location *component_2d_edge_location::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_2d_edge_location *>(s);
      }
   return NULL;
   }
component_2d_edge_location *component_2d_edge_location::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_2d_edge_location *>(s);
      }
   return NULL;
   }
// construction factory
component_2d_edge_location *component_2d_edge_location::Construct() {
   component_2d_edge_location *result = NULL;

   // create the component_2d_edge_location.
   result = new component_2d_edge_location();
   return result;
   }
bool component_2d_edge_location::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_2d_edge_location\r\n");

   // Check for the existence of all required attributes
   if (_reference_terminal_assembly_joint == NULL) {
      TRACE("ERROR: _reference_terminal_assembly_joint a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (component_2d_location::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
