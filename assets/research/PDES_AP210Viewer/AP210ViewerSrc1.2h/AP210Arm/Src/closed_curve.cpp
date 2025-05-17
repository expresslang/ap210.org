// Source for AP210 application object
//     closed_curve

// Precompiled include files
#include <StdAfx.h>

#include "closed_curve.h"

// Classes

closed_curve::closed_curve() {
   initialize();
   }
closed_curve::~closed_curve() {
   // Free string attributes
   }
// intialize data members
void closed_curve::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int closed_curve::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = curve::DynamicType(ID);
      }
   return result;
   }
closed_curve *closed_curve::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<closed_curve *>(s);
      }
   return NULL;
   }
closed_curve *closed_curve::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<closed_curve *>(s);
      }
   return NULL;
   }
// construction factory
closed_curve *closed_curve::Construct() {
   closed_curve *result = NULL;

   // create the closed_curve.
   result = new closed_curve();
   return result;
   }
bool closed_curve::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: closed_curve\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (curve::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
