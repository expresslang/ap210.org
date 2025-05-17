// Source for AP210 application object
//     styled_text

// Precompiled include files
#include <StdAfx.h>

#include "styled_text.h"

// Classes

styled_text::styled_text() {
   initialize();
   }
styled_text::~styled_text() {
   // Free string attributes
   }
// intialize data members
void styled_text::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int styled_text::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = feature_shape_definition::DynamicType(ID);
      }
   return result;
   }
styled_text *styled_text::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<styled_text *>(s);
      }
   return NULL;
   }
styled_text *styled_text::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<styled_text *>(s);
      }
   return NULL;
   }
// construction factory
styled_text *styled_text::Construct() {
   styled_text *result = NULL;

   // create the styled_text.
   result = new styled_text();
   return result;
   }
bool styled_text::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: styled_text\r\n");

   // Check for the existence of all required attributes
   if (_text_font == NULL) {
      TRACE("ERROR: _text_font a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (feature_shape_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
