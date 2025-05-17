// Source for AP210 application object
//     statistical_dimensional_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "statistical_dimensional_tolerance.h"

// Classes
#include <dimensional_characteristic.h>
#include <ee_requirement_occurrence.h>

statistical_dimensional_tolerance::statistical_dimensional_tolerance() {
   initialize();
   }
statistical_dimensional_tolerance::~statistical_dimensional_tolerance() {
   // Free string attributes
   }
// intialize data members
void statistical_dimensional_tolerance::initialize() {
   // Required attributes
   _statistical_control_requirement = NULL;

   // Optional attributes
   _alternate_dimension = NULL;
   }
// Runtime type identification
int statistical_dimensional_tolerance::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = dimensional_characteristic::DynamicType(ID);
      }
   return result;
   }
statistical_dimensional_tolerance *statistical_dimensional_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<statistical_dimensional_tolerance *>(s);
      }
   return NULL;
   }
statistical_dimensional_tolerance *statistical_dimensional_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<statistical_dimensional_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
statistical_dimensional_tolerance *statistical_dimensional_tolerance::Construct() {
   statistical_dimensional_tolerance *result = NULL;

   // create the statistical_dimensional_tolerance.
   result = new statistical_dimensional_tolerance();
   return result;
   }
bool statistical_dimensional_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: statistical_dimensional_tolerance\r\n");

   // Check for the existence of all required attributes
   if (_statistical_control_requirement == NULL) {
      TRACE("ERROR: _statistical_control_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (dimensional_characteristic::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
