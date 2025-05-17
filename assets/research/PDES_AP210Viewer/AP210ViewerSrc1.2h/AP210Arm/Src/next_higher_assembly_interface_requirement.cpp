// Source for AP210 application object
//     next_higher_assembly_interface_requirement

// Precompiled include files
#include <StdAfx.h>

#include "next_higher_assembly_interface_requirement.h"

// Classes
#include <bound_volume_shape.h>
#include <ee_product_version.h>

next_higher_assembly_interface_requirement::next_higher_assembly_interface_requirement() {
   initialize();
   }
next_higher_assembly_interface_requirement::~next_higher_assembly_interface_requirement() {
   // Free string attributes
   }
// intialize data members
void next_higher_assembly_interface_requirement::initialize() {
   // Required attributes
   _shape = NULL;
   _version_of_next_higher_assembly = NULL;

   // Optional attributes
   }
// Runtime type identification
int next_higher_assembly_interface_requirement::DynamicType(int ID) {
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
next_higher_assembly_interface_requirement *next_higher_assembly_interface_requirement::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<next_higher_assembly_interface_requirement *>(s);
      }
   return NULL;
   }
next_higher_assembly_interface_requirement *next_higher_assembly_interface_requirement::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<next_higher_assembly_interface_requirement *>(s);
      }
   return NULL;
   }
// construction factory
next_higher_assembly_interface_requirement *next_higher_assembly_interface_requirement::Construct() {
   next_higher_assembly_interface_requirement *result = NULL;

   // create the next_higher_assembly_interface_requirement.
   result = new next_higher_assembly_interface_requirement();
   return result;
   }
bool next_higher_assembly_interface_requirement::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: next_higher_assembly_interface_requirement\r\n");

   // Check for the existence of all required attributes
   if (_shape == NULL) {
      TRACE("ERROR: _shape a required attribute is NULL!\r\n");
      result = false;
      }
   if (_version_of_next_higher_assembly == NULL) {
      TRACE("ERROR: _version_of_next_higher_assembly a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
