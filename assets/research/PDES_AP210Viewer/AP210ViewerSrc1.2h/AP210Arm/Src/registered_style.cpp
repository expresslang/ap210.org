// Source for AP210 application object
//     registered_style

// Precompiled include files
#include <StdAfx.h>

#include "registered_style.h"

// Classes
#include <ee_document.h>

registered_style::registered_style() {
   initialize();
   }
registered_style::~registered_style() {
   // Free string attributes
   if (_case_style_code != NULL) {
      free(_case_style_code);
     }
   }
// intialize data members
void registered_style::initialize() {
   // Required attributes
   _case_style_code = NULL;
   _registration_document = NULL;

   // Optional attributes
   }
// Runtime type identification
int registered_style::DynamicType(int ID) {
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
registered_style *registered_style::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<registered_style *>(s);
      }
   return NULL;
   }
registered_style *registered_style::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<registered_style *>(s);
      }
   return NULL;
   }
// construction factory
registered_style *registered_style::Construct() {
   registered_style *result = NULL;

   // create the registered_style.
   result = new registered_style();
   return result;
   }
bool registered_style::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: registered_style\r\n");

   // Check for the existence of all required attributes
   if (_case_style_code == NULL) {
      TRACE("ERROR: _case_style_code a required attribute is NULL!\r\n");
      result = false;
      }
   if (_registration_document == NULL) {
      TRACE("ERROR: _registration_document a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
