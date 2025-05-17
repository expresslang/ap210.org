// Source for AP210 application object
//     inter_stratum_feature_edge_template

// Precompiled include files
#include <StdAfx.h>

#include "inter_stratum_feature_edge_template.h"

// Classes

inter_stratum_feature_edge_template::inter_stratum_feature_edge_template() {
   initialize();
   }
inter_stratum_feature_edge_template::~inter_stratum_feature_edge_template() {
   // Free string attributes
   }
// intialize data members
void inter_stratum_feature_edge_template::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int inter_stratum_feature_edge_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = inter_stratum_feature_template::DynamicType(ID);
      }
   return result;
   }
inter_stratum_feature_edge_template *inter_stratum_feature_edge_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<inter_stratum_feature_edge_template *>(s);
      }
   return NULL;
   }
inter_stratum_feature_edge_template *inter_stratum_feature_edge_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<inter_stratum_feature_edge_template *>(s);
      }
   return NULL;
   }
// construction factory
inter_stratum_feature_edge_template *inter_stratum_feature_edge_template::Construct() {
   inter_stratum_feature_edge_template *result = NULL;

   // create the inter_stratum_feature_edge_template.
   result = new inter_stratum_feature_edge_template();
   return result;
   }
bool inter_stratum_feature_edge_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: inter_stratum_feature_edge_template\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (inter_stratum_feature_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
