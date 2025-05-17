// Source for AP210 application object
//     component_mounting_clearance_relationship

// Precompiled include files
#include <StdAfx.h>

#include "component_mounting_clearance_relationship.h"

// Classes
#include <next_higher_assembly_relationship.h>
#include <next_higher_assembly_relationship.h>
#include <length_data_element.h>
#include <length_data_element.h>

component_mounting_clearance_relationship::component_mounting_clearance_relationship() {
   initialize();
   }
component_mounting_clearance_relationship::~component_mounting_clearance_relationship() {
   // Free string attributes
   }
// intialize data members
void component_mounting_clearance_relationship::initialize() {
   // Required attributes
   _previously_placed_component = NULL;
   _current_component = NULL;
   _minimum_mounting_clearance = NULL;

   // Optional attributes
   _maximum_mounting_clearance = NULL;
   }
// Runtime type identification
int component_mounting_clearance_relationship::DynamicType(int ID) {
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
component_mounting_clearance_relationship *component_mounting_clearance_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_mounting_clearance_relationship *>(s);
      }
   return NULL;
   }
component_mounting_clearance_relationship *component_mounting_clearance_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_mounting_clearance_relationship *>(s);
      }
   return NULL;
   }
// construction factory
component_mounting_clearance_relationship *component_mounting_clearance_relationship::Construct() {
   component_mounting_clearance_relationship *result = NULL;

   // create the component_mounting_clearance_relationship.
   result = new component_mounting_clearance_relationship();
   return result;
   }
bool component_mounting_clearance_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_mounting_clearance_relationship\r\n");

   // Check for the existence of all required attributes
   if (_previously_placed_component == NULL) {
      TRACE("ERROR: _previously_placed_component a required attribute is NULL!\r\n");
      result = false;
      }
   if (_current_component == NULL) {
      TRACE("ERROR: _current_component a required attribute is NULL!\r\n");
      result = false;
      }
   if (_minimum_mounting_clearance == NULL) {
      TRACE("ERROR: _minimum_mounting_clearance a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
