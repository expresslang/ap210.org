// Source for AP210 application object
//     physical_connectivity_definition

// Precompiled include files
#include <StdAfx.h>

#include "physical_connectivity_definition.h"

// Classes

physical_connectivity_definition::physical_connectivity_definition() {
   initialize();
   }
physical_connectivity_definition::~physical_connectivity_definition() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void physical_connectivity_definition::initialize() {
   // Required attributes
   _name = NULL;

   // Optional attributes
   }
// Runtime type identification
int physical_connectivity_definition::DynamicType(int ID) {
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
physical_connectivity_definition *physical_connectivity_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<physical_connectivity_definition *>(s);
      }
   return NULL;
   }
physical_connectivity_definition *physical_connectivity_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<physical_connectivity_definition *>(s);
      }
   return NULL;
   }
// construction factory
physical_connectivity_definition *physical_connectivity_definition::Construct() {
   physical_connectivity_definition *result = NULL;

   // create the physical_connectivity_definition.
   result = new physical_connectivity_definition();
   return result;
   }
bool physical_connectivity_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: physical_connectivity_definition\r\n");

   // Check for the existence of all required attributes
   if (_associated_terminals == NULL) {
      TRACE("ERROR: _associated_terminals a required attribute is NULL!\r\n");
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
