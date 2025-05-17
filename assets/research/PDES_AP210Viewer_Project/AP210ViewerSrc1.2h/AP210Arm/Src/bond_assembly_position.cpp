// Source for AP210 application object
//     bond_assembly_position

// Precompiled include files
#include <StdAfx.h>

#include "bond_assembly_position.h"

// Classes
#include <assembled_with_bonding.h>
#include <physical_unit_3d_shape.h>
#include <default_assembly_bond_shape.h>
#include <axis_placement_3d.h>

bond_assembly_position::bond_assembly_position() {
   initialize();
   }
bond_assembly_position::~bond_assembly_position() {
   // Free string attributes
   }
// intialize data members
void bond_assembly_position::initialize() {
   // Required attributes
   _bond = NULL;
   _assembly_model = NULL;
   _bond_model = NULL;
   _bond_definition_placement = NULL;

   // Optional attributes
   }
// Runtime type identification
int bond_assembly_position::DynamicType(int ID) {
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
bond_assembly_position *bond_assembly_position::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<bond_assembly_position *>(s);
      }
   return NULL;
   }
bond_assembly_position *bond_assembly_position::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<bond_assembly_position *>(s);
      }
   return NULL;
   }
// construction factory
bond_assembly_position *bond_assembly_position::Construct() {
   bond_assembly_position *result = NULL;

   // create the bond_assembly_position.
   result = new bond_assembly_position();
   return result;
   }
bool bond_assembly_position::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: bond_assembly_position\r\n");

   // Check for the existence of all required attributes
   if (_bond == NULL) {
      TRACE("ERROR: _bond a required attribute is NULL!\r\n");
      result = false;
      }
   if (_assembly_model == NULL) {
      TRACE("ERROR: _assembly_model a required attribute is NULL!\r\n");
      result = false;
      }
   if (_bond_model == NULL) {
      TRACE("ERROR: _bond_model a required attribute is NULL!\r\n");
      result = false;
      }
   if (_bond_definition_placement == NULL) {
      TRACE("ERROR: _bond_definition_placement a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
