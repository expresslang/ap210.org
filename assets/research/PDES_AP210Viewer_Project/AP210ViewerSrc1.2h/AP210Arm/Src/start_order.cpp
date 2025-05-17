// Source for AP210 application object
//     start_order

// Precompiled include files
#include <StdAfx.h>

#include "start_order.h"

// Classes

start_order::start_order() {
   initialize();
   }
start_order::~start_order() {
   // Free string attributes
   }
// intialize data members
void start_order::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int start_order::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = work_order::DynamicType(ID);
      }
   return result;
   }
start_order *start_order::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<start_order *>(s);
      }
   return NULL;
   }
start_order *start_order::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<start_order *>(s);
      }
   return NULL;
   }
// construction factory
start_order *start_order::Construct() {
   start_order *result = NULL;

   // create the start_order.
   result = new start_order();
   return result;
   }
bool start_order::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: start_order\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (work_order::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
