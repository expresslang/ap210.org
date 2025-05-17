// Source for AP210 application object
//     SetOflength_data_element

// Precompiled include files
#include <StdAfx.h>

#include "SetOflength_data_element.h"

// Classes
#include <length_data_element.h>

SetOflength_data_element::SetOflength_data_element() {
   initialize();
   }
SetOflength_data_element::~SetOflength_data_element() {
   // Free string attributes
   }
// intialize data members
void SetOflength_data_element::initialize() {
   // Required attributes
   _length_data_element = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOflength_data_element::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOflength_data_element *SetOflength_data_element::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOflength_data_element *>(s);
      }
   return NULL;
   }
SetOflength_data_element *SetOflength_data_element::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOflength_data_element *>(s);
      }
   return NULL;
   }
// construction factory
SetOflength_data_element *SetOflength_data_element::Construct() {
   SetOflength_data_element *result = NULL;

   // create the SetOflength_data_element.
   result = new SetOflength_data_element();
   return result;
   }
bool SetOflength_data_element::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOflength_data_element\r\n");

   // Check for the existence of all required attributes
   if (_length_data_element == NULL) {
      TRACE("ERROR: _length_data_element a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
