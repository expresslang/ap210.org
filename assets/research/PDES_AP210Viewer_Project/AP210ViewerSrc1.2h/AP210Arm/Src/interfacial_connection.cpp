// Source for AP210 application object
//     interfacial_connection

// Precompiled include files
#include <StdAfx.h>

#include "interfacial_connection.h"

// Classes

interfacial_connection::interfacial_connection() {
   initialize();
   }
interfacial_connection::~interfacial_connection() {
   // Free string attributes
   }
// intialize data members
void interfacial_connection::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int interfacial_connection::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = via::DynamicType(ID);
      }
   return result;
   }
interfacial_connection *interfacial_connection::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interfacial_connection *>(s);
      }
   return NULL;
   }
interfacial_connection *interfacial_connection::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interfacial_connection *>(s);
      }
   return NULL;
   }
// construction factory
interfacial_connection *interfacial_connection::Construct() {
   interfacial_connection *result = NULL;

   // create the interfacial_connection.
   result = new interfacial_connection();
   return result;
   }
bool interfacial_connection::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interfacial_connection\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (via::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
