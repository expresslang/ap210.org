// Source for AP210 application object
//     ee_text

// Precompiled include files
#include <StdAfx.h>

#include "ee_text.h"

// Classes

ee_text::ee_text() {
   initialize();
   }
ee_text::~ee_text() {
   // Free string attributes
   if (_content != NULL) {
      free(_content);
     }
   }
// intialize data members
void ee_text::initialize() {
   // Required attributes
   _content = NULL;

   // Optional attributes
   }
// Runtime type identification
int ee_text::DynamicType(int ID) {
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
ee_text *ee_text::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_text *>(s);
      }
   return NULL;
   }
ee_text *ee_text::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_text *>(s);
      }
   return NULL;
   }
// construction factory
ee_text *ee_text::Construct() {
   ee_text *result = NULL;

   // create the ee_text.
   result = new ee_text();
   return result;
   }
bool ee_text::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_text\r\n");

   // Check for the existence of all required attributes
   if (_content == NULL) {
      TRACE("ERROR: _content a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
