// Source for AP210 application object
//     join_relationship

// Precompiled include files
#include <StdAfx.h>

#include "join_relationship.h"

// Classes

join_relationship::join_relationship() {
   initialize();
   }
join_relationship::~join_relationship() {
   // Free string attributes
   }
// intialize data members
void join_relationship::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int join_relationship::DynamicType(int ID) {
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
join_relationship *join_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<join_relationship *>(s);
      }
   return NULL;
   }
join_relationship *join_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<join_relationship *>(s);
      }
   return NULL;
   }
// construction factory
join_relationship *join_relationship::Construct() {
   join_relationship *result = NULL;

   // create the join_relationship.
   result = new join_relationship();
   return result;
   }
bool join_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: join_relationship\r\n");

   // Check for the existence of all required attributes
   if (_points_to_be_connected == NULL) {
      TRACE("ERROR: _points_to_be_connected a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
