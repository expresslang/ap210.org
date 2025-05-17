// Source for AP210 application object
//     shape_element

// Precompiled include files
#include <StdAfx.h>

#include "shape_element.h"

// Classes

shape_element::shape_element() {
   initialize();
   }
shape_element::~shape_element() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   if (_description != NULL) {
      free(_description);
     }
   }
// intialize data members
void shape_element::initialize() {
   // Required attributes
   _name = NULL;

   // Optional attributes
   _description = NULL;
   }
// Runtime type identification
int shape_element::DynamicType(int ID) {
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
shape_element *shape_element::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<shape_element *>(s);
      }
   return NULL;
   }
shape_element *shape_element::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<shape_element *>(s);
      }
   return NULL;
   }
// construction factory
shape_element *shape_element::Construct() {
   shape_element *result = NULL;

   // create the shape_element.
   result = new shape_element();
   return result;
   }
bool shape_element::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: shape_element\r\n");

   // Check for the existence of all required attributes
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
