// Source for AP210 application object
//     centre_of_symmetry

// Precompiled include files
#include <StdAfx.h>

#include "centre_of_symmetry.h"

// Classes

centre_of_symmetry::centre_of_symmetry() {
   initialize();
   }
centre_of_symmetry::~centre_of_symmetry() {
   // Free string attributes
   }
// intialize data members
void centre_of_symmetry::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int centre_of_symmetry::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = derived_shape_element::DynamicType(ID);
      }
   return result;
   }
centre_of_symmetry *centre_of_symmetry::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<centre_of_symmetry *>(s);
      }
   return NULL;
   }
centre_of_symmetry *centre_of_symmetry::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<centre_of_symmetry *>(s);
      }
   return NULL;
   }
// construction factory
centre_of_symmetry *centre_of_symmetry::Construct() {
   centre_of_symmetry *result = NULL;

   // create the centre_of_symmetry.
   result = new centre_of_symmetry();
   return result;
   }
bool centre_of_symmetry::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: centre_of_symmetry\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (derived_shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
