// Source for AP210 application object
//     interconnect_module_edge_surface

// Precompiled include files
#include <StdAfx.h>

#include "interconnect_module_edge_surface.h"

// Classes

interconnect_module_edge_surface::interconnect_module_edge_surface() {
   initialize();
   }
interconnect_module_edge_surface::~interconnect_module_edge_surface() {
   // Free string attributes
   }
// intialize data members
void interconnect_module_edge_surface::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int interconnect_module_edge_surface::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = interconnect_module_surface_feature::DynamicType(ID);
      }
   return result;
   }
interconnect_module_edge_surface *interconnect_module_edge_surface::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interconnect_module_edge_surface *>(s);
      }
   return NULL;
   }
interconnect_module_edge_surface *interconnect_module_edge_surface::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interconnect_module_edge_surface *>(s);
      }
   return NULL;
   }
// construction factory
interconnect_module_edge_surface *interconnect_module_edge_surface::Construct() {
   interconnect_module_edge_surface *result = NULL;

   // create the interconnect_module_edge_surface.
   result = new interconnect_module_edge_surface();
   return result;
   }
bool interconnect_module_edge_surface::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interconnect_module_edge_surface\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (interconnect_module_surface_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
