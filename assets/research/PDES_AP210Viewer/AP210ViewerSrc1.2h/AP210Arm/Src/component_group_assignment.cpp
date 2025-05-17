// Source for AP210 application object
//     component_group_assignment

// Precompiled include files
#include <StdAfx.h>

#include "component_group_assignment.h"

// Classes
#include <placement_group.h>
#include <assembly_component.h>

component_group_assignment::component_group_assignment() {
   initialize();
   }
component_group_assignment::~component_group_assignment() {
   // Free string attributes
   }
// intialize data members
void component_group_assignment::initialize() {
   // Required attributes
   _associated_group = NULL;
   _assigned_component = NULL;

   // Optional attributes
   }
// Runtime type identification
int component_group_assignment::DynamicType(int ID) {
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
component_group_assignment *component_group_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_group_assignment *>(s);
      }
   return NULL;
   }
component_group_assignment *component_group_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_group_assignment *>(s);
      }
   return NULL;
   }
// construction factory
component_group_assignment *component_group_assignment::Construct() {
   component_group_assignment *result = NULL;

   // create the component_group_assignment.
   result = new component_group_assignment();
   return result;
   }
bool component_group_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_group_assignment\r\n");

   // Check for the existence of all required attributes
   if (_associated_group == NULL) {
      TRACE("ERROR: _associated_group a required attribute is NULL!\r\n");
      result = false;
      }
   if (_assigned_component == NULL) {
      TRACE("ERROR: _assigned_component a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
