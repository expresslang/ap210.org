// Source for AP210 application object
//     functional_specification

// Precompiled include files
#include <StdAfx.h>

#include "functional_specification.h"

// Classes
#include <signal_specification.h>
#include <signal_specification.h>
#include <external_definition.h>

functional_specification::functional_specification() {
   initialize();
   }
functional_specification::~functional_specification() {
   // Free string attributes
   }
// intialize data members
void functional_specification::initialize() {
   // Required attributes
   _reference_signal = NULL;
   _characterizing_signal = NULL;
   _characteristic_category = NULL;

   // Optional attributes
   }
// Runtime type identification
int functional_specification::DynamicType(int ID) {
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
functional_specification *functional_specification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<functional_specification *>(s);
      }
   return NULL;
   }
functional_specification *functional_specification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<functional_specification *>(s);
      }
   return NULL;
   }
// construction factory
functional_specification *functional_specification::Construct() {
   functional_specification *result = NULL;

   // create the functional_specification.
   result = new functional_specification();
   return result;
   }
bool functional_specification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: functional_specification\r\n");

   // Check for the existence of all required attributes
   if (_reference_signal == NULL) {
      TRACE("ERROR: _reference_signal a required attribute is NULL!\r\n");
      result = false;
      }
   if (_characterizing_signal == NULL) {
      TRACE("ERROR: _characterizing_signal a required attribute is NULL!\r\n");
      result = false;
      }
   if (_characteristic_category == NULL) {
      TRACE("ERROR: _characteristic_category a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
