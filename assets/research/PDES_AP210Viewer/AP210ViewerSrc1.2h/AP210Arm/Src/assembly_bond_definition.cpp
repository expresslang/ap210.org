// Source for AP210 application object
//     assembly_bond_definition

// Precompiled include files
#include <StdAfx.h>

#include "assembly_bond_definition.h"

// Classes
#include <external_definition.h>
#include <ee_material.h>
#include <part_feature.h>
#include <part_feature.h>

assembly_bond_definition::assembly_bond_definition() {
   initialize();
   }
assembly_bond_definition::~assembly_bond_definition() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void assembly_bond_definition::initialize() {
   // Required attributes
   _bond_category = NULL;
   _bond_material = NULL;
   _bonded_feature_1 = NULL;
   _bonded_feature_2 = NULL;
   _name = NULL;

   // Optional attributes
   }
// Runtime type identification
int assembly_bond_definition::DynamicType(int ID) {
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
assembly_bond_definition *assembly_bond_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<assembly_bond_definition *>(s);
      }
   return NULL;
   }
assembly_bond_definition *assembly_bond_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<assembly_bond_definition *>(s);
      }
   return NULL;
   }
// construction factory
assembly_bond_definition *assembly_bond_definition::Construct() {
   assembly_bond_definition *result = NULL;

   // create the assembly_bond_definition.
   result = new assembly_bond_definition();
   return result;
   }
bool assembly_bond_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: assembly_bond_definition\r\n");

   // Check for the existence of all required attributes
   if (_bond_category == NULL) {
      TRACE("ERROR: _bond_category a required attribute is NULL!\r\n");
      result = false;
      }
   if (_bond_material == NULL) {
      TRACE("ERROR: _bond_material a required attribute is NULL!\r\n");
      result = false;
      }
   if (_bonded_feature_1 == NULL) {
      TRACE("ERROR: _bonded_feature_1 a required attribute is NULL!\r\n");
      result = false;
      }
   if (_bonded_feature_2 == NULL) {
      TRACE("ERROR: _bonded_feature_2 a required attribute is NULL!\r\n");
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
