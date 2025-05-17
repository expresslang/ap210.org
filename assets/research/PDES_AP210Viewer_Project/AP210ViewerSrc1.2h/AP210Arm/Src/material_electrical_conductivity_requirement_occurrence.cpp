// Source for AP210 application object
//     material_electrical_conductivity_requirement_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "material_electrical_conductivity_requirement_occurrence.h"

// Classes

material_electrical_conductivity_requirement_occurrence::material_electrical_conductivity_requirement_occurrence() {
   initialize();
   }
material_electrical_conductivity_requirement_occurrence::~material_electrical_conductivity_requirement_occurrence() {
   // Free string attributes
   }
// intialize data members
void material_electrical_conductivity_requirement_occurrence::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int material_electrical_conductivity_requirement_occurrence::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = electrical_requirement_occurrence::DynamicType(ID);
      }
   return result;
   }
material_electrical_conductivity_requirement_occurrence *material_electrical_conductivity_requirement_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<material_electrical_conductivity_requirement_occurrence *>(s);
      }
   return NULL;
   }
material_electrical_conductivity_requirement_occurrence *material_electrical_conductivity_requirement_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<material_electrical_conductivity_requirement_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
material_electrical_conductivity_requirement_occurrence *material_electrical_conductivity_requirement_occurrence::Construct() {
   material_electrical_conductivity_requirement_occurrence *result = NULL;

   // create the material_electrical_conductivity_requirement_occurrence.
   result = new material_electrical_conductivity_requirement_occurrence();
   return result;
   }
bool material_electrical_conductivity_requirement_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: material_electrical_conductivity_requirement_occurrence\r\n");

   // Check for the existence of all required attributes
   if (_electrical_conductivity_characteristic == NULL) {
      TRACE("ERROR: _electrical_conductivity_characteristic a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (electrical_requirement_occurrence::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
