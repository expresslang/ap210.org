// Source for AP210 application object
//     dimensional_size_based_on_opposing_boundaries

// Precompiled include files
#include <StdAfx.h>

#include "dimensional_size_based_on_opposing_boundaries.h"

// Classes
#include <shape_element_locating_relationship.h>

dimensional_size_based_on_opposing_boundaries::dimensional_size_based_on_opposing_boundaries() {
   initialize();
   }
dimensional_size_based_on_opposing_boundaries::~dimensional_size_based_on_opposing_boundaries() {
   // Free string attributes
   }
// intialize data members
void dimensional_size_based_on_opposing_boundaries::initialize() {
   // Required attributes
   _boundary_separation = NULL;

   // Optional attributes
   }
// Runtime type identification
int dimensional_size_based_on_opposing_boundaries::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = dimensional_size::DynamicType(ID);
      }
   return result;
   }
dimensional_size_based_on_opposing_boundaries *dimensional_size_based_on_opposing_boundaries::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<dimensional_size_based_on_opposing_boundaries *>(s);
      }
   return NULL;
   }
dimensional_size_based_on_opposing_boundaries *dimensional_size_based_on_opposing_boundaries::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<dimensional_size_based_on_opposing_boundaries *>(s);
      }
   return NULL;
   }
// construction factory
dimensional_size_based_on_opposing_boundaries *dimensional_size_based_on_opposing_boundaries::Construct() {
   dimensional_size_based_on_opposing_boundaries *result = NULL;

   // create the dimensional_size_based_on_opposing_boundaries.
   result = new dimensional_size_based_on_opposing_boundaries();
   return result;
   }
bool dimensional_size_based_on_opposing_boundaries::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: dimensional_size_based_on_opposing_boundaries\r\n");

   // Check for the existence of all required attributes
   if (_boundary_separation == NULL) {
      TRACE("ERROR: _boundary_separation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (dimensional_size::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
