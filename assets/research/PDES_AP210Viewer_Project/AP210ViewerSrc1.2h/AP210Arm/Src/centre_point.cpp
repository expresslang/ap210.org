// Source for AP210 application object
//     centre_point

// Precompiled include files
#include <StdAfx.h>

#include "centre_point.h"

// Classes

centre_point::centre_point() {
   initialize();
   }
centre_point::~centre_point() {
   // Free string attributes
   }
// intialize data members
void centre_point::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int centre_point::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = centre_of_symmetry::DynamicType(ID);
      }
   return result;
   }
centre_point *centre_point::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<centre_point *>(s);
      }
   return NULL;
   }
centre_point *centre_point::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<centre_point *>(s);
      }
   return NULL;
   }
// construction factory
centre_point *centre_point::Construct() {
   centre_point *result = NULL;

   // create the centre_point.
   result = new centre_point();
   return result;
   }
bool centre_point::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: centre_point\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (centre_of_symmetry::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
