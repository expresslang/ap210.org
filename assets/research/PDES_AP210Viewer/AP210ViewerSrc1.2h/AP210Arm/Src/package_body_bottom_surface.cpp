// Source for AP210 application object
//     package_body_bottom_surface

// Precompiled include files
#include <StdAfx.h>

#include "package_body_bottom_surface.h"

// Classes

package_body_bottom_surface::package_body_bottom_surface() {
   initialize();
   }
package_body_bottom_surface::~package_body_bottom_surface() {
   // Free string attributes
   }
// intialize data members
void package_body_bottom_surface::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int package_body_bottom_surface::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = package_body_surface::DynamicType(ID);
      }
   return result;
   }
package_body_bottom_surface *package_body_bottom_surface::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<package_body_bottom_surface *>(s);
      }
   return NULL;
   }
package_body_bottom_surface *package_body_bottom_surface::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<package_body_bottom_surface *>(s);
      }
   return NULL;
   }
// construction factory
package_body_bottom_surface *package_body_bottom_surface::Construct() {
   package_body_bottom_surface *result = NULL;

   // create the package_body_bottom_surface.
   result = new package_body_bottom_surface();
   return result;
   }
bool package_body_bottom_surface::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: package_body_bottom_surface\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (package_body_surface::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
