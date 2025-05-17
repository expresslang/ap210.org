// Source for AP210 application object
//     design_layer_technology

// Precompiled include files
#include <StdAfx.h>

#include "design_layer_technology.h"

// Classes

design_layer_technology::design_layer_technology() {
   initialize();
   }
design_layer_technology::~design_layer_technology() {
   // Free string attributes
   }
// intialize data members
void design_layer_technology::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int design_layer_technology::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = stratum_technology::DynamicType(ID);
      }
   return result;
   }
design_layer_technology *design_layer_technology::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<design_layer_technology *>(s);
      }
   return NULL;
   }
design_layer_technology *design_layer_technology::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<design_layer_technology *>(s);
      }
   return NULL;
   }
// construction factory
design_layer_technology *design_layer_technology::Construct() {
   design_layer_technology *result = NULL;

   // create the design_layer_technology.
   result = new design_layer_technology();
   return result;
   }
bool design_layer_technology::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: design_layer_technology\r\n");

   // Check for the existence of all required attributes
   if (_design_layer_purpose == NULL) {
      TRACE("ERROR: _design_layer_purpose a required attribute is NULL!\r\n");
      result = false;
      }
   if (_design_layer_position == NULL) {
      TRACE("ERROR: _design_layer_position a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (stratum_technology::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
