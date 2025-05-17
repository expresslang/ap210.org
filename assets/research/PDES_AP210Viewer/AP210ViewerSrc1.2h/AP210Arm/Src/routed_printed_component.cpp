// Source for AP210 application object
//     routed_printed_component

// Precompiled include files
#include <StdAfx.h>

#include "routed_printed_component.h"

// Classes
#include <feature_shape_definition.h>
#include <inter_stratum_extent.h>

routed_printed_component::routed_printed_component() {
   initialize();
   }
routed_printed_component::~routed_printed_component() {
   // Free string attributes
   }
// intialize data members
void routed_printed_component::initialize() {
   // Required attributes
   _routed_shape = NULL;
   _component_extent = NULL;

   // Optional attributes
   }
// Runtime type identification
int routed_printed_component::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = laminate_component::DynamicType(ID);
      }
   return result;
   }
routed_printed_component *routed_printed_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<routed_printed_component *>(s);
      }
   return NULL;
   }
routed_printed_component *routed_printed_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<routed_printed_component *>(s);
      }
   return NULL;
   }
// construction factory
routed_printed_component *routed_printed_component::Construct() {
   routed_printed_component *result = NULL;

   // create the routed_printed_component.
   result = new routed_printed_component();
   return result;
   }
bool routed_printed_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: routed_printed_component\r\n");

   // Check for the existence of all required attributes
   if (_routed_shape == NULL) {
      TRACE("ERROR: _routed_shape a required attribute is NULL!\r\n");
      result = false;
      }
   if (_component_extent == NULL) {
      TRACE("ERROR: _component_extent a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (laminate_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
