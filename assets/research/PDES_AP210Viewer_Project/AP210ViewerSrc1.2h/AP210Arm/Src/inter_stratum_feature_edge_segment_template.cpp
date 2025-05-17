// Source for AP210 application object
//     inter_stratum_feature_edge_segment_template

// Precompiled include files
#include <StdAfx.h>

#include "inter_stratum_feature_edge_segment_template.h"

// Classes
#include <inter_stratum_feature_edge_template.h>
#include <edge_segment_vertex.h>
#include <edge_segment_vertex.h>

inter_stratum_feature_edge_segment_template::inter_stratum_feature_edge_segment_template() {
   initialize();
   }
inter_stratum_feature_edge_segment_template::~inter_stratum_feature_edge_segment_template() {
   // Free string attributes
   }
// intialize data members
void inter_stratum_feature_edge_segment_template::initialize() {
   // Required attributes
   _composed_edge = NULL;
   _start_vertex = NULL;
   _end_vertex = NULL;

   // Optional attributes
   }
// Runtime type identification
int inter_stratum_feature_edge_segment_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = inter_stratum_feature_template::DynamicType(ID);
      }
   return result;
   }
inter_stratum_feature_edge_segment_template *inter_stratum_feature_edge_segment_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<inter_stratum_feature_edge_segment_template *>(s);
      }
   return NULL;
   }
inter_stratum_feature_edge_segment_template *inter_stratum_feature_edge_segment_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<inter_stratum_feature_edge_segment_template *>(s);
      }
   return NULL;
   }
// construction factory
inter_stratum_feature_edge_segment_template *inter_stratum_feature_edge_segment_template::Construct() {
   inter_stratum_feature_edge_segment_template *result = NULL;

   // create the inter_stratum_feature_edge_segment_template.
   result = new inter_stratum_feature_edge_segment_template();
   return result;
   }
bool inter_stratum_feature_edge_segment_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: inter_stratum_feature_edge_segment_template\r\n");

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
   if (inter_stratum_feature_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
