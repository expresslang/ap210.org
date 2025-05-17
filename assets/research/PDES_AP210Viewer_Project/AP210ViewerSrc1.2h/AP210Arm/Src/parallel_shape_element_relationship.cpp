// Source for AP210 application object
//     parallel_shape_element_relationship

// Precompiled include files
#include <StdAfx.h>

#include "parallel_shape_element_relationship.h"

// Classes

parallel_shape_element_relationship::parallel_shape_element_relationship() {
   initialize();
   }
parallel_shape_element_relationship::~parallel_shape_element_relationship() {
   // Free string attributes
   }
// intialize data members
void parallel_shape_element_relationship::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int parallel_shape_element_relationship::DynamicType(int ID) {
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
parallel_shape_element_relationship *parallel_shape_element_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<parallel_shape_element_relationship *>(s);
      }
   return NULL;
   }
parallel_shape_element_relationship *parallel_shape_element_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<parallel_shape_element_relationship *>(s);
      }
   return NULL;
   }
// construction factory
parallel_shape_element_relationship *parallel_shape_element_relationship::Construct() {
   parallel_shape_element_relationship *result = NULL;

   // create the parallel_shape_element_relationship.
   result = new parallel_shape_element_relationship();
   return result;
   }
bool parallel_shape_element_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: parallel_shape_element_relationship\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (shape_element_relationship::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
