// Source for AP210 application object
//     explicitly_located_layer_connection_point

// Precompiled include files
#include <StdAfx.h>

#include "explicitly_located_layer_connection_point.h"

// Classes
#include <cartesian_point.h>

explicitly_located_layer_connection_point::explicitly_located_layer_connection_point() {
   initialize();
   }
explicitly_located_layer_connection_point::~explicitly_located_layer_connection_point() {
   // Free string attributes
   }
// intialize data members
void explicitly_located_layer_connection_point::initialize() {
   // Required attributes
   _location = NULL;

   // Optional attributes
   }
// Runtime type identification
int explicitly_located_layer_connection_point::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = layer_connection_point::DynamicType(ID);
      }
   return result;
   }
explicitly_located_layer_connection_point *explicitly_located_layer_connection_point::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<explicitly_located_layer_connection_point *>(s);
      }
   return NULL;
   }
explicitly_located_layer_connection_point *explicitly_located_layer_connection_point::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<explicitly_located_layer_connection_point *>(s);
      }
   return NULL;
   }
// construction factory
explicitly_located_layer_connection_point *explicitly_located_layer_connection_point::Construct() {
   explicitly_located_layer_connection_point *result = NULL;

   // create the explicitly_located_layer_connection_point.
   result = new explicitly_located_layer_connection_point();
   return result;
   }
bool explicitly_located_layer_connection_point::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: explicitly_located_layer_connection_point\r\n");

   // Check for the existence of all required attributes
   if (_location == NULL) {
      TRACE("ERROR: _location a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (layer_connection_point::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
