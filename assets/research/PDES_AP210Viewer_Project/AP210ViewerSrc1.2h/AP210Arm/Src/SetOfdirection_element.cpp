// Source for AP210 application object
//     SetOfdirection_element

// Precompiled include files
#include <StdAfx.h>

#include "SetOfdirection_element.h"

// Classes
#include <direction_element.h>

SetOfdirection_element::SetOfdirection_element() {
   initialize();
   }
SetOfdirection_element::~SetOfdirection_element() {
   // Free string attributes
   }
// intialize data members
void SetOfdirection_element::initialize() {
   // Required attributes
   _direction_element = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfdirection_element::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfdirection_element *SetOfdirection_element::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfdirection_element *>(s);
      }
   return NULL;
   }
SetOfdirection_element *SetOfdirection_element::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfdirection_element *>(s);
      }
   return NULL;
   }
// construction factory
SetOfdirection_element *SetOfdirection_element::Construct() {
   SetOfdirection_element *result = NULL;

   // create the SetOfdirection_element.
   result = new SetOfdirection_element();
   return result;
   }
bool SetOfdirection_element::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfdirection_element\r\n");

   // Check for the existence of all required attributes
   if (_direction_element == NULL) {
      TRACE("ERROR: _direction_element a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
