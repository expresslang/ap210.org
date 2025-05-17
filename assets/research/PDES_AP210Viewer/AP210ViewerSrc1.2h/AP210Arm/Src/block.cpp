// Source for AP210 application object
//     block

// Precompiled include files
#include <StdAfx.h>

#include "block.h"

// Classes

block::block() {
   initialize();
   }
block::~block() {
   // Free string attributes
   }
// intialize data members
void block::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int block::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = csg_primitive::DynamicType(ID);
      }
   return result;
   }
block *block::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<block *>(s);
      }
   return NULL;
   }
block *block::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<block *>(s);
      }
   return NULL;
   }
// construction factory
block *block::Construct() {
   block *result = NULL;

   // create the block.
   result = new block();
   return result;
   }
bool block::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: block\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (csg_primitive::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
