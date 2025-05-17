// Source for AP210 application object
//     part_tooling_feature

// Precompiled include files
#include <StdAfx.h>

#include "part_tooling_feature.h"

// Classes

part_tooling_feature::part_tooling_feature() {
   initialize();
   }
part_tooling_feature::~part_tooling_feature() {
   // Free string attributes
   }
// intialize data members
void part_tooling_feature::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int part_tooling_feature::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = part_feature::DynamicType(ID);
      }
   return result;
   }
part_tooling_feature *part_tooling_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<part_tooling_feature *>(s);
      }
   return NULL;
   }
part_tooling_feature *part_tooling_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<part_tooling_feature *>(s);
      }
   return NULL;
   }
// construction factory
part_tooling_feature *part_tooling_feature::Construct() {
   part_tooling_feature *result = NULL;

   // create the part_tooling_feature.
   result = new part_tooling_feature();
   return result;
   }
bool part_tooling_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: part_tooling_feature\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (part_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
