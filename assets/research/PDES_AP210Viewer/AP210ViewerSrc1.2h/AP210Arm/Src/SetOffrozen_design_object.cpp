// Source for AP210 application object
//     SetOffrozen_design_object

// Precompiled include files
#include <StdAfx.h>

#include "SetOffrozen_design_object.h"

// Classes
#include <frozen_design_object.h>

SetOffrozen_design_object::SetOffrozen_design_object() {
   initialize();
   }
SetOffrozen_design_object::~SetOffrozen_design_object() {
   // Free string attributes
   }
// intialize data members
void SetOffrozen_design_object::initialize() {
   // Required attributes
   _frozen_design_object = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOffrozen_design_object::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOffrozen_design_object *SetOffrozen_design_object::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOffrozen_design_object *>(s);
      }
   return NULL;
   }
SetOffrozen_design_object *SetOffrozen_design_object::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOffrozen_design_object *>(s);
      }
   return NULL;
   }
// construction factory
SetOffrozen_design_object *SetOffrozen_design_object::Construct() {
   SetOffrozen_design_object *result = NULL;

   // create the SetOffrozen_design_object.
   result = new SetOffrozen_design_object();
   return result;
   }
bool SetOffrozen_design_object::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOffrozen_design_object\r\n");

   // Check for the existence of all required attributes
   if (_frozen_design_object == NULL) {
      TRACE("ERROR: _frozen_design_object a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
