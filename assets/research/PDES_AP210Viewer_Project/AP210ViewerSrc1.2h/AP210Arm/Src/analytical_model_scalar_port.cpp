// Source for AP210 application object
//     analytical_model_scalar_port

// Precompiled include files
#include <StdAfx.h>

#include "analytical_model_scalar_port.h"

// Classes

analytical_model_scalar_port::analytical_model_scalar_port() {
   initialize();
   }
analytical_model_scalar_port::~analytical_model_scalar_port() {
   // Free string attributes
   }
// intialize data members
void analytical_model_scalar_port::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int analytical_model_scalar_port::DynamicType(int ID) {
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
analytical_model_scalar_port *analytical_model_scalar_port::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<analytical_model_scalar_port *>(s);
      }
   return NULL;
   }
analytical_model_scalar_port *analytical_model_scalar_port::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<analytical_model_scalar_port *>(s);
      }
   return NULL;
   }
// construction factory
analytical_model_scalar_port *analytical_model_scalar_port::Construct() {
   analytical_model_scalar_port *result = NULL;

   // create the analytical_model_scalar_port.
   result = new analytical_model_scalar_port();
   return result;
   }
bool analytical_model_scalar_port::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: analytical_model_scalar_port\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (analytical_model_port::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
