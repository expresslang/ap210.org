// Source for AP210 application object
//     reference_composition_path

// Precompiled include files
#include <StdAfx.h>

#include "reference_composition_path.h"

// Classes
#include <functional_unit.h>

reference_composition_path::reference_composition_path() {
   initialize();
   }
reference_composition_path::~reference_composition_path() {
   // Free string attributes
   }
// intialize data members
void reference_composition_path::initialize() {
   // Required attributes
   _reference_functional_unit = NULL;

   // Optional attributes
   }
// Runtime type identification
int reference_composition_path::DynamicType(int ID) {
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
reference_composition_path *reference_composition_path::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<reference_composition_path *>(s);
      }
   return NULL;
   }
reference_composition_path *reference_composition_path::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<reference_composition_path *>(s);
      }
   return NULL;
   }
// construction factory
reference_composition_path *reference_composition_path::Construct() {
   reference_composition_path *result = NULL;

   // create the reference_composition_path.
   result = new reference_composition_path();
   return result;
   }
bool reference_composition_path::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: reference_composition_path\r\n");

   // Check for the existence of all required attributes
   if (_path_element == NULL) {
      TRACE("ERROR: _path_element a required attribute is NULL!\r\n");
      result = false;
      }
   if (_reference_functional_unit == NULL) {
      TRACE("ERROR: _reference_functional_unit a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
