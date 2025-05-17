// Source for AP210 application object
//     component_overlap_relationship

// Precompiled include files
#include <StdAfx.h>

#include "component_overlap_relationship.h"

// Classes
#include <next_higher_assembly_relationship.h>
#include <next_higher_assembly_relationship.h>
#include <length_data_element.h>
#include <length_data_element.h>

component_overlap_relationship::component_overlap_relationship() {
   initialize();
   }
component_overlap_relationship::~component_overlap_relationship() {
   // Free string attributes
   }
// intialize data members
void component_overlap_relationship::initialize() {
   // Required attributes
   _previously_placed_component = NULL;
   _current_component = NULL;
   _minimum_added_clearance = NULL;

   // Optional attributes
   _maximum_added_clearance = NULL;
   }
// Runtime type identification
int component_overlap_relationship::DynamicType(int ID) {
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
component_overlap_relationship *component_overlap_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_overlap_relationship *>(s);
      }
   return NULL;
   }
component_overlap_relationship *component_overlap_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_overlap_relationship *>(s);
      }
   return NULL;
   }
// construction factory
component_overlap_relationship *component_overlap_relationship::Construct() {
   component_overlap_relationship *result = NULL;

   // create the component_overlap_relationship.
   result = new component_overlap_relationship();
   return result;
   }
bool component_overlap_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_overlap_relationship\r\n");

   // Check for the existence of all required attributes
   if (_previously_placed_component == NULL) {
      TRACE("ERROR: _previously_placed_component a required attribute is NULL!\r\n");
      result = false;
      }
   if (_current_component == NULL) {
      TRACE("ERROR: _current_component a required attribute is NULL!\r\n");
      result = false;
      }
   if (_minimum_added_clearance == NULL) {
      TRACE("ERROR: _minimum_added_clearance a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
