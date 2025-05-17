// Source for AP210 application object
//     connection_zone_based_assembly_joint

// Precompiled include files
#include <StdAfx.h>

#include "connection_zone_based_assembly_joint.h"

// Classes
#include <connection_zone.h>
#include <connection_zone.h>

connection_zone_based_assembly_joint::connection_zone_based_assembly_joint() {
   initialize();
   }
connection_zone_based_assembly_joint::~connection_zone_based_assembly_joint() {
   // Free string attributes
   }
// intialize data members
void connection_zone_based_assembly_joint::initialize() {
   // Required attributes
   _zone_1 = NULL;
   _zone_2 = NULL;

   // Optional attributes
   }
// Runtime type identification
int connection_zone_based_assembly_joint::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = assembly_joint::DynamicType(ID);
      }
   return result;
   }
connection_zone_based_assembly_joint *connection_zone_based_assembly_joint::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<connection_zone_based_assembly_joint *>(s);
      }
   return NULL;
   }
connection_zone_based_assembly_joint *connection_zone_based_assembly_joint::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<connection_zone_based_assembly_joint *>(s);
      }
   return NULL;
   }
// construction factory
connection_zone_based_assembly_joint *connection_zone_based_assembly_joint::Construct() {
   connection_zone_based_assembly_joint *result = NULL;

   // create the connection_zone_based_assembly_joint.
   result = new connection_zone_based_assembly_joint();
   return result;
   }
bool connection_zone_based_assembly_joint::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: connection_zone_based_assembly_joint\r\n");

   // Check for the existence of all required attributes
   if (_zone_1 == NULL) {
      TRACE("ERROR: _zone_1 a required attribute is NULL!\r\n");
      result = false;
      }
   if (_zone_2 == NULL) {
      TRACE("ERROR: _zone_2 a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (assembly_joint::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
