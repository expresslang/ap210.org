// Source for AP210 application object
//     parallelism_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "parallelism_tolerance.h"

// Classes

parallelism_tolerance::parallelism_tolerance() {
   initialize();
   }
parallelism_tolerance::~parallelism_tolerance() {
   // Free string attributes
   }
// intialize data members
void parallelism_tolerance::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int parallelism_tolerance::DynamicType(int ID) {
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
parallelism_tolerance *parallelism_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<parallelism_tolerance *>(s);
      }
   return NULL;
   }
parallelism_tolerance *parallelism_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<parallelism_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
parallelism_tolerance *parallelism_tolerance::Construct() {
   parallelism_tolerance *result = NULL;

   // create the parallelism_tolerance.
   result = new parallelism_tolerance();
   return result;
   }
bool parallelism_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: parallelism_tolerance\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (geometric_tolerance_with_referenced_datum_system::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
