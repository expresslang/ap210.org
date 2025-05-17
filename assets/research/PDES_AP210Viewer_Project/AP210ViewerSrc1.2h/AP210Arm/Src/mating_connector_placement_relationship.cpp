// Source for AP210 application object
//     mating_connector_placement_relationship

// Precompiled include files
#include <StdAfx.h>

#include "mating_connector_placement_relationship.h"

// Classes
#include <mating_connector_component.h>
#include <next_higher_assembly_interface_requirement.h>
#include <axis_placement.h>

mating_connector_placement_relationship::mating_connector_placement_relationship() {
   initialize();
   }
mating_connector_placement_relationship::~mating_connector_placement_relationship() {
   // Free string attributes
   }
// intialize data members
void mating_connector_placement_relationship::initialize() {
   // Required attributes
   _placed_connector = NULL;
   _interface_context = NULL;
   _connector_placement = NULL;

   // Optional attributes
   }
// Runtime type identification
int mating_connector_placement_relationship::DynamicType(int ID) {
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
mating_connector_placement_relationship *mating_connector_placement_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<mating_connector_placement_relationship *>(s);
      }
   return NULL;
   }
mating_connector_placement_relationship *mating_connector_placement_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<mating_connector_placement_relationship *>(s);
      }
   return NULL;
   }
// construction factory
mating_connector_placement_relationship *mating_connector_placement_relationship::Construct() {
   mating_connector_placement_relationship *result = NULL;

   // create the mating_connector_placement_relationship.
   result = new mating_connector_placement_relationship();
   return result;
   }
bool mating_connector_placement_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: mating_connector_placement_relationship\r\n");

   // Check for the existence of all required attributes
   if (_placed_connector == NULL) {
      TRACE("ERROR: _placed_connector a required attribute is NULL!\r\n");
      result = false;
      }
   if (_interface_context == NULL) {
      TRACE("ERROR: _interface_context a required attribute is NULL!\r\n");
      result = false;
      }
   if (_connector_placement == NULL) {
      TRACE("ERROR: _connector_placement a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
