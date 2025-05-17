// Source for AP210 application object
//     array_placement_group

// Precompiled include files
#include <StdAfx.h>

#include "array_placement_group.h"

// Classes

array_placement_group::array_placement_group() {
   initialize();
   }
array_placement_group::~array_placement_group() {
   // Free string attributes
   }
// intialize data members
void array_placement_group::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int array_placement_group::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = assembly_group_component::DynamicType(ID);
      }
   return result;
   }
array_placement_group *array_placement_group::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<array_placement_group *>(s);
      }
   return NULL;
   }
array_placement_group *array_placement_group::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<array_placement_group *>(s);
      }
   return NULL;
   }
// construction factory
array_placement_group *array_placement_group::Construct() {
   array_placement_group *result = NULL;

   // create the array_placement_group.
   result = new array_placement_group();
   return result;
   }
bool array_placement_group::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: array_placement_group\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (assembly_group_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
