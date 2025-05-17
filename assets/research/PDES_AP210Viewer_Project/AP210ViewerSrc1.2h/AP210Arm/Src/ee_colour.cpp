// Source for AP210 application object
//     ee_colour

// Precompiled include files
#include <StdAfx.h>

#include "ee_colour.h"

// Classes

ee_colour::ee_colour() {
   initialize();
   }
ee_colour::~ee_colour() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void ee_colour::initialize() {
   // Required attributes
   _name = NULL;

   // Optional attributes
   }
// Runtime type identification
int ee_colour::DynamicType(int ID) {
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
ee_colour *ee_colour::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_colour *>(s);
      }
   return NULL;
   }
ee_colour *ee_colour::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_colour *>(s);
      }
   return NULL;
   }
// construction factory
ee_colour *ee_colour::Construct() {
   ee_colour *result = NULL;

   // create the ee_colour.
   result = new ee_colour();
   return result;
   }
bool ee_colour::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_colour\r\n");

   // Check for the existence of all required attributes
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
