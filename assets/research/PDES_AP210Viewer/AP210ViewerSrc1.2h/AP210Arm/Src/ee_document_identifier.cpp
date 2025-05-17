// Source for AP210 application object
//     ee_document_identifier

// Precompiled include files
#include <StdAfx.h>

#include "ee_document_identifier.h"

// Classes

ee_document_identifier::ee_document_identifier() {
   initialize();
   }
ee_document_identifier::~ee_document_identifier() {
   // Free string attributes
   if (_identifier_name != NULL) {
      free(_identifier_name);
     }
   if (_assigned_value != NULL) {
      free(_assigned_value);
     }
   }
// intialize data members
void ee_document_identifier::initialize() {
   // Required attributes
   _identifier_name = NULL;
   _assigned_value = NULL;

   // Optional attributes
   }
// Runtime type identification
int ee_document_identifier::DynamicType(int ID) {
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
ee_document_identifier *ee_document_identifier::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_document_identifier *>(s);
      }
   return NULL;
   }
ee_document_identifier *ee_document_identifier::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_document_identifier *>(s);
      }
   return NULL;
   }
// construction factory
ee_document_identifier *ee_document_identifier::Construct() {
   ee_document_identifier *result = NULL;

   // create the ee_document_identifier.
   result = new ee_document_identifier();
   return result;
   }
bool ee_document_identifier::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_document_identifier\r\n");

   // Check for the existence of all required attributes
   if (_identifier_name == NULL) {
      TRACE("ERROR: _identifier_name a required attribute is NULL!\r\n");
      result = false;
      }
   if (_assigned_value == NULL) {
      TRACE("ERROR: _assigned_value a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
