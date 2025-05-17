// Source for AP210 application object
//     inter_stratum_feature_template

// Precompiled include files
#include <StdAfx.h>

#include "inter_stratum_feature_template.h"

// Classes
#include <passage_technology.h>

inter_stratum_feature_template::inter_stratum_feature_template() {
   initialize();
   }
inter_stratum_feature_template::~inter_stratum_feature_template() {
   // Free string attributes
   }
// intialize data members
void inter_stratum_feature_template::initialize() {
   // Required attributes
   _of_passage_technology = NULL;

   // Optional attributes
   }
// Runtime type identification
int inter_stratum_feature_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = part_template::DynamicType(ID);
      }
   return result;
   }
inter_stratum_feature_template *inter_stratum_feature_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<inter_stratum_feature_template *>(s);
      }
   return NULL;
   }
inter_stratum_feature_template *inter_stratum_feature_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<inter_stratum_feature_template *>(s);
      }
   return NULL;
   }
// construction factory
inter_stratum_feature_template *inter_stratum_feature_template::Construct() {
   inter_stratum_feature_template *result = NULL;

   // create the inter_stratum_feature_template.
   result = new inter_stratum_feature_template();
   return result;
   }
bool inter_stratum_feature_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: inter_stratum_feature_template\r\n");

   // Check for the existence of all required attributes
   if (_of_passage_technology == NULL) {
      TRACE("ERROR: _of_passage_technology a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (part_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
