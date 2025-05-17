// Source for AP210 application object
//     surface_prepped_terminal

// Precompiled include files
#include <StdAfx.h>

#include "surface_prepped_terminal.h"

// Classes
#include <surface_finish_specification.h>

surface_prepped_terminal::surface_prepped_terminal() {
   initialize();
   }
surface_prepped_terminal::~surface_prepped_terminal() {
   // Free string attributes
   }
// intialize data members
void surface_prepped_terminal::initialize() {
   // Required attributes
   _surface_preparation = NULL;

   // Optional attributes
   }
// Runtime type identification
int surface_prepped_terminal::DynamicType(int ID) {
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
surface_prepped_terminal *surface_prepped_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<surface_prepped_terminal *>(s);
      }
   return NULL;
   }
surface_prepped_terminal *surface_prepped_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<surface_prepped_terminal *>(s);
      }
   return NULL;
   }
// construction factory
surface_prepped_terminal *surface_prepped_terminal::Construct() {
   surface_prepped_terminal *result = NULL;

   // create the surface_prepped_terminal.
   result = new surface_prepped_terminal();
   return result;
   }
bool surface_prepped_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: surface_prepped_terminal\r\n");

   // Check for the existence of all required attributes
   if (_surface_preparation == NULL) {
      TRACE("ERROR: _surface_preparation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (altered_package_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
