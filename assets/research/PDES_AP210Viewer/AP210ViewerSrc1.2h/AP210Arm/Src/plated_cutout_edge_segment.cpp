// Source for AP210 application object
//     plated_cutout_edge_segment

// Precompiled include files
#include <StdAfx.h>

#include "plated_cutout_edge_segment.h"

// Classes

plated_cutout_edge_segment::plated_cutout_edge_segment() {
   initialize();
   }
plated_cutout_edge_segment::~plated_cutout_edge_segment() {
   // Free string attributes
   }
// intialize data members
void plated_cutout_edge_segment::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int plated_cutout_edge_segment::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = cutout_edge_segment::DynamicType(ID);
      }
   if (result == 0) {
      result = plated_inter_stratum_feature::DynamicType(ID);
      }
   return result;
   }
plated_cutout_edge_segment *plated_cutout_edge_segment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<plated_cutout_edge_segment *>(s);
      }
   return NULL;
   }
plated_cutout_edge_segment *plated_cutout_edge_segment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<plated_cutout_edge_segment *>(s);
      }
   return NULL;
   }
// construction factory
plated_cutout_edge_segment *plated_cutout_edge_segment::Construct() {
   plated_cutout_edge_segment *result = NULL;

   // create the plated_cutout_edge_segment.
   result = new plated_cutout_edge_segment();
   return result;
   }
bool plated_cutout_edge_segment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: plated_cutout_edge_segment\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (cutout_edge_segment::hasRequiredAttributes() == false) {
      result = false;
      }
   if (plated_inter_stratum_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
