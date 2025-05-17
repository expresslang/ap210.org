// Source for AP210 application object
//     SetOflayer_connection_point

// Precompiled include files
#include <StdAfx.h>

#include "SetOflayer_connection_point.h"

// Classes
#include <layer_connection_point.h>

SetOflayer_connection_point::SetOflayer_connection_point() {
   initialize();
   }
SetOflayer_connection_point::~SetOflayer_connection_point() {
   // Free string attributes
   }
// intialize data members
void SetOflayer_connection_point::initialize() {
   // Required attributes
   _layer_connection_point = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOflayer_connection_point::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOflayer_connection_point *SetOflayer_connection_point::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOflayer_connection_point *>(s);
      }
   return NULL;
   }
SetOflayer_connection_point *SetOflayer_connection_point::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOflayer_connection_point *>(s);
      }
   return NULL;
   }
// construction factory
SetOflayer_connection_point *SetOflayer_connection_point::Construct() {
   SetOflayer_connection_point *result = NULL;

   // create the SetOflayer_connection_point.
   result = new SetOflayer_connection_point();
   return result;
   }
bool SetOflayer_connection_point::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOflayer_connection_point\r\n");

   // Check for the existence of all required attributes
   if (_layer_connection_point == NULL) {
      TRACE("ERROR: _layer_connection_point a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
