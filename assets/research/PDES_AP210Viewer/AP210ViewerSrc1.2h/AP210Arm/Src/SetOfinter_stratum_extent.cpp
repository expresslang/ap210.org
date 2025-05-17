// Source for AP210 application object
//     SetOfinter_stratum_extent

// Precompiled include files
#include <StdAfx.h>

#include "SetOfinter_stratum_extent.h"

// Classes
#include <inter_stratum_extent.h>

SetOfinter_stratum_extent::SetOfinter_stratum_extent() {
   initialize();
   }
SetOfinter_stratum_extent::~SetOfinter_stratum_extent() {
   // Free string attributes
   }
// intialize data members
void SetOfinter_stratum_extent::initialize() {
   // Required attributes
   _inter_stratum_extent = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfinter_stratum_extent::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfinter_stratum_extent *SetOfinter_stratum_extent::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfinter_stratum_extent *>(s);
      }
   return NULL;
   }
SetOfinter_stratum_extent *SetOfinter_stratum_extent::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfinter_stratum_extent *>(s);
      }
   return NULL;
   }
// construction factory
SetOfinter_stratum_extent *SetOfinter_stratum_extent::Construct() {
   SetOfinter_stratum_extent *result = NULL;

   // create the SetOfinter_stratum_extent.
   result = new SetOfinter_stratum_extent();
   return result;
   }
bool SetOfinter_stratum_extent::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfinter_stratum_extent\r\n");

   // Check for the existence of all required attributes
   if (_inter_stratum_extent == NULL) {
      TRACE("ERROR: _inter_stratum_extent a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
