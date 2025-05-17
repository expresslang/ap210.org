// Source for AP210 application object
//     aggregate_connectivity_requirement

// Precompiled include files
#include <StdAfx.h>

#include "aggregate_connectivity_requirement.h"

// Classes
#include <functional_unit_network_node_definition.h>
#include <design_composition_path.h>

aggregate_connectivity_requirement::aggregate_connectivity_requirement() {
   initialize();
   }
aggregate_connectivity_requirement::~aggregate_connectivity_requirement() {
   // Free string attributes
   }
// intialize data members
void aggregate_connectivity_requirement::initialize() {
   // Required attributes
   _connectivity_requirement = NULL;
   _design_definition_path = NULL;

   // Optional attributes
   }
// Runtime type identification
int aggregate_connectivity_requirement::DynamicType(int ID) {
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
aggregate_connectivity_requirement *aggregate_connectivity_requirement::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<aggregate_connectivity_requirement *>(s);
      }
   return NULL;
   }
aggregate_connectivity_requirement *aggregate_connectivity_requirement::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<aggregate_connectivity_requirement *>(s);
      }
   return NULL;
   }
// construction factory
aggregate_connectivity_requirement *aggregate_connectivity_requirement::Construct() {
   aggregate_connectivity_requirement *result = NULL;

   // create the aggregate_connectivity_requirement.
   result = new aggregate_connectivity_requirement();
   return result;
   }
bool aggregate_connectivity_requirement::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: aggregate_connectivity_requirement\r\n");

   // Check for the existence of all required attributes
   if (_connectivity_requirement == NULL) {
      TRACE("ERROR: _connectivity_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   if (_design_definition_path == NULL) {
      TRACE("ERROR: _design_definition_path a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
