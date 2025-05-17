// Source for AP210 application object
//     right_circular_cylinder

// Precompiled include files
#include <StdAfx.h>

#include "right_circular_cylinder.h"

// Classes

right_circular_cylinder::right_circular_cylinder() {
   initialize();
   }
right_circular_cylinder::~right_circular_cylinder() {
   // Free string attributes
   }
// intialize data members
void right_circular_cylinder::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int right_circular_cylinder::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = csg_primitive::DynamicType(ID);
      }
   return result;
   }
right_circular_cylinder *right_circular_cylinder::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<right_circular_cylinder *>(s);
      }
   return NULL;
   }
right_circular_cylinder *right_circular_cylinder::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<right_circular_cylinder *>(s);
      }
   return NULL;
   }
// construction factory
right_circular_cylinder *right_circular_cylinder::Construct() {
   right_circular_cylinder *result = NULL;

   // create the right_circular_cylinder.
   result = new right_circular_cylinder();
   return result;
   }
bool right_circular_cylinder::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: right_circular_cylinder\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (csg_primitive::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
