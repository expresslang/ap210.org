#ifndef PLUS_MINUS_TOLERANCE_RANGE_REPRESENTATION_H
#define PLUS_MINUS_TOLERANCE_RANGE_REPRESENTATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <shape_dimension_representation.h>

// Unions

// Enumerations

class AP210ARM_API plus_minus_tolerance_range_representation:
public shape_dimension_representation
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 715};

   private:
      // Required attributes
      class data_element *_basic_dimension_value;
      class data_element *_upper_deviation;
      class data_element *_lower_deviation;

      // Optional attributes

   protected:
      plus_minus_tolerance_range_representation();

   public:
      ~plus_minus_tolerance_range_representation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static plus_minus_tolerance_range_representation *InstanceOf(ARMObject *);
      static plus_minus_tolerance_range_representation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static plus_minus_tolerance_range_representation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
