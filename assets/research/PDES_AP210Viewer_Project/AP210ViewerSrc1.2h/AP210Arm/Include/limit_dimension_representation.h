#ifndef LIMIT_DIMENSION_REPRESENTATION_H
#define LIMIT_DIMENSION_REPRESENTATION_H

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

class AP210ARM_API limit_dimension_representation:
public shape_dimension_representation
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 636};

   private:
      // Required attributes
      class data_element *_upper_dimension_value;
      class data_element *_lower_dimension_value;

      // Optional attributes

   protected:
      limit_dimension_representation();

   public:
      ~limit_dimension_representation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static limit_dimension_representation *InstanceOf(ARMObject *);
      static limit_dimension_representation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static limit_dimension_representation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
