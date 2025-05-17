// Source for AP210 application object
//     physical_network_supporting_inter_stratum_feature

// Precompiled include files
#include <StdAfx.h>

#include "physical_network_supporting_inter_stratum_feature.h"

// Classes

physical_network_supporting_inter_stratum_feature::physical_network_supporting_inter_stratum_feature() {
   initialize();
   }
physical_network_supporting_inter_stratum_feature::~physical_network_supporting_inter_stratum_feature() {
   // Free string attributes
   }
// intialize data members
void physical_network_supporting_inter_stratum_feature::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int physical_network_supporting_inter_stratum_feature::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = plated_inter_stratum_feature::DynamicType(ID);
      }
   if (result == 0) {
      result = inter_stratum_join_implementation::DynamicType(ID);
      }
   return result;
   }
physical_network_supporting_inter_stratum_feature *physical_network_supporting_inter_stratum_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<physical_network_supporting_inter_stratum_feature *>(s);
      }
   return NULL;
   }
physical_network_supporting_inter_stratum_feature *physical_network_supporting_inter_stratum_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<physical_network_supporting_inter_stratum_feature *>(s);
      }
   return NULL;
   }
// construction factory
physical_network_supporting_inter_stratum_feature *physical_network_supporting_inter_stratum_feature::Construct() {
   physical_network_supporting_inter_stratum_feature *result = NULL;

   // create the physical_network_supporting_inter_stratum_feature.
   result = new physical_network_supporting_inter_stratum_feature();
   return result;
   }
bool physical_network_supporting_inter_stratum_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: physical_network_supporting_inter_stratum_feature\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (plated_inter_stratum_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   if (inter_stratum_join_implementation::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
