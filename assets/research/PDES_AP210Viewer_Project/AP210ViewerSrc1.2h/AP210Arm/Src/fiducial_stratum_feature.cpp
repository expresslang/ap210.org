// Source for AP210 application object
//     fiducial_stratum_feature

// Precompiled include files
#include <StdAfx.h>

#include "fiducial_stratum_feature.h"

// Classes

fiducial_stratum_feature::fiducial_stratum_feature() {
   initialize();
   }
fiducial_stratum_feature::~fiducial_stratum_feature() {
   // Free string attributes
   }
// intialize data members
void fiducial_stratum_feature::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int fiducial_stratum_feature::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = stratum_feature::DynamicType(ID);
      }
   return result;
   }
fiducial_stratum_feature *fiducial_stratum_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<fiducial_stratum_feature *>(s);
      }
   return NULL;
   }
fiducial_stratum_feature *fiducial_stratum_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<fiducial_stratum_feature *>(s);
      }
   return NULL;
   }
// construction factory
fiducial_stratum_feature *fiducial_stratum_feature::Construct() {
   fiducial_stratum_feature *result = NULL;

   // create the fiducial_stratum_feature.
   result = new fiducial_stratum_feature();
   return result;
   }
bool fiducial_stratum_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: fiducial_stratum_feature\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (stratum_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
