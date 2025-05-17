// Source for AP210 application object
//     design_layer_stratum

// Precompiled include files
#include <StdAfx.h>

#include "design_layer_stratum.h"

// Classes

design_layer_stratum::design_layer_stratum() {
   initialize();
   }
design_layer_stratum::~design_layer_stratum() {
   // Free string attributes
   }
// intialize data members
void design_layer_stratum::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int design_layer_stratum::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = stratum::DynamicType(ID);
      }
   return result;
   }
design_layer_stratum *design_layer_stratum::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<design_layer_stratum *>(s);
      }
   return NULL;
   }
design_layer_stratum *design_layer_stratum::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<design_layer_stratum *>(s);
      }
   return NULL;
   }
// construction factory
design_layer_stratum *design_layer_stratum::Construct() {
   design_layer_stratum *result = NULL;

   // create the design_layer_stratum.
   result = new design_layer_stratum();
   return result;
   }
bool design_layer_stratum::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: design_layer_stratum\r\n");

   // Check for the existence of all required attributes
   if (_primary_design_layer_stratum == NULL) {
      TRACE("ERROR: _primary_design_layer_stratum a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (stratum::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
