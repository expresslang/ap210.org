// Source for AP210 application object
//     physical_connectivity_definition_relationship

// Precompiled include files
#include <StdAfx.h>

#include "physical_connectivity_definition_relationship.h"

// Classes
#include <ee_requirement_occurrence.h>
#include <physical_connectivity_definition.h>
#include <physical_connectivity_definition.h>

physical_connectivity_definition_relationship::physical_connectivity_definition_relationship() {
   initialize();
   }
physical_connectivity_definition_relationship::~physical_connectivity_definition_relationship() {
   // Free string attributes
   }
// intialize data members
void physical_connectivity_definition_relationship::initialize() {
   // Required attributes
   _requirement = NULL;
   _previous_definition = NULL;
   _current_definition = NULL;

   // Optional attributes
   }
// Runtime type identification
int physical_connectivity_definition_relationship::DynamicType(int ID) {
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
physical_connectivity_definition_relationship *physical_connectivity_definition_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<physical_connectivity_definition_relationship *>(s);
      }
   return NULL;
   }
physical_connectivity_definition_relationship *physical_connectivity_definition_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<physical_connectivity_definition_relationship *>(s);
      }
   return NULL;
   }
// construction factory
physical_connectivity_definition_relationship *physical_connectivity_definition_relationship::Construct() {
   physical_connectivity_definition_relationship *result = NULL;

   // create the physical_connectivity_definition_relationship.
   result = new physical_connectivity_definition_relationship();
   return result;
   }
bool physical_connectivity_definition_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: physical_connectivity_definition_relationship\r\n");

   // Check for the existence of all required attributes
   if (_requirement == NULL) {
      TRACE("ERROR: _requirement a required attribute is NULL!\r\n");
      result = false;
      }
   if (_previous_definition == NULL) {
      TRACE("ERROR: _previous_definition a required attribute is NULL!\r\n");
      result = false;
      }
   if (_current_definition == NULL) {
      TRACE("ERROR: _current_definition a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
