// Source for AP210 application object
//     right_angular_wedge

// Precompiled include files
#include <StdAfx.h>

#include "right_angular_wedge.h"

// Classes

right_angular_wedge::right_angular_wedge() {
   initialize();
   }
right_angular_wedge::~right_angular_wedge() {
   // Free string attributes
   }
// intialize data members
void right_angular_wedge::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int right_angular_wedge::DynamicType(int ID) {
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
right_angular_wedge *right_angular_wedge::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<right_angular_wedge *>(s);
      }
   return NULL;
   }
right_angular_wedge *right_angular_wedge::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<right_angular_wedge *>(s);
      }
   return NULL;
   }
// construction factory
right_angular_wedge *right_angular_wedge::Construct() {
   right_angular_wedge *result = NULL;

   // create the right_angular_wedge.
   result = new right_angular_wedge();
   return result;
   }
bool right_angular_wedge::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: right_angular_wedge\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (csg_primitive::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
