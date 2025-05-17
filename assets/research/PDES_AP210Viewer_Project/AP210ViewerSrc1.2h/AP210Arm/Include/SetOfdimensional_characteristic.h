#ifndef SETOFDIMENSIONAL_CHARACTERISTIC_H
#define SETOFDIMENSIONAL_CHARACTERISTIC_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions

// Enumerations

class AP210ARM_API SetOfdimensional_characteristic:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 501};

   private:
      // Required attributes
      class dimensional_characteristic *_dimensional_characteristic;

      // Optional attributes

   protected:
      SetOfdimensional_characteristic();

   public:
      ~SetOfdimensional_characteristic();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfdimensional_characteristic *InstanceOf(ARMObject *);
      static SetOfdimensional_characteristic *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfdimensional_characteristic *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
