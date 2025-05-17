#ifndef SINGLE_BOUNDARY_DIMENSION_H
#define SINGLE_BOUNDARY_DIMENSION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <dimensional_size.h>

// Unions

// Enumerations

class AP210ARM_API single_boundary_dimension:
public dimensional_size
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 405};

   private:
      // Required attributes

      // Optional attributes

   protected:
      single_boundary_dimension();

   public:
      ~single_boundary_dimension();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static single_boundary_dimension *InstanceOf(ARMObject *);
      static single_boundary_dimension *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static single_boundary_dimension *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
