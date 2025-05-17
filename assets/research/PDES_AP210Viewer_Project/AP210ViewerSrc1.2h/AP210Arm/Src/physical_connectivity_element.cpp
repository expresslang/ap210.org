// Source for AP210 application object
//     physical_connectivity_element

// Precompiled include files
#include <StdAfx.h>

#include "physical_connectivity_element.h"

// Classes
#include <physical_connectivity_structure_definition.h>

physical_connectivity_element::physical_connectivity_element() {
   initialize();
   }
physical_connectivity_element::~physical_connectivity_element() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void physical_connectivity_element::initialize() {
   // Required attributes
   _name = NULL;
   _connectivity_context = NULL;

   // Optional attributes
   }
// Runtime type identification
int physical_connectivity_element::DynamicType(int ID) {
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
physical_connectivity_element *physical_connectivity_element::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<physical_connectivity_element *>(s);
      }
   return NULL;
   }
physical_connectivity_element *physical_connectivity_element::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<physical_connectivity_element *>(s);
      }
   return NULL;
   }
// construction factory
physical_connectivity_element *physical_connectivity_element::Construct() {
   physical_connectivity_element *result = NULL;

   // create the physical_connectivity_element.
   result = new physical_connectivity_element();
   return result;
   }
bool physical_connectivity_element::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: physical_connectivity_element\r\n");

   // Check for the existence of all required attributes
   if (_start_terminus == NULL) {
      TRACE("ERROR: _start_terminus a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   if (_end_terminus == NULL) {
      TRACE("ERROR: _end_terminus a required attribute is NULL!\r\n");
      result = false;
      }
   if (_connectivity_context == NULL) {
      TRACE("ERROR: _connectivity_context a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
