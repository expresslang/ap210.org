// Source for AP210 application object
//     analytical_model

// Precompiled include files
#include <StdAfx.h>

#include "analytical_model.h"

// Classes
#include <language_reference_manual.h>
#include <ee_document.h>
#include <ee_specification.h>

analytical_model::analytical_model() {
   initialize();
   }
analytical_model::~analytical_model() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void analytical_model::initialize() {
   // Required attributes
   _name = NULL;
   _representation_language = NULL;
   _reference_document = NULL;
   _source_code = NULL;

   // Optional attributes
   }
// Runtime type identification
int analytical_model::DynamicType(int ID) {
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
analytical_model *analytical_model::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<analytical_model *>(s);
      }
   return NULL;
   }
analytical_model *analytical_model::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<analytical_model *>(s);
      }
   return NULL;
   }
// construction factory
analytical_model *analytical_model::Construct() {
   analytical_model *result = NULL;

   // create the analytical_model.
   result = new analytical_model();
   return result;
   }
bool analytical_model::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: analytical_model\r\n");

   // Check for the existence of all required attributes
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   if (_representation_language == NULL) {
      TRACE("ERROR: _representation_language a required attribute is NULL!\r\n");
      result = false;
      }
   if (_reference_document == NULL) {
      TRACE("ERROR: _reference_document a required attribute is NULL!\r\n");
      result = false;
      }
   if (_parameter == NULL) {
      TRACE("ERROR: _parameter a required attribute is NULL!\r\n");
      result = false;
      }
   if (_source_code == NULL) {
      TRACE("ERROR: _source_code a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
