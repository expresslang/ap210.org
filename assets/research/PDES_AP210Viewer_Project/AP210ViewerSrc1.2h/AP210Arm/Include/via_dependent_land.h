#ifndef VIA_DEPENDENT_LAND_H
#define VIA_DEPENDENT_LAND_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <land.h>

// Unions

// Enumerations

class AP210ARM_API via_dependent_land:
public land
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 858};

   private:
      // Required attributes
      class via *_reference_via;

      // Optional attributes

   protected:
      via_dependent_land();

   public:
      ~via_dependent_land();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static via_dependent_land *InstanceOf(ARMObject *);
      static via_dependent_land *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static via_dependent_land *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
