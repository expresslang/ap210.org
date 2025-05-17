// Source for AP210 application object
//     package_terminal

// Precompiled include files
#include <StdAfx.h>

#include "package_terminal.h"

// Classes
#include <material_assembly_relationship.h>
#include <material_assembly_relationship.h>
#include <length_data_element.h>
#include <length_data_element.h>

package_terminal::package_terminal() {
   initialize();
   }
package_terminal::~package_terminal() {
   // Free string attributes
   }
// intialize data members
void package_terminal::initialize() {
   // Required attributes
   _terminal_surface_material = NULL;
   _terminal_core_material = NULL;

   // Optional attributes
   _minimum_terminal_diametrical_extent = NULL;
   _maximum_terminal_diametrical_extent = NULL;
   }
// Runtime type identification
int package_terminal::DynamicType(int ID) {
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
package_terminal *package_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<package_terminal *>(s);
      }
   return NULL;
   }
package_terminal *package_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<package_terminal *>(s);
      }
   return NULL;
   }
// construction factory
package_terminal *package_terminal::Construct() {
   package_terminal *result = NULL;

   // create the package_terminal.
   result = new package_terminal();
   return result;
   }
bool package_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: package_terminal\r\n");

   // Check for the existence of all required attributes
   if (_external_connection_zone == NULL) {
      TRACE("ERROR: _external_connection_zone a required attribute is NULL!\r\n");
      result = false;
      }
   if (_terminal_surface_material == NULL) {
      TRACE("ERROR: _terminal_surface_material a required attribute is NULL!\r\n");
      result = false;
      }
   if (_terminal_core_material == NULL) {
      TRACE("ERROR: _terminal_core_material a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (part_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
