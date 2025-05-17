// Source for AP210 application object
//     blind_via

// Precompiled include files
#include <StdAfx.h>

#include "blind_via.h"

// Classes

blind_via::blind_via() {
   initialize();
   }
blind_via::~blind_via() {
   // Free string attributes
   }
// intialize data members
void blind_via::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int blind_via::DynamicType(int ID) {
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
blind_via *blind_via::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<blind_via *>(s);
      }
   return NULL;
   }
blind_via *blind_via::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<blind_via *>(s);
      }
   return NULL;
   }
// construction factory
blind_via *blind_via::Construct() {
   blind_via *result = NULL;

   // create the blind_via.
   result = new blind_via();
   return result;
   }
bool blind_via::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: blind_via\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (via::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
