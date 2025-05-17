// Source for AP210 application object
//     bus_structural_definition

// Precompiled include files
#include <StdAfx.h>

#include "bus_structural_definition.h"

// Classes

bus_structural_definition::bus_structural_definition() {
   initialize();
   }
bus_structural_definition::~bus_structural_definition() {
   // Free string attributes
   if (_bus_name != NULL) {
      free(_bus_name);
     }
   }
// intialize data members
void bus_structural_definition::initialize() {
   // Required attributes
   _bus_name = NULL;

   // Optional attributes
   }
// Runtime type identification
int bus_structural_definition::DynamicType(int ID) {
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
bus_structural_definition *bus_structural_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<bus_structural_definition *>(s);
      }
   return NULL;
   }
bus_structural_definition *bus_structural_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<bus_structural_definition *>(s);
      }
   return NULL;
   }
// construction factory
bus_structural_definition *bus_structural_definition::Construct() {
   bus_structural_definition *result = NULL;

   // create the bus_structural_definition.
   result = new bus_structural_definition();
   return result;
   }
bool bus_structural_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: bus_structural_definition\r\n");

   // Check for the existence of all required attributes
   if (_bus_name == NULL) {
      TRACE("ERROR: _bus_name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
