// Source for AP210 application object
//     process_specification

// Precompiled include files
#include <StdAfx.h>

#include "process_specification.h"

// Classes

process_specification::process_specification() {
   initialize();
   }
process_specification::~process_specification() {
   // Free string attributes
   }
// intialize data members
void process_specification::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int process_specification::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = ee_specification::DynamicType(ID);
      }
   return result;
   }
process_specification *process_specification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<process_specification *>(s);
      }
   return NULL;
   }
process_specification *process_specification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<process_specification *>(s);
      }
   return NULL;
   }
// construction factory
process_specification *process_specification::Construct() {
   process_specification *result = NULL;

   // create the process_specification.
   result = new process_specification();
   return result;
   }
bool process_specification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: process_specification\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (ee_specification::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
