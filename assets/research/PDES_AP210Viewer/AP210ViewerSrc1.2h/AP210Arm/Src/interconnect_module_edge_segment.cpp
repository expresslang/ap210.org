// Source for AP210 application object
//     interconnect_module_edge_segment

// Precompiled include files
#include <StdAfx.h>

#include "interconnect_module_edge_segment.h"

// Classes
#include <interconnect_module_edge.h>
#include <edge_segment_vertex.h>
#include <edge_segment_vertex.h>

interconnect_module_edge_segment::interconnect_module_edge_segment() {
   initialize();
   }
interconnect_module_edge_segment::~interconnect_module_edge_segment() {
   // Free string attributes
   }
// intialize data members
void interconnect_module_edge_segment::initialize() {
   // Required attributes
   _composed_edge = NULL;
   _start_vertex = NULL;
   _end_vertex = NULL;

   // Optional attributes
   }
// Runtime type identification
int interconnect_module_edge_segment::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = inter_stratum_feature::DynamicType(ID);
      }
   return result;
   }
interconnect_module_edge_segment *interconnect_module_edge_segment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interconnect_module_edge_segment *>(s);
      }
   return NULL;
   }
interconnect_module_edge_segment *interconnect_module_edge_segment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interconnect_module_edge_segment *>(s);
      }
   return NULL;
   }
// construction factory
interconnect_module_edge_segment *interconnect_module_edge_segment::Construct() {
   interconnect_module_edge_segment *result = NULL;

   // create the interconnect_module_edge_segment.
   result = new interconnect_module_edge_segment();
   return result;
   }
bool interconnect_module_edge_segment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interconnect_module_edge_segment\r\n");

   // Check for the existence of all required attributes
   if (_composed_edge == NULL) {
      TRACE("ERROR: _composed_edge a required attribute is NULL!\r\n");
      result = false;
      }
   if (_start_vertex == NULL) {
      TRACE("ERROR: _start_vertex a required attribute is NULL!\r\n");
      result = false;
      }
   if (_end_vertex == NULL) {
      TRACE("ERROR: _end_vertex a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (inter_stratum_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
