// Source for AP210 application object
//     interconnect_module_edge

// Precompiled include files
#include <StdAfx.h>

#include "interconnect_module_edge.h"

// Classes

interconnect_module_edge::interconnect_module_edge() {
   initialize();
   }
interconnect_module_edge::~interconnect_module_edge() {
   // Free string attributes
   }
// intialize data members
void interconnect_module_edge::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int interconnect_module_edge::DynamicType(int ID) {
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
interconnect_module_edge *interconnect_module_edge::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interconnect_module_edge *>(s);
      }
   return NULL;
   }
interconnect_module_edge *interconnect_module_edge::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interconnect_module_edge *>(s);
      }
   return NULL;
   }
// construction factory
interconnect_module_edge *interconnect_module_edge::Construct() {
   interconnect_module_edge *result = NULL;

   // create the interconnect_module_edge.
   result = new interconnect_module_edge();
   return result;
   }
bool interconnect_module_edge::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interconnect_module_edge\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (inter_stratum_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
