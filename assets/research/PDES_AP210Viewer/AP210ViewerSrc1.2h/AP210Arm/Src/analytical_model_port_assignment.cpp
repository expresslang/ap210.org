// Source for AP210 application object
//     analytical_model_port_assignment

// Precompiled include files
#include <StdAfx.h>

#include "analytical_model_port_assignment.h"

// Classes
#include <scalar_terminal_definition.h>
#include <analytical_model_port.h>

analytical_model_port_assignment::analytical_model_port_assignment() {
   initialize();
   }
analytical_model_port_assignment::~analytical_model_port_assignment() {
   // Free string attributes
   }
// intialize data members
void analytical_model_port_assignment::initialize() {
   // Required attributes
   _assigned_functional_unit_terminal = NULL;
   _assigned_analytical_model_port = NULL;

   // Optional attributes
   }
// Runtime type identification
int analytical_model_port_assignment::DynamicType(int ID) {
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
analytical_model_port_assignment *analytical_model_port_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<analytical_model_port_assignment *>(s);
      }
   return NULL;
   }
analytical_model_port_assignment *analytical_model_port_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<analytical_model_port_assignment *>(s);
      }
   return NULL;
   }
// construction factory
analytical_model_port_assignment *analytical_model_port_assignment::Construct() {
   analytical_model_port_assignment *result = NULL;

   // create the analytical_model_port_assignment.
   result = new analytical_model_port_assignment();
   return result;
   }
bool analytical_model_port_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: analytical_model_port_assignment\r\n");

   // Check for the existence of all required attributes
   if (_assigned_functional_unit_terminal == NULL) {
      TRACE("ERROR: _assigned_functional_unit_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   if (_assigned_analytical_model_port == NULL) {
      TRACE("ERROR: _assigned_analytical_model_port a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
