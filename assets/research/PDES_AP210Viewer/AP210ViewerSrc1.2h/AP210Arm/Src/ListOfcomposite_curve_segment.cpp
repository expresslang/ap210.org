// Source for AP210 application object
//     ListOfcomposite_curve_segment

// Precompiled include files
#include <StdAfx.h>

#include "ListOfcomposite_curve_segment.h"

// Classes
#include <composite_curve_segment.h>

ListOfcomposite_curve_segment::ListOfcomposite_curve_segment() {
   initialize();
   }
ListOfcomposite_curve_segment::~ListOfcomposite_curve_segment() {
   // Free string attributes
   }
// intialize data members
void ListOfcomposite_curve_segment::initialize() {
   // Required attributes
   _composite_curve_segment = NULL;

   // Optional attributes
   }
// Runtime type identification
int ListOfcomposite_curve_segment::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
ListOfcomposite_curve_segment *ListOfcomposite_curve_segment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ListOfcomposite_curve_segment *>(s);
      }
   return NULL;
   }
ListOfcomposite_curve_segment *ListOfcomposite_curve_segment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ListOfcomposite_curve_segment *>(s);
      }
   return NULL;
   }
// construction factory
ListOfcomposite_curve_segment *ListOfcomposite_curve_segment::Construct() {
   ListOfcomposite_curve_segment *result = NULL;

   // create the ListOfcomposite_curve_segment.
   result = new ListOfcomposite_curve_segment();
   return result;
   }
bool ListOfcomposite_curve_segment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ListOfcomposite_curve_segment\r\n");

   // Check for the existence of all required attributes
   if (_composite_curve_segment == NULL) {
      TRACE("ERROR: _composite_curve_segment a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
