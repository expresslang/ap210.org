// Source for AP210 application object
//     plated_inter_stratum_feature

// Precompiled include files
#include <StdAfx.h>

#include "plated_inter_stratum_feature.h"

// Classes

plated_inter_stratum_feature::plated_inter_stratum_feature() {
   initialize();
   }
plated_inter_stratum_feature::~plated_inter_stratum_feature() {
   // Free string attributes
   }
// intialize data members
void plated_inter_stratum_feature::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int plated_inter_stratum_feature::DynamicType(int ID) {
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
plated_inter_stratum_feature *plated_inter_stratum_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<plated_inter_stratum_feature *>(s);
      }
   return NULL;
   }
plated_inter_stratum_feature *plated_inter_stratum_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<plated_inter_stratum_feature *>(s);
      }
   return NULL;
   }
// construction factory
plated_inter_stratum_feature *plated_inter_stratum_feature::Construct() {
   plated_inter_stratum_feature *result = NULL;

   // create the plated_inter_stratum_feature.
   result = new plated_inter_stratum_feature();
   return result;
   }
bool plated_inter_stratum_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: plated_inter_stratum_feature\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (inter_stratum_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
