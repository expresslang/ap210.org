// Source for AP210 application object
//     datum_based_vector_orientation

// Precompiled include files
#include <StdAfx.h>

#include "datum_based_vector_orientation.h"

// Classes

datum_based_vector_orientation::datum_based_vector_orientation() {
   initialize();
   }
datum_based_vector_orientation::~datum_based_vector_orientation() {
   // Free string attributes
   }
// intialize data members
void datum_based_vector_orientation::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int datum_based_vector_orientation::DynamicType(int ID) {
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
datum_based_vector_orientation *datum_based_vector_orientation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_based_vector_orientation *>(s);
      }
   return NULL;
   }
datum_based_vector_orientation *datum_based_vector_orientation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_based_vector_orientation *>(s);
      }
   return NULL;
   }
// construction factory
datum_based_vector_orientation *datum_based_vector_orientation::Construct() {
   datum_based_vector_orientation *result = NULL;

   // create the datum_based_vector_orientation.
   result = new datum_based_vector_orientation();
   return result;
   }
bool datum_based_vector_orientation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_based_vector_orientation\r\n");

   // Check for the existence of all required attributes
   if (_direction_components == NULL) {
      TRACE("ERROR: _direction_components a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
