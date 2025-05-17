// Source for AP210 application object
//     adjacent_stratum_surface_definition

// Precompiled include files
#include <StdAfx.h>

#include "adjacent_stratum_surface_definition.h"

// Classes
#include <stratum_surface.h>
#include <stratum_surface.h>

adjacent_stratum_surface_definition::adjacent_stratum_surface_definition() {
   initialize();
   }
adjacent_stratum_surface_definition::~adjacent_stratum_surface_definition() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void adjacent_stratum_surface_definition::initialize() {
   // Required attributes
   _name = NULL;
   _precedent_surface = NULL;
   _subsequent_surface = NULL;

   // Optional attributes
   }
// Runtime type identification
int adjacent_stratum_surface_definition::DynamicType(int ID) {
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
adjacent_stratum_surface_definition *adjacent_stratum_surface_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<adjacent_stratum_surface_definition *>(s);
      }
   return NULL;
   }
adjacent_stratum_surface_definition *adjacent_stratum_surface_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<adjacent_stratum_surface_definition *>(s);
      }
   return NULL;
   }
// construction factory
adjacent_stratum_surface_definition *adjacent_stratum_surface_definition::Construct() {
   adjacent_stratum_surface_definition *result = NULL;

   // create the adjacent_stratum_surface_definition.
   result = new adjacent_stratum_surface_definition();
   return result;
   }
bool adjacent_stratum_surface_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: adjacent_stratum_surface_definition\r\n");

   // Check for the existence of all required attributes
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   if (_precedent_surface == NULL) {
      TRACE("ERROR: _precedent_surface a required attribute is NULL!\r\n");
      result = false;
      }
   if (_subsequent_surface == NULL) {
      TRACE("ERROR: _subsequent_surface a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
