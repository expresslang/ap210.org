// Source for AP210 application object
//     cylindricity_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "cylindricity_tolerance.h"

// Classes

cylindricity_tolerance::cylindricity_tolerance() {
   initialize();
   }
cylindricity_tolerance::~cylindricity_tolerance() {
   // Free string attributes
   }
// intialize data members
void cylindricity_tolerance::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int cylindricity_tolerance::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = geometric_tolerance_without_referenced_datum_system::DynamicType(ID);
      }
   return result;
   }
cylindricity_tolerance *cylindricity_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<cylindricity_tolerance *>(s);
      }
   return NULL;
   }
cylindricity_tolerance *cylindricity_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<cylindricity_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
cylindricity_tolerance *cylindricity_tolerance::Construct() {
   cylindricity_tolerance *result = NULL;

   // create the cylindricity_tolerance.
   result = new cylindricity_tolerance();
   return result;
   }
bool cylindricity_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: cylindricity_tolerance\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (geometric_tolerance_without_referenced_datum_system::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
