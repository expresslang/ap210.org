#ifndef DIMENSIONAL_SIZE_H
#define DIMENSIONAL_SIZE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <dimensional_characteristic.h>

// Unions

// Enumerations

class AP210ARM_API dimensional_size:
public dimensional_characteristic
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 112};

   private:
      // Required attributes
      class shape_element *_size_of;
      RoseBoolean _envelope;

      // Optional attributes

   protected:
      dimensional_size();

   public:
      ~dimensional_size();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static dimensional_size *InstanceOf(ARMObject *);
      static dimensional_size *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static dimensional_size *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
