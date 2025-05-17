// Source for AP210 application object
//     open_shell_based_surface

// Precompiled include files
#include <StdAfx.h>

#include "open_shell_based_surface.h"

// Classes

open_shell_based_surface::open_shell_based_surface() {
   initialize();
   }
open_shell_based_surface::~open_shell_based_surface() {
   // Free string attributes
   }
// intialize data members
void open_shell_based_surface::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int open_shell_based_surface::DynamicType(int ID) {
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
open_shell_based_surface *open_shell_based_surface::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<open_shell_based_surface *>(s);
      }
   return NULL;
   }
open_shell_based_surface *open_shell_based_surface::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<open_shell_based_surface *>(s);
      }
   return NULL;
   }
// construction factory
open_shell_based_surface *open_shell_based_surface::Construct() {
   open_shell_based_surface *result = NULL;

   // create the open_shell_based_surface.
   result = new open_shell_based_surface();
   return result;
   }
bool open_shell_based_surface::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: open_shell_based_surface\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (feature_shape_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
