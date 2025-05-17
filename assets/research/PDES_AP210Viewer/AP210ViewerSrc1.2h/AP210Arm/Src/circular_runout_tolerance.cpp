// Source for AP210 application object
//     circular_runout_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "circular_runout_tolerance.h"

// Classes

circular_runout_tolerance::circular_runout_tolerance() {
   initialize();
   }
circular_runout_tolerance::~circular_runout_tolerance() {
   // Free string attributes
   }
// intialize data members
void circular_runout_tolerance::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int circular_runout_tolerance::DynamicType(int ID) {
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
circular_runout_tolerance *circular_runout_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<circular_runout_tolerance *>(s);
      }
   return NULL;
   }
circular_runout_tolerance *circular_runout_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<circular_runout_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
circular_runout_tolerance *circular_runout_tolerance::Construct() {
   circular_runout_tolerance *result = NULL;

   // create the circular_runout_tolerance.
   result = new circular_runout_tolerance();
   return result;
   }
bool circular_runout_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: circular_runout_tolerance\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (geometric_tolerance_with_referenced_datum_system::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
