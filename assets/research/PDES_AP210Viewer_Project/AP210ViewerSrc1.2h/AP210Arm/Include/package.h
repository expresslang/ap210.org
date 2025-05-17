#ifndef PACKAGE_H
#define PACKAGE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <physical_unit_usage_view.h>

// Unions

// Enumerations

class AP210ARM_API package:
public physical_unit_usage_view
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 61};

   private:
      // Required attributes
      class registered_style *_case_style[2000];
      class seating_plane *_package_seating_plane;
      class length_data_element *_maximum_body_height_above_seating_plane;

      // Optional attributes
      class cartesian_point *_least_material_condition_centroid_location;
      class cartesian_point *_maximum_material_condition_centroid_location;
      class length_data_element *_maximum_body_height_below_seating_plane;
      class length_data_element *_maximum_body_clearance_above_seating_plane;
      class length_data_element *_maximum_body_clearance_below_seating_plane;
      class length_data_element *_minimum_body_clearance_above_seating_plane;
      class length_data_element *_minimum_body_clearance_below_seating_plane;
      class length_data_element *_maximum_lead_length_below_seating_plane;
      class length_data_element *_least_lead_length_below_seating_plane;

   protected:
      package();

   public:
      ~package();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static package *InstanceOf(ARMObject *);
      static package *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static package *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
