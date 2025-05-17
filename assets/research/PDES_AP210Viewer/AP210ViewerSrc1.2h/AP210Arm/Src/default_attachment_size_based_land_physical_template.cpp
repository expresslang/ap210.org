// Source for AP210 application object
//     default_attachment_size_based_land_physical_template

// Precompiled include files
#include <StdAfx.h>

#include "default_attachment_size_based_land_physical_template.h"

// Classes
#include <connection_zone.h>
#include <connection_zone.h>

default_attachment_size_based_land_physical_template::default_attachment_size_based_land_physical_template() {
   initialize();
   }
default_attachment_size_based_land_physical_template::~default_attachment_size_based_land_physical_template() {
   // Free string attributes
   }
// intialize data members
void default_attachment_size_based_land_physical_template::initialize() {
   // Required attributes
   _minimum_attachment_region_size = NULL;
   _maximum_attachment_region_size = NULL;

   // Optional attributes
   }
// Runtime type identification
int default_attachment_size_based_land_physical_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = default_land_physical_template::DynamicType(ID);
      }
   return result;
   }
default_attachment_size_based_land_physical_template *default_attachment_size_based_land_physical_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<default_attachment_size_based_land_physical_template *>(s);
      }
   return NULL;
   }
default_attachment_size_based_land_physical_template *default_attachment_size_based_land_physical_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<default_attachment_size_based_land_physical_template *>(s);
      }
   return NULL;
   }
// construction factory
default_attachment_size_based_land_physical_template *default_attachment_size_based_land_physical_template::Construct() {
   default_attachment_size_based_land_physical_template *result = NULL;

   // create the default_attachment_size_based_land_physical_template.
   result = new default_attachment_size_based_land_physical_template();
   return result;
   }
bool default_attachment_size_based_land_physical_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: default_attachment_size_based_land_physical_template\r\n");

   // Check for the existence of all required attributes
   if (_minimum_attachment_region_size == NULL) {
      TRACE("ERROR: _minimum_attachment_region_size a required attribute is NULL!\r\n");
      result = false;
      }
   if (_maximum_attachment_region_size == NULL) {
      TRACE("ERROR: _maximum_attachment_region_size a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (default_land_physical_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
