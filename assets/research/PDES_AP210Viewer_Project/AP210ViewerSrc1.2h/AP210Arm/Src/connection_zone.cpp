// Source for AP210 application object
//     connection_zone

// Precompiled include files
#include <StdAfx.h>

#include "connection_zone.h"

// Classes
#include <ee_colour.h>

connection_zone::connection_zone() {
   initialize();
   }
connection_zone::~connection_zone() {
   // Free string attributes
   }
// intialize data members
void connection_zone::initialize() {
   // Required attributes
   _representation_colour = NULL;

   // Optional attributes
   }
// Runtime type identification
int connection_zone::DynamicType(int ID) {
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
connection_zone *connection_zone::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<connection_zone *>(s);
      }
   return NULL;
   }
connection_zone *connection_zone::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<connection_zone *>(s);
      }
   return NULL;
   }
// construction factory
connection_zone *connection_zone::Construct() {
   connection_zone *result = NULL;

   // create the connection_zone.
   result = new connection_zone();
   return result;
   }
bool connection_zone::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: connection_zone\r\n");

   // Check for the existence of all required attributes
   if (_representation_colour == NULL) {
      TRACE("ERROR: _representation_colour a required attribute is NULL!\r\n");
      result = false;
      }
   if (_zone_shape == NULL) {
      TRACE("ERROR: _zone_shape a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
