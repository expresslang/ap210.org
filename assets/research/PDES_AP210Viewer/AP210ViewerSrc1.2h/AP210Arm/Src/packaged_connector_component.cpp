// Source for AP210 application object
//     packaged_connector_component

// Precompiled include files
#include <StdAfx.h>

#include "packaged_connector_component.h"

// Classes

packaged_connector_component::packaged_connector_component() {
   initialize();
   }
packaged_connector_component::~packaged_connector_component() {
   // Free string attributes
   }
// intialize data members
void packaged_connector_component::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int packaged_connector_component::DynamicType(int ID) {
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
packaged_connector_component *packaged_connector_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<packaged_connector_component *>(s);
      }
   return NULL;
   }
packaged_connector_component *packaged_connector_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<packaged_connector_component *>(s);
      }
   return NULL;
   }
// construction factory
packaged_connector_component *packaged_connector_component::Construct() {
   packaged_connector_component *result = NULL;

   // create the packaged_connector_component.
   result = new packaged_connector_component();
   return result;
   }
bool packaged_connector_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: packaged_connector_component\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (packaged_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
