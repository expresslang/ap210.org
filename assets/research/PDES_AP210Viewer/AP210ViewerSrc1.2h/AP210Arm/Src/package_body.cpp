// Source for AP210 application object
//     package_body

// Precompiled include files
#include <StdAfx.h>

#include "package_body.h"

// Classes
#include <ee_material.h>

package_body::package_body() {
   initialize();
   }
package_body::~package_body() {
   // Free string attributes
   }
// intialize data members
void package_body::initialize() {
   // Required attributes
   _body_material = NULL;

   // Optional attributes
   }
// Runtime type identification
int package_body::DynamicType(int ID) {
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
package_body *package_body::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<package_body *>(s);
      }
   return NULL;
   }
package_body *package_body::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<package_body *>(s);
      }
   return NULL;
   }
// construction factory
package_body *package_body::Construct() {
   package_body *result = NULL;

   // create the package_body.
   result = new package_body();
   return result;
   }
bool package_body::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: package_body\r\n");

   // Check for the existence of all required attributes
   if (_body_material == NULL) {
      TRACE("ERROR: _body_material a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (part_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
