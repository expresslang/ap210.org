// Source for AP210 application object
//     SetOfjoin_relationship

// Precompiled include files
#include <StdAfx.h>

#include "SetOfjoin_relationship.h"

// Classes
#include <join_relationship.h>

SetOfjoin_relationship::SetOfjoin_relationship() {
   initialize();
   }
SetOfjoin_relationship::~SetOfjoin_relationship() {
   // Free string attributes
   }
// intialize data members
void SetOfjoin_relationship::initialize() {
   // Required attributes
   _join_relationship = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfjoin_relationship::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfjoin_relationship *SetOfjoin_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfjoin_relationship *>(s);
      }
   return NULL;
   }
SetOfjoin_relationship *SetOfjoin_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfjoin_relationship *>(s);
      }
   return NULL;
   }
// construction factory
SetOfjoin_relationship *SetOfjoin_relationship::Construct() {
   SetOfjoin_relationship *result = NULL;

   // create the SetOfjoin_relationship.
   result = new SetOfjoin_relationship();
   return result;
   }
bool SetOfjoin_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfjoin_relationship\r\n");

   // Check for the existence of all required attributes
   if (_join_relationship == NULL) {
      TRACE("ERROR: _join_relationship a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
