// Source for AP210 application object
//     dimension_location_with_specified_datum_system

// Precompiled include files
#include <StdAfx.h>

#include "dimension_location_with_specified_datum_system.h"

// Classes
#include <datum_system_defining_conditions_without_material_conditions.h>

dimension_location_with_specified_datum_system::dimension_location_with_specified_datum_system() {
   initialize();
   }
dimension_location_with_specified_datum_system::~dimension_location_with_specified_datum_system() {
   // Free string attributes
   }
// intialize data members
void dimension_location_with_specified_datum_system::initialize() {
   // Required attributes
   _referenced_datum_system_defining_conditions = NULL;

   // Optional attributes
   }
// Runtime type identification
int dimension_location_with_specified_datum_system::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = dimensional_location::DynamicType(ID);
      }
   return result;
   }
dimension_location_with_specified_datum_system *dimension_location_with_specified_datum_system::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<dimension_location_with_specified_datum_system *>(s);
      }
   return NULL;
   }
dimension_location_with_specified_datum_system *dimension_location_with_specified_datum_system::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<dimension_location_with_specified_datum_system *>(s);
      }
   return NULL;
   }
// construction factory
dimension_location_with_specified_datum_system *dimension_location_with_specified_datum_system::Construct() {
   dimension_location_with_specified_datum_system *result = NULL;

   // create the dimension_location_with_specified_datum_system.
   result = new dimension_location_with_specified_datum_system();
   return result;
   }
bool dimension_location_with_specified_datum_system::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: dimension_location_with_specified_datum_system\r\n");

   // Check for the existence of all required attributes
   if (_referenced_datum_system_defining_conditions == NULL) {
      TRACE("ERROR: _referenced_datum_system_defining_conditions a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (dimensional_location::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
