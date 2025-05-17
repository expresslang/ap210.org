// Source for AP210 application object
//     default_assembly_bond_shape

// Precompiled include files
#include <StdAfx.h>

#include "default_assembly_bond_shape.h"

// Classes
#include <assembly_bond_definition.h>

default_assembly_bond_shape::default_assembly_bond_shape() {
   initialize();
   }
default_assembly_bond_shape::~default_assembly_bond_shape() {
   // Free string attributes
   }
// intialize data members
void default_assembly_bond_shape::initialize() {
   // Required attributes
   _characterized_bond_definition = NULL;

   // Optional attributes
   }
// Runtime type identification
int default_assembly_bond_shape::DynamicType(int ID) {
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
default_assembly_bond_shape *default_assembly_bond_shape::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<default_assembly_bond_shape *>(s);
      }
   return NULL;
   }
default_assembly_bond_shape *default_assembly_bond_shape::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<default_assembly_bond_shape *>(s);
      }
   return NULL;
   }
// construction factory
default_assembly_bond_shape *default_assembly_bond_shape::Construct() {
   default_assembly_bond_shape *result = NULL;

   // create the default_assembly_bond_shape.
   result = new default_assembly_bond_shape();
   return result;
   }
bool default_assembly_bond_shape::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: default_assembly_bond_shape\r\n");

   // Check for the existence of all required attributes
   if (_characterized_bond_definition == NULL) {
      TRACE("ERROR: _characterized_bond_definition a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
