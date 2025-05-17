// Source for AP210 application object
//     connection_zone_interface_plane_relationship

// Precompiled include files
#include <StdAfx.h>

#include "connection_zone_interface_plane_relationship.h"

// Classes
#include <seating_plane.h>
#include <connection_zone.h>

connection_zone_interface_plane_relationship::connection_zone_interface_plane_relationship() {
   initialize();
   }
connection_zone_interface_plane_relationship::~connection_zone_interface_plane_relationship() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void connection_zone_interface_plane_relationship::initialize() {
   // Required attributes
   _interface_plane = NULL;
   _mating_zone = NULL;
   _name = NULL;

   // Optional attributes
   }
// Runtime type identification
int connection_zone_interface_plane_relationship::DynamicType(int ID) {
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
connection_zone_interface_plane_relationship *connection_zone_interface_plane_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<connection_zone_interface_plane_relationship *>(s);
      }
   return NULL;
   }
connection_zone_interface_plane_relationship *connection_zone_interface_plane_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<connection_zone_interface_plane_relationship *>(s);
      }
   return NULL;
   }
// construction factory
connection_zone_interface_plane_relationship *connection_zone_interface_plane_relationship::Construct() {
   connection_zone_interface_plane_relationship *result = NULL;

   // create the connection_zone_interface_plane_relationship.
   result = new connection_zone_interface_plane_relationship();
   return result;
   }
bool connection_zone_interface_plane_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: connection_zone_interface_plane_relationship\r\n");

   // Check for the existence of all required attributes
   if (_interface_plane == NULL) {
      TRACE("ERROR: _interface_plane a required attribute is NULL!\r\n");
      result = false;
      }
   if (_mating_zone == NULL) {
      TRACE("ERROR: _mating_zone a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
