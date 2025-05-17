// Source for AP210 application object
//     signal_property

// Precompiled include files
#include <StdAfx.h>

#include "signal_property.h"

// Classes
#include <representation.h>
#include <signal.h>
#include <external_definition.h>

signal_property::signal_property() {
   initialize();
   }
signal_property::~signal_property() {
   // Free string attributes
   }
// intialize data members
void signal_property::initialize() {
   // Required attributes
   _signal_property_representation = NULL;
   _characterized_signal = NULL;
   _signal_property_category = NULL;

   // Optional attributes
   }
// Runtime type identification
int signal_property::DynamicType(int ID) {
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
signal_property *signal_property::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<signal_property *>(s);
      }
   return NULL;
   }
signal_property *signal_property::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<signal_property *>(s);
      }
   return NULL;
   }
// construction factory
signal_property *signal_property::Construct() {
   signal_property *result = NULL;

   // create the signal_property.
   result = new signal_property();
   return result;
   }
bool signal_property::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: signal_property\r\n");

   // Check for the existence of all required attributes
   if (_signal_property_representation == NULL) {
      TRACE("ERROR: _signal_property_representation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_characterized_signal == NULL) {
      TRACE("ERROR: _characterized_signal a required attribute is NULL!\r\n");
      result = false;
      }
   if (_signal_property_category == NULL) {
      TRACE("ERROR: _signal_property_category a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
