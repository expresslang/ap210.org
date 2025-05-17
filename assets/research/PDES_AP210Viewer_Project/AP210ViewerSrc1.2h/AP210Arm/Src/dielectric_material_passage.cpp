// Source for AP210 application object
//     dielectric_material_passage

// Precompiled include files
#include <StdAfx.h>

#include "dielectric_material_passage.h"

// Classes
#include <cutout.h>

dielectric_material_passage::dielectric_material_passage() {
   initialize();
   }
dielectric_material_passage::~dielectric_material_passage() {
   // Free string attributes
   }
// intialize data members
void dielectric_material_passage::initialize() {
   // Required attributes
   _precedent_passage = NULL;

   // Optional attributes
   }
// Runtime type identification
int dielectric_material_passage::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = inter_stratum_feature::DynamicType(ID);
      }
   return result;
   }
dielectric_material_passage *dielectric_material_passage::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<dielectric_material_passage *>(s);
      }
   return NULL;
   }
dielectric_material_passage *dielectric_material_passage::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<dielectric_material_passage *>(s);
      }
   return NULL;
   }
// construction factory
dielectric_material_passage *dielectric_material_passage::Construct() {
   dielectric_material_passage *result = NULL;

   // create the dielectric_material_passage.
   result = new dielectric_material_passage();
   return result;
   }
bool dielectric_material_passage::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: dielectric_material_passage\r\n");

   // Check for the existence of all required attributes
   if (_precedent_passage == NULL) {
      TRACE("ERROR: _precedent_passage a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (inter_stratum_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
