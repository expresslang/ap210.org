// Source for AP210 application object
//     SetOfcomponent_or_feature

// Precompiled include files
#include <StdAfx.h>

#include "SetOfcomponent_or_feature.h"

// Classes

SetOfcomponent_or_feature::SetOfcomponent_or_feature() {
   initialize();
   }
SetOfcomponent_or_feature::~SetOfcomponent_or_feature() {
   // Free string attributes
   }
// intialize data members
void SetOfcomponent_or_feature::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int SetOfcomponent_or_feature::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfcomponent_or_feature *SetOfcomponent_or_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfcomponent_or_feature *>(s);
      }
   return NULL;
   }
SetOfcomponent_or_feature *SetOfcomponent_or_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfcomponent_or_feature *>(s);
      }
   return NULL;
   }
// construction factory
SetOfcomponent_or_feature *SetOfcomponent_or_feature::Construct() {
   SetOfcomponent_or_feature *result = NULL;

   // create the SetOfcomponent_or_feature.
   result = new SetOfcomponent_or_feature();
   return result;
   }
bool SetOfcomponent_or_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfcomponent_or_feature\r\n");

   // Check for the existence of all required attributes
   if (_component_or_feature == NULL) {
      TRACE("ERROR: _component_or_feature a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
