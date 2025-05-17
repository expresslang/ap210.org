// Source for AP210 application object
//     packaged_part

// Precompiled include files
#include <StdAfx.h>

#include "packaged_part.h"

// Classes
#include <ee_material.h>
#include <functional_unit_usage_view.h>

packaged_part::packaged_part() {
   initialize();
   }
packaged_part::~packaged_part() {
   // Free string attributes
   }
// intialize data members
void packaged_part::initialize() {
   // Required attributes
   _implemented_function = NULL;

   // Optional attributes
   _potting_compound = NULL;
   }
// Runtime type identification
int packaged_part::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = physical_unit_usage_view::DynamicType(ID);
      }
   return result;
   }
packaged_part *packaged_part::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<packaged_part *>(s);
      }
   return NULL;
   }
packaged_part *packaged_part::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<packaged_part *>(s);
      }
   return NULL;
   }
// construction factory
packaged_part *packaged_part::Construct() {
   packaged_part *result = NULL;

   // create the packaged_part.
   result = new packaged_part();
   return result;
   }
bool packaged_part::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: packaged_part\r\n");

   // Check for the existence of all required attributes
   if (_used_package == NULL) {
      TRACE("ERROR: _used_package a required attribute is NULL!\r\n");
      result = false;
      }
   if (_implemented_function == NULL) {
      TRACE("ERROR: _implemented_function a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (physical_unit_usage_view::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
