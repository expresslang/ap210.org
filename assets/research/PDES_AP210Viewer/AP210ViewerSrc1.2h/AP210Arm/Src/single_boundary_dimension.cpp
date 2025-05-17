// Source for AP210 application object
//     single_boundary_dimension

// Precompiled include files
#include <StdAfx.h>

#include "single_boundary_dimension.h"

// Classes

single_boundary_dimension::single_boundary_dimension() {
   initialize();
   }
single_boundary_dimension::~single_boundary_dimension() {
   // Free string attributes
   }
// intialize data members
void single_boundary_dimension::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int single_boundary_dimension::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = dimensional_size::DynamicType(ID);
      }
   return result;
   }
single_boundary_dimension *single_boundary_dimension::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<single_boundary_dimension *>(s);
      }
   return NULL;
   }
single_boundary_dimension *single_boundary_dimension::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<single_boundary_dimension *>(s);
      }
   return NULL;
   }
// construction factory
single_boundary_dimension *single_boundary_dimension::Construct() {
   single_boundary_dimension *result = NULL;

   // create the single_boundary_dimension.
   result = new single_boundary_dimension();
   return result;
   }
bool single_boundary_dimension::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: single_boundary_dimension\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (dimensional_size::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
