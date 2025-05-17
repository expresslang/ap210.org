// Source for AP210 application object
//     shape_element_deriving_relationship

// Precompiled include files
#include <StdAfx.h>

#include "shape_element_deriving_relationship.h"

// Classes

shape_element_deriving_relationship::shape_element_deriving_relationship() {
   initialize();
   }
shape_element_deriving_relationship::~shape_element_deriving_relationship() {
   // Free string attributes
   }
// intialize data members
void shape_element_deriving_relationship::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int shape_element_deriving_relationship::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = shape_element_relationship::DynamicType(ID);
      }
   return result;
   }
shape_element_deriving_relationship *shape_element_deriving_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<shape_element_deriving_relationship *>(s);
      }
   return NULL;
   }
shape_element_deriving_relationship *shape_element_deriving_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<shape_element_deriving_relationship *>(s);
      }
   return NULL;
   }
// construction factory
shape_element_deriving_relationship *shape_element_deriving_relationship::Construct() {
   shape_element_deriving_relationship *result = NULL;

   // create the shape_element_deriving_relationship.
   result = new shape_element_deriving_relationship();
   return result;
   }
bool shape_element_deriving_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: shape_element_deriving_relationship\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (shape_element_relationship::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
