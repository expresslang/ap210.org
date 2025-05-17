// Source for AP210 application object
//     routed_packaged_component

// Precompiled include files
#include <StdAfx.h>

#include "routed_packaged_component.h"

// Classes
#include <feature_shape_definition.h>

routed_packaged_component::routed_packaged_component() {
   initialize();
   }
routed_packaged_component::~routed_packaged_component() {
   // Free string attributes
   }
// intialize data members
void routed_packaged_component::initialize() {
   // Required attributes
   _routed_shape = NULL;

   // Optional attributes
   }
// Runtime type identification
int routed_packaged_component::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = packaged_component::DynamicType(ID);
      }
   return result;
   }
routed_packaged_component *routed_packaged_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<routed_packaged_component *>(s);
      }
   return NULL;
   }
routed_packaged_component *routed_packaged_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<routed_packaged_component *>(s);
      }
   return NULL;
   }
// construction factory
routed_packaged_component *routed_packaged_component::Construct() {
   routed_packaged_component *result = NULL;

   // create the routed_packaged_component.
   result = new routed_packaged_component();
   return result;
   }
bool routed_packaged_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: routed_packaged_component\r\n");

   // Check for the existence of all required attributes
   if (_routed_shape == NULL) {
      TRACE("ERROR: _routed_shape a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (packaged_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
