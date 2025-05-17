// Source for AP210 application object
//     ee_product_definition

// Precompiled include files
#include <StdAfx.h>

#include "ee_product_definition.h"

// Classes
#include <security_classification.h>
#include <ee_text.h>
#include <ee_product_version.h>
#include <ee_approval.h>
#include <date_and_time.h>

ee_product_definition::ee_product_definition() {
   initialize();
   }
ee_product_definition::~ee_product_definition() {
   // Free string attributes
   if (_product_definition_id != NULL) {
      free(_product_definition_id);
     }
   if (_cad_filename != NULL) {
      free(_cad_filename);
     }
   if (_discipline_id != NULL) {
      free(_discipline_id);
     }
   }
// intialize data members
void ee_product_definition::initialize() {
   // Required attributes
   _product_definition_id = NULL;
   _security_code = NULL;
   _context_description = NULL;
   _version = NULL;
   _product_definition_approval = NULL;
   _creation_date = NULL;
   _discipline_id = NULL;

   // Optional attributes
   _cad_filename = NULL;
   }
// Runtime type identification
int ee_product_definition::DynamicType(int ID) {
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
ee_product_definition *ee_product_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_product_definition *>(s);
      }
   return NULL;
   }
ee_product_definition *ee_product_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_product_definition *>(s);
      }
   return NULL;
   }
// construction factory
ee_product_definition *ee_product_definition::Construct() {
   ee_product_definition *result = NULL;

   // create the ee_product_definition.
   result = new ee_product_definition();
   return result;
   }
bool ee_product_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_product_definition\r\n");

   // Check for the existence of all required attributes
   if (_creator == NULL) {
      TRACE("ERROR: _creator a required attribute is NULL!\r\n");
      result = false;
      }
   if (_product_definition_id == NULL) {
      TRACE("ERROR: _product_definition_id a required attribute is NULL!\r\n");
      result = false;
      }
   if (_security_code == NULL) {
      TRACE("ERROR: _security_code a required attribute is NULL!\r\n");
      result = false;
      }
   if (_context_description == NULL) {
      TRACE("ERROR: _context_description a required attribute is NULL!\r\n");
      result = false;
      }
   if (_version == NULL) {
      TRACE("ERROR: _version a required attribute is NULL!\r\n");
      result = false;
      }
   if (_product_definition_approval == NULL) {
      TRACE("ERROR: _product_definition_approval a required attribute is NULL!\r\n");
      result = false;
      }
   if (_creation_date == NULL) {
      TRACE("ERROR: _creation_date a required attribute is NULL!\r\n");
      result = false;
      }
   if (_discipline_id == NULL) {
      TRACE("ERROR: _discipline_id a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
