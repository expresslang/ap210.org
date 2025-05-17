// Source for AP210 application object
//     layer

// Precompiled include files
#include <StdAfx.h>

#include "layer.h"

// Classes
#include <inter_stratum_extent.h>
#include <external_definition.h>

layer::layer() {
   initialize();
   }
layer::~layer() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void layer::initialize() {
   // Required attributes
   _extent = NULL;
   _name = NULL;

   // Optional attributes
   _layer_usage = NULL;
   }
// Runtime type identification
int layer::DynamicType(int ID) {
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
layer *layer::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<layer *>(s);
      }
   return NULL;
   }
layer *layer::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<layer *>(s);
      }
   return NULL;
   }
// construction factory
layer *layer::Construct() {
   layer *result = NULL;

   // create the layer.
   result = new layer();
   return result;
   }
bool layer::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: layer\r\n");

   // Check for the existence of all required attributes
   if (_extent == NULL) {
      TRACE("ERROR: _extent a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
