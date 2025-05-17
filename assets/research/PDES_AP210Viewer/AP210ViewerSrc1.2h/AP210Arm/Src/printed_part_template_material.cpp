// Source for AP210 application object
//     printed_part_template_material

// Precompiled include files
#include <StdAfx.h>

#include "printed_part_template_material.h"

// Classes
#include <length_data_element.h>
#include <ee_material.h>
#include <length_data_element.h>

printed_part_template_material::printed_part_template_material() {
   initialize();
   }
printed_part_template_material::~printed_part_template_material() {
   // Free string attributes
   }
// intialize data members
void printed_part_template_material::initialize() {
   // Required attributes
   _maximum_thickness = NULL;
   _required_material = NULL;
   _minimum_thickness = NULL;

   // Optional attributes
   }
// Runtime type identification
int printed_part_template_material::DynamicType(int ID) {
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
printed_part_template_material *printed_part_template_material::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<printed_part_template_material *>(s);
      }
   return NULL;
   }
printed_part_template_material *printed_part_template_material::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<printed_part_template_material *>(s);
      }
   return NULL;
   }
// construction factory
printed_part_template_material *printed_part_template_material::Construct() {
   printed_part_template_material *result = NULL;

   // create the printed_part_template_material.
   result = new printed_part_template_material();
   return result;
   }
bool printed_part_template_material::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: printed_part_template_material\r\n");

   // Check for the existence of all required attributes
   if (_maximum_thickness == NULL) {
      TRACE("ERROR: _maximum_thickness a required attribute is NULL!\r\n");
      result = false;
      }
   if (_required_material == NULL) {
      TRACE("ERROR: _required_material a required attribute is NULL!\r\n");
      result = false;
      }
   if (_minimum_thickness == NULL) {
      TRACE("ERROR: _minimum_thickness a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
