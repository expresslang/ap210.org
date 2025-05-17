// Source for AP210 application object
//     analytical_model_port

// Precompiled include files
#include <StdAfx.h>

#include "analytical_model_port.h"

// Classes
#include <analytical_model.h>

analytical_model_port::analytical_model_port() {
   initialize();
   }
analytical_model_port::~analytical_model_port() {
   // Free string attributes
   if (_port_name != NULL) {
      free(_port_name);
     }
   if (_unit_of_measure != NULL) {
      free(_unit_of_measure);
     }
   }
// intialize data members
void analytical_model_port::initialize() {
   // Required attributes
   _accessed_analytical_model = NULL;
   _port_name = NULL;

   // Optional attributes
   _unit_of_measure = NULL;
   }
// Runtime type identification
int analytical_model_port::DynamicType(int ID) {
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
analytical_model_port *analytical_model_port::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<analytical_model_port *>(s);
      }
   return NULL;
   }
analytical_model_port *analytical_model_port::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<analytical_model_port *>(s);
      }
   return NULL;
   }
// construction factory
analytical_model_port *analytical_model_port::Construct() {
   analytical_model_port *result = NULL;

   // create the analytical_model_port.
   result = new analytical_model_port();
   return result;
   }
bool analytical_model_port::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: analytical_model_port\r\n");

   // Check for the existence of all required attributes
   if (_accessed_analytical_model == NULL) {
      TRACE("ERROR: _accessed_analytical_model a required attribute is NULL!\r\n");
      result = false;
      }
   if (_port_name == NULL) {
      TRACE("ERROR: _port_name a required attribute is NULL!\r\n");
      result = false;
      }
   if (_port_type == NULL) {
      TRACE("ERROR: _port_type a required attribute is NULL!\r\n");
      result = false;
      }
   if (_distributed_properties == NULL) {
      TRACE("ERROR: _distributed_properties a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
