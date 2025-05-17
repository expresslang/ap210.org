// Source for AP210 application object
//     interface_requirement_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "interface_requirement_occurrence.h"

// Classes
#include <next_higher_assembly_interface_requirement.h>

interface_requirement_occurrence::interface_requirement_occurrence() {
   initialize();
   }
interface_requirement_occurrence::~interface_requirement_occurrence() {
   // Free string attributes
   }
// intialize data members
void interface_requirement_occurrence::initialize() {
   // Required attributes
   _interface_to_next_higher_assembly = NULL;

   // Optional attributes
   }
// Runtime type identification
int interface_requirement_occurrence::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = design_requirement_occurrence::DynamicType(ID);
      }
   return result;
   }
interface_requirement_occurrence *interface_requirement_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interface_requirement_occurrence *>(s);
      }
   return NULL;
   }
interface_requirement_occurrence *interface_requirement_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interface_requirement_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
interface_requirement_occurrence *interface_requirement_occurrence::Construct() {
   interface_requirement_occurrence *result = NULL;

   // create the interface_requirement_occurrence.
   result = new interface_requirement_occurrence();
   return result;
   }
bool interface_requirement_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interface_requirement_occurrence\r\n");

   // Check for the existence of all required attributes
   if (_interface_to_next_higher_assembly == NULL) {
      TRACE("ERROR: _interface_to_next_higher_assembly a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (design_requirement_occurrence::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
