// Source for AP210 application object
//     surface_finish_specification

// Precompiled include files
#include <StdAfx.h>

#include "surface_finish_specification.h"

// Classes

surface_finish_specification::surface_finish_specification() {
   initialize();
   }
surface_finish_specification::~surface_finish_specification() {
   // Free string attributes
   }
// intialize data members
void surface_finish_specification::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int surface_finish_specification::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = material_specification::DynamicType(ID);
      }
   return result;
   }
surface_finish_specification *surface_finish_specification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<surface_finish_specification *>(s);
      }
   return NULL;
   }
surface_finish_specification *surface_finish_specification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<surface_finish_specification *>(s);
      }
   return NULL;
   }
// construction factory
surface_finish_specification *surface_finish_specification::Construct() {
   surface_finish_specification *result = NULL;

   // create the surface_finish_specification.
   result = new surface_finish_specification();
   return result;
   }
bool surface_finish_specification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: surface_finish_specification\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (material_specification::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
