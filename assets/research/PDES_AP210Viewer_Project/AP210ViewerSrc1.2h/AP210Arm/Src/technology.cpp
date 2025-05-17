// Source for AP210 application object
//     technology

// Precompiled include files
#include <StdAfx.h>

#include "technology.h"

// Classes
#include <process_specification.h>
#include <external_definition.h>
#include <ee_material.h>

technology::technology() {
   initialize();
   }
technology::~technology() {
   // Free string attributes
   }
// intialize data members
void technology::initialize() {
   // Required attributes
   _process_technology = NULL;
   _classification = NULL;
   _material_product_system = NULL;

   // Optional attributes
   }
// Runtime type identification
int technology::DynamicType(int ID) {
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
technology *technology::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<technology *>(s);
      }
   return NULL;
   }
technology *technology::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<technology *>(s);
      }
   return NULL;
   }
// construction factory
technology *technology::Construct() {
   technology *result = NULL;

   // create the technology.
   result = new technology();
   return result;
   }
bool technology::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: technology\r\n");

   // Check for the existence of all required attributes
   if (_process_technology == NULL) {
      TRACE("ERROR: _process_technology a required attribute is NULL!\r\n");
      result = false;
      }
   if (_classification == NULL) {
      TRACE("ERROR: _classification a required attribute is NULL!\r\n");
      result = false;
      }
   if (_material_product_system == NULL) {
      TRACE("ERROR: _material_product_system a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
