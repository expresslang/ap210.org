// Source for AP210 application object
//     interconnect_module_edge_segment_surface

// Precompiled include files
#include <StdAfx.h>

#include "interconnect_module_edge_segment_surface.h"

// Classes
#include <interconnect_module_edge_surface.h>
#include <edge_segment_vertex.h>
#include <edge_segment_vertex.h>

interconnect_module_edge_segment_surface::interconnect_module_edge_segment_surface() {
   initialize();
   }
interconnect_module_edge_segment_surface::~interconnect_module_edge_segment_surface() {
   // Free string attributes
   }
// intialize data members
void interconnect_module_edge_segment_surface::initialize() {
   // Required attributes
   _composed_surface = NULL;
   _start_vertex = NULL;
   _end_vertex = NULL;

   // Optional attributes
   }
// Runtime type identification
int interconnect_module_edge_segment_surface::DynamicType(int ID) {
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
interconnect_module_edge_segment_surface *interconnect_module_edge_segment_surface::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interconnect_module_edge_segment_surface *>(s);
      }
   return NULL;
   }
interconnect_module_edge_segment_surface *interconnect_module_edge_segment_surface::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interconnect_module_edge_segment_surface *>(s);
      }
   return NULL;
   }
// construction factory
interconnect_module_edge_segment_surface *interconnect_module_edge_segment_surface::Construct() {
   interconnect_module_edge_segment_surface *result = NULL;

   // create the interconnect_module_edge_segment_surface.
   result = new interconnect_module_edge_segment_surface();
   return result;
   }
bool interconnect_module_edge_segment_surface::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interconnect_module_edge_segment_surface\r\n");

   // Check for the existence of all required attributes
   if (_composed_surface == NULL) {
      TRACE("ERROR: _composed_surface a required attribute is NULL!\r\n");
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
   if (interconnect_module_surface_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
