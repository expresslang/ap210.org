// Source for AP210 application object
//     material_composition_relationship

// Precompiled include files
#include <StdAfx.h>

#include "material_composition_relationship.h"

// Classes
#include <ee_text.h>
#include <data_element.h>
#include <ee_material.h>
#include <ee_material.h>

material_composition_relationship::material_composition_relationship() {
   initialize();
   }
material_composition_relationship::~material_composition_relationship() {
   // Free string attributes
   if (_composition_basis != NULL) {
      free(_composition_basis);
     }
   if (_composition_class != NULL) {
      free(_composition_class);
     }
   }
// intialize data members
void material_composition_relationship::initialize() {
   // Required attributes
   _composition_basis = NULL;
   _determination_method = NULL;
   _composition_class = NULL;
   _constituent_amount = NULL;
   _related_product = NULL;
   _relating_product = NULL;

   // Optional attributes
   }
// Runtime type identification
int material_composition_relationship::DynamicType(int ID) {
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
material_composition_relationship *material_composition_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<material_composition_relationship *>(s);
      }
   return NULL;
   }
material_composition_relationship *material_composition_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<material_composition_relationship *>(s);
      }
   return NULL;
   }
// construction factory
material_composition_relationship *material_composition_relationship::Construct() {
   material_composition_relationship *result = NULL;

   // create the material_composition_relationship.
   result = new material_composition_relationship();
   return result;
   }
bool material_composition_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: material_composition_relationship\r\n");

   // Check for the existence of all required attributes
   if (_composition_basis == NULL) {
      TRACE("ERROR: _composition_basis a required attribute is NULL!\r\n");
      result = false;
      }
   if (_determination_method == NULL) {
      TRACE("ERROR: _determination_method a required attribute is NULL!\r\n");
      result = false;
      }
   if (_composition_class == NULL) {
      TRACE("ERROR: _composition_class a required attribute is NULL!\r\n");
      result = false;
      }
   if (_constituent_amount == NULL) {
      TRACE("ERROR: _constituent_amount a required attribute is NULL!\r\n");
      result = false;
      }
   if (_related_product == NULL) {
      TRACE("ERROR: _related_product a required attribute is NULL!\r\n");
      result = false;
      }
   if (_relating_product == NULL) {
      TRACE("ERROR: _relating_product a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
