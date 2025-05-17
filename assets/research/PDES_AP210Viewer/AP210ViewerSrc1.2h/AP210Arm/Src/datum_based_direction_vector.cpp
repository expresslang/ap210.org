// Source for AP210 application object
//     datum_based_direction_vector

// Precompiled include files
#include <StdAfx.h>

#include "datum_based_direction_vector.h"

// Classes
#include <axis_placement.h>
#include <datum_plane.h>

datum_based_direction_vector::datum_based_direction_vector() {
   initialize();
   }
datum_based_direction_vector::~datum_based_direction_vector() {
   // Free string attributes
   }
// intialize data members
void datum_based_direction_vector::initialize() {
   // Required attributes
   _direction_vector_representation = NULL;
   _vector_of = NULL;

   // Optional attributes
   }
// Runtime type identification
int datum_based_direction_vector::DynamicType(int ID) {
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
datum_based_direction_vector *datum_based_direction_vector::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_based_direction_vector *>(s);
      }
   return NULL;
   }
datum_based_direction_vector *datum_based_direction_vector::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_based_direction_vector *>(s);
      }
   return NULL;
   }
// construction factory
datum_based_direction_vector *datum_based_direction_vector::Construct() {
   datum_based_direction_vector *result = NULL;

   // create the datum_based_direction_vector.
   result = new datum_based_direction_vector();
   return result;
   }
bool datum_based_direction_vector::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_based_direction_vector\r\n");

   // Check for the existence of all required attributes
   if (_direction_vector_representation == NULL) {
      TRACE("ERROR: _direction_vector_representation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_vector_of == NULL) {
      TRACE("ERROR: _vector_of a required attribute is NULL!\r\n");
      result = false;
      }
   if (_positive_direction_vector == NULL) {
      TRACE("ERROR: _positive_direction_vector a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
