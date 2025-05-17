// Source for AP210 application object
//     curve

// Precompiled include files
#include <StdAfx.h>

#include "curve.h"

// Classes

curve::curve() {
   initialize();
   }
curve::~curve() {
   // Free string attributes
   }
// intialize data members
void curve::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int curve::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = feature_shape_definition::DynamicType(ID);
      }
   return result;
   }
curve *curve::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<curve *>(s);
      }
   return NULL;
   }
curve *curve::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<curve *>(s);
      }
   return NULL;
   }
// construction factory
curve *curve::Construct() {
   curve *result = NULL;

   // create the curve.
   result = new curve();
   return result;
   }
bool curve::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: curve\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (feature_shape_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
