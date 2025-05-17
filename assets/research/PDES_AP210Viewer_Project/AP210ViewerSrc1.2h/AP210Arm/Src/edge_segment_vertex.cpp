// Source for AP210 application object
//     edge_segment_vertex

// Precompiled include files
#include <StdAfx.h>

#include "edge_segment_vertex.h"

// Classes

edge_segment_vertex::edge_segment_vertex() {
   initialize();
   }
edge_segment_vertex::~edge_segment_vertex() {
   // Free string attributes
   }
// intialize data members
void edge_segment_vertex::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int edge_segment_vertex::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = single_datum::DynamicType(ID);
      }
   return result;
   }
edge_segment_vertex *edge_segment_vertex::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<edge_segment_vertex *>(s);
      }
   return NULL;
   }
edge_segment_vertex *edge_segment_vertex::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<edge_segment_vertex *>(s);
      }
   return NULL;
   }
// construction factory
edge_segment_vertex *edge_segment_vertex::Construct() {
   edge_segment_vertex *result = NULL;

   // create the edge_segment_vertex.
   result = new edge_segment_vertex();
   return result;
   }
bool edge_segment_vertex::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: edge_segment_vertex\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (single_datum::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
