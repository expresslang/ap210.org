// Source for AP210 application object
//     via_template_terminal

// Precompiled include files
#include <StdAfx.h>

#include "via_template_terminal.h"

// Classes
#include <via_template.h>
#include <inter_stratum_extent.h>

via_template_terminal::via_template_terminal() {
   initialize();
   }
via_template_terminal::~via_template_terminal() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void via_template_terminal::initialize() {
   // Required attributes
   _associated_definition = NULL;
   _disallowed_inter_stratum_extent = NULL;
   _name = NULL;

   // Optional attributes
   }
// Runtime type identification
int via_template_terminal::DynamicType(int ID) {
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
via_template_terminal *via_template_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<via_template_terminal *>(s);
      }
   return NULL;
   }
via_template_terminal *via_template_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<via_template_terminal *>(s);
      }
   return NULL;
   }
// construction factory
via_template_terminal *via_template_terminal::Construct() {
   via_template_terminal *result = NULL;

   // create the via_template_terminal.
   result = new via_template_terminal();
   return result;
   }
bool via_template_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: via_template_terminal\r\n");

   // Check for the existence of all required attributes
   if (_associated_definition == NULL) {
      TRACE("ERROR: _associated_definition a required attribute is NULL!\r\n");
      result = false;
      }
   if (_disallowed_inter_stratum_extent == NULL) {
      TRACE("ERROR: _disallowed_inter_stratum_extent a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   if (_terminal_connection_zone == NULL) {
      TRACE("ERROR: _terminal_connection_zone a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
