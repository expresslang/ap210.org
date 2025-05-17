#ifndef DIMENSION_LOCATION_WITH_DIRECTION_VECTOR_H
#define DIMENSION_LOCATION_WITH_DIRECTION_VECTOR_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <dimensional_location.h>

// Unions
#include <axis_placement_or_datum_based_vector_orientation_select.h>

// Enumerations

class AP210ARM_API dimension_location_with_direction_vector:
public dimensional_location
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 498};

   private:
      // Required attributes
      union axis_placement_or_datum_based_vector_orientation_select *_measurement_direction;

      // Optional attributes

   protected:
      dimension_location_with_direction_vector();

   public:
      ~dimension_location_with_direction_vector();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static dimension_location_with_direction_vector *InstanceOf(ARMObject *);
      static dimension_location_with_direction_vector *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static dimension_location_with_direction_vector *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
