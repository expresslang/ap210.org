// Source for AP210 application object
//     SetOfwork_request

// Precompiled include files
#include <StdAfx.h>

#include "SetOfwork_request.h"

// Classes
#include <work_request.h>

SetOfwork_request::SetOfwork_request() {
   initialize();
   }
SetOfwork_request::~SetOfwork_request() {
   // Free string attributes
   }
// intialize data members
void SetOfwork_request::initialize() {
   // Required attributes
   _work_request = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfwork_request::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfwork_request *SetOfwork_request::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfwork_request *>(s);
      }
   return NULL;
   }
SetOfwork_request *SetOfwork_request::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfwork_request *>(s);
      }
   return NULL;
   }
// construction factory
SetOfwork_request *SetOfwork_request::Construct() {
   SetOfwork_request *result = NULL;

   // create the SetOfwork_request.
   result = new SetOfwork_request();
   return result;
   }
bool SetOfwork_request::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfwork_request\r\n");

   // Check for the existence of all required attributes
   if (_work_request == NULL) {
      TRACE("ERROR: _work_request a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
