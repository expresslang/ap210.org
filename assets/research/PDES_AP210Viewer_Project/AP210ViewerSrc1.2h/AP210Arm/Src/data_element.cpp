// Source for AP210 application object
//     data_element

// Precompiled include files
#include <StdAfx.h>

#include "data_element.h"

// Classes

data_element::data_element() {
   initialize();
   }
data_element::~data_element() {
   // Free string attributes
   if (_unit_of_measure != NULL) {
      free(_unit_of_measure);
     }
   }
// intialize data members
void data_element::initialize() {
   // Required attributes
   _unit_of_measure = NULL;

   // Optional attributes
   }
// Runtime type identification
int data_element::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = managed_design_object::DynamicType(ID);
      }
   return result;
   }
data_element *data_element::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<data_element *>(s);
      }
   return NULL;
   }
data_element *data_element::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<data_element *>(s);
      }
   return NULL;
   }
// construction factory
data_element *data_element::Construct() {
   data_element *result = NULL;

   // create the data_element.
   result = new data_element();
   return result;
   }
bool data_element::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: data_element\r\n");

   // Check for the existence of all required attributes
   if (_measure_value == NULL) {
      TRACE("ERROR: _measure_value a required attribute is NULL!\r\n");
      result = false;
      }
   if (_unit_of_measure == NULL) {
      TRACE("ERROR: _unit_of_measure a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
