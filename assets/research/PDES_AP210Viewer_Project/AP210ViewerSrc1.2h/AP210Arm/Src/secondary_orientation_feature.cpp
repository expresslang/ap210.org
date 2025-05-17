// Source for AP210 application object
//     secondary_orientation_feature

// Precompiled include files
#include <StdAfx.h>

#include "secondary_orientation_feature.h"

// Classes

secondary_orientation_feature::secondary_orientation_feature() {
   initialize();
   }
secondary_orientation_feature::~secondary_orientation_feature() {
   // Free string attributes
   }
// intialize data members
void secondary_orientation_feature::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int secondary_orientation_feature::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = part_feature::DynamicType(ID);
      }
   if (result == 0) {
      result = datum_feature::DynamicType(ID);
      }
   return result;
   }
secondary_orientation_feature *secondary_orientation_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<secondary_orientation_feature *>(s);
      }
   return NULL;
   }
secondary_orientation_feature *secondary_orientation_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<secondary_orientation_feature *>(s);
      }
   return NULL;
   }
// construction factory
secondary_orientation_feature *secondary_orientation_feature::Construct() {
   secondary_orientation_feature *result = NULL;

   // create the secondary_orientation_feature.
   result = new secondary_orientation_feature();
   return result;
   }
bool secondary_orientation_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: secondary_orientation_feature\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (part_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   if (datum_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
