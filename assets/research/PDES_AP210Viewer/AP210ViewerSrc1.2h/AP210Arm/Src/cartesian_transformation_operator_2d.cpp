// Source for AP210 application object
//     cartesian_transformation_operator_2d

// Precompiled include files
#include <StdAfx.h>

#include "cartesian_transformation_operator_2d.h"

// Classes
#include <orientation.h>
#include <cartesian_point.h>
#include <positive_ratio_measure.h>

cartesian_transformation_operator_2d::cartesian_transformation_operator_2d() {
   initialize();
   }
cartesian_transformation_operator_2d::~cartesian_transformation_operator_2d() {
   // Free string attributes
   }
// intialize data members
void cartesian_transformation_operator_2d::initialize() {
   // Required attributes
   _device_orientation = NULL;
   _translation = NULL;
   _scale = NULL;

   // Optional attributes
   }
// Runtime type identification
int cartesian_transformation_operator_2d::DynamicType(int ID) {
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
cartesian_transformation_operator_2d *cartesian_transformation_operator_2d::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<cartesian_transformation_operator_2d *>(s);
      }
   return NULL;
   }
cartesian_transformation_operator_2d *cartesian_transformation_operator_2d::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<cartesian_transformation_operator_2d *>(s);
      }
   return NULL;
   }
// construction factory
cartesian_transformation_operator_2d *cartesian_transformation_operator_2d::Construct() {
   cartesian_transformation_operator_2d *result = NULL;

   // create the cartesian_transformation_operator_2d.
   result = new cartesian_transformation_operator_2d();
   return result;
   }
bool cartesian_transformation_operator_2d::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: cartesian_transformation_operator_2d\r\n");

   // Check for the existence of all required attributes
   if (_device_orientation == NULL) {
      TRACE("ERROR: _device_orientation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_translation == NULL) {
      TRACE("ERROR: _translation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_scale == NULL) {
      TRACE("ERROR: _scale a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
