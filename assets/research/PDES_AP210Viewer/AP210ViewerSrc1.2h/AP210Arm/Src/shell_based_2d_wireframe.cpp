// Source for AP210 application object
//     shell_based_2d_wireframe

// Precompiled include files
#include <StdAfx.h>

#include "shell_based_2d_wireframe.h"

// Classes

shell_based_2d_wireframe::shell_based_2d_wireframe() {
   initialize();
   }
shell_based_2d_wireframe::~shell_based_2d_wireframe() {
   // Free string attributes
   }
// intialize data members
void shell_based_2d_wireframe::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int shell_based_2d_wireframe::DynamicType(int ID) {
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
shell_based_2d_wireframe *shell_based_2d_wireframe::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<shell_based_2d_wireframe *>(s);
      }
   return NULL;
   }
shell_based_2d_wireframe *shell_based_2d_wireframe::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<shell_based_2d_wireframe *>(s);
      }
   return NULL;
   }
// construction factory
shell_based_2d_wireframe *shell_based_2d_wireframe::Construct() {
   shell_based_2d_wireframe *result = NULL;

   // create the shell_based_2d_wireframe.
   result = new shell_based_2d_wireframe();
   return result;
   }
bool shell_based_2d_wireframe::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: shell_based_2d_wireframe\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (feature_shape_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
