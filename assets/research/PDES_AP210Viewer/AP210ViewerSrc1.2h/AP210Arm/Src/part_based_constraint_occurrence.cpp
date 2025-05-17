// Source for AP210 application object
//     part_based_constraint_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "part_based_constraint_occurrence.h"

// Classes
#include <ee_product.h>

part_based_constraint_occurrence::part_based_constraint_occurrence() {
   initialize();
   }
part_based_constraint_occurrence::~part_based_constraint_occurrence() {
   // Free string attributes
   }
// intialize data members
void part_based_constraint_occurrence::initialize() {
   // Required attributes
   _constraining_part = NULL;

   // Optional attributes
   }
// Runtime type identification
int part_based_constraint_occurrence::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = constraint_occurrence::DynamicType(ID);
      }
   return result;
   }
part_based_constraint_occurrence *part_based_constraint_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<part_based_constraint_occurrence *>(s);
      }
   return NULL;
   }
part_based_constraint_occurrence *part_based_constraint_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<part_based_constraint_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
part_based_constraint_occurrence *part_based_constraint_occurrence::Construct() {
   part_based_constraint_occurrence *result = NULL;

   // create the part_based_constraint_occurrence.
   result = new part_based_constraint_occurrence();
   return result;
   }
bool part_based_constraint_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: part_based_constraint_occurrence\r\n");

   // Check for the existence of all required attributes
   if (_constraining_part == NULL) {
      TRACE("ERROR: _constraining_part a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (constraint_occurrence::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
