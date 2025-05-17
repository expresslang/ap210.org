// Source for AP210 application object
//     line_width_class

// Precompiled include files
#include <StdAfx.h>

#include "line_width_class.h"

// Classes

line_width_class::line_width_class() {
   initialize();
   }
line_width_class::~line_width_class() {
   // Free string attributes
   if (_class_name != NULL) {
      free(_class_name);
     }
   }
// intialize data members
void line_width_class::initialize() {
   // Required attributes
   _class_name = NULL;

   // Optional attributes
   }
// Runtime type identification
int line_width_class::DynamicType(int ID) {
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
line_width_class *line_width_class::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<line_width_class *>(s);
      }
   return NULL;
   }
line_width_class *line_width_class::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<line_width_class *>(s);
      }
   return NULL;
   }
// construction factory
line_width_class *line_width_class::Construct() {
   line_width_class *result = NULL;

   // create the line_width_class.
   result = new line_width_class();
   return result;
   }
bool line_width_class::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: line_width_class\r\n");

   // Check for the existence of all required attributes
   if (_class_member == NULL) {
      TRACE("ERROR: _class_member a required attribute is NULL!\r\n");
      result = false;
      }
   if (_class_name == NULL) {
      TRACE("ERROR: _class_name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
