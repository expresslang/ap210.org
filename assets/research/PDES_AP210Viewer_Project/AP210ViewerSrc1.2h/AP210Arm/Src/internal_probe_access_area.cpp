// Source for AP210 application object
//     internal_probe_access_area

// Precompiled include files
#include <StdAfx.h>

#include "internal_probe_access_area.h"

// Classes
#include <stratum_feature.h>

internal_probe_access_area::internal_probe_access_area() {
   initialize();
   }
internal_probe_access_area::~internal_probe_access_area() {
   // Free string attributes
   }
// intialize data members
void internal_probe_access_area::initialize() {
   // Required attributes
   _stratum_feature_implementation = NULL;

   // Optional attributes
   }
// Runtime type identification
int internal_probe_access_area::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = probe_access_area::DynamicType(ID);
      }
   return result;
   }
internal_probe_access_area *internal_probe_access_area::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<internal_probe_access_area *>(s);
      }
   return NULL;
   }
internal_probe_access_area *internal_probe_access_area::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<internal_probe_access_area *>(s);
      }
   return NULL;
   }
// construction factory
internal_probe_access_area *internal_probe_access_area::Construct() {
   internal_probe_access_area *result = NULL;

   // create the internal_probe_access_area.
   result = new internal_probe_access_area();
   return result;
   }
bool internal_probe_access_area::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: internal_probe_access_area\r\n");

   // Check for the existence of all required attributes
   if (_stratum_feature_implementation == NULL) {
      TRACE("ERROR: _stratum_feature_implementation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (probe_access_area::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
