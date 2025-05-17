// Source for AP210 application object
//     part_text_template

// Precompiled include files
#include <StdAfx.h>

#include "part_text_template.h"

// Classes
#include <length_data_element.h>
#include <length_data_element.h>
#include <angle_data_element.h>
#include <length_data_element.h>

part_text_template::part_text_template() {
   initialize();
   }
part_text_template::~part_text_template() {
   // Free string attributes
   }
// intialize data members
void part_text_template::initialize() {
   // Required attributes
   _maximum_font_horizontal_extent = NULL;
   _maximum_font_vertical_extent = NULL;
   _slant_angle = NULL;
   _stroke_width = NULL;

   // Optional attributes
   }
// Runtime type identification
int part_text_template::DynamicType(int ID) {
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
part_text_template *part_text_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<part_text_template *>(s);
      }
   return NULL;
   }
part_text_template *part_text_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<part_text_template *>(s);
      }
   return NULL;
   }
// construction factory
part_text_template *part_text_template::Construct() {
   part_text_template *result = NULL;

   // create the part_text_template.
   result = new part_text_template();
   return result;
   }
bool part_text_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: part_text_template\r\n");

   // Check for the existence of all required attributes
   if (_font == NULL) {
      TRACE("ERROR: _font a required attribute is NULL!\r\n");
      result = false;
      }
   if (_maximum_font_horizontal_extent == NULL) {
      TRACE("ERROR: _maximum_font_horizontal_extent a required attribute is NULL!\r\n");
      result = false;
      }
   if (_maximum_font_vertical_extent == NULL) {
      TRACE("ERROR: _maximum_font_vertical_extent a required attribute is NULL!\r\n");
      result = false;
      }
   if (_slant_angle == NULL) {
      TRACE("ERROR: _slant_angle a required attribute is NULL!\r\n");
      result = false;
      }
   if (_stroke_width == NULL) {
      TRACE("ERROR: _stroke_width a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (part_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
