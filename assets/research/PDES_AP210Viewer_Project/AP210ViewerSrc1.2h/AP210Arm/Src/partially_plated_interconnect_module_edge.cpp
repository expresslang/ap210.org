// Source for AP210 application object
//     partially_plated_interconnect_module_edge

// Precompiled include files
#include <StdAfx.h>

#include "partially_plated_interconnect_module_edge.h"

// Classes

partially_plated_interconnect_module_edge::partially_plated_interconnect_module_edge() {
   initialize();
   }
partially_plated_interconnect_module_edge::~partially_plated_interconnect_module_edge() {
   // Free string attributes
   }
// intialize data members
void partially_plated_interconnect_module_edge::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int partially_plated_interconnect_module_edge::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = interconnect_module_edge::DynamicType(ID);
      }
   return result;
   }
partially_plated_interconnect_module_edge *partially_plated_interconnect_module_edge::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<partially_plated_interconnect_module_edge *>(s);
      }
   return NULL;
   }
partially_plated_interconnect_module_edge *partially_plated_interconnect_module_edge::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<partially_plated_interconnect_module_edge *>(s);
      }
   return NULL;
   }
// construction factory
partially_plated_interconnect_module_edge *partially_plated_interconnect_module_edge::Construct() {
   partially_plated_interconnect_module_edge *result = NULL;

   // create the partially_plated_interconnect_module_edge.
   result = new partially_plated_interconnect_module_edge();
   return result;
   }
bool partially_plated_interconnect_module_edge::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: partially_plated_interconnect_module_edge\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (interconnect_module_edge::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
