// Source for AP210 application object
//     SetOfgeometric_tolerance_with_referenced_datum_system

// Precompiled include files
#include <StdAfx.h>

#include "SetOfgeometric_tolerance_with_referenced_datum_system.h"

// Classes
#include <geometric_tolerance_with_referenced_datum_system.h>

SetOfgeometric_tolerance_with_referenced_datum_system::SetOfgeometric_tolerance_with_referenced_datum_system() {
   initialize();
   }
SetOfgeometric_tolerance_with_referenced_datum_system::~SetOfgeometric_tolerance_with_referenced_datum_system() {
   // Free string attributes
   }
// intialize data members
void SetOfgeometric_tolerance_with_referenced_datum_system::initialize() {
   // Required attributes
   _geometric_tolerance_with_referenced_datum_system = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfgeometric_tolerance_with_referenced_datum_system::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfgeometric_tolerance_with_referenced_datum_system *SetOfgeometric_tolerance_with_referenced_datum_system::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfgeometric_tolerance_with_referenced_datum_system *>(s);
      }
   return NULL;
   }
SetOfgeometric_tolerance_with_referenced_datum_system *SetOfgeometric_tolerance_with_referenced_datum_system::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfgeometric_tolerance_with_referenced_datum_system *>(s);
      }
   return NULL;
   }
// construction factory
SetOfgeometric_tolerance_with_referenced_datum_system *SetOfgeometric_tolerance_with_referenced_datum_system::Construct() {
   SetOfgeometric_tolerance_with_referenced_datum_system *result = NULL;

   // create the SetOfgeometric_tolerance_with_referenced_datum_system.
   result = new SetOfgeometric_tolerance_with_referenced_datum_system();
   return result;
   }
bool SetOfgeometric_tolerance_with_referenced_datum_system::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfgeometric_tolerance_with_referenced_datum_system\r\n");

   // Check for the existence of all required attributes
   if (_geometric_tolerance_with_referenced_datum_system == NULL) {
      TRACE("ERROR: _geometric_tolerance_with_referenced_datum_system a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
