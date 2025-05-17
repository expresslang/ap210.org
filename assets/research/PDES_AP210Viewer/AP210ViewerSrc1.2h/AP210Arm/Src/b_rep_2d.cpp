// Source for AP210 application object
//     b_rep_2d

// Precompiled include files
#include <StdAfx.h>

#include "b_rep_2d.h"

// Classes

b_rep_2d::b_rep_2d() {
   initialize();
   }
b_rep_2d::~b_rep_2d() {
   // Free string attributes
   }
// intialize data members
void b_rep_2d::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int b_rep_2d::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = bound_volume_shape::DynamicType(ID);
      }
   return result;
   }
b_rep_2d *b_rep_2d::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<b_rep_2d *>(s);
      }
   return NULL;
   }
b_rep_2d *b_rep_2d::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<b_rep_2d *>(s);
      }
   return NULL;
   }
// construction factory
b_rep_2d *b_rep_2d::Construct() {
   b_rep_2d *result = NULL;

   // create the b_rep_2d.
   result = new b_rep_2d();
   return result;
   }
bool b_rep_2d::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: b_rep_2d\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (bound_volume_shape::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
