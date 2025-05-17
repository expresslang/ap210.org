// Source for AP210 application object
//     shape_dimension_representation

// Precompiled include files
#include <StdAfx.h>

#include "shape_dimension_representation.h"

// Classes

shape_dimension_representation::shape_dimension_representation() {
   initialize();
   }
shape_dimension_representation::~shape_dimension_representation() {
   // Free string attributes
   }
// intialize data members
void shape_dimension_representation::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int shape_dimension_representation::DynamicType(int ID) {
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
shape_dimension_representation *shape_dimension_representation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<shape_dimension_representation *>(s);
      }
   return NULL;
   }
shape_dimension_representation *shape_dimension_representation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<shape_dimension_representation *>(s);
      }
   return NULL;
   }
// construction factory
shape_dimension_representation *shape_dimension_representation::Construct() {
   shape_dimension_representation *result = NULL;

   // create the shape_dimension_representation.
   result = new shape_dimension_representation();
   return result;
   }
bool shape_dimension_representation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: shape_dimension_representation\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
