// Source for AP210 application object
//     engineering_make_from

// Precompiled include files
#include <StdAfx.h>

#include "engineering_make_from.h"

// Classes
#include <ee_product_definition.h>
#include <ee_product_definition.h>

engineering_make_from::engineering_make_from() {
   initialize();
   }
engineering_make_from::~engineering_make_from() {
   // Free string attributes
   }
// intialize data members
void engineering_make_from::initialize() {
   // Required attributes
   _base_design = NULL;
   _resultant_design = NULL;

   // Optional attributes
   }
// Runtime type identification
int engineering_make_from::DynamicType(int ID) {
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
engineering_make_from *engineering_make_from::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<engineering_make_from *>(s);
      }
   return NULL;
   }
engineering_make_from *engineering_make_from::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<engineering_make_from *>(s);
      }
   return NULL;
   }
// construction factory
engineering_make_from *engineering_make_from::Construct() {
   engineering_make_from *result = NULL;

   // create the engineering_make_from.
   result = new engineering_make_from();
   return result;
   }
bool engineering_make_from::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: engineering_make_from\r\n");

   // Check for the existence of all required attributes
   if (_base_design == NULL) {
      TRACE("ERROR: _base_design a required attribute is NULL!\r\n");
      result = false;
      }
   if (_resultant_design == NULL) {
      TRACE("ERROR: _resultant_design a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
