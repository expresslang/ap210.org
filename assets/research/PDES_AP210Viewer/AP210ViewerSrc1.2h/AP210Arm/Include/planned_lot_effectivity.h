#ifndef PLANNED_LOT_EFFECTIVITY_H
#define PLANNED_LOT_EFFECTIVITY_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <planned_effectivity.h>

// Unions

// Enumerations

class AP210ARM_API planned_lot_effectivity:
public planned_effectivity
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 707};

   private:
      // Required attributes
      STR _lot_number;
      class data_element *_lot_size;

      // Optional attributes

   protected:
      planned_lot_effectivity();

   public:
      ~planned_lot_effectivity();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static planned_lot_effectivity *InstanceOf(ARMObject *);
      static planned_lot_effectivity *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static planned_lot_effectivity *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
