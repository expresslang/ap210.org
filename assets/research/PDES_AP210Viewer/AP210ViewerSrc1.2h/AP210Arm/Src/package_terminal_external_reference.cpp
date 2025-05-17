// Source for AP210 application object
//     package_terminal_external_reference

// Precompiled include files
#include <StdAfx.h>

#include "package_terminal_external_reference.h"

// Classes
#include <package_external_reference.h>

package_terminal_external_reference::package_terminal_external_reference() {
   initialize();
   }
package_terminal_external_reference::~package_terminal_external_reference() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void package_terminal_external_reference::initialize() {
   // Required attributes
   _associated_definition = NULL;
   _name = NULL;

   // Optional attributes
   }
// Runtime type identification
int package_terminal_external_reference::DynamicType(int ID) {
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
package_terminal_external_reference *package_terminal_external_reference::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<package_terminal_external_reference *>(s);
      }
   return NULL;
   }
package_terminal_external_reference *package_terminal_external_reference::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<package_terminal_external_reference *>(s);
      }
   return NULL;
   }
// construction factory
package_terminal_external_reference *package_terminal_external_reference::Construct() {
   package_terminal_external_reference *result = NULL;

   // create the package_terminal_external_reference.
   result = new package_terminal_external_reference();
   return result;
   }
bool package_terminal_external_reference::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: package_terminal_external_reference\r\n");

   // Check for the existence of all required attributes
   if (_associated_definition == NULL) {
      TRACE("ERROR: _associated_definition a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
