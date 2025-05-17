// Source for AP210 application object
//     package_body_surface

// Precompiled include files
#include <StdAfx.h>

#include "package_body_surface.h"

// Classes
#include <package_body.h>

package_body_surface::package_body_surface() {
   initialize();
   }
package_body_surface::~package_body_surface() {
   // Free string attributes
   }
// intialize data members
void package_body_surface::initialize() {
   // Required attributes
   _associated_package_body = NULL;

   // Optional attributes
   }
// Runtime type identification
int package_body_surface::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = part_feature::DynamicType(ID);
      }
   return result;
   }
package_body_surface *package_body_surface::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<package_body_surface *>(s);
      }
   return NULL;
   }
package_body_surface *package_body_surface::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<package_body_surface *>(s);
      }
   return NULL;
   }
// construction factory
package_body_surface *package_body_surface::Construct() {
   package_body_surface *result = NULL;

   // create the package_body_surface.
   result = new package_body_surface();
   return result;
   }
bool package_body_surface::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: package_body_surface\r\n");

   // Check for the existence of all required attributes
   if (_associated_package_body == NULL) {
      TRACE("ERROR: _associated_package_body a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (part_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
