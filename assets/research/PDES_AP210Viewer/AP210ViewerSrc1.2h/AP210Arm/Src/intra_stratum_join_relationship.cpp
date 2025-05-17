// Source for AP210 application object
//     intra_stratum_join_relationship

// Precompiled include files
#include <StdAfx.h>

#include "intra_stratum_join_relationship.h"

// Classes

intra_stratum_join_relationship::intra_stratum_join_relationship() {
   initialize();
   }
intra_stratum_join_relationship::~intra_stratum_join_relationship() {
   // Free string attributes
   }
// intialize data members
void intra_stratum_join_relationship::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int intra_stratum_join_relationship::DynamicType(int ID) {
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
intra_stratum_join_relationship *intra_stratum_join_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<intra_stratum_join_relationship *>(s);
      }
   return NULL;
   }
intra_stratum_join_relationship *intra_stratum_join_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<intra_stratum_join_relationship *>(s);
      }
   return NULL;
   }
// construction factory
intra_stratum_join_relationship *intra_stratum_join_relationship::Construct() {
   intra_stratum_join_relationship *result = NULL;

   // create the intra_stratum_join_relationship.
   result = new intra_stratum_join_relationship();
   return result;
   }
bool intra_stratum_join_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: intra_stratum_join_relationship\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (join_relationship::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
