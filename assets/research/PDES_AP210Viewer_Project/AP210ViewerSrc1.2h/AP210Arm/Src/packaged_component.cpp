// Source for AP210 application object
//     packaged_component

// Precompiled include files
#include <StdAfx.h>

#include "packaged_component.h"

// Classes
#include <altered_package.h>

packaged_component::packaged_component() {
   initialize();
   }
packaged_component::~packaged_component() {
   // Free string attributes
   }
// intialize data members
void packaged_component::initialize() {
   // Required attributes

   // Optional attributes
   _selected_package_alternate = NULL;
   }
// Runtime type identification
int packaged_component::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = assembly_component::DynamicType(ID);
      }
   return result;
   }
packaged_component *packaged_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<packaged_component *>(s);
      }
   return NULL;
   }
packaged_component *packaged_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<packaged_component *>(s);
      }
   return NULL;
   }
// construction factory
packaged_component *packaged_component::Construct() {
   packaged_component *result = NULL;

   // create the packaged_component.
   result = new packaged_component();
   return result;
   }
bool packaged_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: packaged_component\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (assembly_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
