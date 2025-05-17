// Source for AP210 application object
//     SetOfassembled_feature_select

// Precompiled include files
#include <StdAfx.h>

#include "SetOfassembled_feature_select.h"

// Classes

SetOfassembled_feature_select::SetOfassembled_feature_select() {
   initialize();
   }
SetOfassembled_feature_select::~SetOfassembled_feature_select() {
   // Free string attributes
   }
// intialize data members
void SetOfassembled_feature_select::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int SetOfassembled_feature_select::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfassembled_feature_select *SetOfassembled_feature_select::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfassembled_feature_select *>(s);
      }
   return NULL;
   }
SetOfassembled_feature_select *SetOfassembled_feature_select::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfassembled_feature_select *>(s);
      }
   return NULL;
   }
// construction factory
SetOfassembled_feature_select *SetOfassembled_feature_select::Construct() {
   SetOfassembled_feature_select *result = NULL;

   // create the SetOfassembled_feature_select.
   result = new SetOfassembled_feature_select();
   return result;
   }
bool SetOfassembled_feature_select::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfassembled_feature_select\r\n");

   // Check for the existence of all required attributes
   if (_assembled_feature_select == NULL) {
      TRACE("ERROR: _assembled_feature_select a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
