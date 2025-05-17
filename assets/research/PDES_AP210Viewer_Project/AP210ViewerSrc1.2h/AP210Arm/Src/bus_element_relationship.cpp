// Source for AP210 application object
//     bus_element_relationship

// Precompiled include files
#include <StdAfx.h>

#include "bus_element_relationship.h"

// Classes
#include <bus_structural_definition.h>

bus_element_relationship::bus_element_relationship() {
   initialize();
   }
bus_element_relationship::~bus_element_relationship() {
   // Free string attributes
   }
// intialize data members
void bus_element_relationship::initialize() {
   // Required attributes
   _bus_definition = NULL;

   // Optional attributes
   }
// Runtime type identification
int bus_element_relationship::DynamicType(int ID) {
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
bus_element_relationship *bus_element_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<bus_element_relationship *>(s);
      }
   return NULL;
   }
bus_element_relationship *bus_element_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<bus_element_relationship *>(s);
      }
   return NULL;
   }
// construction factory
bus_element_relationship *bus_element_relationship::Construct() {
   bus_element_relationship *result = NULL;

   // create the bus_element_relationship.
   result = new bus_element_relationship();
   return result;
   }
bool bus_element_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: bus_element_relationship\r\n");

   // Check for the existence of all required attributes
   if (_element == NULL) {
      TRACE("ERROR: _element a required attribute is NULL!\r\n");
      result = false;
      }
   if (_bus_definition == NULL) {
      TRACE("ERROR: _bus_definition a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
