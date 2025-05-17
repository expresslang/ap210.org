// Source for AP210 application object
//     signal_specification

// Precompiled include files
#include <StdAfx.h>

#include "signal_specification.h"

// Classes
#include <test_specification.h>
#include <scalar_terminal_definition.h>
#include <scalar_terminal_definition.h>
#include <signal_property.h>
#include <signal_property.h>
#include <functional_unit_network_definition.h>
#include <functional_unit.h>

signal_specification::signal_specification() {
   initialize();
   }
signal_specification::~signal_specification() {
   // Free string attributes
   }
// intialize data members
void signal_specification::initialize() {
   // Required attributes
   _measurement_condition = NULL;
   _measurement_access_mechanism = NULL;
   _minimum_characteristic = NULL;
   _maximum_characteristic = NULL;
   _characterization_network = NULL;
   _characterizing_functional_unit = NULL;

   // Optional attributes
   _reference_access_mechanism = NULL;
   }
// Runtime type identification
int signal_specification::DynamicType(int ID) {
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
signal_specification *signal_specification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<signal_specification *>(s);
      }
   return NULL;
   }
signal_specification *signal_specification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<signal_specification *>(s);
      }
   return NULL;
   }
// construction factory
signal_specification *signal_specification::Construct() {
   signal_specification *result = NULL;

   // create the signal_specification.
   result = new signal_specification();
   return result;
   }
bool signal_specification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: signal_specification\r\n");

   // Check for the existence of all required attributes
   if (_measurement_condition == NULL) {
      TRACE("ERROR: _measurement_condition a required attribute is NULL!\r\n");
      result = false;
      }
   if (_measurement_access_mechanism == NULL) {
      TRACE("ERROR: _measurement_access_mechanism a required attribute is NULL!\r\n");
      result = false;
      }
   if (_minimum_characteristic == NULL) {
      TRACE("ERROR: _minimum_characteristic a required attribute is NULL!\r\n");
      result = false;
      }
   if (_maximum_characteristic == NULL) {
      TRACE("ERROR: _maximum_characteristic a required attribute is NULL!\r\n");
      result = false;
      }
   if (_characterization_network == NULL) {
      TRACE("ERROR: _characterization_network a required attribute is NULL!\r\n");
      result = false;
      }
   if (_characterizing_functional_unit == NULL) {
      TRACE("ERROR: _characterizing_functional_unit a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
