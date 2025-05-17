#ifndef MINIMUM_DIMENSION_REPRESENTATION_H
#define MINIMUM_DIMENSION_REPRESENTATION_H

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

class AP210ARM_API minimum_dimension_representation:
public singular_dimension_representation
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 658};

   private:
      // Required attributes

      // Optional attributes

   protected:
      minimum_dimension_representation();

   public:
      ~minimum_dimension_representation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static minimum_dimension_representation *InstanceOf(ARMObject *);
      static minimum_dimension_representation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static minimum_dimension_representation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
