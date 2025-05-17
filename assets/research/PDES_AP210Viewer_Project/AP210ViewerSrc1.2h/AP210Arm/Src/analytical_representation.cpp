// Source for AP210 application object
//     analytical_representation

// Precompiled include files
#include <StdAfx.h>

#include "analytical_representation.h"

// Classes
#include <analytical_model.h>

analytical_representation::analytical_representation() {
   initialize();
   }
analytical_representation::~analytical_representation() {
   // Free string attributes
   if (_analytical_representation_name != NULL) {
      free(_analytical_representation_name);
     }
   }
// intialize data members
void analytical_representation::initialize() {
   // Required attributes
   _model_representation = NULL;
   _analytical_representation_name = NULL;

   // Optional attributes
   }
// Runtime type identification
int analytical_representation::DynamicType(int ID) {
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
analytical_representation *analytical_representation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<analytical_representation *>(s);
      }
   return NULL;
   }
analytical_representation *analytical_representation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<analytical_representation *>(s);
      }
   return NULL;
   }
// construction factory
analytical_representation *analytical_representation::Construct() {
   analytical_representation *result = NULL;

   // create the analytical_representation.
   result = new analytical_representation();
   return result;
   }
bool analytical_representation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: analytical_representation\r\n");

   // Check for the existence of all required attributes
   if (_model_parameter_assignment == NULL) {
      TRACE("ERROR: _model_parameter_assignment a required attribute is NULL!\r\n");
      result = false;
      }
   if (_model_representation == NULL) {
      TRACE("ERROR: _model_representation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_analytical_representation_name == NULL) {
      TRACE("ERROR: _analytical_representation_name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
