// Source for AP210 application object
//     frozen_design_object

// Precompiled include files
#include <StdAfx.h>

#include "frozen_design_object.h"

// Classes

frozen_design_object::frozen_design_object() {
   initialize();
   }
frozen_design_object::~frozen_design_object() {
   // Free string attributes
   }
// intialize data members
void frozen_design_object::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int frozen_design_object::DynamicType(int ID) {
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
frozen_design_object *frozen_design_object::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<frozen_design_object *>(s);
      }
   return NULL;
   }
frozen_design_object *frozen_design_object::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<frozen_design_object *>(s);
      }
   return NULL;
   }
// construction factory
frozen_design_object *frozen_design_object::Construct() {
   frozen_design_object *result = NULL;

   // create the frozen_design_object.
   result = new frozen_design_object();
   return result;
   }
bool frozen_design_object::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: frozen_design_object\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
