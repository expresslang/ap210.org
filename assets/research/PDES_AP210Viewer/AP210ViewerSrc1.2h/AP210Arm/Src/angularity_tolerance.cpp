// Source for AP210 application object
//     angularity_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "angularity_tolerance.h"

// Classes

angularity_tolerance::angularity_tolerance() {
   initialize();
   }
angularity_tolerance::~angularity_tolerance() {
   // Free string attributes
   }
// intialize data members
void angularity_tolerance::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int angularity_tolerance::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = geometric_tolerance_with_referenced_datum_system::DynamicType(ID);
      }
   return result;
   }
angularity_tolerance *angularity_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<angularity_tolerance *>(s);
      }
   return NULL;
   }
angularity_tolerance *angularity_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<angularity_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
angularity_tolerance *angularity_tolerance::Construct() {
   angularity_tolerance *result = NULL;

   // create the angularity_tolerance.
   result = new angularity_tolerance();
   return result;
   }
bool angularity_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: angularity_tolerance\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (geometric_tolerance_with_referenced_datum_system::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
