// Source for AP210 application object
//     mating_connector_termination

// Precompiled include files
#include <StdAfx.h>

#include "mating_connector_termination.h"

// Classes
#include <mating_connector_component.h>
#include <ee_requirement_occurrence.h>

mating_connector_termination::mating_connector_termination() {
   initialize();
   }
mating_connector_termination::~mating_connector_termination() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void mating_connector_termination::initialize() {
   // Required attributes
   _accessed_connector = NULL;
   _name = NULL;

   // Optional attributes
   _signal_definition = NULL;
   }
// Runtime type identification
int mating_connector_termination::DynamicType(int ID) {
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
mating_connector_termination *mating_connector_termination::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<mating_connector_termination *>(s);
      }
   return NULL;
   }
mating_connector_termination *mating_connector_termination::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<mating_connector_termination *>(s);
      }
   return NULL;
   }
// construction factory
mating_connector_termination *mating_connector_termination::Construct() {
   mating_connector_termination *result = NULL;

   // create the mating_connector_termination.
   result = new mating_connector_termination();
   return result;
   }
bool mating_connector_termination::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: mating_connector_termination\r\n");

   // Check for the existence of all required attributes
   if (_definition == NULL) {
      TRACE("ERROR: _definition a required attribute is NULL!\r\n");
      result = false;
      }
   if (_accessed_connector == NULL) {
      TRACE("ERROR: _accessed_connector a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
