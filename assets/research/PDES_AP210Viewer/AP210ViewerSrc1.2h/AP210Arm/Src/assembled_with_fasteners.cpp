// Source for AP210 application object
//     assembled_with_fasteners

// Precompiled include files
#include <StdAfx.h>

#include "assembled_with_fasteners.h"

// Classes
#include <sub_assembly_relationship.h>

assembled_with_fasteners::assembled_with_fasteners() {
   initialize();
   }
assembled_with_fasteners::~assembled_with_fasteners() {
   // Free string attributes
   }
// intialize data members
void assembled_with_fasteners::initialize() {
   // Required attributes
   _sub_assembly = NULL;

   // Optional attributes
   }
// Runtime type identification
int assembled_with_fasteners::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = assembly_joint::DynamicType(ID);
      }
   return result;
   }
assembled_with_fasteners *assembled_with_fasteners::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<assembled_with_fasteners *>(s);
      }
   return NULL;
   }
assembled_with_fasteners *assembled_with_fasteners::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<assembled_with_fasteners *>(s);
      }
   return NULL;
   }
// construction factory
assembled_with_fasteners *assembled_with_fasteners::Construct() {
   assembled_with_fasteners *result = NULL;

   // create the assembled_with_fasteners.
   result = new assembled_with_fasteners();
   return result;
   }
bool assembled_with_fasteners::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: assembled_with_fasteners\r\n");

   // Check for the existence of all required attributes
   if (_sub_assembly == NULL) {
      TRACE("ERROR: _sub_assembly a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (assembly_joint::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
