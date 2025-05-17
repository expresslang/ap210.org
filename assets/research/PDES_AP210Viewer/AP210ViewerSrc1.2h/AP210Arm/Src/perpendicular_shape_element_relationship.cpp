// Source for AP210 application object
//     perpendicular_shape_element_relationship

// Precompiled include files
#include <StdAfx.h>

#include "perpendicular_shape_element_relationship.h"

// Classes

perpendicular_shape_element_relationship::perpendicular_shape_element_relationship() {
   initialize();
   }
perpendicular_shape_element_relationship::~perpendicular_shape_element_relationship() {
   // Free string attributes
   }
// intialize data members
void perpendicular_shape_element_relationship::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int perpendicular_shape_element_relationship::DynamicType(int ID) {
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
perpendicular_shape_element_relationship *perpendicular_shape_element_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<perpendicular_shape_element_relationship *>(s);
      }
   return NULL;
   }
perpendicular_shape_element_relationship *perpendicular_shape_element_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<perpendicular_shape_element_relationship *>(s);
      }
   return NULL;
   }
// construction factory
perpendicular_shape_element_relationship *perpendicular_shape_element_relationship::Construct() {
   perpendicular_shape_element_relationship *result = NULL;

   // create the perpendicular_shape_element_relationship.
   result = new perpendicular_shape_element_relationship();
   return result;
   }
bool perpendicular_shape_element_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: perpendicular_shape_element_relationship\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (shape_element_relationship::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
