// Source for AP210 application object
//     minimum_dimension_representation

// Precompiled include files
#include <StdAfx.h>

#include "minimum_dimension_representation.h"

// Classes

minimum_dimension_representation::minimum_dimension_representation() {
   initialize();
   }
minimum_dimension_representation::~minimum_dimension_representation() {
   // Free string attributes
   }
// intialize data members
void minimum_dimension_representation::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int minimum_dimension_representation::DynamicType(int ID) {
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
minimum_dimension_representation *minimum_dimension_representation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<minimum_dimension_representation *>(s);
      }
   return NULL;
   }
minimum_dimension_representation *minimum_dimension_representation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<minimum_dimension_representation *>(s);
      }
   return NULL;
   }
// construction factory
minimum_dimension_representation *minimum_dimension_representation::Construct() {
   minimum_dimension_representation *result = NULL;

   // create the minimum_dimension_representation.
   result = new minimum_dimension_representation();
   return result;
   }
bool minimum_dimension_representation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: minimum_dimension_representation\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (singular_dimension_representation::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
