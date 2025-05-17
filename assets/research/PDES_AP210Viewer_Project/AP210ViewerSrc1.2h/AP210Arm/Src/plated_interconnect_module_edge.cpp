// Source for AP210 application object
//     plated_interconnect_module_edge

// Precompiled include files
#include <StdAfx.h>

#include "plated_interconnect_module_edge.h"

// Classes

plated_interconnect_module_edge::plated_interconnect_module_edge() {
   initialize();
   }
plated_interconnect_module_edge::~plated_interconnect_module_edge() {
   // Free string attributes
   }
// intialize data members
void plated_interconnect_module_edge::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int plated_interconnect_module_edge::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = interconnect_module_edge::DynamicType(ID);
      }
   if (result == 0) {
      result = plated_inter_stratum_feature::DynamicType(ID);
      }
   return result;
   }
plated_interconnect_module_edge *plated_interconnect_module_edge::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<plated_interconnect_module_edge *>(s);
      }
   return NULL;
   }
plated_interconnect_module_edge *plated_interconnect_module_edge::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<plated_interconnect_module_edge *>(s);
      }
   return NULL;
   }
// construction factory
plated_interconnect_module_edge *plated_interconnect_module_edge::Construct() {
   plated_interconnect_module_edge *result = NULL;

   // create the plated_interconnect_module_edge.
   result = new plated_interconnect_module_edge();
   return result;
   }
bool plated_interconnect_module_edge::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: plated_interconnect_module_edge\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (interconnect_module_edge::hasRequiredAttributes() == false) {
      result = false;
      }
   if (plated_inter_stratum_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
