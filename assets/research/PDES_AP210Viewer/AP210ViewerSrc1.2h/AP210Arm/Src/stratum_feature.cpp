// Source for AP210 application object
//     stratum_feature

// Precompiled include files
#include <StdAfx.h>

#include "stratum_feature.h"

// Classes
#include <stratum.h>

stratum_feature::stratum_feature() {
   initialize();
   }
stratum_feature::~stratum_feature() {
   // Free string attributes
   }
// intialize data members
void stratum_feature::initialize() {
   // Required attributes
   _resident_stratum = NULL;

   // Optional attributes
   }
// Runtime type identification
int stratum_feature::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = physical_feature_or_part_template::DynamicType(ID);
      }
   return result;
   }
stratum_feature *stratum_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<stratum_feature *>(s);
      }
   return NULL;
   }
stratum_feature *stratum_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<stratum_feature *>(s);
      }
   return NULL;
   }
// construction factory
stratum_feature *stratum_feature::Construct() {
   stratum_feature *result = NULL;

   // create the stratum_feature.
   result = new stratum_feature();
   return result;
   }
bool stratum_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: stratum_feature\r\n");

   // Check for the existence of all required attributes
   if (_resident_stratum == NULL) {
      TRACE("ERROR: _resident_stratum a required attribute is NULL!\r\n");
      result = false;
      }
   if (_feature_of_size == NULL) {
      TRACE("ERROR: _feature_of_size a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (physical_feature_or_part_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
