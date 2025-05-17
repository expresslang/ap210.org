// Source for AP210 application object
//     unsupported_passage_template

// Precompiled include files
#include <StdAfx.h>

#include "unsupported_passage_template.h"

// Classes

unsupported_passage_template::unsupported_passage_template() {
   initialize();
   }
unsupported_passage_template::~unsupported_passage_template() {
   // Free string attributes
   }
// intialize data members
void unsupported_passage_template::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int unsupported_passage_template::DynamicType(int ID) {
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
unsupported_passage_template *unsupported_passage_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<unsupported_passage_template *>(s);
      }
   return NULL;
   }
unsupported_passage_template *unsupported_passage_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<unsupported_passage_template *>(s);
      }
   return NULL;
   }
// construction factory
unsupported_passage_template *unsupported_passage_template::Construct() {
   unsupported_passage_template *result = NULL;

   // create the unsupported_passage_template.
   result = new unsupported_passage_template();
   return result;
   }
bool unsupported_passage_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: unsupported_passage_template\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (inter_stratum_feature_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
