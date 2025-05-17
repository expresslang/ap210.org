// Source for AP210 application object
//     inter_stratum_join_relationship

// Precompiled include files
#include <StdAfx.h>

#include "inter_stratum_join_relationship.h"

// Classes

inter_stratum_join_relationship::inter_stratum_join_relationship() {
   initialize();
   }
inter_stratum_join_relationship::~inter_stratum_join_relationship() {
   // Free string attributes
   }
// intialize data members
void inter_stratum_join_relationship::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int inter_stratum_join_relationship::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = join_relationship::DynamicType(ID);
      }
   return result;
   }
inter_stratum_join_relationship *inter_stratum_join_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<inter_stratum_join_relationship *>(s);
      }
   return NULL;
   }
inter_stratum_join_relationship *inter_stratum_join_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<inter_stratum_join_relationship *>(s);
      }
   return NULL;
   }
// construction factory
inter_stratum_join_relationship *inter_stratum_join_relationship::Construct() {
   inter_stratum_join_relationship *result = NULL;

   // create the inter_stratum_join_relationship.
   result = new inter_stratum_join_relationship();
   return result;
   }
bool inter_stratum_join_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: inter_stratum_join_relationship\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (join_relationship::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
