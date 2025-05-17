// Source for AP210 application object
//     shape_formed_terminal

// Precompiled include files
#include <StdAfx.h>

#include "shape_formed_terminal.h"

// Classes
#include <lead_form_specification.h>

shape_formed_terminal::shape_formed_terminal() {
   initialize();
   }
shape_formed_terminal::~shape_formed_terminal() {
   // Free string attributes
   }
// intialize data members
void shape_formed_terminal::initialize() {
   // Required attributes
   _terminal_form_specification = NULL;

   // Optional attributes
   }
// Runtime type identification
int shape_formed_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = altered_package_terminal::DynamicType(ID);
      }
   return result;
   }
shape_formed_terminal *shape_formed_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<shape_formed_terminal *>(s);
      }
   return NULL;
   }
shape_formed_terminal *shape_formed_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<shape_formed_terminal *>(s);
      }
   return NULL;
   }
// construction factory
shape_formed_terminal *shape_formed_terminal::Construct() {
   shape_formed_terminal *result = NULL;

   // create the shape_formed_terminal.
   result = new shape_formed_terminal();
   return result;
   }
bool shape_formed_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: shape_formed_terminal\r\n");

   // Check for the existence of all required attributes
   if (_terminal_form_specification == NULL) {
      TRACE("ERROR: _terminal_form_specification a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (altered_package_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
