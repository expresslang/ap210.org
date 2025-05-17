// Source for AP210 application object
//     datum_system_defining_conditions_without_material_conditions

// Precompiled include files
#include <StdAfx.h>

#include "datum_system_defining_conditions_without_material_conditions.h"

// Classes

datum_system_defining_conditions_without_material_conditions::datum_system_defining_conditions_without_material_conditions() {
   initialize();
   }
datum_system_defining_conditions_without_material_conditions::~datum_system_defining_conditions_without_material_conditions() {
   // Free string attributes
   }
// intialize data members
void datum_system_defining_conditions_without_material_conditions::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int datum_system_defining_conditions_without_material_conditions::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = datum_system_defining_conditions::DynamicType(ID);
      }
   return result;
   }
datum_system_defining_conditions_without_material_conditions *datum_system_defining_conditions_without_material_conditions::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_system_defining_conditions_without_material_conditions *>(s);
      }
   return NULL;
   }
datum_system_defining_conditions_without_material_conditions *datum_system_defining_conditions_without_material_conditions::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_system_defining_conditions_without_material_conditions *>(s);
      }
   return NULL;
   }
// construction factory
datum_system_defining_conditions_without_material_conditions *datum_system_defining_conditions_without_material_conditions::Construct() {
   datum_system_defining_conditions_without_material_conditions *result = NULL;

   // create the datum_system_defining_conditions_without_material_conditions.
   result = new datum_system_defining_conditions_without_material_conditions();
   return result;
   }
bool datum_system_defining_conditions_without_material_conditions::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_system_defining_conditions_without_material_conditions\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (datum_system_defining_conditions::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
