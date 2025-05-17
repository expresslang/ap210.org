// Source for AP210 application object
//     managed_design_object

// Precompiled include files
#include <StdAfx.h>

#include "managed_design_object.h"

// Classes

managed_design_object::managed_design_object() {
   initialize();
   }
managed_design_object::~managed_design_object() {
   // Free string attributes
   }
// intialize data members
void managed_design_object::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int managed_design_object::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
managed_design_object *managed_design_object::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<managed_design_object *>(s);
      }
   return NULL;
   }
managed_design_object *managed_design_object::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<managed_design_object *>(s);
      }
   return NULL;
   }
// construction factory
managed_design_object *managed_design_object::Construct() {
   managed_design_object *result = NULL;

   // create the managed_design_object.
   result = new managed_design_object();
   return result;
   }
bool managed_design_object::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: managed_design_object\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   return(result);
   }
