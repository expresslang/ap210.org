// Source for AP210 application object
//     composite_signal_property_relationship

// Precompiled include files
#include <StdAfx.h>

#include "composite_signal_property_relationship.h"

// Classes
#include <composite_signal_property.h>
#include <signal_property.h>
#include <external_definition.h>

composite_signal_property_relationship::composite_signal_property_relationship() {
   initialize();
   }
composite_signal_property_relationship::~composite_signal_property_relationship() {
   // Free string attributes
   }
// intialize data members
void composite_signal_property_relationship::initialize() {
   // Required attributes
   _composition = NULL;
   _signal_property_structural_element = NULL;
   _aggregation_operation = NULL;

   // Optional attributes
   }
// Runtime type identification
int composite_signal_property_relationship::DynamicType(int ID) {
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
composite_signal_property_relationship *composite_signal_property_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<composite_signal_property_relationship *>(s);
      }
   return NULL;
   }
composite_signal_property_relationship *composite_signal_property_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<composite_signal_property_relationship *>(s);
      }
   return NULL;
   }
// construction factory
composite_signal_property_relationship *composite_signal_property_relationship::Construct() {
   composite_signal_property_relationship *result = NULL;

   // create the composite_signal_property_relationship.
   result = new composite_signal_property_relationship();
   return result;
   }
bool composite_signal_property_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: composite_signal_property_relationship\r\n");

   // Check for the existence of all required attributes
   if (_composition == NULL) {
      TRACE("ERROR: _composition a required attribute is NULL!\r\n");
      result = false;
      }
   if (_signal_property_structural_element == NULL) {
      TRACE("ERROR: _signal_property_structural_element a required attribute is NULL!\r\n");
      result = false;
      }
   if (_aggregation_operation == NULL) {
      TRACE("ERROR: _aggregation_operation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
