// Source for AP210 application object
//     start_request

// Precompiled include files
#include <StdAfx.h>

#include "start_request.h"

// Classes

start_request::start_request() {
   initialize();
   }
start_request::~start_request() {
   // Free string attributes
   }
// intialize data members
void start_request::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int start_request::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = work_request::DynamicType(ID);
      }
   return result;
   }
start_request *start_request::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<start_request *>(s);
      }
   return NULL;
   }
start_request *start_request::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<start_request *>(s);
      }
   return NULL;
   }
// construction factory
start_request *start_request::Construct() {
   start_request *result = NULL;

   // create the start_request.
   result = new start_request();
   return result;
   }
bool start_request::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: start_request\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (work_request::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
