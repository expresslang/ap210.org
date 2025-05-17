// Source for AP210 application object
//     SetOfee_product

// Precompiled include files
#include <StdAfx.h>

#include "SetOfee_product.h"

// Classes
#include <ee_product.h>

SetOfee_product::SetOfee_product() {
   initialize();
   }
SetOfee_product::~SetOfee_product() {
   // Free string attributes
   }
// intialize data members
void SetOfee_product::initialize() {
   // Required attributes
   _ee_product = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfee_product::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfee_product *SetOfee_product::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfee_product *>(s);
      }
   return NULL;
   }
SetOfee_product *SetOfee_product::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfee_product *>(s);
      }
   return NULL;
   }
// construction factory
SetOfee_product *SetOfee_product::Construct() {
   SetOfee_product *result = NULL;

   // create the SetOfee_product.
   result = new SetOfee_product();
   return result;
   }
bool SetOfee_product::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfee_product\r\n");

   // Check for the existence of all required attributes
   if (_ee_product == NULL) {
      TRACE("ERROR: _ee_product a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
