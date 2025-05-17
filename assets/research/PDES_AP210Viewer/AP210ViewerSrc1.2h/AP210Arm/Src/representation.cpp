// Source for AP210 application object
//     representation

// Precompiled include files
#include <StdAfx.h>

#include "representation.h"

// Classes

representation::representation() {
   initialize();
   }
representation::~representation() {
   // Free string attributes
   }
// intialize data members
void representation::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int representation::DynamicType(int ID) {
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
representation *representation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<representation *>(s);
      }
   return NULL;
   }
representation *representation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<representation *>(s);
      }
   return NULL;
   }
// construction factory
representation *representation::Construct() {
   representation *result = NULL;

   // create the representation.
   result = new representation();
   return result;
   }
bool representation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: representation\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
