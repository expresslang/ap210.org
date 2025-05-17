// Source for AP210 application object
//     length_data_element

// Precompiled include files
#include <StdAfx.h>

#include "length_data_element.h"

// Classes

length_data_element::length_data_element() {
   initialize();
   }
length_data_element::~length_data_element() {
   // Free string attributes
   }
// intialize data members
void length_data_element::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int length_data_element::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = data_element::DynamicType(ID);
      }
   return result;
   }
length_data_element *length_data_element::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<length_data_element *>(s);
      }
   return NULL;
   }
length_data_element *length_data_element::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<length_data_element *>(s);
      }
   return NULL;
   }
// construction factory
length_data_element *length_data_element::Construct() {
   length_data_element *result = NULL;

   // create the length_data_element.
   result = new length_data_element();
   return result;
   }
bool length_data_element::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: length_data_element\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (data_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
