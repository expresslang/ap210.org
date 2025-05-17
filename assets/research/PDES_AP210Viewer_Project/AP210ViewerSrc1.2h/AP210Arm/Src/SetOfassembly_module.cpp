// Source for AP210 application object
//     SetOfassembly_module

// Precompiled include files
#include <StdAfx.h>

#include "SetOfassembly_module.h"

// Classes
#include <assembly_module.h>

SetOfassembly_module::SetOfassembly_module() {
   initialize();
   }
SetOfassembly_module::~SetOfassembly_module() {
   // Free string attributes
   }
// intialize data members
void SetOfassembly_module::initialize() {
   // Required attributes
   _assembly_module = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfassembly_module::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfassembly_module *SetOfassembly_module::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfassembly_module *>(s);
      }
   return NULL;
   }
SetOfassembly_module *SetOfassembly_module::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfassembly_module *>(s);
      }
   return NULL;
   }
// construction factory
SetOfassembly_module *SetOfassembly_module::Construct() {
   SetOfassembly_module *result = NULL;

   // create the SetOfassembly_module.
   result = new SetOfassembly_module();
   return result;
   }
bool SetOfassembly_module::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfassembly_module\r\n");

   // Check for the existence of all required attributes
   if (_assembly_module == NULL) {
      TRACE("ERROR: _assembly_module a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
