// Source for AP210 application object
//     SetOfassembly_component

// Precompiled include files
#include <StdAfx.h>

#include "SetOfassembly_component.h"

// Classes
#include <assembly_component.h>

SetOfassembly_component::SetOfassembly_component() {
   initialize();
   }
SetOfassembly_component::~SetOfassembly_component() {
   // Free string attributes
   }
// intialize data members
void SetOfassembly_component::initialize() {
   // Required attributes
   _assembly_component = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfassembly_component::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfassembly_component *SetOfassembly_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfassembly_component *>(s);
      }
   return NULL;
   }
SetOfassembly_component *SetOfassembly_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfassembly_component *>(s);
      }
   return NULL;
   }
// construction factory
SetOfassembly_component *SetOfassembly_component::Construct() {
   SetOfassembly_component *result = NULL;

   // create the SetOfassembly_component.
   result = new SetOfassembly_component();
   return result;
   }
bool SetOfassembly_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfassembly_component\r\n");

   // Check for the existence of all required attributes
   if (_assembly_component == NULL) {
      TRACE("ERROR: _assembly_component a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
