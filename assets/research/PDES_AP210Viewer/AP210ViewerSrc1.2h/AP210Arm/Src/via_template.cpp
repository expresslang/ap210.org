// Source for AP210 application object
//     via_template

// Precompiled include files
#include <StdAfx.h>

#include "via_template.h"

// Classes

via_template::via_template() {
   initialize();
   }
via_template::~via_template() {
   // Free string attributes
   }
// intialize data members
void via_template::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int via_template::DynamicType(int ID) {
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
via_template *via_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<via_template *>(s);
      }
   return NULL;
   }
via_template *via_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<via_template *>(s);
      }
   return NULL;
   }
// construction factory
via_template *via_template::Construct() {
   via_template *result = NULL;

   // create the via_template.
   result = new via_template();
   return result;
   }
bool via_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: via_template\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (inter_stratum_feature_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
