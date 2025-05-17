// Source for AP210 application object
//     internal_stratum_access

// Precompiled include files
#include <StdAfx.h>

#include "internal_stratum_access.h"

// Classes
#include <internal_probe_access_area.h>
#include <via.h>

internal_stratum_access::internal_stratum_access() {
   initialize();
   }
internal_stratum_access::~internal_stratum_access() {
   // Free string attributes
   }
// intialize data members
void internal_stratum_access::initialize() {
   // Required attributes
   _connected_probe = NULL;
   _inter_stratum_feature = NULL;

   // Optional attributes
   }
// Runtime type identification
int internal_stratum_access::DynamicType(int ID) {
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
internal_stratum_access *internal_stratum_access::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<internal_stratum_access *>(s);
      }
   return NULL;
   }
internal_stratum_access *internal_stratum_access::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<internal_stratum_access *>(s);
      }
   return NULL;
   }
// construction factory
internal_stratum_access *internal_stratum_access::Construct() {
   internal_stratum_access *result = NULL;

   // create the internal_stratum_access.
   result = new internal_stratum_access();
   return result;
   }
bool internal_stratum_access::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: internal_stratum_access\r\n");

   // Check for the existence of all required attributes
   if (_connected_probe == NULL) {
      TRACE("ERROR: _connected_probe a required attribute is NULL!\r\n");
      result = false;
      }
   if (_inter_stratum_feature == NULL) {
      TRACE("ERROR: _inter_stratum_feature a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
