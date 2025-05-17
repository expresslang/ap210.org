// Source for AP210 application object
//     SetOftolerance_zone_boundary_member_offset

// Precompiled include files
#include <StdAfx.h>

#include "SetOftolerance_zone_boundary_member_offset.h"

// Classes
#include <tolerance_zone_boundary_member_offset.h>

SetOftolerance_zone_boundary_member_offset::SetOftolerance_zone_boundary_member_offset() {
   initialize();
   }
SetOftolerance_zone_boundary_member_offset::~SetOftolerance_zone_boundary_member_offset() {
   // Free string attributes
   }
// intialize data members
void SetOftolerance_zone_boundary_member_offset::initialize() {
   // Required attributes
   _tolerance_zone_boundary_member_offset = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOftolerance_zone_boundary_member_offset::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOftolerance_zone_boundary_member_offset *SetOftolerance_zone_boundary_member_offset::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOftolerance_zone_boundary_member_offset *>(s);
      }
   return NULL;
   }
SetOftolerance_zone_boundary_member_offset *SetOftolerance_zone_boundary_member_offset::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOftolerance_zone_boundary_member_offset *>(s);
      }
   return NULL;
   }
// construction factory
SetOftolerance_zone_boundary_member_offset *SetOftolerance_zone_boundary_member_offset::Construct() {
   SetOftolerance_zone_boundary_member_offset *result = NULL;

   // create the SetOftolerance_zone_boundary_member_offset.
   result = new SetOftolerance_zone_boundary_member_offset();
   return result;
   }
bool SetOftolerance_zone_boundary_member_offset::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOftolerance_zone_boundary_member_offset\r\n");

   // Check for the existence of all required attributes
   if (_tolerance_zone_boundary_member_offset == NULL) {
      TRACE("ERROR: _tolerance_zone_boundary_member_offset a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
