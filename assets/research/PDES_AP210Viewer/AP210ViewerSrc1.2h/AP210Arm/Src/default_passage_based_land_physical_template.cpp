// Source for AP210 application object
//     default_passage_based_land_physical_template

// Precompiled include files
#include <StdAfx.h>

#include "default_passage_based_land_physical_template.h"

// Classes
#include <length_data_element.h>
#include <passage_technology.h>
#include <length_data_element.h>

default_passage_based_land_physical_template::default_passage_based_land_physical_template() {
   initialize();
   }
default_passage_based_land_physical_template::~default_passage_based_land_physical_template() {
   // Free string attributes
   }
// intialize data members
void default_passage_based_land_physical_template::initialize() {
   // Required attributes
   _minimum_fabrication_allowance = NULL;
   _of_passage_technology = NULL;
   _minimum_annular_ring = NULL;

   // Optional attributes
   }
// Runtime type identification
int default_passage_based_land_physical_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = default_land_physical_template::DynamicType(ID);
      }
   return result;
   }
default_passage_based_land_physical_template *default_passage_based_land_physical_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<default_passage_based_land_physical_template *>(s);
      }
   return NULL;
   }
default_passage_based_land_physical_template *default_passage_based_land_physical_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<default_passage_based_land_physical_template *>(s);
      }
   return NULL;
   }
// construction factory
default_passage_based_land_physical_template *default_passage_based_land_physical_template::Construct() {
   default_passage_based_land_physical_template *result = NULL;

   // create the default_passage_based_land_physical_template.
   result = new default_passage_based_land_physical_template();
   return result;
   }
bool default_passage_based_land_physical_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: default_passage_based_land_physical_template\r\n");

   // Check for the existence of all required attributes
   if (_minimum_fabrication_allowance == NULL) {
      TRACE("ERROR: _minimum_fabrication_allowance a required attribute is NULL!\r\n");
      result = false;
      }
   if (_of_passage_technology == NULL) {
      TRACE("ERROR: _of_passage_technology a required attribute is NULL!\r\n");
      result = false;
      }
   if (_minimum_annular_ring == NULL) {
      TRACE("ERROR: _minimum_annular_ring a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (default_land_physical_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
