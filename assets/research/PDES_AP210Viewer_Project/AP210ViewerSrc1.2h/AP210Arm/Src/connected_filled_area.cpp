// Source for AP210 application object
//     connected_filled_area

// Precompiled include files
#include <StdAfx.h>

#include "connected_filled_area.h"

// Classes
#include <intra_stratum_join_relationship.h>

connected_filled_area::connected_filled_area() {
   initialize();
   }
connected_filled_area::~connected_filled_area() {
   // Free string attributes
   }
// intialize data members
void connected_filled_area::initialize() {
   // Required attributes
   _implementation_requirement = NULL;

   // Optional attributes
   }
// Runtime type identification
int connected_filled_area::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = conductive_filled_area::DynamicType(ID);
      }
   return result;
   }
connected_filled_area *connected_filled_area::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<connected_filled_area *>(s);
      }
   return NULL;
   }
connected_filled_area *connected_filled_area::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<connected_filled_area *>(s);
      }
   return NULL;
   }
// construction factory
connected_filled_area *connected_filled_area::Construct() {
   connected_filled_area *result = NULL;

   // create the connected_filled_area.
   result = new connected_filled_area();
   return result;
   }
bool connected_filled_area::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: connected_filled_area\r\n");

   // Check for the existence of all required attributes
   if (_implementation_requirement == NULL) {
      TRACE("ERROR: _implementation_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (conductive_filled_area::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
