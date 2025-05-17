// Source for AP210 application object
//     SetOfdatum_axis

// Precompiled include files
#include <StdAfx.h>

#include "SetOfdatum_axis.h"

// Classes
#include <datum_axis.h>

SetOfdatum_axis::SetOfdatum_axis() {
   initialize();
   }
SetOfdatum_axis::~SetOfdatum_axis() {
   // Free string attributes
   }
// intialize data members
void SetOfdatum_axis::initialize() {
   // Required attributes
   _datum_axis = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfdatum_axis::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfdatum_axis *SetOfdatum_axis::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfdatum_axis *>(s);
      }
   return NULL;
   }
SetOfdatum_axis *SetOfdatum_axis::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfdatum_axis *>(s);
      }
   return NULL;
   }
// construction factory
SetOfdatum_axis *SetOfdatum_axis::Construct() {
   SetOfdatum_axis *result = NULL;

   // create the SetOfdatum_axis.
   result = new SetOfdatum_axis();
   return result;
   }
bool SetOfdatum_axis::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfdatum_axis\r\n");

   // Check for the existence of all required attributes
   if (_datum_axis == NULL) {
      TRACE("ERROR: _datum_axis a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
