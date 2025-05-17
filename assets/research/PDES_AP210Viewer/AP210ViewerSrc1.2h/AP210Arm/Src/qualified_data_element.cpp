// Source for AP210 application object
//     qualified_data_element

// Precompiled include files
#include <StdAfx.h>

#include "qualified_data_element.h"

// Classes

qualified_data_element::qualified_data_element() {
   initialize();
   }
qualified_data_element::~qualified_data_element() {
   // Free string attributes
   }
// intialize data members
void qualified_data_element::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int qualified_data_element::DynamicType(int ID) {
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
qualified_data_element *qualified_data_element::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<qualified_data_element *>(s);
      }
   return NULL;
   }
qualified_data_element *qualified_data_element::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<qualified_data_element *>(s);
      }
   return NULL;
   }
// construction factory
qualified_data_element *qualified_data_element::Construct() {
   qualified_data_element *result = NULL;

   // create the qualified_data_element.
   result = new qualified_data_element();
   return result;
   }
bool qualified_data_element::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: qualified_data_element\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (data_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
