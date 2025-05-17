// Source for AP210 application object
//     analytical_model_vector_port

// Precompiled include files
#include <StdAfx.h>

#include "analytical_model_vector_port.h"

// Classes

analytical_model_vector_port::analytical_model_vector_port() {
   initialize();
   }
analytical_model_vector_port::~analytical_model_vector_port() {
   // Free string attributes
   }
// intialize data members
void analytical_model_vector_port::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int analytical_model_vector_port::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = analytical_model_port::DynamicType(ID);
      }
   return result;
   }
analytical_model_vector_port *analytical_model_vector_port::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<analytical_model_vector_port *>(s);
      }
   return NULL;
   }
analytical_model_vector_port *analytical_model_vector_port::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<analytical_model_vector_port *>(s);
      }
   return NULL;
   }
// construction factory
analytical_model_vector_port *analytical_model_vector_port::Construct() {
   analytical_model_vector_port *result = NULL;

   // create the analytical_model_vector_port.
   result = new analytical_model_vector_port();
   return result;
   }
bool analytical_model_vector_port::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: analytical_model_vector_port\r\n");

   // Check for the existence of all required attributes
   if (_Size == NULL) {
      TRACE("ERROR: _Size a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (analytical_model_port::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
