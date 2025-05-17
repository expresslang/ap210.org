// Source for AP210 application object
//     SetOftolerance_zone_boundary_member

// Precompiled include files
#include <StdAfx.h>

#include "SetOftolerance_zone_boundary_member.h"

// Classes
#include <tolerance_zone_boundary_member.h>

SetOftolerance_zone_boundary_member::SetOftolerance_zone_boundary_member() {
   initialize();
   }
SetOftolerance_zone_boundary_member::~SetOftolerance_zone_boundary_member() {
   // Free string attributes
   }
// intialize data members
void SetOftolerance_zone_boundary_member::initialize() {
   // Required attributes
   _tolerance_zone_boundary_member = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOftolerance_zone_boundary_member::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOftolerance_zone_boundary_member *SetOftolerance_zone_boundary_member::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOftolerance_zone_boundary_member *>(s);
      }
   return NULL;
   }
SetOftolerance_zone_boundary_member *SetOftolerance_zone_boundary_member::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOftolerance_zone_boundary_member *>(s);
      }
   return NULL;
   }
// construction factory
SetOftolerance_zone_boundary_member *SetOftolerance_zone_boundary_member::Construct() {
   SetOftolerance_zone_boundary_member *result = NULL;

   // create the SetOftolerance_zone_boundary_member.
   result = new SetOftolerance_zone_boundary_member();
   return result;
   }
bool SetOftolerance_zone_boundary_member::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOftolerance_zone_boundary_member\r\n");

   // Check for the existence of all required attributes
   if (_tolerance_zone_boundary_member == NULL) {
      TRACE("ERROR: _tolerance_zone_boundary_member a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
