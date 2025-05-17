// Source for AP210 application object
//     functional_unit_network_definition

// Precompiled include files
#include <StdAfx.h>

#include "functional_unit_network_definition.h"

// Classes
#include <functional_unit_usage_view.h>

functional_unit_network_definition::functional_unit_network_definition() {
   initialize();
   }
functional_unit_network_definition::~functional_unit_network_definition() {
   // Free string attributes
   }
// intialize data members
void functional_unit_network_definition::initialize() {
   // Required attributes
   _usage_view = NULL;

   // Optional attributes
   }
// Runtime type identification
int functional_unit_network_definition::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = functional_unit_definition::DynamicType(ID);
      }
   return result;
   }
functional_unit_network_definition *functional_unit_network_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<functional_unit_network_definition *>(s);
      }
   return NULL;
   }
functional_unit_network_definition *functional_unit_network_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<functional_unit_network_definition *>(s);
      }
   return NULL;
   }
// construction factory
functional_unit_network_definition *functional_unit_network_definition::Construct() {
   functional_unit_network_definition *result = NULL;

   // create the functional_unit_network_definition.
   result = new functional_unit_network_definition();
   return result;
   }
bool functional_unit_network_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: functional_unit_network_definition\r\n");

   // Check for the existence of all required attributes
   if (_usage_view == NULL) {
      TRACE("ERROR: _usage_view a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (functional_unit_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
