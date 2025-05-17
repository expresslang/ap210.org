// Source for AP210 application object
//     dielectric_crossover_area

// Precompiled include files
#include <StdAfx.h>

#include "dielectric_crossover_area.h"

// Classes
#include <stratum_feature.h>
#include <stratum_feature.h>
#include <stratum_feature.h>

dielectric_crossover_area::dielectric_crossover_area() {
   initialize();
   }
dielectric_crossover_area::~dielectric_crossover_area() {
   // Free string attributes
   }
// intialize data members
void dielectric_crossover_area::initialize() {
   // Required attributes
   _related_concept = NULL;
   _relating_concept = NULL;
   _resulting_dielectric_crossover = NULL;

   // Optional attributes
   }
// Runtime type identification
int dielectric_crossover_area::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = stratum_concept_relationship::DynamicType(ID);
      }
   return result;
   }
dielectric_crossover_area *dielectric_crossover_area::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<dielectric_crossover_area *>(s);
      }
   return NULL;
   }
dielectric_crossover_area *dielectric_crossover_area::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<dielectric_crossover_area *>(s);
      }
   return NULL;
   }
// construction factory
dielectric_crossover_area *dielectric_crossover_area::Construct() {
   dielectric_crossover_area *result = NULL;

   // create the dielectric_crossover_area.
   result = new dielectric_crossover_area();
   return result;
   }
bool dielectric_crossover_area::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: dielectric_crossover_area\r\n");

   // Check for the existence of all required attributes
   if (_related_concept == NULL) {
      TRACE("ERROR: _related_concept a required attribute is NULL!\r\n");
      result = false;
      }
   if (_relating_concept == NULL) {
      TRACE("ERROR: _relating_concept a required attribute is NULL!\r\n");
      result = false;
      }
   if (_resulting_dielectric_crossover == NULL) {
      TRACE("ERROR: _resulting_dielectric_crossover a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (stratum_concept_relationship::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
