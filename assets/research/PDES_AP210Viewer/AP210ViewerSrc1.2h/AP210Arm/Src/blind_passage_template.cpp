// Source for AP210 application object
//     blind_passage_template

// Precompiled include files
#include <StdAfx.h>

#include "blind_passage_template.h"

// Classes
#include <stratum_surface.h>
#include <shape_dimension_representation.h>

blind_passage_template::blind_passage_template() {
   initialize();
   }
blind_passage_template::~blind_passage_template() {
   // Free string attributes
   }
// intialize data members
void blind_passage_template::initialize() {
   // Required attributes
   _datum_reference = NULL;
   _bottom_distance_from_datum_reference = NULL;

   // Optional attributes
   }
// Runtime type identification
int blind_passage_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = unsupported_passage_template::DynamicType(ID);
      }
   return result;
   }
blind_passage_template *blind_passage_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<blind_passage_template *>(s);
      }
   return NULL;
   }
blind_passage_template *blind_passage_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<blind_passage_template *>(s);
      }
   return NULL;
   }
// construction factory
blind_passage_template *blind_passage_template::Construct() {
   blind_passage_template *result = NULL;

   // create the blind_passage_template.
   result = new blind_passage_template();
   return result;
   }
bool blind_passage_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: blind_passage_template\r\n");

   // Check for the existence of all required attributes
   if (_of_measure_orientation == NULL) {
      TRACE("ERROR: _of_measure_orientation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_datum_reference == NULL) {
      TRACE("ERROR: _datum_reference a required attribute is NULL!\r\n");
      result = false;
      }
   if (_bottom_distance_from_datum_reference == NULL) {
      TRACE("ERROR: _bottom_distance_from_datum_reference a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (unsupported_passage_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
