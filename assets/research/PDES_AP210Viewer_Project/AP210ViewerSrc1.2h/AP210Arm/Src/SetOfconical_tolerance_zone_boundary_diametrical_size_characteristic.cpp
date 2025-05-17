// Source for AP210 application object
//     SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic

// Precompiled include files
#include <StdAfx.h>

#include "SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic.h"

// Classes
#include <conical_tolerance_zone_boundary_diametrical_size_characteristic.h>

SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic::SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic() {
   initialize();
   }
SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic::~SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic() {
   // Free string attributes
   }
// intialize data members
void SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic::initialize() {
   // Required attributes
   _conical_tolerance_zone_boundary_diametrical_size_characteristic = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic *SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic *>(s);
      }
   return NULL;
   }
SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic *SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic *>(s);
      }
   return NULL;
   }
// construction factory
SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic *SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic::Construct() {
   SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic *result = NULL;

   // create the SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic.
   result = new SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic();
   return result;
   }
bool SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic\r\n");

   // Check for the existence of all required attributes
   if (_conical_tolerance_zone_boundary_diametrical_size_characteristic == NULL) {
      TRACE("ERROR: _conical_tolerance_zone_boundary_diametrical_size_characteristic a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
