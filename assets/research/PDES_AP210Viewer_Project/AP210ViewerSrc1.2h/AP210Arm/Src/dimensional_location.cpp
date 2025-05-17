// Source for AP210 application object
//     dimensional_location

// Precompiled include files
#include <StdAfx.h>

#include "dimensional_location.h"

// Classes
#include <shape_element_locating_relationship.h>

dimensional_location::dimensional_location() {
   initialize();
   }
dimensional_location::~dimensional_location() {
   // Free string attributes
   }
// intialize data members
void dimensional_location::initialize() {
   // Required attributes
   _located_elements = NULL;

   // Optional attributes
   }
// Runtime type identification
int dimensional_location::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = dimensional_characteristic::DynamicType(ID);
      }
   return result;
   }
dimensional_location *dimensional_location::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<dimensional_location *>(s);
      }
   return NULL;
   }
dimensional_location *dimensional_location::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<dimensional_location *>(s);
      }
   return NULL;
   }
// construction factory
dimensional_location *dimensional_location::Construct() {
   dimensional_location *result = NULL;

   // create the dimensional_location.
   result = new dimensional_location();
   return result;
   }
bool dimensional_location::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: dimensional_location\r\n");

   // Check for the existence of all required attributes
   if (_located_elements == NULL) {
      TRACE("ERROR: _located_elements a required attribute is NULL!\r\n");
      result = false;
      }
   if (_directed == NULL) {
      TRACE("ERROR: _directed a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (dimensional_characteristic::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
