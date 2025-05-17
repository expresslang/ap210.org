#ifndef THEORETICALLY_EXACT_DIMENSION_REPRESENTATION_H
#define THEORETICALLY_EXACT_DIMENSION_REPRESENTATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <singular_dimension_representation.h>

// Unions

// Enumerations

class AP210ARM_API theoretically_exact_dimension_representation:
public singular_dimension_representation
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 828};

   private:
      // Required attributes

      // Optional attributes

   protected:
      theoretically_exact_dimension_representation();

   public:
      ~theoretically_exact_dimension_representation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static theoretically_exact_dimension_representation *InstanceOf(ARMObject *);
      static theoretically_exact_dimension_representation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static theoretically_exact_dimension_representation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
