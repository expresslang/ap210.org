// Source for AP210 application object
//     plated_passage

// Precompiled include files
#include <StdAfx.h>

#include "plated_passage.h"

// Classes

plated_passage::plated_passage() {
   initialize();
   }
plated_passage::~plated_passage() {
   // Free string attributes
   }
// intialize data members
void plated_passage::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int plated_passage::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = plated_inter_stratum_feature::DynamicType(ID);
      }
   return result;
   }
plated_passage *plated_passage::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<plated_passage *>(s);
      }
   return NULL;
   }
plated_passage *plated_passage::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<plated_passage *>(s);
      }
   return NULL;
   }
// construction factory
plated_passage *plated_passage::Construct() {
   plated_passage *result = NULL;

   // create the plated_passage.
   result = new plated_passage();
   return result;
   }
bool plated_passage::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: plated_passage\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (plated_inter_stratum_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
