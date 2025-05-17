// Source for AP210 application object
//     SetOfconnection_zone

// Precompiled include files
#include <StdAfx.h>

#include "SetOfconnection_zone.h"

// Classes
#include <connection_zone.h>

SetOfconnection_zone::SetOfconnection_zone() {
   initialize();
   }
SetOfconnection_zone::~SetOfconnection_zone() {
   // Free string attributes
   }
// intialize data members
void SetOfconnection_zone::initialize() {
   // Required attributes
   _connection_zone = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfconnection_zone::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfconnection_zone *SetOfconnection_zone::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfconnection_zone *>(s);
      }
   return NULL;
   }
SetOfconnection_zone *SetOfconnection_zone::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfconnection_zone *>(s);
      }
   return NULL;
   }
// construction factory
SetOfconnection_zone *SetOfconnection_zone::Construct() {
   SetOfconnection_zone *result = NULL;

   // create the SetOfconnection_zone.
   result = new SetOfconnection_zone();
   return result;
   }
bool SetOfconnection_zone::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfconnection_zone\r\n");

   // Check for the existence of all required attributes
   if (_connection_zone == NULL) {
      TRACE("ERROR: _connection_zone a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
