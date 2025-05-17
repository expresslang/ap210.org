// Source for AP210 application object
//     datum_system_defining_conditions

// Precompiled include files
#include <StdAfx.h>

#include "datum_system_defining_conditions.h"

// Classes
#include <datum_system.h>

datum_system_defining_conditions::datum_system_defining_conditions() {
   initialize();
   }
datum_system_defining_conditions::~datum_system_defining_conditions() {
   // Free string attributes
   }
// intialize data members
void datum_system_defining_conditions::initialize() {
   // Required attributes
   _conditions_of = NULL;

   // Optional attributes
   }
// Runtime type identification
int datum_system_defining_conditions::DynamicType(int ID) {
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
datum_system_defining_conditions *datum_system_defining_conditions::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_system_defining_conditions *>(s);
      }
   return NULL;
   }
datum_system_defining_conditions *datum_system_defining_conditions::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_system_defining_conditions *>(s);
      }
   return NULL;
   }
// construction factory
datum_system_defining_conditions *datum_system_defining_conditions::Construct() {
   datum_system_defining_conditions *result = NULL;

   // create the datum_system_defining_conditions.
   result = new datum_system_defining_conditions();
   return result;
   }
bool datum_system_defining_conditions::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_system_defining_conditions\r\n");

   // Check for the existence of all required attributes
   if (_conditions_of == NULL) {
      TRACE("ERROR: _conditions_of a required attribute is NULL!\r\n");
      result = false;
      }
   if (_assigned_datum_precedences == NULL) {
      TRACE("ERROR: _assigned_datum_precedences a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
