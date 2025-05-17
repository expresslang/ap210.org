// Source for AP210 application object
//     laminate_text_component

// Precompiled include files
#include <StdAfx.h>

#include "laminate_text_component.h"

// Classes

laminate_text_component::laminate_text_component() {
   initialize();
   }
laminate_text_component::~laminate_text_component() {
   // Free string attributes
   if (_of_character != NULL) {
      free(_of_character);
     }
   }
// intialize data members
void laminate_text_component::initialize() {
   // Required attributes
   _of_character = NULL;

   // Optional attributes
   }
// Runtime type identification
int laminate_text_component::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = laminate_component::DynamicType(ID);
      }
   return result;
   }
laminate_text_component *laminate_text_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<laminate_text_component *>(s);
      }
   return NULL;
   }
laminate_text_component *laminate_text_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<laminate_text_component *>(s);
      }
   return NULL;
   }
// construction factory
laminate_text_component *laminate_text_component::Construct() {
   laminate_text_component *result = NULL;

   // create the laminate_text_component.
   result = new laminate_text_component();
   return result;
   }
bool laminate_text_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: laminate_text_component\r\n");

   // Check for the existence of all required attributes
   if (_of_character == NULL) {
      TRACE("ERROR: _of_character a required attribute is NULL!\r\n");
      result = false;
      }
   if (_stratum_feature_implementation == NULL) {
      TRACE("ERROR: _stratum_feature_implementation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (laminate_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
