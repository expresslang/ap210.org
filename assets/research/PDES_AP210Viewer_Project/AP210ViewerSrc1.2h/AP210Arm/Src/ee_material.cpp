// Source for AP210 application object
//     ee_material

// Precompiled include files
#include <StdAfx.h>

#include "ee_material.h"

// Classes
#include <ee_document.h>

ee_material::ee_material() {
   initialize();
   }
ee_material::~ee_material() {
   // Free string attributes
   if (_material_name != NULL) {
      free(_material_name);
     }
   }
// intialize data members
void ee_material::initialize() {
   // Required attributes
   _material_name = NULL;
   _registration_document = NULL;

   // Optional attributes
   }
// Runtime type identification
int ee_material::DynamicType(int ID) {
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
ee_material *ee_material::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_material *>(s);
      }
   return NULL;
   }
ee_material *ee_material::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_material *>(s);
      }
   return NULL;
   }
// construction factory
ee_material *ee_material::Construct() {
   ee_material *result = NULL;

   // create the ee_material.
   result = new ee_material();
   return result;
   }
bool ee_material::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_material\r\n");

   // Check for the existence of all required attributes
   if (_material_name == NULL) {
      TRACE("ERROR: _material_name a required attribute is NULL!\r\n");
      result = false;
      }
   if (_registration_document == NULL) {
      TRACE("ERROR: _registration_document a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
