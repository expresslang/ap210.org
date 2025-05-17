// Source for AP210 application object
//     tolerance_zone

// Precompiled include files
#include <StdAfx.h>

#include "tolerance_zone.h"

// Classes
#include <tolerance_zone_boundary.h>

tolerance_zone::tolerance_zone() {
   initialize();
   }
tolerance_zone::~tolerance_zone() {
   // Free string attributes
   }
// intialize data members
void tolerance_zone::initialize() {
   // Required attributes
   _zone_boundary = NULL;

   // Optional attributes
   }
// Runtime type identification
int tolerance_zone::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = non_feature_shape_element::DynamicType(ID);
      }
   return result;
   }
tolerance_zone *tolerance_zone::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<tolerance_zone *>(s);
      }
   return NULL;
   }
tolerance_zone *tolerance_zone::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<tolerance_zone *>(s);
      }
   return NULL;
   }
// construction factory
tolerance_zone *tolerance_zone::Construct() {
   tolerance_zone *result = NULL;

   // create the tolerance_zone.
   result = new tolerance_zone();
   return result;
   }
bool tolerance_zone::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: tolerance_zone\r\n");

   // Check for the existence of all required attributes
   if (_zone_boundary == NULL) {
      TRACE("ERROR: _zone_boundary a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (non_feature_shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
