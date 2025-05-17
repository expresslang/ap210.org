// Source for AP210 application object
//     bounding_curve

// Precompiled include files
#include <StdAfx.h>

#include "bounding_curve.h"

// Classes
#include <external_definition.h>
#include <trimmed_line.h>

bounding_curve::bounding_curve() {
   initialize();
   }
bounding_curve::~bounding_curve() {
   // Free string attributes
   }
// intialize data members
void bounding_curve::initialize() {
   // Required attributes
   _mapping_function = NULL;
   _basis_curve = NULL;

   // Optional attributes
   }
// Runtime type identification
int bounding_curve::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = curve::DynamicType(ID);
      }
   return result;
   }
bounding_curve *bounding_curve::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<bounding_curve *>(s);
      }
   return NULL;
   }
bounding_curve *bounding_curve::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<bounding_curve *>(s);
      }
   return NULL;
   }
// construction factory
bounding_curve *bounding_curve::Construct() {
   bounding_curve *result = NULL;

   // create the bounding_curve.
   result = new bounding_curve();
   return result;
   }
bool bounding_curve::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: bounding_curve\r\n");

   // Check for the existence of all required attributes
   if (_mapping_function == NULL) {
      TRACE("ERROR: _mapping_function a required attribute is NULL!\r\n");
      result = false;
      }
   if (_basis_curve == NULL) {
      TRACE("ERROR: _basis_curve a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (curve::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
