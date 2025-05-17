// Source for AP210 application object
//     maximum_dimension_representation

// Precompiled include files
#include <StdAfx.h>

#include "maximum_dimension_representation.h"

// Classes

maximum_dimension_representation::maximum_dimension_representation() {
   initialize();
   }
maximum_dimension_representation::~maximum_dimension_representation() {
   // Free string attributes
   }
// intialize data members
void maximum_dimension_representation::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int maximum_dimension_representation::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = singular_dimension_representation::DynamicType(ID);
      }
   return result;
   }
maximum_dimension_representation *maximum_dimension_representation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<maximum_dimension_representation *>(s);
      }
   return NULL;
   }
maximum_dimension_representation *maximum_dimension_representation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<maximum_dimension_representation *>(s);
      }
   return NULL;
   }
// construction factory
maximum_dimension_representation *maximum_dimension_representation::Construct() {
   maximum_dimension_representation *result = NULL;

   // create the maximum_dimension_representation.
   result = new maximum_dimension_representation();
   return result;
   }
bool maximum_dimension_representation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: maximum_dimension_representation\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (singular_dimension_representation::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
