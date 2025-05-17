// Source for AP210 application object
//     SetOfassembly_or_interconnect_design_object_select

// Precompiled include files
#include <StdAfx.h>

#include "SetOfassembly_or_interconnect_design_object_select.h"

// Classes

SetOfassembly_or_interconnect_design_object_select::SetOfassembly_or_interconnect_design_object_select() {
   initialize();
   }
SetOfassembly_or_interconnect_design_object_select::~SetOfassembly_or_interconnect_design_object_select() {
   // Free string attributes
   }
// intialize data members
void SetOfassembly_or_interconnect_design_object_select::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int SetOfassembly_or_interconnect_design_object_select::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfassembly_or_interconnect_design_object_select *SetOfassembly_or_interconnect_design_object_select::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfassembly_or_interconnect_design_object_select *>(s);
      }
   return NULL;
   }
SetOfassembly_or_interconnect_design_object_select *SetOfassembly_or_interconnect_design_object_select::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfassembly_or_interconnect_design_object_select *>(s);
      }
   return NULL;
   }
// construction factory
SetOfassembly_or_interconnect_design_object_select *SetOfassembly_or_interconnect_design_object_select::Construct() {
   SetOfassembly_or_interconnect_design_object_select *result = NULL;

   // create the SetOfassembly_or_interconnect_design_object_select.
   result = new SetOfassembly_or_interconnect_design_object_select();
   return result;
   }
bool SetOfassembly_or_interconnect_design_object_select::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfassembly_or_interconnect_design_object_select\r\n");

   // Check for the existence of all required attributes
   if (_assembly_or_interconnect_design_object_select == NULL) {
      TRACE("ERROR: _assembly_or_interconnect_design_object_select a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
