// Source for AP210 application object
//     edge_shape

// Precompiled include files
#include <StdAfx.h>

#include "edge_shape.h"

// Classes

edge_shape::edge_shape() {
   initialize();
   }
edge_shape::~edge_shape() {
   // Free string attributes
   }
// intialize data members
void edge_shape::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int edge_shape::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = planar_shape::DynamicType(ID);
      }
   return result;
   }
edge_shape *edge_shape::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<edge_shape *>(s);
      }
   return NULL;
   }
edge_shape *edge_shape::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<edge_shape *>(s);
      }
   return NULL;
   }
// construction factory
edge_shape *edge_shape::Construct() {
   edge_shape *result = NULL;

   // create the edge_shape.
   result = new edge_shape();
   return result;
   }
bool edge_shape::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: edge_shape\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (planar_shape::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
