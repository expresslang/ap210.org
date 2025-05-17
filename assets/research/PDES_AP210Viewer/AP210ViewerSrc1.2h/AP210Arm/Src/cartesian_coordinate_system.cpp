// Source for AP210 application object
//     cartesian_coordinate_system

// Precompiled include files
#include <StdAfx.h>

#include "cartesian_coordinate_system.h"

// Classes
#include <length_data_element.h>
#include <angle_data_element.h>

cartesian_coordinate_system::cartesian_coordinate_system() {
   initialize();
   }
cartesian_coordinate_system::~cartesian_coordinate_system() {
   // Free string attributes
   if (_length_unit_of_measure != NULL) {
      free(_length_unit_of_measure);
     }
   }
// intialize data members
void cartesian_coordinate_system::initialize() {
   // Required attributes
   _length_unit_of_measure = NULL;
   _length_uncertainty = NULL;

   // Optional attributes
   _angular_uncertainty = NULL;
   }
// Runtime type identification
int cartesian_coordinate_system::DynamicType(int ID) {
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
cartesian_coordinate_system *cartesian_coordinate_system::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<cartesian_coordinate_system *>(s);
      }
   return NULL;
   }
cartesian_coordinate_system *cartesian_coordinate_system::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<cartesian_coordinate_system *>(s);
      }
   return NULL;
   }
// construction factory
cartesian_coordinate_system *cartesian_coordinate_system::Construct() {
   cartesian_coordinate_system *result = NULL;

   // create the cartesian_coordinate_system.
   result = new cartesian_coordinate_system();
   return result;
   }
bool cartesian_coordinate_system::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: cartesian_coordinate_system\r\n");

   // Check for the existence of all required attributes
   if (_length_unit_of_measure == NULL) {
      TRACE("ERROR: _length_unit_of_measure a required attribute is NULL!\r\n");
      result = false;
      }
   if (_dimensionality == NULL) {
      TRACE("ERROR: _dimensionality a required attribute is NULL!\r\n");
      result = false;
      }
   if (_angle_unit_of_measure == NULL) {
      TRACE("ERROR: _angle_unit_of_measure a required attribute is NULL!\r\n");
      result = false;
      }
   if (_length_uncertainty == NULL) {
      TRACE("ERROR: _length_uncertainty a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
