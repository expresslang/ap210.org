// Source for AP210 application object
//     connectivity_allocation

// Precompiled include files
#include <StdAfx.h>

#include "connectivity_allocation.h"

// Classes
#include <physical_connectivity_definition.h>
#include <aggregate_connectivity_requirement.h>

connectivity_allocation::connectivity_allocation() {
   initialize();
   }
connectivity_allocation::~connectivity_allocation() {
   // Free string attributes
   }
// intialize data members
void connectivity_allocation::initialize() {
   // Required attributes
   _implementation = NULL;
   _connectivity_requirement = NULL;

   // Optional attributes
   }
// Runtime type identification
int connectivity_allocation::DynamicType(int ID) {
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
connectivity_allocation *connectivity_allocation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<connectivity_allocation *>(s);
      }
   return NULL;
   }
connectivity_allocation *connectivity_allocation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<connectivity_allocation *>(s);
      }
   return NULL;
   }
// construction factory
connectivity_allocation *connectivity_allocation::Construct() {
   connectivity_allocation *result = NULL;

   // create the connectivity_allocation.
   result = new connectivity_allocation();
   return result;
   }
bool connectivity_allocation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: connectivity_allocation\r\n");

   // Check for the existence of all required attributes
   if (_implementation == NULL) {
      TRACE("ERROR: _implementation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_connectivity_requirement == NULL) {
      TRACE("ERROR: _connectivity_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
