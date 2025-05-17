#ifndef BARE_DIE_H
#define BARE_DIE_H

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

class AP210ARM_API bare_die:
public physical_unit_usage_view
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 216};

   private:
      // Required attributes
      class seating_plane *_die_seating_plane;
      class functional_unit_usage_view *_implemented_function;

      // Optional attributes
      class cartesian_point *_least_material_condition_centroid_location;
      class length_data_element *_maximum_height_above_seating_plane;
      class cartesian_point *_maximum_material_condition_centroid_location;

   protected:
      bare_die();

   public:
      ~bare_die();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static bare_die *InstanceOf(ARMObject *);
      static bare_die *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static bare_die *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
