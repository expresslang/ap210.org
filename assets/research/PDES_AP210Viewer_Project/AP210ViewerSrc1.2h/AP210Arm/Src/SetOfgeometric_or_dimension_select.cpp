// Source for AP210 application object
//     SetOfgeometric_or_dimension_select

// Precompiled include files
#include <StdAfx.h>

#include "SetOfgeometric_or_dimension_select.h"

// Classes

SetOfgeometric_or_dimension_select::SetOfgeometric_or_dimension_select() {
   initialize();
   }
SetOfgeometric_or_dimension_select::~SetOfgeometric_or_dimension_select() {
   // Free string attributes
   }
// intialize data members
void SetOfgeometric_or_dimension_select::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int SetOfgeometric_or_dimension_select::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfgeometric_or_dimension_select *SetOfgeometric_or_dimension_select::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfgeometric_or_dimension_select *>(s);
      }
   return NULL;
   }
SetOfgeometric_or_dimension_select *SetOfgeometric_or_dimension_select::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfgeometric_or_dimension_select *>(s);
      }
   return NULL;
   }
// construction factory
SetOfgeometric_or_dimension_select *SetOfgeometric_or_dimension_select::Construct() {
   SetOfgeometric_or_dimension_select *result = NULL;

   // create the SetOfgeometric_or_dimension_select.
   result = new SetOfgeometric_or_dimension_select();
   return result;
   }
bool SetOfgeometric_or_dimension_select::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfgeometric_or_dimension_select\r\n");

   // Check for the existence of all required attributes
   if (_geometric_or_dimension_select == NULL) {
      TRACE("ERROR: _geometric_or_dimension_select a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
