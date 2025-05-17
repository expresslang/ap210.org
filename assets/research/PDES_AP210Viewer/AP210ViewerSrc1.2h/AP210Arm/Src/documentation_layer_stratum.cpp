// Source for AP210 application object
//     documentation_layer_stratum

// Precompiled include files
#include <StdAfx.h>

#include "documentation_layer_stratum.h"

// Classes

documentation_layer_stratum::documentation_layer_stratum() {
   initialize();
   }
documentation_layer_stratum::~documentation_layer_stratum() {
   // Free string attributes
   }
// intialize data members
void documentation_layer_stratum::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int documentation_layer_stratum::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = stratum::DynamicType(ID);
      }
   return result;
   }
documentation_layer_stratum *documentation_layer_stratum::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<documentation_layer_stratum *>(s);
      }
   return NULL;
   }
documentation_layer_stratum *documentation_layer_stratum::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<documentation_layer_stratum *>(s);
      }
   return NULL;
   }
// construction factory
documentation_layer_stratum *documentation_layer_stratum::Construct() {
   documentation_layer_stratum *result = NULL;

   // create the documentation_layer_stratum.
   result = new documentation_layer_stratum();
   return result;
   }
bool documentation_layer_stratum::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: documentation_layer_stratum\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (stratum::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
