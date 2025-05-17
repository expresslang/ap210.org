// Source for AP210 application object
//     registered_font

// Precompiled include files
#include <StdAfx.h>

#include "registered_font.h"

// Classes
#include <ee_document.h>

registered_font::registered_font() {
   initialize();
   }
registered_font::~registered_font() {
   // Free string attributes
   if (_font_code != NULL) {
      free(_font_code);
     }
   }
// intialize data members
void registered_font::initialize() {
   // Required attributes
   _registration_document = NULL;
   _font_code = NULL;

   // Optional attributes
   }
// Runtime type identification
int registered_font::DynamicType(int ID) {
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
registered_font *registered_font::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<registered_font *>(s);
      }
   return NULL;
   }
registered_font *registered_font::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<registered_font *>(s);
      }
   return NULL;
   }
// construction factory
registered_font *registered_font::Construct() {
   registered_font *result = NULL;

   // create the registered_font.
   result = new registered_font();
   return result;
   }
bool registered_font::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: registered_font\r\n");

   // Check for the existence of all required attributes
   if (_registration_document == NULL) {
      TRACE("ERROR: _registration_document a required attribute is NULL!\r\n");
      result = false;
      }
   if (_font_code == NULL) {
      TRACE("ERROR: _font_code a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
