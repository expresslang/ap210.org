// Source for AP210 application object
//     statistical_geometric_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "statistical_geometric_tolerance.h"

// Classes
#include <geometric_tolerance.h>
#include <ee_requirement_occurrence.h>

statistical_geometric_tolerance::statistical_geometric_tolerance() {
   initialize();
   }
statistical_geometric_tolerance::~statistical_geometric_tolerance() {
   // Free string attributes
   }
// intialize data members
void statistical_geometric_tolerance::initialize() {
   // Required attributes
   _statistical_control_requirement = NULL;

   // Optional attributes
   _alternate_tolerance = NULL;
   }
// Runtime type identification
int statistical_geometric_tolerance::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = geometric_tolerance::DynamicType(ID);
      }
   return result;
   }
statistical_geometric_tolerance *statistical_geometric_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<statistical_geometric_tolerance *>(s);
      }
   return NULL;
   }
statistical_geometric_tolerance *statistical_geometric_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<statistical_geometric_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
statistical_geometric_tolerance *statistical_geometric_tolerance::Construct() {
   statistical_geometric_tolerance *result = NULL;

   // create the statistical_geometric_tolerance.
   result = new statistical_geometric_tolerance();
   return result;
   }
bool statistical_geometric_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: statistical_geometric_tolerance\r\n");

   // Check for the existence of all required attributes
   if (_statistical_control_requirement == NULL) {
      TRACE("ERROR: _statistical_control_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (geometric_tolerance::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
