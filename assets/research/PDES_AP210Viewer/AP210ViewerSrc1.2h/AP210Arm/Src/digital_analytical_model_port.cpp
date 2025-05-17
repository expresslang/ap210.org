// Source for AP210 application object
//     digital_analytical_model_port

// Precompiled include files
#include <StdAfx.h>

#include "digital_analytical_model_port.h"

// Classes

digital_analytical_model_port::digital_analytical_model_port() {
   initialize();
   }
digital_analytical_model_port::~digital_analytical_model_port() {
   // Free string attributes
   }
// intialize data members
void digital_analytical_model_port::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int digital_analytical_model_port::DynamicType(int ID) {
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
digital_analytical_model_port *digital_analytical_model_port::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<digital_analytical_model_port *>(s);
      }
   return NULL;
   }
digital_analytical_model_port *digital_analytical_model_port::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<digital_analytical_model_port *>(s);
      }
   return NULL;
   }
// construction factory
digital_analytical_model_port *digital_analytical_model_port::Construct() {
   digital_analytical_model_port *result = NULL;

   // create the digital_analytical_model_port.
   result = new digital_analytical_model_port();
   return result;
   }
bool digital_analytical_model_port::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: digital_analytical_model_port\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (analytical_model_port::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
