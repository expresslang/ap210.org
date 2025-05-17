#ifndef SYMMETRICAL_TOLERANCE_CHARACTERISTIC_H
#define SYMMETRICAL_TOLERANCE_CHARACTERISTIC_H

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

class AP210ARM_API symmetrical_tolerance_characteristic:
public tolerance_characteristic
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 820};

   private:
      // Required attributes

      // Optional attributes

   protected:
      symmetrical_tolerance_characteristic();

   public:
      ~symmetrical_tolerance_characteristic();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static symmetrical_tolerance_characteristic *InstanceOf(ARMObject *);
      static symmetrical_tolerance_characteristic *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static symmetrical_tolerance_characteristic *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
