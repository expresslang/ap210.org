// Source for AP210 application object
//     material_assembly_relationship

// Precompiled include files
#include <StdAfx.h>

#include "material_assembly_relationship.h"

// Classes
#include <ee_material.h>
#include <ee_material.h>

material_assembly_relationship::material_assembly_relationship() {
   initialize();
   }
material_assembly_relationship::~material_assembly_relationship() {
   // Free string attributes
   if (_component_identifier != NULL) {
      free(_component_identifier);
     }
   }
// intialize data members
void material_assembly_relationship::initialize() {
   // Required attributes
   _component = NULL;
   _assembly = NULL;
   _component_identifier = NULL;

   // Optional attributes
   }
// Runtime type identification
int material_assembly_relationship::DynamicType(int ID) {
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
material_assembly_relationship *material_assembly_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<material_assembly_relationship *>(s);
      }
   return NULL;
   }
material_assembly_relationship *material_assembly_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<material_assembly_relationship *>(s);
      }
   return NULL;
   }
// construction factory
material_assembly_relationship *material_assembly_relationship::Construct() {
   material_assembly_relationship *result = NULL;

   // create the material_assembly_relationship.
   result = new material_assembly_relationship();
   return result;
   }
bool material_assembly_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: material_assembly_relationship\r\n");

   // Check for the existence of all required attributes
   if (_component == NULL) {
      TRACE("ERROR: _component a required attribute is NULL!\r\n");
      result = false;
      }
   if (_assembly == NULL) {
      TRACE("ERROR: _assembly a required attribute is NULL!\r\n");
      result = false;
      }
   if (_component_identifier == NULL) {
      TRACE("ERROR: _component_identifier a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
