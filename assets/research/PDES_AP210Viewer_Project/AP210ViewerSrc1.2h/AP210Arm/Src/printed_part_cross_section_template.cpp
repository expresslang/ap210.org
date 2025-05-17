// Source for AP210 application object
//     printed_part_cross_section_template

// Precompiled include files
#include <StdAfx.h>

#include "printed_part_cross_section_template.h"

// Classes
#include <analytical_model.h>
#include <length_data_element.h>
#include <length_data_element.h>

printed_part_cross_section_template::printed_part_cross_section_template() {
   initialize();
   }
printed_part_cross_section_template::~printed_part_cross_section_template() {
   // Free string attributes
   }
// intialize data members
void printed_part_cross_section_template::initialize() {
   // Required attributes
   _transmission_line_model = NULL;
   _maximum_width = NULL;
   _minimum_width = NULL;

   // Optional attributes
   }
// Runtime type identification
int printed_part_cross_section_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = printed_part_template::DynamicType(ID);
      }
   return result;
   }
printed_part_cross_section_template *printed_part_cross_section_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<printed_part_cross_section_template *>(s);
      }
   return NULL;
   }
printed_part_cross_section_template *printed_part_cross_section_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<printed_part_cross_section_template *>(s);
      }
   return NULL;
   }
// construction factory
printed_part_cross_section_template *printed_part_cross_section_template::Construct() {
   printed_part_cross_section_template *result = NULL;

   // create the printed_part_cross_section_template.
   result = new printed_part_cross_section_template();
   return result;
   }
bool printed_part_cross_section_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: printed_part_cross_section_template\r\n");

   // Check for the existence of all required attributes
   if (_transmission_line_model == NULL) {
      TRACE("ERROR: _transmission_line_model a required attribute is NULL!\r\n");
      result = false;
      }
   if (_maximum_width == NULL) {
      TRACE("ERROR: _maximum_width a required attribute is NULL!\r\n");
      result = false;
      }
   if (_minimum_width == NULL) {
      TRACE("ERROR: _minimum_width a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (printed_part_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
