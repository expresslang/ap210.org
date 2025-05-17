// Source for AP210 application object
//     viewing_plane_definition

// Precompiled include files
#include <StdAfx.h>

#include "viewing_plane_definition.h"

// Classes
#include <viewing_plane.h>
#include <axis_placement.h>

viewing_plane_definition::viewing_plane_definition() {
   initialize();
   }
viewing_plane_definition::~viewing_plane_definition() {
   // Free string attributes
   }
// intialize data members
void viewing_plane_definition::initialize() {
   // Required attributes
   _defined_viewing_plane = NULL;
   _viewing_plane_representation = NULL;

   // Optional attributes
   }
// Runtime type identification
int viewing_plane_definition::DynamicType(int ID) {
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
viewing_plane_definition *viewing_plane_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<viewing_plane_definition *>(s);
      }
   return NULL;
   }
viewing_plane_definition *viewing_plane_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<viewing_plane_definition *>(s);
      }
   return NULL;
   }
// construction factory
viewing_plane_definition *viewing_plane_definition::Construct() {
   viewing_plane_definition *result = NULL;

   // create the viewing_plane_definition.
   result = new viewing_plane_definition();
   return result;
   }
bool viewing_plane_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: viewing_plane_definition\r\n");

   // Check for the existence of all required attributes
   if (_defined_viewing_plane == NULL) {
      TRACE("ERROR: _defined_viewing_plane a required attribute is NULL!\r\n");
      result = false;
      }
   if (_viewing_plane_representation == NULL) {
      TRACE("ERROR: _viewing_plane_representation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
