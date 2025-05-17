// Source for AP210 application object
//     change_request

// Precompiled include files
#include <StdAfx.h>

#include "change_request.h"

// Classes

change_request::change_request() {
   initialize();
   }
change_request::~change_request() {
   // Free string attributes
   if (_version != NULL) {
      free(_version);
     }
   }
// intialize data members
void change_request::initialize() {
   // Required attributes
   _version = NULL;

   // Optional attributes
   }
// Runtime type identification
int change_request::DynamicType(int ID) {
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
change_request *change_request::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<change_request *>(s);
      }
   return NULL;
   }
change_request *change_request::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<change_request *>(s);
      }
   return NULL;
   }
// construction factory
change_request *change_request::Construct() {
   change_request *result = NULL;

   // create the change_request.
   result = new change_request();
   return result;
   }
bool change_request::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: change_request\r\n");

   // Check for the existence of all required attributes
   if (_consequence == NULL) {
      TRACE("ERROR: _consequence a required attribute is NULL!\r\n");
      result = false;
      }
   if (_version == NULL) {
      TRACE("ERROR: _version a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (work_request::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
