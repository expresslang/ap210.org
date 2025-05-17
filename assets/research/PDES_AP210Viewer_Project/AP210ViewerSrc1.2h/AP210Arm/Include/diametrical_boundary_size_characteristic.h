#ifndef DIAMETRICAL_BOUNDARY_SIZE_CHARACTERISTIC_H
#define DIAMETRICAL_BOUNDARY_SIZE_CHARACTERISTIC_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <boundary_size_characteristic.h>

// Unions

// Enumerations

class AP210ARM_API diametrical_boundary_size_characteristic:
public boundary_size_characteristic
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 492};

   private:
      // Required attributes
      class tolerance_zone_circular_or_cylindrical_or_spherical_boundary *_sized_boundary;

      // Optional attributes

   protected:
      diametrical_boundary_size_characteristic();

   public:
      ~diametrical_boundary_size_characteristic();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static diametrical_boundary_size_characteristic *InstanceOf(ARMObject *);
      static diametrical_boundary_size_characteristic *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static diametrical_boundary_size_characteristic *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
