// Source for AP210 application object
//     physical_connectivity_abstraction_map

// Precompiled include files
#include <StdAfx.h>

#include "physical_connectivity_abstraction_map.h"

// Classes
#include <physical_connectivity_element.h>
#include <conductive_interconnect_element.h>

physical_connectivity_abstraction_map::physical_connectivity_abstraction_map() {
   initialize();
   }
physical_connectivity_abstraction_map::~physical_connectivity_abstraction_map() {
   // Free string attributes
   }
// intialize data members
void physical_connectivity_abstraction_map::initialize() {
   // Required attributes
   _name_space_context_based_definition = NULL;
   _geometric_context_based_definition = NULL;

   // Optional attributes
   }
// Runtime type identification
int physical_connectivity_abstraction_map::DynamicType(int ID) {
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
physical_connectivity_abstraction_map *physical_connectivity_abstraction_map::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<physical_connectivity_abstraction_map *>(s);
      }
   return NULL;
   }
physical_connectivity_abstraction_map *physical_connectivity_abstraction_map::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<physical_connectivity_abstraction_map *>(s);
      }
   return NULL;
   }
// construction factory
physical_connectivity_abstraction_map *physical_connectivity_abstraction_map::Construct() {
   physical_connectivity_abstraction_map *result = NULL;

   // create the physical_connectivity_abstraction_map.
   result = new physical_connectivity_abstraction_map();
   return result;
   }
bool physical_connectivity_abstraction_map::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: physical_connectivity_abstraction_map\r\n");

   // Check for the existence of all required attributes
   if (_name_space_context_based_definition == NULL) {
      TRACE("ERROR: _name_space_context_based_definition a required attribute is NULL!\r\n");
      result = false;
      }
   if (_geometric_context_based_definition == NULL) {
      TRACE("ERROR: _geometric_context_based_definition a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
