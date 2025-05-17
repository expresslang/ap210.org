// Source for AP210 application object
//     functional_unit

// Precompiled include files
#include <StdAfx.h>

#include "functional_unit.h"

// Classes
#include <functional_unit_definition.h>
#include <functional_unit_network_definition.h>

functional_unit::functional_unit() {
   initialize();
   }
functional_unit::~functional_unit() {
   // Free string attributes
   if (_reference_designation != NULL) {
      free(_reference_designation);
     }
   }
// intialize data members
void functional_unit::initialize() {
   // Required attributes
   _definition = NULL;
   _reference_designation = NULL;
   _composed_network = NULL;

   // Optional attributes
   }
// Runtime type identification
int functional_unit::DynamicType(int ID) {
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
functional_unit *functional_unit::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<functional_unit *>(s);
      }
   return NULL;
   }
functional_unit *functional_unit::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<functional_unit *>(s);
      }
   return NULL;
   }
// construction factory
functional_unit *functional_unit::Construct() {
   functional_unit *result = NULL;

   // create the functional_unit.
   result = new functional_unit();
   return result;
   }
bool functional_unit::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: functional_unit\r\n");

   // Check for the existence of all required attributes
   if (_definition == NULL) {
      TRACE("ERROR: _definition a required attribute is NULL!\r\n");
      result = false;
      }
   if (_reference_designation == NULL) {
      TRACE("ERROR: _reference_designation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_composed_network == NULL) {
      TRACE("ERROR: _composed_network a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
