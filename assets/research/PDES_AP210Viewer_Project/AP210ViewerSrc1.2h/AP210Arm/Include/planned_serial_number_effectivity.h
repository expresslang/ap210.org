#ifndef PLANNED_SERIAL_NUMBER_EFFECTIVITY_H
#define PLANNED_SERIAL_NUMBER_EFFECTIVITY_H

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

class AP210ARM_API planned_serial_number_effectivity:
public planned_effectivity
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 708};

   private:
      // Required attributes
      STR _from_effectivity_id;

      // Optional attributes
      STR _through_effectivity_id;

   protected:
      planned_serial_number_effectivity();

   public:
      ~planned_serial_number_effectivity();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static planned_serial_number_effectivity *InstanceOf(ARMObject *);
      static planned_serial_number_effectivity *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static planned_serial_number_effectivity *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
