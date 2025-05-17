// Source for AP210 application object
//     datum_difference_based_model_parameter

// Precompiled include files
#include <StdAfx.h>

#include "datum_difference_based_model_parameter.h"

// Classes
#include <datum_difference.h>

datum_difference_based_model_parameter::datum_difference_based_model_parameter() {
   initialize();
   }
datum_difference_based_model_parameter::~datum_difference_based_model_parameter() {
   // Free string attributes
   }
// intialize data members
void datum_difference_based_model_parameter::initialize() {
   // Required attributes
   _of_datum_difference = NULL;

   // Optional attributes
   }
// Runtime type identification
int datum_difference_based_model_parameter::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = model_parameter::DynamicType(ID);
      }
   return result;
   }
datum_difference_based_model_parameter *datum_difference_based_model_parameter::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_difference_based_model_parameter *>(s);
      }
   return NULL;
   }
datum_difference_based_model_parameter *datum_difference_based_model_parameter::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_difference_based_model_parameter *>(s);
      }
   return NULL;
   }
// construction factory
datum_difference_based_model_parameter *datum_difference_based_model_parameter::Construct() {
   datum_difference_based_model_parameter *result = NULL;

   // create the datum_difference_based_model_parameter.
   result = new datum_difference_based_model_parameter();
   return result;
   }
bool datum_difference_based_model_parameter::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_difference_based_model_parameter\r\n");

   // Check for the existence of all required attributes
   if (_of_datum_difference == NULL) {
      TRACE("ERROR: _of_datum_difference a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (model_parameter::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
