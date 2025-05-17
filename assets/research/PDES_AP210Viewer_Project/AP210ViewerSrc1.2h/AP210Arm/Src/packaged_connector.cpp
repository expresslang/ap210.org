// Source for AP210 application object
//     packaged_connector

// Precompiled include files
#include <StdAfx.h>

#include "packaged_connector.h"

// Classes
#include <seating_plane.h>

packaged_connector::packaged_connector() {
   initialize();
   }
packaged_connector::~packaged_connector() {
   // Free string attributes
   }
// intialize data members
void packaged_connector::initialize() {
   // Required attributes

   // Optional attributes
   _interface_plane = NULL;
   }
// Runtime type identification
int packaged_connector::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = packaged_part::DynamicType(ID);
      }
   return result;
   }
packaged_connector *packaged_connector::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<packaged_connector *>(s);
      }
   return NULL;
   }
packaged_connector *packaged_connector::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<packaged_connector *>(s);
      }
   return NULL;
   }
// construction factory
packaged_connector *packaged_connector::Construct() {
   packaged_connector *result = NULL;

   // create the packaged_connector.
   result = new packaged_connector();
   return result;
   }
bool packaged_connector::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: packaged_connector\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (packaged_part::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
