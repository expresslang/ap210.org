// Source for AP210 application object
//     printed_component

// Precompiled include files
#include <StdAfx.h>

#include "printed_component.h"

// Classes

printed_component::printed_component() {
   initialize();
   }
printed_component::~printed_component() {
   // Free string attributes
   }
// intialize data members
void printed_component::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int printed_component::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = laminate_component::DynamicType(ID);
      }
   return result;
   }
printed_component *printed_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<printed_component *>(s);
      }
   return NULL;
   }
printed_component *printed_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<printed_component *>(s);
      }
   return NULL;
   }
// construction factory
printed_component *printed_component::Construct() {
   printed_component *result = NULL;

   // create the printed_component.
   result = new printed_component();
   return result;
   }
bool printed_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: printed_component\r\n");

   // Check for the existence of all required attributes
   if (_stratum_feature_implementation == NULL) {
      TRACE("ERROR: _stratum_feature_implementation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (laminate_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
