// Source for AP210 application object
//     stratum_feature_conductive_join

// Precompiled include files
#include <StdAfx.h>

#include "stratum_feature_conductive_join.h"

// Classes
#include <stratum_feature_template_component.h>
#include <stratum_feature_template_component.h>

stratum_feature_conductive_join::stratum_feature_conductive_join() {
   initialize();
   }
stratum_feature_conductive_join::~stratum_feature_conductive_join() {
   // Free string attributes
   }
// intialize data members
void stratum_feature_conductive_join::initialize() {
   // Required attributes
   _related_concept = NULL;
   _relating_concept = NULL;

   // Optional attributes
   }
// Runtime type identification
int stratum_feature_conductive_join::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = stratum_concept_relationship::DynamicType(ID);
      }
   return result;
   }
stratum_feature_conductive_join *stratum_feature_conductive_join::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<stratum_feature_conductive_join *>(s);
      }
   return NULL;
   }
stratum_feature_conductive_join *stratum_feature_conductive_join::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<stratum_feature_conductive_join *>(s);
      }
   return NULL;
   }
// construction factory
stratum_feature_conductive_join *stratum_feature_conductive_join::Construct() {
   stratum_feature_conductive_join *result = NULL;

   // create the stratum_feature_conductive_join.
   result = new stratum_feature_conductive_join();
   return result;
   }
bool stratum_feature_conductive_join::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: stratum_feature_conductive_join\r\n");

   // Check for the existence of all required attributes
   if (_related_concept == NULL) {
      TRACE("ERROR: _related_concept a required attribute is NULL!\r\n");
      result = false;
      }
   if (_relating_concept == NULL) {
      TRACE("ERROR: _relating_concept a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (stratum_concept_relationship::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
