// Source for AP210 application object
//     positional_boundary

// Precompiled include files
#include <StdAfx.h>

#include "positional_boundary.h"

// Classes

positional_boundary::positional_boundary() {
   initialize();
   }
positional_boundary::~positional_boundary() {
   // Free string attributes
   }
// intialize data members
void positional_boundary::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int positional_boundary::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = non_feature_shape_element::DynamicType(ID);
      }
   return result;
   }
positional_boundary *positional_boundary::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<positional_boundary *>(s);
      }
   return NULL;
   }
positional_boundary *positional_boundary::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<positional_boundary *>(s);
      }
   return NULL;
   }
// construction factory
positional_boundary *positional_boundary::Construct() {
   positional_boundary *result = NULL;

   // create the positional_boundary.
   result = new positional_boundary();
   return result;
   }
bool positional_boundary::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: positional_boundary\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (non_feature_shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
