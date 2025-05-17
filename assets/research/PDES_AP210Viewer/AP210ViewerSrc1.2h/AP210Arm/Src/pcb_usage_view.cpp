// Source for AP210 application object
//     pcb_usage_view

// Precompiled include files
#include <StdAfx.h>

#include "pcb_usage_view.h"

// Classes

pcb_usage_view::pcb_usage_view() {
   initialize();
   }
pcb_usage_view::~pcb_usage_view() {
   // Free string attributes
   }
// intialize data members
void pcb_usage_view::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int pcb_usage_view::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = interconnect_module_usage_view::DynamicType(ID);
      }
   return result;
   }
pcb_usage_view *pcb_usage_view::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<pcb_usage_view *>(s);
      }
   return NULL;
   }
pcb_usage_view *pcb_usage_view::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<pcb_usage_view *>(s);
      }
   return NULL;
   }
// construction factory
pcb_usage_view *pcb_usage_view::Construct() {
   pcb_usage_view *result = NULL;

   // create the pcb_usage_view.
   result = new pcb_usage_view();
   return result;
   }
bool pcb_usage_view::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: pcb_usage_view\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (interconnect_module_usage_view::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
