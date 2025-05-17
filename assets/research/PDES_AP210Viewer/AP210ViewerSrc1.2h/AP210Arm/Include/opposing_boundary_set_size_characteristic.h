#ifndef OPPOSING_BOUNDARY_SET_SIZE_CHARACTERISTIC_H
#define OPPOSING_BOUNDARY_SET_SIZE_CHARACTERISTIC_H

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

class AP210ARM_API opposing_boundary_set_size_characteristic:
public boundary_size_characteristic
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 663};

   private:
      // Required attributes
      class tolerance_zone_opposing_boundary_set *_sized_boundary_set;

      // Optional attributes

   protected:
      opposing_boundary_set_size_characteristic();

   public:
      ~opposing_boundary_set_size_characteristic();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static opposing_boundary_set_size_characteristic *InstanceOf(ARMObject *);
      static opposing_boundary_set_size_characteristic *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static opposing_boundary_set_size_characteristic *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
