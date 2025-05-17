// Source for AP210 application object
//     dimensional_size

// Precompiled include files
#include <StdAfx.h>

#include "dimensional_size.h"

// Classes
#include <shape_element.h>

dimensional_size::dimensional_size() {
   initialize();
   }
dimensional_size::~dimensional_size() {
   // Free string attributes
   }
// intialize data members
void dimensional_size::initialize() {
   // Required attributes
   _size_of = NULL;

   // Optional attributes
   }
// Runtime type identification
int dimensional_size::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = dimensional_characteristic::DynamicType(ID);
      }
   return result;
   }
dimensional_size *dimensional_size::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<dimensional_size *>(s);
      }
   return NULL;
   }
dimensional_size *dimensional_size::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<dimensional_size *>(s);
      }
   return NULL;
   }
// construction factory
dimensional_size *dimensional_size::Construct() {
   dimensional_size *result = NULL;

   // create the dimensional_size.
   result = new dimensional_size();
   return result;
   }
bool dimensional_size::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: dimensional_size\r\n");

   // Check for the existence of all required attributes
   if (_size_of == NULL) {
      TRACE("ERROR: _size_of a required attribute is NULL!\r\n");
      result = false;
      }
   if (_envelope == NULL) {
      TRACE("ERROR: _envelope a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (dimensional_characteristic::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
