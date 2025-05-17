// Source for AP210 application object
//     routed_interconnect_component

// Precompiled include files
#include <StdAfx.h>

#include "routed_interconnect_component.h"

// Classes
#include <feature_shape_definition.h>

routed_interconnect_component::routed_interconnect_component() {
   initialize();
   }
routed_interconnect_component::~routed_interconnect_component() {
   // Free string attributes
   }
// intialize data members
void routed_interconnect_component::initialize() {
   // Required attributes
   _routed_shape = NULL;

   // Optional attributes
   }
// Runtime type identification
int routed_interconnect_component::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = assembly_component::DynamicType(ID);
      }
   return result;
   }
routed_interconnect_component *routed_interconnect_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<routed_interconnect_component *>(s);
      }
   return NULL;
   }
routed_interconnect_component *routed_interconnect_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<routed_interconnect_component *>(s);
      }
   return NULL;
   }
// construction factory
routed_interconnect_component *routed_interconnect_component::Construct() {
   routed_interconnect_component *result = NULL;

   // create the routed_interconnect_component.
   result = new routed_interconnect_component();
   return result;
   }
bool routed_interconnect_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: routed_interconnect_component\r\n");

   // Check for the existence of all required attributes
   if (_routed_shape == NULL) {
      TRACE("ERROR: _routed_shape a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (assembly_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
