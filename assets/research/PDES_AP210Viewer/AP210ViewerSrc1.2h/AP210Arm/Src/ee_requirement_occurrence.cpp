// Source for AP210 application object
//     ee_requirement_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "ee_requirement_occurrence.h"

// Classes
#include <ee_material.h>
#include <ee_text.h>

ee_requirement_occurrence::ee_requirement_occurrence() {
   initialize();
   }
ee_requirement_occurrence::~ee_requirement_occurrence() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void ee_requirement_occurrence::initialize() {
   // Required attributes
   _name = NULL;

   // Optional attributes
   _required_material = NULL;
   _description = NULL;
   }
// Runtime type identification
int ee_requirement_occurrence::DynamicType(int ID) {
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
ee_requirement_occurrence *ee_requirement_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_requirement_occurrence *>(s);
      }
   return NULL;
   }
ee_requirement_occurrence *ee_requirement_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_requirement_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
ee_requirement_occurrence *ee_requirement_occurrence::Construct() {
   ee_requirement_occurrence *result = NULL;

   // create the ee_requirement_occurrence.
   result = new ee_requirement_occurrence();
   return result;
   }
bool ee_requirement_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_requirement_occurrence\r\n");

   // Check for the existence of all required attributes
   if (_requirement_specification == NULL) {
      TRACE("ERROR: _requirement_specification a required attribute is NULL!\r\n");
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
