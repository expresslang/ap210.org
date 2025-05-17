// Source for AP210 application object
//     layer_connection_point

// Precompiled include files
#include <StdAfx.h>

#include "layer_connection_point.h"

// Classes
#include <design_layer_stratum.h>

layer_connection_point::layer_connection_point() {
   initialize();
   }
layer_connection_point::~layer_connection_point() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void layer_connection_point::initialize() {
   // Required attributes
   _name = NULL;
   _resident_design_layer_stratum = NULL;

   // Optional attributes
   }
// Runtime type identification
int layer_connection_point::DynamicType(int ID) {
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
layer_connection_point *layer_connection_point::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<layer_connection_point *>(s);
      }
   return NULL;
   }
layer_connection_point *layer_connection_point::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<layer_connection_point *>(s);
      }
   return NULL;
   }
// construction factory
layer_connection_point *layer_connection_point::Construct() {
   layer_connection_point *result = NULL;

   // create the layer_connection_point.
   result = new layer_connection_point();
   return result;
   }
bool layer_connection_point::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: layer_connection_point\r\n");

   // Check for the existence of all required attributes
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   if (_resident_design_layer_stratum == NULL) {
      TRACE("ERROR: _resident_design_layer_stratum a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
