// Source for AP210 application object
//     component_external_reference

// Precompiled include files
#include <StdAfx.h>

#include "component_external_reference.h"

// Classes

component_external_reference::component_external_reference() {
   initialize();
   }
component_external_reference::~component_external_reference() {
   // Free string attributes
   if (_design_owner != NULL) {
      free(_design_owner);
     }
   if (_part_number != NULL) {
      free(_part_number);
     }
   if (_revision_code != NULL) {
      free(_revision_code);
     }
   if (_product_definition_id != NULL) {
      free(_product_definition_id);
     }
   if (_reference_designation != NULL) {
      free(_reference_designation);
     }
   }
// intialize data members
void component_external_reference::initialize() {
   // Required attributes
   _design_owner = NULL;
   _part_number = NULL;
   _revision_code = NULL;
   _product_definition_id = NULL;
   _reference_designation = NULL;

   // Optional attributes
   }
// Runtime type identification
int component_external_reference::DynamicType(int ID) {
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
component_external_reference *component_external_reference::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_external_reference *>(s);
      }
   return NULL;
   }
component_external_reference *component_external_reference::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_external_reference *>(s);
      }
   return NULL;
   }
// construction factory
component_external_reference *component_external_reference::Construct() {
   component_external_reference *result = NULL;

   // create the component_external_reference.
   result = new component_external_reference();
   return result;
   }
bool component_external_reference::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_external_reference\r\n");

   // Check for the existence of all required attributes
   if (_design_owner == NULL) {
      TRACE("ERROR: _design_owner a required attribute is NULL!\r\n");
      result = false;
      }
   if (_part_number == NULL) {
      TRACE("ERROR: _part_number a required attribute is NULL!\r\n");
      result = false;
      }
   if (_revision_code == NULL) {
      TRACE("ERROR: _revision_code a required attribute is NULL!\r\n");
      result = false;
      }
   if (_product_definition_id == NULL) {
      TRACE("ERROR: _product_definition_id a required attribute is NULL!\r\n");
      result = false;
      }
   if (_reference_designation == NULL) {
      TRACE("ERROR: _reference_designation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
