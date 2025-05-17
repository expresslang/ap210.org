// Source for AP210 application object
//     stratum_feature_template

// Precompiled include files
#include <StdAfx.h>

#include "stratum_feature_template.h"

// Classes

stratum_feature_template::stratum_feature_template() {
   initialize();
   }
stratum_feature_template::~stratum_feature_template() {
   // Free string attributes
   }
// intialize data members
void stratum_feature_template::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int stratum_feature_template::DynamicType(int ID) {
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
stratum_feature_template *stratum_feature_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<stratum_feature_template *>(s);
      }
   return NULL;
   }
stratum_feature_template *stratum_feature_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<stratum_feature_template *>(s);
      }
   return NULL;
   }
// construction factory
stratum_feature_template *stratum_feature_template::Construct() {
   stratum_feature_template *result = NULL;

   // create the stratum_feature_template.
   result = new stratum_feature_template();
   return result;
   }
bool stratum_feature_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: stratum_feature_template\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (part_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
