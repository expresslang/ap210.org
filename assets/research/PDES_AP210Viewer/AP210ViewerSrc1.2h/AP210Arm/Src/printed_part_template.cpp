// Source for AP210 application object
//     printed_part_template

// Precompiled include files
#include <StdAfx.h>

#include "printed_part_template.h"

// Classes
#include <functional_unit_usage_view.h>
#include <printed_part_cross_section_template.h>

printed_part_template::printed_part_template() {
   initialize();
   }
printed_part_template::~printed_part_template() {
   // Free string attributes
   }
// intialize data members
void printed_part_template::initialize() {
   // Required attributes
   _implemented_function = NULL;

   // Optional attributes
   _cross_section = NULL;
   }
// Runtime type identification
int printed_part_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = part_template::DynamicType(ID);
      }
   return result;
   }
printed_part_template *printed_part_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<printed_part_template *>(s);
      }
   return NULL;
   }
printed_part_template *printed_part_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<printed_part_template *>(s);
      }
   return NULL;
   }
// construction factory
printed_part_template *printed_part_template::Construct() {
   printed_part_template *result = NULL;

   // create the printed_part_template.
   result = new printed_part_template();
   return result;
   }
bool printed_part_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: printed_part_template\r\n");

   // Check for the existence of all required attributes
   if (_characterized_material == NULL) {
      TRACE("ERROR: _characterized_material a required attribute is NULL!\r\n");
      result = false;
      }
   if (_implemented_function == NULL) {
      TRACE("ERROR: _implemented_function a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (part_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
