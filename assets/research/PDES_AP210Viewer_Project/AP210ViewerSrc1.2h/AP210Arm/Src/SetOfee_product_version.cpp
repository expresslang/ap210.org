// Source for AP210 application object
//     SetOfee_product_version

// Precompiled include files
#include <StdAfx.h>

#include "SetOfee_product_version.h"

// Classes
#include <ee_product_version.h>

SetOfee_product_version::SetOfee_product_version() {
   initialize();
   }
SetOfee_product_version::~SetOfee_product_version() {
   // Free string attributes
   }
// intialize data members
void SetOfee_product_version::initialize() {
   // Required attributes
   _ee_product_version = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfee_product_version::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfee_product_version *SetOfee_product_version::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfee_product_version *>(s);
      }
   return NULL;
   }
SetOfee_product_version *SetOfee_product_version::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfee_product_version *>(s);
      }
   return NULL;
   }
// construction factory
SetOfee_product_version *SetOfee_product_version::Construct() {
   SetOfee_product_version *result = NULL;

   // create the SetOfee_product_version.
   result = new SetOfee_product_version();
   return result;
   }
bool SetOfee_product_version::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfee_product_version\r\n");

   // Check for the existence of all required attributes
   if (_ee_product_version == NULL) {
      TRACE("ERROR: _ee_product_version a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
