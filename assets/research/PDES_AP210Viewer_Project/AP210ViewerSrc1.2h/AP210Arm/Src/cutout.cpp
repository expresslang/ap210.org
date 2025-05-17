// Source for AP210 application object
//     cutout

// Precompiled include files
#include <StdAfx.h>

#include "cutout.h"

// Classes

cutout::cutout() {
   initialize();
   }
cutout::~cutout() {
   // Free string attributes
   }
// intialize data members
void cutout::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int cutout::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = inter_stratum_feature::DynamicType(ID);
      }
   return result;
   }
cutout *cutout::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<cutout *>(s);
      }
   return NULL;
   }
cutout *cutout::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<cutout *>(s);
      }
   return NULL;
   }
// construction factory
cutout *cutout::Construct() {
   cutout *result = NULL;

   // create the cutout.
   result = new cutout();
   return result;
   }
bool cutout::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: cutout\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (inter_stratum_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
