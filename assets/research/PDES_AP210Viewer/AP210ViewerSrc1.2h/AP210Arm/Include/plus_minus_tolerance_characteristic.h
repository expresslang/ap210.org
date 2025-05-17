#ifndef PLUS_MINUS_TOLERANCE_CHARACTERISTIC_H
#define PLUS_MINUS_TOLERANCE_CHARACTERISTIC_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <tolerance_characteristic.h>

// Unions

// Enumerations

class AP210ARM_API plus_minus_tolerance_characteristic:
public tolerance_characteristic
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 714};

   private:
      // Required attributes

      // Optional attributes

   protected:
      plus_minus_tolerance_characteristic();

   public:
      ~plus_minus_tolerance_characteristic();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static plus_minus_tolerance_characteristic *InstanceOf(ARMObject *);
      static plus_minus_tolerance_characteristic *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static plus_minus_tolerance_characteristic *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
