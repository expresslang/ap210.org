// Source for AP210 application object
//     plated_interconnect_module_edge_segment

// Precompiled include files
#include <StdAfx.h>

#include "plated_interconnect_module_edge_segment.h"

// Classes

plated_interconnect_module_edge_segment::plated_interconnect_module_edge_segment() {
   initialize();
   }
plated_interconnect_module_edge_segment::~plated_interconnect_module_edge_segment() {
   // Free string attributes
   }
// intialize data members
void plated_interconnect_module_edge_segment::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int plated_interconnect_module_edge_segment::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = plated_inter_stratum_feature::DynamicType(ID);
      }
   if (result == 0) {
      result = interconnect_module_edge_segment::DynamicType(ID);
      }
   return result;
   }
plated_interconnect_module_edge_segment *plated_interconnect_module_edge_segment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<plated_interconnect_module_edge_segment *>(s);
      }
   return NULL;
   }
plated_interconnect_module_edge_segment *plated_interconnect_module_edge_segment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<plated_interconnect_module_edge_segment *>(s);
      }
   return NULL;
   }
// construction factory
plated_interconnect_module_edge_segment *plated_interconnect_module_edge_segment::Construct() {
   plated_interconnect_module_edge_segment *result = NULL;

   // create the plated_interconnect_module_edge_segment.
   result = new plated_interconnect_module_edge_segment();
   return result;
   }
bool plated_interconnect_module_edge_segment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: plated_interconnect_module_edge_segment\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (plated_inter_stratum_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   if (interconnect_module_edge_segment::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
