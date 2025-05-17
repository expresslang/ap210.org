// Source for AP210 application object
//     electrical_isolation_removal_structure

// Precompiled include files
#include <StdAfx.h>

#include "electrical_isolation_removal_structure.h"

// Classes
#include <ee_requirement_occurrence.h>

electrical_isolation_removal_structure::electrical_isolation_removal_structure() {
   initialize();
   }
electrical_isolation_removal_structure::~electrical_isolation_removal_structure() {
   // Free string attributes
   }
// intialize data members
void electrical_isolation_removal_structure::initialize() {
   // Required attributes
   _electrical_isolation_spacing_requirement = NULL;

   // Optional attributes
   }
// Runtime type identification
int electrical_isolation_removal_structure::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = filled_area_material_removal_structure::DynamicType(ID);
      }
   return result;
   }
electrical_isolation_removal_structure *electrical_isolation_removal_structure::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<electrical_isolation_removal_structure *>(s);
      }
   return NULL;
   }
electrical_isolation_removal_structure *electrical_isolation_removal_structure::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<electrical_isolation_removal_structure *>(s);
      }
   return NULL;
   }
// construction factory
electrical_isolation_removal_structure *electrical_isolation_removal_structure::Construct() {
   electrical_isolation_removal_structure *result = NULL;

   // create the electrical_isolation_removal_structure.
   result = new electrical_isolation_removal_structure();
   return result;
   }
bool electrical_isolation_removal_structure::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: electrical_isolation_removal_structure\r\n");

   // Check for the existence of all required attributes
   if (_electrical_isolation_spacing_requirement == NULL) {
      TRACE("ERROR: _electrical_isolation_spacing_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (filled_area_material_removal_structure::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
