// Source for AP210 application object
//     inter_stratum_extent

// Precompiled include files
#include <StdAfx.h>

#include "inter_stratum_extent.h"

// Classes
#include <stratum.h>
#include <stratum.h>

inter_stratum_extent::inter_stratum_extent() {
   initialize();
   }
inter_stratum_extent::~inter_stratum_extent() {
   // Free string attributes
   }
// intialize data members
void inter_stratum_extent::initialize() {
   // Required attributes
   _from_stratum = NULL;
   _to_stratum = NULL;

   // Optional attributes
   }
// Runtime type identification
int inter_stratum_extent::DynamicType(int ID) {
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
inter_stratum_extent *inter_stratum_extent::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<inter_stratum_extent *>(s);
      }
   return NULL;
   }
inter_stratum_extent *inter_stratum_extent::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<inter_stratum_extent *>(s);
      }
   return NULL;
   }
// construction factory
inter_stratum_extent *inter_stratum_extent::Construct() {
   inter_stratum_extent *result = NULL;

   // create the inter_stratum_extent.
   result = new inter_stratum_extent();
   return result;
   }
bool inter_stratum_extent::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: inter_stratum_extent\r\n");

   // Check for the existence of all required attributes
   if (_from_stratum == NULL) {
      TRACE("ERROR: _from_stratum a required attribute is NULL!\r\n");
      result = false;
      }
   if (_to_stratum == NULL) {
      TRACE("ERROR: _to_stratum a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
