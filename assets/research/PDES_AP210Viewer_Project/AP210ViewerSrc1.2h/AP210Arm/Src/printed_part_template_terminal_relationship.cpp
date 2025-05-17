// Source for AP210 application object
//     printed_part_template_terminal_relationship

// Precompiled include files
#include <StdAfx.h>

#include "printed_part_template_terminal_relationship.h"

// Classes
#include <printed_part_template_terminal.h>
#include <printed_part_template_terminal.h>

printed_part_template_terminal_relationship::printed_part_template_terminal_relationship() {
   initialize();
   }
printed_part_template_terminal_relationship::~printed_part_template_terminal_relationship() {
   // Free string attributes
   }
// intialize data members
void printed_part_template_terminal_relationship::initialize() {
   // Required attributes
   _related_printed_part_terminal = NULL;
   _relating_printed_part_terminal = NULL;

   // Optional attributes
   }
// Runtime type identification
int printed_part_template_terminal_relationship::DynamicType(int ID) {
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
printed_part_template_terminal_relationship *printed_part_template_terminal_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<printed_part_template_terminal_relationship *>(s);
      }
   return NULL;
   }
printed_part_template_terminal_relationship *printed_part_template_terminal_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<printed_part_template_terminal_relationship *>(s);
      }
   return NULL;
   }
// construction factory
printed_part_template_terminal_relationship *printed_part_template_terminal_relationship::Construct() {
   printed_part_template_terminal_relationship *result = NULL;

   // create the printed_part_template_terminal_relationship.
   result = new printed_part_template_terminal_relationship();
   return result;
   }
bool printed_part_template_terminal_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: printed_part_template_terminal_relationship\r\n");

   // Check for the existence of all required attributes
   if (_related_printed_part_terminal == NULL) {
      TRACE("ERROR: _related_printed_part_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   if (_relating_printed_part_terminal == NULL) {
      TRACE("ERROR: _relating_printed_part_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
