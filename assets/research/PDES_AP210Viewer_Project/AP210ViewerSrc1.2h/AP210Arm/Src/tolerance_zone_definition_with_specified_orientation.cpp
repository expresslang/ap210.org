// Source for AP210 application object
//     tolerance_zone_definition_with_specified_orientation

// Precompiled include files
#include <StdAfx.h>

#include "tolerance_zone_definition_with_specified_orientation.h"

// Classes

tolerance_zone_definition_with_specified_orientation::tolerance_zone_definition_with_specified_orientation() {
   initialize();
   }
tolerance_zone_definition_with_specified_orientation::~tolerance_zone_definition_with_specified_orientation() {
   // Free string attributes
   }
// intialize data members
void tolerance_zone_definition_with_specified_orientation::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int tolerance_zone_definition_with_specified_orientation::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = tolerance_zone_definition::DynamicType(ID);
      }
   return result;
   }
tolerance_zone_definition_with_specified_orientation *tolerance_zone_definition_with_specified_orientation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<tolerance_zone_definition_with_specified_orientation *>(s);
      }
   return NULL;
   }
tolerance_zone_definition_with_specified_orientation *tolerance_zone_definition_with_specified_orientation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<tolerance_zone_definition_with_specified_orientation *>(s);
      }
   return NULL;
   }
// construction factory
tolerance_zone_definition_with_specified_orientation *tolerance_zone_definition_with_specified_orientation::Construct() {
   tolerance_zone_definition_with_specified_orientation *result = NULL;

   // create the tolerance_zone_definition_with_specified_orientation.
   result = new tolerance_zone_definition_with_specified_orientation();
   return result;
   }
bool tolerance_zone_definition_with_specified_orientation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: tolerance_zone_definition_with_specified_orientation\r\n");

   // Check for the existence of all required attributes
   if (_zone_orientation == NULL) {
      TRACE("ERROR: _zone_orientation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (tolerance_zone_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
