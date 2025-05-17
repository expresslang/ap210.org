// Source for AP210 application object
//     tolerance_zone_form

// Precompiled include files
#include <StdAfx.h>

#include "tolerance_zone_form.h"

// Classes
#include <tolerance_zone.h>

tolerance_zone_form::tolerance_zone_form() {
   initialize();
   }
tolerance_zone_form::~tolerance_zone_form() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void tolerance_zone_form::initialize() {
   // Required attributes
   _characterized_tolerance_zone = NULL;
   _name = NULL;

   // Optional attributes
   }
// Runtime type identification
int tolerance_zone_form::DynamicType(int ID) {
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
tolerance_zone_form *tolerance_zone_form::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<tolerance_zone_form *>(s);
      }
   return NULL;
   }
tolerance_zone_form *tolerance_zone_form::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<tolerance_zone_form *>(s);
      }
   return NULL;
   }
// construction factory
tolerance_zone_form *tolerance_zone_form::Construct() {
   tolerance_zone_form *result = NULL;

   // create the tolerance_zone_form.
   result = new tolerance_zone_form();
   return result;
   }
bool tolerance_zone_form::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: tolerance_zone_form\r\n");

   // Check for the existence of all required attributes
   if (_characterized_tolerance_zone == NULL) {
      TRACE("ERROR: _characterized_tolerance_zone a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
