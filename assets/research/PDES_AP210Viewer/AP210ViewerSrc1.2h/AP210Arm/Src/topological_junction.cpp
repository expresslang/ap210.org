// Source for AP210 application object
//     topological_junction

// Precompiled include files
#include <StdAfx.h>

#include "topological_junction.h"

// Classes
#include <physical_connectivity_structure_definition.h>

topological_junction::topological_junction() {
   initialize();
   }
topological_junction::~topological_junction() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void topological_junction::initialize() {
   // Required attributes
   _scope = NULL;
   _name = NULL;

   // Optional attributes
   }
// Runtime type identification
int topological_junction::DynamicType(int ID) {
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
topological_junction *topological_junction::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<topological_junction *>(s);
      }
   return NULL;
   }
topological_junction *topological_junction::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<topological_junction *>(s);
      }
   return NULL;
   }
// construction factory
topological_junction *topological_junction::Construct() {
   topological_junction *result = NULL;

   // create the topological_junction.
   result = new topological_junction();
   return result;
   }
bool topological_junction::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: topological_junction\r\n");

   // Check for the existence of all required attributes
   if (_scope == NULL) {
      TRACE("ERROR: _scope a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
