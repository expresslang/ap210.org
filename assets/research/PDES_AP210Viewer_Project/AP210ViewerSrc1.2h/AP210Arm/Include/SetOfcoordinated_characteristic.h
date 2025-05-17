#ifndef SETOFCOORDINATED_CHARACTERISTIC_H
#define SETOFCOORDINATED_CHARACTERISTIC_H

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

class AP210ARM_API SetOfcoordinated_characteristic:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 31};

   private:
      // Required attributes
      class coordinated_characteristic *_coordinated_characteristic;

      // Optional attributes

   protected:
      SetOfcoordinated_characteristic();

   public:
      ~SetOfcoordinated_characteristic();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfcoordinated_characteristic *InstanceOf(ARMObject *);
      static SetOfcoordinated_characteristic *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfcoordinated_characteristic *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
