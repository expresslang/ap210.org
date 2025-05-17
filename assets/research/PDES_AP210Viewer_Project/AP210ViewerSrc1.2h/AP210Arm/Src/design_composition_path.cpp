// Source for AP210 application object
//     design_composition_path

// Precompiled include files
#include <StdAfx.h>

#include "design_composition_path.h"

// Classes
#include <functional_unit.h>

design_composition_path::design_composition_path() {
   initialize();
   }
design_composition_path::~design_composition_path() {
   // Free string attributes
   }
// intialize data members
void design_composition_path::initialize() {
   // Required attributes
   _design_functional_unit = NULL;

   // Optional attributes
   }
// Runtime type identification
int design_composition_path::DynamicType(int ID) {
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
design_composition_path *design_composition_path::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<design_composition_path *>(s);
      }
   return NULL;
   }
design_composition_path *design_composition_path::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<design_composition_path *>(s);
      }
   return NULL;
   }
// construction factory
design_composition_path *design_composition_path::Construct() {
   design_composition_path *result = NULL;

   // create the design_composition_path.
   result = new design_composition_path();
   return result;
   }
bool design_composition_path::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: design_composition_path\r\n");

   // Check for the existence of all required attributes
   if (_path_element == NULL) {
      TRACE("ERROR: _path_element a required attribute is NULL!\r\n");
      result = false;
      }
   if (_design_functional_unit == NULL) {
      TRACE("ERROR: _design_functional_unit a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
