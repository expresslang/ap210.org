// Source for AP210 application object
//     laminate_component

// Precompiled include files
#include <StdAfx.h>

#include "laminate_component.h"

// Classes
#include <external_definition.h>

laminate_component::laminate_component() {
   initialize();
   }
laminate_component::~laminate_component() {
   // Free string attributes
   }
// intialize data members
void laminate_component::initialize() {
   // Required attributes

   // Optional attributes
   _cad_layer = NULL;
   }
// Runtime type identification
int laminate_component::DynamicType(int ID) {
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
laminate_component *laminate_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<laminate_component *>(s);
      }
   return NULL;
   }
laminate_component *laminate_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<laminate_component *>(s);
      }
   return NULL;
   }
// construction factory
laminate_component *laminate_component::Construct() {
   laminate_component *result = NULL;

   // create the laminate_component.
   result = new laminate_component();
   return result;
   }
bool laminate_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: laminate_component\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (assembly_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
