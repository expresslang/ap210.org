// Source for AP210 application object
//     SetOfproduct_object_select

// Precompiled include files
#include <StdAfx.h>

#include "SetOfproduct_object_select.h"

// Classes

SetOfproduct_object_select::SetOfproduct_object_select() {
   initialize();
   }
SetOfproduct_object_select::~SetOfproduct_object_select() {
   // Free string attributes
   }
// intialize data members
void SetOfproduct_object_select::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int SetOfproduct_object_select::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfproduct_object_select *SetOfproduct_object_select::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfproduct_object_select *>(s);
      }
   return NULL;
   }
SetOfproduct_object_select *SetOfproduct_object_select::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfproduct_object_select *>(s);
      }
   return NULL;
   }
// construction factory
SetOfproduct_object_select *SetOfproduct_object_select::Construct() {
   SetOfproduct_object_select *result = NULL;

   // create the SetOfproduct_object_select.
   result = new SetOfproduct_object_select();
   return result;
   }
bool SetOfproduct_object_select::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfproduct_object_select\r\n");

   // Check for the existence of all required attributes
   if (_product_object_select == NULL) {
      TRACE("ERROR: _product_object_select a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
