// Source for AP210 application object
//     positive_ratio_measure

// Precompiled include files
#include <StdAfx.h>

#include "positive_ratio_measure.h"

// Classes

positive_ratio_measure::positive_ratio_measure() {
   initialize();
   }
positive_ratio_measure::~positive_ratio_measure() {
   // Free string attributes
   }
// intialize data members
void positive_ratio_measure::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int positive_ratio_measure::DynamicType(int ID) {
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
positive_ratio_measure *positive_ratio_measure::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<positive_ratio_measure *>(s);
      }
   return NULL;
   }
positive_ratio_measure *positive_ratio_measure::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<positive_ratio_measure *>(s);
      }
   return NULL;
   }
// construction factory
positive_ratio_measure *positive_ratio_measure::Construct() {
   positive_ratio_measure *result = NULL;

   // create the positive_ratio_measure.
   result = new positive_ratio_measure();
   return result;
   }
bool positive_ratio_measure::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: positive_ratio_measure\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
