// Source for AP210 application object
//     package_terminal_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "package_terminal_occurrence.h"

// Classes
#include <package_terminal.h>
#include <packaged_component.h>

package_terminal_occurrence::package_terminal_occurrence() {
   initialize();
   }
package_terminal_occurrence::~package_terminal_occurrence() {
   // Free string attributes
   }
// intialize data members
void package_terminal_occurrence::initialize() {
   // Required attributes
   _definition = NULL;
   _associated_component = NULL;

   // Optional attributes
   }
// Runtime type identification
int package_terminal_occurrence::DynamicType(int ID) {
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
package_terminal_occurrence *package_terminal_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<package_terminal_occurrence *>(s);
      }
   return NULL;
   }
package_terminal_occurrence *package_terminal_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<package_terminal_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
package_terminal_occurrence *package_terminal_occurrence::Construct() {
   package_terminal_occurrence *result = NULL;

   // create the package_terminal_occurrence.
   result = new package_terminal_occurrence();
   return result;
   }
bool package_terminal_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: package_terminal_occurrence\r\n");

   // Check for the existence of all required attributes
   if (_definition == NULL) {
      TRACE("ERROR: _definition a required attribute is NULL!\r\n");
      result = false;
      }
   if (_associated_component == NULL) {
      TRACE("ERROR: _associated_component a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
