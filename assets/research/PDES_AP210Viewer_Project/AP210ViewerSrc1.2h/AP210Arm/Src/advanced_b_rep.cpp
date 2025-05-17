// Source for AP210 application object
//     advanced_b_rep

// Precompiled include files
#include <StdAfx.h>

#include "advanced_b_rep.h"

// Classes

advanced_b_rep::advanced_b_rep() {
   initialize();
   }
advanced_b_rep::~advanced_b_rep() {
   // Free string attributes
   }
// intialize data members
void advanced_b_rep::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int advanced_b_rep::DynamicType(int ID) {
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
advanced_b_rep *advanced_b_rep::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<advanced_b_rep *>(s);
      }
   return NULL;
   }
advanced_b_rep *advanced_b_rep::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<advanced_b_rep *>(s);
      }
   return NULL;
   }
// construction factory
advanced_b_rep *advanced_b_rep::Construct() {
   advanced_b_rep *result = NULL;

   // create the advanced_b_rep.
   result = new advanced_b_rep();
   return result;
   }
bool advanced_b_rep::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: advanced_b_rep\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (bound_volume_shape::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
