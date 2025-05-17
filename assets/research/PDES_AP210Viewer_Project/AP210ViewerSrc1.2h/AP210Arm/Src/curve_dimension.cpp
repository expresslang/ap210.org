// Source for AP210 application object
//     curve_dimension

// Precompiled include files
#include <StdAfx.h>

#include "curve_dimension.h"

// Classes

curve_dimension::curve_dimension() {
   initialize();
   }
curve_dimension::~curve_dimension() {
   // Free string attributes
   }
// intialize data members
void curve_dimension::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int curve_dimension::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = single_boundary_dimension::DynamicType(ID);
      }
   return result;
   }
curve_dimension *curve_dimension::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<curve_dimension *>(s);
      }
   return NULL;
   }
curve_dimension *curve_dimension::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<curve_dimension *>(s);
      }
   return NULL;
   }
// construction factory
curve_dimension *curve_dimension::Construct() {
   curve_dimension *result = NULL;

   // create the curve_dimension.
   result = new curve_dimension();
   return result;
   }
bool curve_dimension::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: curve_dimension\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (single_boundary_dimension::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
