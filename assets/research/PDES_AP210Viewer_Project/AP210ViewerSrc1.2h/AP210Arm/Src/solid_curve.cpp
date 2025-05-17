// Source for AP210 application object
//     solid_curve

// Precompiled include files
#include <StdAfx.h>

#include "solid_curve.h"

// Classes

solid_curve::solid_curve() {
   initialize();
   }
solid_curve::~solid_curve() {
   // Free string attributes
   }
// intialize data members
void solid_curve::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int solid_curve::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = managed_design_object::DynamicType(ID);
      }
   return result;
   }
solid_curve *solid_curve::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<solid_curve *>(s);
      }
   return NULL;
   }
solid_curve *solid_curve::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<solid_curve *>(s);
      }
   return NULL;
   }
// construction factory
solid_curve *solid_curve::Construct() {
   solid_curve *result = NULL;

   // create the solid_curve.
   result = new solid_curve();
   return result;
   }
bool solid_curve::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: solid_curve\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
