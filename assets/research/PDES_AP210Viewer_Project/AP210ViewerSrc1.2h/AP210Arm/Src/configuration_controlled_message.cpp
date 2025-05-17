// Source for AP210 application object
//     configuration_controlled_message

// Precompiled include files
#include <StdAfx.h>

#include "configuration_controlled_message.h"

// Classes

configuration_controlled_message::configuration_controlled_message() {
   initialize();
   }
configuration_controlled_message::~configuration_controlled_message() {
   // Free string attributes
   if (_message_content != NULL) {
      free(_message_content);
     }
   }
// intialize data members
void configuration_controlled_message::initialize() {
   // Required attributes
   _message_content = NULL;

   // Optional attributes
   }
// Runtime type identification
int configuration_controlled_message::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = managed_design_object::DynamicType(ID);
      }
   return result;
   }
configuration_controlled_message *configuration_controlled_message::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<configuration_controlled_message *>(s);
      }
   return NULL;
   }
configuration_controlled_message *configuration_controlled_message::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<configuration_controlled_message *>(s);
      }
   return NULL;
   }
// construction factory
configuration_controlled_message *configuration_controlled_message::Construct() {
   configuration_controlled_message *result = NULL;

   // create the configuration_controlled_message.
   result = new configuration_controlled_message();
   return result;
   }
bool configuration_controlled_message::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: configuration_controlled_message\r\n");

   // Check for the existence of all required attributes
   if (_message_source == NULL) {
      TRACE("ERROR: _message_source a required attribute is NULL!\r\n");
      result = false;
      }
   if (_message_content == NULL) {
      TRACE("ERROR: _message_content a required attribute is NULL!\r\n");
      result = false;
      }
   if (_message_type_specification == NULL) {
      TRACE("ERROR: _message_type_specification a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
