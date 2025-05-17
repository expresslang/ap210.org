// Source for AP210 application object
//     csg_primitive

// Precompiled include files
#include <StdAfx.h>

#include "csg_primitive.h"

// Classes

csg_primitive::csg_primitive() {
   initialize();
   }
csg_primitive::~csg_primitive() {
   // Free string attributes
   }
// intialize data members
void csg_primitive::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int csg_primitive::DynamicType(int ID) {
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
csg_primitive *csg_primitive::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<csg_primitive *>(s);
      }
   return NULL;
   }
csg_primitive *csg_primitive::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<csg_primitive *>(s);
      }
   return NULL;
   }
// construction factory
csg_primitive *csg_primitive::Construct() {
   csg_primitive *result = NULL;

   // create the csg_primitive.
   result = new csg_primitive();
   return result;
   }
bool csg_primitive::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: csg_primitive\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
