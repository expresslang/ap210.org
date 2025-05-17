// Source for AP210 application object
//     datum_system

// Precompiled include files
#include <StdAfx.h>

#include "datum_system.h"

// Classes
#include <datum_reference_frame.h>

datum_system::datum_system() {
   initialize();
   }
datum_system::~datum_system() {
   // Free string attributes
   }
// intialize data members
void datum_system::initialize() {
   // Required attributes
   _established_datum_reference_frame = NULL;

   // Optional attributes
   }
// Runtime type identification
int datum_system::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = non_feature_shape_element::DynamicType(ID);
      }
   return result;
   }
datum_system *datum_system::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_system *>(s);
      }
   return NULL;
   }
datum_system *datum_system::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_system *>(s);
      }
   return NULL;
   }
// construction factory
datum_system *datum_system::Construct() {
   datum_system *result = NULL;

   // create the datum_system.
   result = new datum_system();
   return result;
   }
bool datum_system::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_system\r\n");

   // Check for the existence of all required attributes
   if (_established_datum_reference_frame == NULL) {
      TRACE("ERROR: _established_datum_reference_frame a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (non_feature_shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
