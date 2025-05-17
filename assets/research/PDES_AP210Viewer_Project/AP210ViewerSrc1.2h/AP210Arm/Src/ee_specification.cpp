// Source for AP210 application object
//     ee_specification

// Precompiled include files
#include <StdAfx.h>

#include "ee_specification.h"

// Classes

ee_specification::ee_specification() {
   initialize();
   }
ee_specification::~ee_specification() {
   // Free string attributes
   if (_code_or_identifier != NULL) {
      free(_code_or_identifier);
     }
   }
// intialize data members
void ee_specification::initialize() {
   // Required attributes

   // Optional attributes
   _code_or_identifier = NULL;
   }
// Runtime type identification
int ee_specification::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = ee_document::DynamicType(ID);
      }
   return result;
   }
ee_specification *ee_specification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_specification *>(s);
      }
   return NULL;
   }
ee_specification *ee_specification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_specification *>(s);
      }
   return NULL;
   }
// construction factory
ee_specification *ee_specification::Construct() {
   ee_specification *result = NULL;

   // create the ee_specification.
   result = new ee_specification();
   return result;
   }
bool ee_specification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_specification\r\n");

   // Check for the existence of all required attributes
   if (_source == NULL) {
      TRACE("ERROR: _source a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (ee_document::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
