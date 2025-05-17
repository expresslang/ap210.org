#ifndef DATUM_DIFFERENCE_BASED_CHARACTERISTIC_H
#define DATUM_DIFFERENCE_BASED_CHARACTERISTIC_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <characteristic.h>

// Unions

// Enumerations

class AP210ARM_API datum_difference_based_characteristic:
public characteristic
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 416};

   private:
      // Required attributes
      class datum_difference *_of_datum_difference;

      // Optional attributes

   protected:
      datum_difference_based_characteristic();

   public:
      ~datum_difference_based_characteristic();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum_difference_based_characteristic *InstanceOf(ARMObject *);
      static datum_difference_based_characteristic *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum_difference_based_characteristic *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
