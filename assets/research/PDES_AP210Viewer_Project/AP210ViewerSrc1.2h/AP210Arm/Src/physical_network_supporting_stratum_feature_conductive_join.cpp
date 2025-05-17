// Source for AP210 application object
//     physical_network_supporting_stratum_feature_conductive_join

// Precompiled include files
#include <StdAfx.h>

#include "physical_network_supporting_stratum_feature_conductive_join.h"

// Classes

physical_network_supporting_stratum_feature_conductive_join::physical_network_supporting_stratum_feature_conductive_join() {
   initialize();
   }
physical_network_supporting_stratum_feature_conductive_join::~physical_network_supporting_stratum_feature_conductive_join() {
   // Free string attributes
   }
// intialize data members
void physical_network_supporting_stratum_feature_conductive_join::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int physical_network_supporting_stratum_feature_conductive_join::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = stratum_feature_conductive_join::DynamicType(ID);
      }
   if (result == 0) {
      result = inter_stratum_join_implementation::DynamicType(ID);
      }
   return result;
   }
physical_network_supporting_stratum_feature_conductive_join *physical_network_supporting_stratum_feature_conductive_join::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<physical_network_supporting_stratum_feature_conductive_join *>(s);
      }
   return NULL;
   }
physical_network_supporting_stratum_feature_conductive_join *physical_network_supporting_stratum_feature_conductive_join::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<physical_network_supporting_stratum_feature_conductive_join *>(s);
      }
   return NULL;
   }
// construction factory
physical_network_supporting_stratum_feature_conductive_join *physical_network_supporting_stratum_feature_conductive_join::Construct() {
   physical_network_supporting_stratum_feature_conductive_join *result = NULL;

   // create the physical_network_supporting_stratum_feature_conductive_join.
   result = new physical_network_supporting_stratum_feature_conductive_join();
   return result;
   }
bool physical_network_supporting_stratum_feature_conductive_join::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: physical_network_supporting_stratum_feature_conductive_join\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (stratum_feature_conductive_join::hasRequiredAttributes() == false) {
      result = false;
      }
   if (inter_stratum_join_implementation::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
