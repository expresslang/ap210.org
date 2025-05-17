// Source for AP210 application object
//     connectivity_sub_structure

// Precompiled include files
#include <StdAfx.h>

#include "connectivity_sub_structure.h"

// Classes

connectivity_sub_structure::connectivity_sub_structure() {
   initialize();
   }
connectivity_sub_structure::~connectivity_sub_structure() {
   // Free string attributes
   }
// intialize data members
void connectivity_sub_structure::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int connectivity_sub_structure::DynamicType(int ID) {
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
connectivity_sub_structure *connectivity_sub_structure::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<connectivity_sub_structure *>(s);
      }
   return NULL;
   }
connectivity_sub_structure *connectivity_sub_structure::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<connectivity_sub_structure *>(s);
      }
   return NULL;
   }
// construction factory
connectivity_sub_structure *connectivity_sub_structure::Construct() {
   connectivity_sub_structure *result = NULL;

   // create the connectivity_sub_structure.
   result = new connectivity_sub_structure();
   return result;
   }
bool connectivity_sub_structure::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: connectivity_sub_structure\r\n");

   // Check for the existence of all required attributes
   if (_members == NULL) {
      TRACE("ERROR: _members a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
