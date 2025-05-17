// Source for AP210 application object
//     thermal_isolation_removal_structure

// Precompiled include files
#include <StdAfx.h>

#include "thermal_isolation_removal_structure.h"

// Classes

thermal_isolation_removal_structure::thermal_isolation_removal_structure() {
   initialize();
   }
thermal_isolation_removal_structure::~thermal_isolation_removal_structure() {
   // Free string attributes
   }
// intialize data members
void thermal_isolation_removal_structure::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int thermal_isolation_removal_structure::DynamicType(int ID) {
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
thermal_isolation_removal_structure *thermal_isolation_removal_structure::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<thermal_isolation_removal_structure *>(s);
      }
   return NULL;
   }
thermal_isolation_removal_structure *thermal_isolation_removal_structure::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<thermal_isolation_removal_structure *>(s);
      }
   return NULL;
   }
// construction factory
thermal_isolation_removal_structure *thermal_isolation_removal_structure::Construct() {
   thermal_isolation_removal_structure *result = NULL;

   // create the thermal_isolation_removal_structure.
   result = new thermal_isolation_removal_structure();
   return result;
   }
bool thermal_isolation_removal_structure::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: thermal_isolation_removal_structure\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (filled_area_material_removal_structure::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
