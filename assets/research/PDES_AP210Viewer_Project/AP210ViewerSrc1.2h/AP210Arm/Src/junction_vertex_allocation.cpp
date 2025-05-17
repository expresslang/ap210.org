// Source for AP210 application object
//     junction_vertex_allocation

// Precompiled include files
#include <StdAfx.h>

#include "junction_vertex_allocation.h"

// Classes
#include <topological_junction.h>

junction_vertex_allocation::junction_vertex_allocation() {
   initialize();
   }
junction_vertex_allocation::~junction_vertex_allocation() {
   // Free string attributes
   }
// intialize data members
void junction_vertex_allocation::initialize() {
   // Required attributes
   _required_vertex = NULL;

   // Optional attributes
   }
// Runtime type identification
int junction_vertex_allocation::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = managed_design_object::DynamicType(ID);
      }
   return result;
   }
junction_vertex_allocation *junction_vertex_allocation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<junction_vertex_allocation *>(s);
      }
   return NULL;
   }
junction_vertex_allocation *junction_vertex_allocation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<junction_vertex_allocation *>(s);
      }
   return NULL;
   }
// construction factory
junction_vertex_allocation *junction_vertex_allocation::Construct() {
   junction_vertex_allocation *result = NULL;

   // create the junction_vertex_allocation.
   result = new junction_vertex_allocation();
   return result;
   }
bool junction_vertex_allocation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: junction_vertex_allocation\r\n");

   // Check for the existence of all required attributes
   if (_implementation_point == NULL) {
      TRACE("ERROR: _implementation_point a required attribute is NULL!\r\n");
      result = false;
      }
   if (_required_vertex == NULL) {
      TRACE("ERROR: _required_vertex a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
