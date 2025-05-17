// Source for AP210 application object
//     centre_axis

// Precompiled include files
#include <StdAfx.h>

#include "centre_axis.h"

// Classes

centre_axis::centre_axis() {
   initialize();
   }
centre_axis::~centre_axis() {
   // Free string attributes
   }
// intialize data members
void centre_axis::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int centre_axis::DynamicType(int ID) {
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
centre_axis *centre_axis::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<centre_axis *>(s);
      }
   return NULL;
   }
centre_axis *centre_axis::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<centre_axis *>(s);
      }
   return NULL;
   }
// construction factory
centre_axis *centre_axis::Construct() {
   centre_axis *result = NULL;

   // create the centre_axis.
   result = new centre_axis();
   return result;
   }
bool centre_axis::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: centre_axis\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (centre_of_symmetry::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
