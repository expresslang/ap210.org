// Source for AP210 application object
//     cartesian_point

// Precompiled include files
#include <StdAfx.h>

#include "cartesian_point.h"

// Classes

cartesian_point::cartesian_point() {
   initialize();
   }
cartesian_point::~cartesian_point() {
   // Free string attributes
   }
// intialize data members
void cartesian_point::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int cartesian_point::DynamicType(int ID) {
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
cartesian_point *cartesian_point::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<cartesian_point *>(s);
      }
   return NULL;
   }
cartesian_point *cartesian_point::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<cartesian_point *>(s);
      }
   return NULL;
   }
// construction factory
cartesian_point *cartesian_point::Construct() {
   cartesian_point *result = NULL;

   // create the cartesian_point.
   result = new cartesian_point();
   return result;
   }
bool cartesian_point::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: cartesian_point\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
