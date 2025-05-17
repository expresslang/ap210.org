// Source for AP210 application object
//     SetOfinterconnect_module_design_object_select

// Precompiled include files
#include <StdAfx.h>

#include "SetOfinterconnect_module_design_object_select.h"

// Classes

SetOfinterconnect_module_design_object_select::SetOfinterconnect_module_design_object_select() {
   initialize();
   }
SetOfinterconnect_module_design_object_select::~SetOfinterconnect_module_design_object_select() {
   // Free string attributes
   }
// intialize data members
void SetOfinterconnect_module_design_object_select::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int SetOfinterconnect_module_design_object_select::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfinterconnect_module_design_object_select *SetOfinterconnect_module_design_object_select::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfinterconnect_module_design_object_select *>(s);
      }
   return NULL;
   }
SetOfinterconnect_module_design_object_select *SetOfinterconnect_module_design_object_select::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfinterconnect_module_design_object_select *>(s);
      }
   return NULL;
   }
// construction factory
SetOfinterconnect_module_design_object_select *SetOfinterconnect_module_design_object_select::Construct() {
   SetOfinterconnect_module_design_object_select *result = NULL;

   // create the SetOfinterconnect_module_design_object_select.
   result = new SetOfinterconnect_module_design_object_select();
   return result;
   }
bool SetOfinterconnect_module_design_object_select::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfinterconnect_module_design_object_select\r\n");

   // Check for the existence of all required attributes
   if (_interconnect_module_design_object_select == NULL) {
      TRACE("ERROR: _interconnect_module_design_object_select a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
