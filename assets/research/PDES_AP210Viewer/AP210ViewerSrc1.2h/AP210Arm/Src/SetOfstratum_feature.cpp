// Source for AP210 application object
//     SetOfstratum_feature

// Precompiled include files
#include <StdAfx.h>

#include "SetOfstratum_feature.h"

// Classes
#include <stratum_feature.h>

SetOfstratum_feature::SetOfstratum_feature() {
   initialize();
   }
SetOfstratum_feature::~SetOfstratum_feature() {
   // Free string attributes
   }
// intialize data members
void SetOfstratum_feature::initialize() {
   // Required attributes
   _stratum_feature = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfstratum_feature::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfstratum_feature *SetOfstratum_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfstratum_feature *>(s);
      }
   return NULL;
   }
SetOfstratum_feature *SetOfstratum_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfstratum_feature *>(s);
      }
   return NULL;
   }
// construction factory
SetOfstratum_feature *SetOfstratum_feature::Construct() {
   SetOfstratum_feature *result = NULL;

   // create the SetOfstratum_feature.
   result = new SetOfstratum_feature();
   return result;
   }
bool SetOfstratum_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfstratum_feature\r\n");

   // Check for the existence of all required attributes
   if (_stratum_feature == NULL) {
      TRACE("ERROR: _stratum_feature a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
