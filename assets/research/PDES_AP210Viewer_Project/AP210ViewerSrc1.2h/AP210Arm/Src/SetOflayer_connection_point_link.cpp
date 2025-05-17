// Source for AP210 application object
//     SetOflayer_connection_point_link

// Precompiled include files
#include <StdAfx.h>

#include "SetOflayer_connection_point_link.h"

// Classes
#include <layer_connection_point_link.h>

SetOflayer_connection_point_link::SetOflayer_connection_point_link() {
   initialize();
   }
SetOflayer_connection_point_link::~SetOflayer_connection_point_link() {
   // Free string attributes
   }
// intialize data members
void SetOflayer_connection_point_link::initialize() {
   // Required attributes
   _layer_connection_point_link = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOflayer_connection_point_link::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOflayer_connection_point_link *SetOflayer_connection_point_link::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOflayer_connection_point_link *>(s);
      }
   return NULL;
   }
SetOflayer_connection_point_link *SetOflayer_connection_point_link::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOflayer_connection_point_link *>(s);
      }
   return NULL;
   }
// construction factory
SetOflayer_connection_point_link *SetOflayer_connection_point_link::Construct() {
   SetOflayer_connection_point_link *result = NULL;

   // create the SetOflayer_connection_point_link.
   result = new SetOflayer_connection_point_link();
   return result;
   }
bool SetOflayer_connection_point_link::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOflayer_connection_point_link\r\n");

   // Check for the existence of all required attributes
   if (_layer_connection_point_link == NULL) {
      TRACE("ERROR: _layer_connection_point_link a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
