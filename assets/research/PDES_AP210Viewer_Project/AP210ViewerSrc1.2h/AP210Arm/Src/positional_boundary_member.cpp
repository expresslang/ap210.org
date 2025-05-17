// Source for AP210 application object
//     positional_boundary_member

// Precompiled include files
#include <StdAfx.h>

#include "positional_boundary_member.h"

// Classes

positional_boundary_member::positional_boundary_member() {
   initialize();
   }
positional_boundary_member::~positional_boundary_member() {
   // Free string attributes
   }
// intialize data members
void positional_boundary_member::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int positional_boundary_member::DynamicType(int ID) {
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
positional_boundary_member *positional_boundary_member::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<positional_boundary_member *>(s);
      }
   return NULL;
   }
positional_boundary_member *positional_boundary_member::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<positional_boundary_member *>(s);
      }
   return NULL;
   }
// construction factory
positional_boundary_member *positional_boundary_member::Construct() {
   positional_boundary_member *result = NULL;

   // create the positional_boundary_member.
   result = new positional_boundary_member();
   return result;
   }
bool positional_boundary_member::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: positional_boundary_member\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (non_feature_shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
