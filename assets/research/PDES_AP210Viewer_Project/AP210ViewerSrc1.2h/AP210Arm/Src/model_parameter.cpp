// Source for AP210 application object
//     model_parameter

// Precompiled include files
#include <StdAfx.h>

#include "model_parameter.h"

// Classes

model_parameter::model_parameter() {
   initialize();
   }
model_parameter::~model_parameter() {
   // Free string attributes
   if (_type_name != NULL) {
      free(_type_name);
     }
   if (_unit_of_measure != NULL) {
      free(_unit_of_measure);
     }
   }
// intialize data members
void model_parameter::initialize() {
   // Required attributes
   _type_name = NULL;

   // Optional attributes
   _unit_of_measure = NULL;
   }
// Runtime type identification
int model_parameter::DynamicType(int ID) {
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
model_parameter *model_parameter::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<model_parameter *>(s);
      }
   return NULL;
   }
model_parameter *model_parameter::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<model_parameter *>(s);
      }
   return NULL;
   }
// construction factory
model_parameter *model_parameter::Construct() {
   model_parameter *result = NULL;

   // create the model_parameter.
   result = new model_parameter();
   return result;
   }
bool model_parameter::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: model_parameter\r\n");

   // Check for the existence of all required attributes
   if (_type_name == NULL) {
      TRACE("ERROR: _type_name a required attribute is NULL!\r\n");
      result = false;
      }
   if (_reference_document == NULL) {
      TRACE("ERROR: _reference_document a required attribute is NULL!\r\n");
      result = false;
      }
   if (_parameter_type == NULL) {
      TRACE("ERROR: _parameter_type a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
