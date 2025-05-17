// Source for AP210 application object
//     part_array_feature

// Precompiled include files
#include <StdAfx.h>

#include "part_array_feature.h"

// Classes

part_array_feature::part_array_feature() {
   initialize();
   }
part_array_feature::~part_array_feature() {
   // Free string attributes
   }
// intialize data members
void part_array_feature::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int part_array_feature::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = part_group_feature::DynamicType(ID);
      }
   return result;
   }
part_array_feature *part_array_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<part_array_feature *>(s);
      }
   return NULL;
   }
part_array_feature *part_array_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<part_array_feature *>(s);
      }
   return NULL;
   }
// construction factory
part_array_feature *part_array_feature::Construct() {
   part_array_feature *result = NULL;

   // create the part_array_feature.
   result = new part_array_feature();
   return result;
   }
bool part_array_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: part_array_feature\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (part_group_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
