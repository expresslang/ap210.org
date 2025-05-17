// Source for AP210 application object
//     total_runout_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "total_runout_tolerance.h"

// Classes

total_runout_tolerance::total_runout_tolerance() {
   initialize();
   }
total_runout_tolerance::~total_runout_tolerance() {
   // Free string attributes
   }
// intialize data members
void total_runout_tolerance::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int total_runout_tolerance::DynamicType(int ID) {
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
total_runout_tolerance *total_runout_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<total_runout_tolerance *>(s);
      }
   return NULL;
   }
total_runout_tolerance *total_runout_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<total_runout_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
total_runout_tolerance *total_runout_tolerance::Construct() {
   total_runout_tolerance *result = NULL;

   // create the total_runout_tolerance.
   result = new total_runout_tolerance();
   return result;
   }
bool total_runout_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: total_runout_tolerance\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (geometric_tolerance_with_referenced_datum_system::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
