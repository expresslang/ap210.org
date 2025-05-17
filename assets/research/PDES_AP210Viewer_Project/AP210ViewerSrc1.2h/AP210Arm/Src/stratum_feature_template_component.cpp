// Source for AP210 application object
//     stratum_feature_template_component

// Precompiled include files
#include <StdAfx.h>

#include "stratum_feature_template_component.h"

// Classes
#include <stratum_feature.h>

stratum_feature_template_component::stratum_feature_template_component() {
   initialize();
   }
stratum_feature_template_component::~stratum_feature_template_component() {
   // Free string attributes
   }
// intialize data members
void stratum_feature_template_component::initialize() {
   // Required attributes
   _stratum_feature_implementation = NULL;

   // Optional attributes
   }
// Runtime type identification
int stratum_feature_template_component::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = laminate_component::DynamicType(ID);
      }
   return result;
   }
stratum_feature_template_component *stratum_feature_template_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<stratum_feature_template_component *>(s);
      }
   return NULL;
   }
stratum_feature_template_component *stratum_feature_template_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<stratum_feature_template_component *>(s);
      }
   return NULL;
   }
// construction factory
stratum_feature_template_component *stratum_feature_template_component::Construct() {
   stratum_feature_template_component *result = NULL;

   // create the stratum_feature_template_component.
   result = new stratum_feature_template_component();
   return result;
   }
bool stratum_feature_template_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: stratum_feature_template_component\r\n");

   // Check for the existence of all required attributes
   if (_stratum_feature_implementation == NULL) {
      TRACE("ERROR: _stratum_feature_implementation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (laminate_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
