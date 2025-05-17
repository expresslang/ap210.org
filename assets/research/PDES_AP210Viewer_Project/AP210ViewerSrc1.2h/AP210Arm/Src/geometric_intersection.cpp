// Source for AP210 application object
//     geometric_intersection

// Precompiled include files
#include <StdAfx.h>

#include "geometric_intersection.h"

// Classes

geometric_intersection::geometric_intersection() {
   initialize();
   }
geometric_intersection::~geometric_intersection() {
   // Free string attributes
   }
// intialize data members
void geometric_intersection::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int geometric_intersection::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = derived_shape_element::DynamicType(ID);
      }
   return result;
   }
geometric_intersection *geometric_intersection::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<geometric_intersection *>(s);
      }
   return NULL;
   }
geometric_intersection *geometric_intersection::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<geometric_intersection *>(s);
      }
   return NULL;
   }
// construction factory
geometric_intersection *geometric_intersection::Construct() {
   geometric_intersection *result = NULL;

   // create the geometric_intersection.
   result = new geometric_intersection();
   return result;
   }
bool geometric_intersection::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: geometric_intersection\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (derived_shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
