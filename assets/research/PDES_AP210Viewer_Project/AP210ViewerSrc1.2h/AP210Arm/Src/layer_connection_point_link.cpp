// Source for AP210 application object
//     layer_connection_point_link

// Precompiled include files
#include <StdAfx.h>

#include "layer_connection_point_link.h"

// Classes
#include <layer_connection_point.h>
#include <layer_connection_point.h>

layer_connection_point_link::layer_connection_point_link() {
   initialize();
   }
layer_connection_point_link::~layer_connection_point_link() {
   // Free string attributes
   }
// intialize data members
void layer_connection_point_link::initialize() {
   // Required attributes
   _precedent_point = NULL;
   _subsequent_point = NULL;

   // Optional attributes
   }
// Runtime type identification
int layer_connection_point_link::DynamicType(int ID) {
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
layer_connection_point_link *layer_connection_point_link::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<layer_connection_point_link *>(s);
      }
   return NULL;
   }
layer_connection_point_link *layer_connection_point_link::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<layer_connection_point_link *>(s);
      }
   return NULL;
   }
// construction factory
layer_connection_point_link *layer_connection_point_link::Construct() {
   layer_connection_point_link *result = NULL;

   // create the layer_connection_point_link.
   result = new layer_connection_point_link();
   return result;
   }
bool layer_connection_point_link::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: layer_connection_point_link\r\n");

   // Check for the existence of all required attributes
   if (_precedent_point == NULL) {
      TRACE("ERROR: _precedent_point a required attribute is NULL!\r\n");
      result = false;
      }
   if (_subsequent_point == NULL) {
      TRACE("ERROR: _subsequent_point a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
