// Source for AP210 application object
//     structured_text

// Precompiled include files
#include <StdAfx.h>

#include "structured_text.h"

// Classes
#include <external_definition.h>
#include <ee_text.h>
#include <structured_text.h>

structured_text::structured_text() {
   initialize();
   }
structured_text::~structured_text() {
   // Free string attributes
   }
// intialize data members
void structured_text::initialize() {
   // Required attributes
   _content_markup = NULL;

   // Optional attributes
   _plain_text_content = NULL;
   _precedent_structured_text = NULL;
   }
// Runtime type identification
int structured_text::DynamicType(int ID) {
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
structured_text *structured_text::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<structured_text *>(s);
      }
   return NULL;
   }
structured_text *structured_text::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<structured_text *>(s);
      }
   return NULL;
   }
// construction factory
structured_text *structured_text::Construct() {
   structured_text *result = NULL;

   // create the structured_text.
   result = new structured_text();
   return result;
   }
bool structured_text::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: structured_text\r\n");

   // Check for the existence of all required attributes
   if (_content_markup == NULL) {
      TRACE("ERROR: _content_markup a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
