// Source for AP210 application object
//     printed_connector_component

// Precompiled include files
#include <StdAfx.h>

#include "printed_connector_component.h"

// Classes

printed_connector_component::printed_connector_component() {
   initialize();
   }
printed_connector_component::~printed_connector_component() {
   // Free string attributes
   }
// intialize data members
void printed_connector_component::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int printed_connector_component::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = printed_component::DynamicType(ID);
      }
   return result;
   }
printed_connector_component *printed_connector_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<printed_connector_component *>(s);
      }
   return NULL;
   }
printed_connector_component *printed_connector_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<printed_connector_component *>(s);
      }
   return NULL;
   }
// construction factory
printed_connector_component *printed_connector_component::Construct() {
   printed_connector_component *result = NULL;

   // create the printed_connector_component.
   result = new printed_connector_component();
   return result;
   }
bool printed_connector_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: printed_connector_component\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (printed_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
