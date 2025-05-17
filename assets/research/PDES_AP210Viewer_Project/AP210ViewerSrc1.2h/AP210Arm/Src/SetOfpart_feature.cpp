// Source for AP210 application object
//     SetOfpart_feature

// Precompiled include files
#include <StdAfx.h>

#include "SetOfpart_feature.h"

// Classes
#include <part_feature.h>

SetOfpart_feature::SetOfpart_feature() {
   initialize();
   }
SetOfpart_feature::~SetOfpart_feature() {
   // Free string attributes
   }
// intialize data members
void SetOfpart_feature::initialize() {
   // Required attributes
   _part_feature = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfpart_feature::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfpart_feature *SetOfpart_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfpart_feature *>(s);
      }
   return NULL;
   }
SetOfpart_feature *SetOfpart_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfpart_feature *>(s);
      }
   return NULL;
   }
// construction factory
SetOfpart_feature *SetOfpart_feature::Construct() {
   SetOfpart_feature *result = NULL;

   // create the SetOfpart_feature.
   result = new SetOfpart_feature();
   return result;
   }
bool SetOfpart_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfpart_feature\r\n");

   // Check for the existence of all required attributes
   if (_part_feature == NULL) {
      TRACE("ERROR: _part_feature a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
