// Source for AP210 application object
//     parameter_assignment

// Precompiled include files
#include <StdAfx.h>

#include "parameter_assignment.h"

// Classes
#include <model_parameter.h>

parameter_assignment::parameter_assignment() {
   initialize();
   }
parameter_assignment::~parameter_assignment() {
   // Free string attributes
   }
// intialize data members
void parameter_assignment::initialize() {
   // Required attributes
   _assigned_parameter = NULL;

   // Optional attributes
   }
// Runtime type identification
int parameter_assignment::DynamicType(int ID) {
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
parameter_assignment *parameter_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<parameter_assignment *>(s);
      }
   return NULL;
   }
parameter_assignment *parameter_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<parameter_assignment *>(s);
      }
   return NULL;
   }
// construction factory
parameter_assignment *parameter_assignment::Construct() {
   parameter_assignment *result = NULL;

   // create the parameter_assignment.
   result = new parameter_assignment();
   return result;
   }
bool parameter_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: parameter_assignment\r\n");

   // Check for the existence of all required attributes
   if (_parameter_value == NULL) {
      TRACE("ERROR: _parameter_value a required attribute is NULL!\r\n");
      result = false;
      }
   if (_assigned_parameter == NULL) {
      TRACE("ERROR: _assigned_parameter a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
