// Source for AP210 application object
//     next_higher_assembly_relationship

// Precompiled include files
#include <StdAfx.h>

#include "next_higher_assembly_relationship.h"

// Classes
#include <data_element.h>

next_higher_assembly_relationship::next_higher_assembly_relationship() {
   initialize();
   }
next_higher_assembly_relationship::~next_higher_assembly_relationship() {
   // Free string attributes
   if (_reference_designation != NULL) {
      free(_reference_designation);
     }
   }
// intialize data members
void next_higher_assembly_relationship::initialize() {
   // Required attributes
   _reference_designation = NULL;

   // Optional attributes
   _quantity = NULL;
   }
// Runtime type identification
int next_higher_assembly_relationship::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = assembly_composition_relationship::DynamicType(ID);
      }
   return result;
   }
next_higher_assembly_relationship *next_higher_assembly_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<next_higher_assembly_relationship *>(s);
      }
   return NULL;
   }
next_higher_assembly_relationship *next_higher_assembly_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<next_higher_assembly_relationship *>(s);
      }
   return NULL;
   }
// construction factory
next_higher_assembly_relationship *next_higher_assembly_relationship::Construct() {
   next_higher_assembly_relationship *result = NULL;

   // create the next_higher_assembly_relationship.
   result = new next_higher_assembly_relationship();
   return result;
   }
bool next_higher_assembly_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: next_higher_assembly_relationship\r\n");

   // Check for the existence of all required attributes
   if (_reference_designation == NULL) {
      TRACE("ERROR: _reference_designation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (assembly_composition_relationship::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
