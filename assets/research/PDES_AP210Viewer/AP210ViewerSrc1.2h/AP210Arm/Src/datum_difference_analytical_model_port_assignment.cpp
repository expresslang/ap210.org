// Source for AP210 application object
//     datum_difference_analytical_model_port_assignment

// Precompiled include files
#include <StdAfx.h>

#include "datum_difference_analytical_model_port_assignment.h"

// Classes
#include <analytical_model_port.h>
#include <datum_difference.h>

datum_difference_analytical_model_port_assignment::datum_difference_analytical_model_port_assignment() {
   initialize();
   }
datum_difference_analytical_model_port_assignment::~datum_difference_analytical_model_port_assignment() {
   // Free string attributes
   }
// intialize data members
void datum_difference_analytical_model_port_assignment::initialize() {
   // Required attributes
   _assigned_analytical_model_port = NULL;
   _of_datum_difference = NULL;

   // Optional attributes
   }
// Runtime type identification
int datum_difference_analytical_model_port_assignment::DynamicType(int ID) {
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
datum_difference_analytical_model_port_assignment *datum_difference_analytical_model_port_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_difference_analytical_model_port_assignment *>(s);
      }
   return NULL;
   }
datum_difference_analytical_model_port_assignment *datum_difference_analytical_model_port_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_difference_analytical_model_port_assignment *>(s);
      }
   return NULL;
   }
// construction factory
datum_difference_analytical_model_port_assignment *datum_difference_analytical_model_port_assignment::Construct() {
   datum_difference_analytical_model_port_assignment *result = NULL;

   // create the datum_difference_analytical_model_port_assignment.
   result = new datum_difference_analytical_model_port_assignment();
   return result;
   }
bool datum_difference_analytical_model_port_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_difference_analytical_model_port_assignment\r\n");

   // Check for the existence of all required attributes
   if (_assigned_analytical_model_port == NULL) {
      TRACE("ERROR: _assigned_analytical_model_port a required attribute is NULL!\r\n");
      result = false;
      }
   if (_of_datum_difference == NULL) {
      TRACE("ERROR: _of_datum_difference a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
