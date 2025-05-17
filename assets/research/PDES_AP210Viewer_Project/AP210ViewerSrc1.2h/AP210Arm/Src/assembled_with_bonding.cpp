// Source for AP210 application object
//     assembled_with_bonding

// Precompiled include files
#include <StdAfx.h>

#include "assembled_with_bonding.h"

// Classes
#include <assembly_bond_definition.h>

assembled_with_bonding::assembled_with_bonding() {
   initialize();
   }
assembled_with_bonding::~assembled_with_bonding() {
   // Free string attributes
   }
// intialize data members
void assembled_with_bonding::initialize() {
   // Required attributes
   _default_bond_definition = NULL;

   // Optional attributes
   }
// Runtime type identification
int assembled_with_bonding::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = assembly_joint::DynamicType(ID);
      }
   return result;
   }
assembled_with_bonding *assembled_with_bonding::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<assembled_with_bonding *>(s);
      }
   return NULL;
   }
assembled_with_bonding *assembled_with_bonding::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<assembled_with_bonding *>(s);
      }
   return NULL;
   }
// construction factory
assembled_with_bonding *assembled_with_bonding::Construct() {
   assembled_with_bonding *result = NULL;

   // create the assembled_with_bonding.
   result = new assembled_with_bonding();
   return result;
   }
bool assembled_with_bonding::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: assembled_with_bonding\r\n");

   // Check for the existence of all required attributes
   if (_default_bond_definition == NULL) {
      TRACE("ERROR: _default_bond_definition a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (assembly_joint::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
