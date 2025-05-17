#ifndef DIMENSIONAL_CHARACTERISTIC_H
#define DIMENSIONAL_CHARACTERISTIC_H

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
#include <dimensional_types.h>

class AP210ARM_API dimensional_characteristic:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 101};

   private:
      // Required attributes
      dimensional_types::dimensional_types _dimension_type;

      // Optional attributes

   protected:
      dimensional_characteristic();

   public:
      ~dimensional_characteristic();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static dimensional_characteristic *InstanceOf(ARMObject *);
      static dimensional_characteristic *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static dimensional_characteristic *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
