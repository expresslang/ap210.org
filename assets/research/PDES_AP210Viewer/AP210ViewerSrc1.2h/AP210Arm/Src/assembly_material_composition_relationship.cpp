// Source for AP210 application object
//     assembly_material_composition_relationship

// Precompiled include files
#include <StdAfx.h>

#include "assembly_material_composition_relationship.h"

// Classes
#include <data_element.h>
#include <physical_unit_design_view.h>
#include <ee_material.h>
#include <security_classification.h>

assembly_material_composition_relationship::assembly_material_composition_relationship() {
   initialize();
   }
assembly_material_composition_relationship::~assembly_material_composition_relationship() {
   // Free string attributes
   }
// intialize data members
void assembly_material_composition_relationship::initialize() {
   // Required attributes
   _assembly = NULL;
   _component_material = NULL;
   _security_code = NULL;

   // Optional attributes
   _quantity = NULL;
   }
// Runtime type identification
int assembly_material_composition_relationship::DynamicType(int ID) {
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
assembly_material_composition_relationship *assembly_material_composition_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<assembly_material_composition_relationship *>(s);
      }
   return NULL;
   }
assembly_material_composition_relationship *assembly_material_composition_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<assembly_material_composition_relationship *>(s);
      }
   return NULL;
   }
// construction factory
assembly_material_composition_relationship *assembly_material_composition_relationship::Construct() {
   assembly_material_composition_relationship *result = NULL;

   // create the assembly_material_composition_relationship.
   result = new assembly_material_composition_relationship();
   return result;
   }
bool assembly_material_composition_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: assembly_material_composition_relationship\r\n");

   // Check for the existence of all required attributes
   if (_assembly == NULL) {
      TRACE("ERROR: _assembly a required attribute is NULL!\r\n");
      result = false;
      }
   if (_component_material == NULL) {
      TRACE("ERROR: _component_material a required attribute is NULL!\r\n");
      result = false;
      }
   if (_security_code == NULL) {
      TRACE("ERROR: _security_code a required attribute is NULL!\r\n");
      result = false;
      }
   if (_as_required == NULL) {
      TRACE("ERROR: _as_required a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
