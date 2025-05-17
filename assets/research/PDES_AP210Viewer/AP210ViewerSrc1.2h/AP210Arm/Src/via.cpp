// Source for AP210 application object
//     via

// Precompiled include files
#include <StdAfx.h>

#include "via.h"

// Classes

via::via() {
   initialize();
   }
via::~via() {
   // Free string attributes
   }
// intialize data members
void via::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int via::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = plated_passage::DynamicType(ID);
      }
   return result;
   }
via *via::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<via *>(s);
      }
   return NULL;
   }
via *via::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<via *>(s);
      }
   return NULL;
   }
// construction factory
via *via::Construct() {
   via *result = NULL;

   // create the via.
   result = new via();
   return result;
   }
bool via::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: via\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (plated_passage::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
