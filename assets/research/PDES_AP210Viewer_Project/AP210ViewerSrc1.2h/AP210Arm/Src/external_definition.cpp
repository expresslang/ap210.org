// Source for AP210 application object
//     external_definition

// Precompiled include files
#include <StdAfx.h>

#include "external_definition.h"

// Classes

external_definition::external_definition() {
   initialize();
   }
external_definition::~external_definition() {
   // Free string attributes
   if (_code != NULL) {
      free(_code);
     }
   if (_code_value != NULL) {
      free(_code_value);
     }
   }
// intialize data members
void external_definition::initialize() {
   // Required attributes
   _code = NULL;
   _code_value = NULL;

   // Optional attributes
   }
// Runtime type identification
int external_definition::DynamicType(int ID) {
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
external_definition *external_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<external_definition *>(s);
      }
   return NULL;
   }
external_definition *external_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<external_definition *>(s);
      }
   return NULL;
   }
// construction factory
external_definition *external_definition::Construct() {
   external_definition *result = NULL;

   // create the external_definition.
   result = new external_definition();
   return result;
   }
bool external_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: external_definition\r\n");

   // Check for the existence of all required attributes
   if (_code == NULL) {
      TRACE("ERROR: _code a required attribute is NULL!\r\n");
      result = false;
      }
   if (_code_value == NULL) {
      TRACE("ERROR: _code_value a required attribute is NULL!\r\n");
      result = false;
      }
   if (_reference_document == NULL) {
      TRACE("ERROR: _reference_document a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
