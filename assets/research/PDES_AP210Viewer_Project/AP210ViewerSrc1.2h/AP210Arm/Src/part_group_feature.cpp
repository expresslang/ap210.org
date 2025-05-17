// Source for AP210 application object
//     part_group_feature

// Precompiled include files
#include <StdAfx.h>

#include "part_group_feature.h"

// Classes

part_group_feature::part_group_feature() {
   initialize();
   }
part_group_feature::~part_group_feature() {
   // Free string attributes
   }
// intialize data members
void part_group_feature::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int part_group_feature::DynamicType(int ID) {
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
part_group_feature *part_group_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<part_group_feature *>(s);
      }
   return NULL;
   }
part_group_feature *part_group_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<part_group_feature *>(s);
      }
   return NULL;
   }
// construction factory
part_group_feature *part_group_feature::Construct() {
   part_group_feature *result = NULL;

   // create the part_group_feature.
   result = new part_group_feature();
   return result;
   }
bool part_group_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: part_group_feature\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (part_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
