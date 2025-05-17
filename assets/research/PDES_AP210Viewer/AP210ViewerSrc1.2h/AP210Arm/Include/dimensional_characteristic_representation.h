#ifndef DIMENSIONAL_CHARACTERISTIC_REPRESENTATION_H
#define DIMENSIONAL_CHARACTERISTIC_REPRESENTATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <dimensional_location_or_dimensional_size.h>

// Enumerations

class AP210ARM_API dimensional_characteristic_representation:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 507};

   private:
      // Required attributes
      class shape_dimension_representation *_representation;
      union dimensional_location_or_dimensional_size *_dimension;
      RoseBoolean _auxiliary_dimension_representation;

      // Optional attributes

   protected:
      dimensional_characteristic_representation();

   public:
      ~dimensional_characteristic_representation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static dimensional_characteristic_representation *InstanceOf(ARMObject *);
      static dimensional_characteristic_representation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static dimensional_characteristic_representation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
