// Source for AP210 application object
//     shield

// Precompiled include files
#include <StdAfx.h>

#include "shield.h"

// Classes

shield::shield() {
   initialize();
   }
shield::~shield() {
   // Free string attributes
   }
// intialize data members
void shield::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int shield::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = assembly_component::DynamicType(ID);
      }
   return result;
   }
shield *shield::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<shield *>(s);
      }
   return NULL;
   }
shield *shield::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<shield *>(s);
      }
   return NULL;
   }
// construction factory
shield *shield::Construct() {
   shield *result = NULL;

   // create the shield.
   result = new shield();
   return result;
   }
bool shield::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: shield\r\n");

   // Check for the existence of all required attributes
   if (_shielded_item == NULL) {
      TRACE("ERROR: _shielded_item a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (assembly_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
