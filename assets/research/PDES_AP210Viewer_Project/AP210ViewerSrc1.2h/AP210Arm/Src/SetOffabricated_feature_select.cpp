// Source for AP210 application object
//     SetOffabricated_feature_select

// Precompiled include files
#include <StdAfx.h>

#include "SetOffabricated_feature_select.h"

// Classes

SetOffabricated_feature_select::SetOffabricated_feature_select() {
   initialize();
   }
SetOffabricated_feature_select::~SetOffabricated_feature_select() {
   // Free string attributes
   }
// intialize data members
void SetOffabricated_feature_select::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int SetOffabricated_feature_select::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOffabricated_feature_select *SetOffabricated_feature_select::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOffabricated_feature_select *>(s);
      }
   return NULL;
   }
SetOffabricated_feature_select *SetOffabricated_feature_select::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOffabricated_feature_select *>(s);
      }
   return NULL;
   }
// construction factory
SetOffabricated_feature_select *SetOffabricated_feature_select::Construct() {
   SetOffabricated_feature_select *result = NULL;

   // create the SetOffabricated_feature_select.
   result = new SetOffabricated_feature_select();
   return result;
   }
bool SetOffabricated_feature_select::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOffabricated_feature_select\r\n");

   // Check for the existence of all required attributes
   if (_fabricated_feature_select == NULL) {
      TRACE("ERROR: _fabricated_feature_select a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
