// Source for AP210 application object
//     physical_network

// Precompiled include files
#include <StdAfx.h>

#include "physical_network.h"

// Classes

physical_network::physical_network() {
   initialize();
   }
physical_network::~physical_network() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void physical_network::initialize() {
   // Required attributes
   _name = NULL;

   // Optional attributes
   }
// Runtime type identification
int physical_network::DynamicType(int ID) {
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
physical_network *physical_network::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<physical_network *>(s);
      }
   return NULL;
   }
physical_network *physical_network::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<physical_network *>(s);
      }
   return NULL;
   }
// construction factory
physical_network *physical_network::Construct() {
   physical_network *result = NULL;

   // create the physical_network.
   result = new physical_network();
   return result;
   }
bool physical_network::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: physical_network\r\n");

   // Check for the existence of all required attributes
   if (_connectivity_requirement_element == NULL) {
      TRACE("ERROR: _connectivity_requirement_element a required attribute is NULL!\r\n");
      result = false;
      }
   if (_interconnect_module_network_topology_element == NULL) {
      TRACE("ERROR: _interconnect_module_network_topology_element a required attribute is NULL!\r\n");
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
