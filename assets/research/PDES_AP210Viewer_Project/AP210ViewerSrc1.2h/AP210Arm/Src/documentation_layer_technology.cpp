// Source for AP210 application object
//     documentation_layer_technology

// Precompiled include files
#include <StdAfx.h>

#include "documentation_layer_technology.h"

// Classes

documentation_layer_technology::documentation_layer_technology() {
   initialize();
   }
documentation_layer_technology::~documentation_layer_technology() {
   // Free string attributes
   if (_documentation_layer_purpose != NULL) {
      free(_documentation_layer_purpose);
     }
   }
// intialize data members
void documentation_layer_technology::initialize() {
   // Required attributes
   _documentation_layer_purpose = NULL;

   // Optional attributes
   }
// Runtime type identification
int documentation_layer_technology::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = stratum_technology::DynamicType(ID);
      }
   return result;
   }
documentation_layer_technology *documentation_layer_technology::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<documentation_layer_technology *>(s);
      }
   return NULL;
   }
documentation_layer_technology *documentation_layer_technology::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<documentation_layer_technology *>(s);
      }
   return NULL;
   }
// construction factory
documentation_layer_technology *documentation_layer_technology::Construct() {
   documentation_layer_technology *result = NULL;

   // create the documentation_layer_technology.
   result = new documentation_layer_technology();
   return result;
   }
bool documentation_layer_technology::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: documentation_layer_technology\r\n");

   // Check for the existence of all required attributes
   if (_documentation_layer_purpose == NULL) {
      TRACE("ERROR: _documentation_layer_purpose a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (stratum_technology::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
