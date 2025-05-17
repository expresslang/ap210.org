// Source for AP210 application object
//     fiducial_part_feature

// Precompiled include files
#include <StdAfx.h>

#include "fiducial_part_feature.h"

// Classes

fiducial_part_feature::fiducial_part_feature() {
   initialize();
   }
fiducial_part_feature::~fiducial_part_feature() {
   // Free string attributes
   }
// intialize data members
void fiducial_part_feature::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int fiducial_part_feature::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = part_tooling_feature::DynamicType(ID);
      }
   return result;
   }
fiducial_part_feature *fiducial_part_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<fiducial_part_feature *>(s);
      }
   return NULL;
   }
fiducial_part_feature *fiducial_part_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<fiducial_part_feature *>(s);
      }
   return NULL;
   }
// construction factory
fiducial_part_feature *fiducial_part_feature::Construct() {
   fiducial_part_feature *result = NULL;

   // create the fiducial_part_feature.
   result = new fiducial_part_feature();
   return result;
   }
bool fiducial_part_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: fiducial_part_feature\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (part_tooling_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
