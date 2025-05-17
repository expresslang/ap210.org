#ifndef PLANNED_DATE_EFFECTIVITY_H
#define PLANNED_DATE_EFFECTIVITY_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <planned_effectivity.h>

// Unions
#include <date_or_date_and_time.h>
#include <date_or_date_and_time.h>

// Enumerations

class AP210ARM_API planned_date_effectivity:
public planned_effectivity
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 705};

   private:
      // Required attributes
      union date_or_date_and_time *_start_date;

      // Optional attributes
      union date_or_date_and_time *_end_date;

   protected:
      planned_date_effectivity();

   public:
      ~planned_date_effectivity();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static planned_date_effectivity *InstanceOf(ARMObject *);
      static planned_date_effectivity *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static planned_date_effectivity *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
