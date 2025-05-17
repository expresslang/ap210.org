// Source for AP210 application object
//     laminate_text_string_component

// Precompiled include files
#include <StdAfx.h>

#include "laminate_text_string_component.h"

// Classes

laminate_text_string_component::laminate_text_string_component() {
   initialize();
   }
laminate_text_string_component::~laminate_text_string_component() {
   // Free string attributes
   if (_message != NULL) {
      free(_message);
     }
   }
// intialize data members
void laminate_text_string_component::initialize() {
   // Required attributes
   _message = NULL;

   // Optional attributes
   }
// Runtime type identification
int laminate_text_string_component::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = array_placement_group::DynamicType(ID);
      }
   if (result == 0) {
      result = laminate_component::DynamicType(ID);
      }
   return result;
   }
laminate_text_string_component *laminate_text_string_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<laminate_text_string_component *>(s);
      }
   return NULL;
   }
laminate_text_string_component *laminate_text_string_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<laminate_text_string_component *>(s);
      }
   return NULL;
   }
// construction factory
laminate_text_string_component *laminate_text_string_component::Construct() {
   laminate_text_string_component *result = NULL;

   // create the laminate_text_string_component.
   result = new laminate_text_string_component();
   return result;
   }
bool laminate_text_string_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: laminate_text_string_component\r\n");

   // Check for the existence of all required attributes
   if (_message == NULL) {
      TRACE("ERROR: _message a required attribute is NULL!\r\n");
      result = false;
      }
   if (_of_horizontal_justification == NULL) {
      TRACE("ERROR: _of_horizontal_justification a required attribute is NULL!\r\n");
      result = false;
      }
   if (_of_vertical_justification == NULL) {
      TRACE("ERROR: _of_vertical_justification a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (array_placement_group::hasRequiredAttributes() == false) {
      result = false;
      }
   if (laminate_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
