// Source for AP210 application object
//     probe_access_area

// Precompiled include files
#include <StdAfx.h>

#include "probe_access_area.h"

// Classes
#include <stratum_feature.h>
#include <connection_zone.h>

probe_access_area::probe_access_area() {
   initialize();
   }
probe_access_area::~probe_access_area() {
   // Free string attributes
   }
// intialize data members
void probe_access_area::initialize() {
   // Required attributes
   _probed_layout_item = NULL;
   _probe_contact_zone = NULL;

   // Optional attributes
   }
// Runtime type identification
int probe_access_area::DynamicType(int ID) {
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
probe_access_area *probe_access_area::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<probe_access_area *>(s);
      }
   return NULL;
   }
probe_access_area *probe_access_area::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<probe_access_area *>(s);
      }
   return NULL;
   }
// construction factory
probe_access_area *probe_access_area::Construct() {
   probe_access_area *result = NULL;

   // create the probe_access_area.
   result = new probe_access_area();
   return result;
   }
bool probe_access_area::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: probe_access_area\r\n");

   // Check for the existence of all required attributes
   if (_probed_layout_item == NULL) {
      TRACE("ERROR: _probed_layout_item a required attribute is NULL!\r\n");
      result = false;
      }
   if (_probe_contact_zone == NULL) {
      TRACE("ERROR: _probe_contact_zone a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (laminate_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
