#ifndef SHAPE_DIMENSION_REPRESENTATION_H
#define SHAPE_DIMENSION_REPRESENTATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions

// Enumerations

class AP210ARM_API shape_dimension_representation:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 225};

   private:
      // Required attributes

      // Optional attributes

   protected:
      shape_dimension_representation();

   public:
      ~shape_dimension_representation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static shape_dimension_representation *InstanceOf(ARMObject *);
      static shape_dimension_representation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static shape_dimension_representation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
