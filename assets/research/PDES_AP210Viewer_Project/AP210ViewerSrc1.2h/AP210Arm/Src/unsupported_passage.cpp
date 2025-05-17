// Source for AP210 application object
//     unsupported_passage

// Precompiled include files
#include <StdAfx.h>

#include "unsupported_passage.h"

// Classes

unsupported_passage::unsupported_passage() {
   initialize();
   }
unsupported_passage::~unsupported_passage() {
   // Free string attributes
   }
// intialize data members
void unsupported_passage::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int unsupported_passage::DynamicType(int ID) {
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
unsupported_passage *unsupported_passage::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<unsupported_passage *>(s);
      }
   return NULL;
   }
unsupported_passage *unsupported_passage::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<unsupported_passage *>(s);
      }
   return NULL;
   }
// construction factory
unsupported_passage *unsupported_passage::Construct() {
   unsupported_passage *result = NULL;

   // create the unsupported_passage.
   result = new unsupported_passage();
   return result;
   }
bool unsupported_passage::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: unsupported_passage\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (inter_stratum_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
