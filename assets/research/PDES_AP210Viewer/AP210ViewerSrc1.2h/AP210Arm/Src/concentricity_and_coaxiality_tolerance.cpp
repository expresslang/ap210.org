// Source for AP210 application object
//     concentricity_and_coaxiality_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "concentricity_and_coaxiality_tolerance.h"

// Classes

concentricity_and_coaxiality_tolerance::concentricity_and_coaxiality_tolerance() {
   initialize();
   }
concentricity_and_coaxiality_tolerance::~concentricity_and_coaxiality_tolerance() {
   // Free string attributes
   }
// intialize data members
void concentricity_and_coaxiality_tolerance::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int concentricity_and_coaxiality_tolerance::DynamicType(int ID) {
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
concentricity_and_coaxiality_tolerance *concentricity_and_coaxiality_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<concentricity_and_coaxiality_tolerance *>(s);
      }
   return NULL;
   }
concentricity_and_coaxiality_tolerance *concentricity_and_coaxiality_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<concentricity_and_coaxiality_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
concentricity_and_coaxiality_tolerance *concentricity_and_coaxiality_tolerance::Construct() {
   concentricity_and_coaxiality_tolerance *result = NULL;

   // create the concentricity_and_coaxiality_tolerance.
   result = new concentricity_and_coaxiality_tolerance();
   return result;
   }
bool concentricity_and_coaxiality_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: concentricity_and_coaxiality_tolerance\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (geometric_tolerance_with_referenced_datum_system::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
