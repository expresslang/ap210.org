// Source for AP210 application object
//     mating_connector_component

// Precompiled include files
#include <StdAfx.h>

#include "mating_connector_component.h"

// Classes

mating_connector_component::mating_connector_component() {
   initialize();
   }
mating_connector_component::~mating_connector_component() {
   // Free string attributes
   if (_reference_designation != NULL) {
      free(_reference_designation);
     }
   }
// intialize data members
void mating_connector_component::initialize() {
   // Required attributes

   // Optional attributes
   _reference_designation = NULL;
   }
// Runtime type identification
int mating_connector_component::DynamicType(int ID) {
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
mating_connector_component *mating_connector_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<mating_connector_component *>(s);
      }
   return NULL;
   }
mating_connector_component *mating_connector_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<mating_connector_component *>(s);
      }
   return NULL;
   }
// construction factory
mating_connector_component *mating_connector_component::Construct() {
   mating_connector_component *result = NULL;

   // create the mating_connector_component.
   result = new mating_connector_component();
   return result;
   }
bool mating_connector_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: mating_connector_component\r\n");

   // Check for the existence of all required attributes
   if (_definition == NULL) {
      TRACE("ERROR: _definition a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
