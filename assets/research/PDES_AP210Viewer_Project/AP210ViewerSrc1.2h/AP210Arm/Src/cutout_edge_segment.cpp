// Source for AP210 application object
//     cutout_edge_segment

// Precompiled include files
#include <StdAfx.h>

#include "cutout_edge_segment.h"

// Classes
#include <cutout.h>
#include <edge_segment_vertex.h>
#include <edge_segment_vertex.h>

cutout_edge_segment::cutout_edge_segment() {
   initialize();
   }
cutout_edge_segment::~cutout_edge_segment() {
   // Free string attributes
   }
// intialize data members
void cutout_edge_segment::initialize() {
   // Required attributes
   _composed_cutout = NULL;
   _start_vertex = NULL;
   _end_vertex = NULL;

   // Optional attributes
   }
// Runtime type identification
int cutout_edge_segment::DynamicType(int ID) {
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
cutout_edge_segment *cutout_edge_segment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<cutout_edge_segment *>(s);
      }
   return NULL;
   }
cutout_edge_segment *cutout_edge_segment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<cutout_edge_segment *>(s);
      }
   return NULL;
   }
// construction factory
cutout_edge_segment *cutout_edge_segment::Construct() {
   cutout_edge_segment *result = NULL;

   // create the cutout_edge_segment.
   result = new cutout_edge_segment();
   return result;
   }
bool cutout_edge_segment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: cutout_edge_segment\r\n");

   // Check for the existence of all required attributes
   if (_composed_cutout == NULL) {
      TRACE("ERROR: _composed_cutout a required attribute is NULL!\r\n");
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
