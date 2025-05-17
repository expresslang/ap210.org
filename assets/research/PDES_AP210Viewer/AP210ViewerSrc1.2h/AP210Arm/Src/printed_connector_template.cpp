// Source for AP210 application object
//     printed_connector_template

// Precompiled include files
#include <StdAfx.h>

#include "printed_connector_template.h"

// Classes

printed_connector_template::printed_connector_template() {
   initialize();
   }
printed_connector_template::~printed_connector_template() {
   // Free string attributes
   }
// intialize data members
void printed_connector_template::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int printed_connector_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = printed_part_template::DynamicType(ID);
      }
   return result;
   }
printed_connector_template *printed_connector_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<printed_connector_template *>(s);
      }
   return NULL;
   }
printed_connector_template *printed_connector_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<printed_connector_template *>(s);
      }
   return NULL;
   }
// construction factory
printed_connector_template *printed_connector_template::Construct() {
   printed_connector_template *result = NULL;

   // create the printed_connector_template.
   result = new printed_connector_template();
   return result;
   }
bool printed_connector_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: printed_connector_template\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (printed_part_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
