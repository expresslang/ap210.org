// Source for AP210 application object
//     part_terminal_external_reference

// Precompiled include files
#include <StdAfx.h>

#include "part_terminal_external_reference.h"

// Classes

part_terminal_external_reference::part_terminal_external_reference() {
   initialize();
   }
part_terminal_external_reference::~part_terminal_external_reference() {
   // Free string attributes
   if (_feature_name != NULL) {
      free(_feature_name);
     }
   if (_feature_type != NULL) {
      free(_feature_type);
     }
   }
// intialize data members
void part_terminal_external_reference::initialize() {
   // Required attributes
   _feature_name = NULL;
   _feature_type = NULL;

   // Optional attributes
   }
// Runtime type identification
int part_terminal_external_reference::DynamicType(int ID) {
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
part_terminal_external_reference *part_terminal_external_reference::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<part_terminal_external_reference *>(s);
      }
   return NULL;
   }
part_terminal_external_reference *part_terminal_external_reference::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<part_terminal_external_reference *>(s);
      }
   return NULL;
   }
// construction factory
part_terminal_external_reference *part_terminal_external_reference::Construct() {
   part_terminal_external_reference *result = NULL;

   // create the part_terminal_external_reference.
   result = new part_terminal_external_reference();
   return result;
   }
bool part_terminal_external_reference::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: part_terminal_external_reference\r\n");

   // Check for the existence of all required attributes
   if (_associated_definition == NULL) {
      TRACE("ERROR: _associated_definition a required attribute is NULL!\r\n");
      result = false;
      }
   if (_feature_name == NULL) {
      TRACE("ERROR: _feature_name a required attribute is NULL!\r\n");
      result = false;
      }
   if (_feature_type == NULL) {
      TRACE("ERROR: _feature_type a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
