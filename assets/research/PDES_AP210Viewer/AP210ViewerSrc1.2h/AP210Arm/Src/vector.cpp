// Source for AP210 application object
//     vector

// Precompiled include files
#include <StdAfx.h>

#include "vector.h"

// Classes

vector::vector() {
   initialize();
   }
vector::~vector() {
   // Free string attributes
   }
// intialize data members
void vector::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int vector::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = managed_design_object::DynamicType(ID);
      }
   return result;
   }
vector *vector::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<vector *>(s);
      }
   return NULL;
   }
vector *vector::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<vector *>(s);
      }
   return NULL;
   }
// construction factory
vector *vector::Construct() {
   vector *result = NULL;

   // create the vector.
   result = new vector();
   return result;
   }
bool vector::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: vector\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
