// Source for AP210 application object
//     partially_plated_cutout

// Precompiled include files
#include <StdAfx.h>

#include "partially_plated_cutout.h"

// Classes

partially_plated_cutout::partially_plated_cutout() {
   initialize();
   }
partially_plated_cutout::~partially_plated_cutout() {
   // Free string attributes
   }
// intialize data members
void partially_plated_cutout::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int partially_plated_cutout::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = cutout::DynamicType(ID);
      }
   return result;
   }
partially_plated_cutout *partially_plated_cutout::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<partially_plated_cutout *>(s);
      }
   return NULL;
   }
partially_plated_cutout *partially_plated_cutout::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<partially_plated_cutout *>(s);
      }
   return NULL;
   }
// construction factory
partially_plated_cutout *partially_plated_cutout::Construct() {
   partially_plated_cutout *result = NULL;

   // create the partially_plated_cutout.
   result = new partially_plated_cutout();
   return result;
   }
bool partially_plated_cutout::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: partially_plated_cutout\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (cutout::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
