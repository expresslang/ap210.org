// Source for AP210 application object
//     plated_cutout

// Precompiled include files
#include <StdAfx.h>

#include "plated_cutout.h"

// Classes

plated_cutout::plated_cutout() {
   initialize();
   }
plated_cutout::~plated_cutout() {
   // Free string attributes
   }
// intialize data members
void plated_cutout::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int plated_cutout::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = cutout::DynamicType(ID);
      }
   if (result == 0) {
      result = plated_inter_stratum_feature::DynamicType(ID);
      }
   return result;
   }
plated_cutout *plated_cutout::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<plated_cutout *>(s);
      }
   return NULL;
   }
plated_cutout *plated_cutout::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<plated_cutout *>(s);
      }
   return NULL;
   }
// construction factory
plated_cutout *plated_cutout::Construct() {
   plated_cutout *result = NULL;

   // create the plated_cutout.
   result = new plated_cutout();
   return result;
   }
bool plated_cutout::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: plated_cutout\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (cutout::hasRequiredAttributes() == false) {
      result = false;
      }
   if (plated_inter_stratum_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
