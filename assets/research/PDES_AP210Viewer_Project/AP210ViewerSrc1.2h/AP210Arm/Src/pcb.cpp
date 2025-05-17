// Source for AP210 application object
//     pcb

// Precompiled include files
#include <StdAfx.h>

#include "pcb.h"

// Classes

pcb::pcb() {
   initialize();
   }
pcb::~pcb() {
   // Free string attributes
   }
// intialize data members
void pcb::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int pcb::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = interconnect_module::DynamicType(ID);
      }
   return result;
   }
pcb *pcb::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<pcb *>(s);
      }
   return NULL;
   }
pcb *pcb::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<pcb *>(s);
      }
   return NULL;
   }
// construction factory
pcb *pcb::Construct() {
   pcb *result = NULL;

   // create the pcb.
   result = new pcb();
   return result;
   }
bool pcb::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: pcb\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (interconnect_module::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
