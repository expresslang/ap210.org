// Source for AP210 application object
//     component_placement_restriction_assignment

// Precompiled include files
#include <StdAfx.h>

#include "component_placement_restriction_assignment.h"

// Classes
#include <datum_based_length_measure.h>
#include <datum_based_length_measure.h>
#include <mounting_restriction_area.h>
#include <item_restricted_requirement_occurrence.h>
#include <datum_based_length_measure.h>
#include <datum_based_length_measure.h>

component_placement_restriction_assignment::component_placement_restriction_assignment() {
   initialize();
   }
component_placement_restriction_assignment::~component_placement_restriction_assignment() {
   // Free string attributes
   }
// intialize data members
void component_placement_restriction_assignment::initialize() {
   // Required attributes
   _area = NULL;
   _requirement = NULL;

   // Optional attributes
   _maximum_negative_component_height = NULL;
   _maximum_positive_component_height = NULL;
   _maximum_mounting_clearance = NULL;
   _minimum_mounting_clearance = NULL;
   }
// Runtime type identification
int component_placement_restriction_assignment::DynamicType(int ID) {
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
component_placement_restriction_assignment *component_placement_restriction_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_placement_restriction_assignment *>(s);
      }
   return NULL;
   }
component_placement_restriction_assignment *component_placement_restriction_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_placement_restriction_assignment *>(s);
      }
   return NULL;
   }
// construction factory
component_placement_restriction_assignment *component_placement_restriction_assignment::Construct() {
   component_placement_restriction_assignment *result = NULL;

   // create the component_placement_restriction_assignment.
   result = new component_placement_restriction_assignment();
   return result;
   }
bool component_placement_restriction_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_placement_restriction_assignment\r\n");

   // Check for the existence of all required attributes
   if (_area == NULL) {
      TRACE("ERROR: _area a required attribute is NULL!\r\n");
      result = false;
      }
   if (_requirement == NULL) {
      TRACE("ERROR: _requirement a required attribute is NULL!\r\n");
      result = false;
      }
   if (_components_permitted == NULL) {
      TRACE("ERROR: _components_permitted a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
