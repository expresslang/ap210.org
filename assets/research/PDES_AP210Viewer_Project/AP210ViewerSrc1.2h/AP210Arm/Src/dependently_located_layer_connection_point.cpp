// Source for AP210 application object
//     dependently_located_layer_connection_point

// Precompiled include files
#include <StdAfx.h>

#include "dependently_located_layer_connection_point.h"

// Classes

dependently_located_layer_connection_point::dependently_located_layer_connection_point() {
   initialize();
   }
dependently_located_layer_connection_point::~dependently_located_layer_connection_point() {
   // Free string attributes
   }
// intialize data members
void dependently_located_layer_connection_point::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int dependently_located_layer_connection_point::DynamicType(int ID) {
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
dependently_located_layer_connection_point *dependently_located_layer_connection_point::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<dependently_located_layer_connection_point *>(s);
      }
   return NULL;
   }
dependently_located_layer_connection_point *dependently_located_layer_connection_point::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<dependently_located_layer_connection_point *>(s);
      }
   return NULL;
   }
// construction factory
dependently_located_layer_connection_point *dependently_located_layer_connection_point::Construct() {
   dependently_located_layer_connection_point *result = NULL;

   // create the dependently_located_layer_connection_point.
   result = new dependently_located_layer_connection_point();
   return result;
   }
bool dependently_located_layer_connection_point::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: dependently_located_layer_connection_point\r\n");

   // Check for the existence of all required attributes
   if (_associated_design_object == NULL) {
      TRACE("ERROR: _associated_design_object a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (layer_connection_point::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
