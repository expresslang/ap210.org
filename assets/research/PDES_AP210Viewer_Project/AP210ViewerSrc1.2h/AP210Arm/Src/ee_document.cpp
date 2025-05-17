// Source for AP210 application object
//     ee_document

// Precompiled include files
#include <StdAfx.h>

#include "ee_document.h"

// Classes
#include <ee_approval.h>
#include <ee_document_identifier.h>
#include <date_and_time.h>
#include <security_classification.h>

ee_document::ee_document() {
   initialize();
   }
ee_document::~ee_document() {
   // Free string attributes
   if (_revision != NULL) {
      free(_revision);
     }
   if (_document_name != NULL) {
      free(_document_name);
     }
   }
// intialize data members
void ee_document::initialize() {
   // Required attributes
   _base_identifier = NULL;
   _creation_date = NULL;
   _document_name = NULL;

   // Optional attributes
   _document_approval = NULL;
   _security_code = NULL;
   _revision = NULL;
   }
// Runtime type identification
int ee_document::DynamicType(int ID) {
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
ee_document *ee_document::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_document *>(s);
      }
   return NULL;
   }
ee_document *ee_document::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_document *>(s);
      }
   return NULL;
   }
// construction factory
ee_document *ee_document::Construct() {
   ee_document *result = NULL;

   // create the ee_document.
   result = new ee_document();
   return result;
   }
bool ee_document::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_document\r\n");

   // Check for the existence of all required attributes
   if (_publisher == NULL) {
      TRACE("ERROR: _publisher a required attribute is NULL!\r\n");
      result = false;
      }
   if (_base_identifier == NULL) {
      TRACE("ERROR: _base_identifier a required attribute is NULL!\r\n");
      result = false;
      }
   if (_creation_date == NULL) {
      TRACE("ERROR: _creation_date a required attribute is NULL!\r\n");
      result = false;
      }
   if (_document_name == NULL) {
      TRACE("ERROR: _document_name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
