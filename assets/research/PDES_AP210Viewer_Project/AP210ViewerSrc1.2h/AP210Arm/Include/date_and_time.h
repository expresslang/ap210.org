#ifndef DATE_AND_TIME_H
#define DATE_AND_TIME_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <date.h>

// Unions

// Enumerations

class AP210ARM_API date_and_time:
public date
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 12};

   private:
      // Required attributes
      RoseInteger _hour;
      RoseInteger _minute;
      RoseInteger _second;
      RoseInteger _time_zone;

      // Optional attributes

   protected:
      date_and_time();

   public:
      ~date_and_time();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static date_and_time *InstanceOf(ARMObject *);
      static date_and_time *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static date_and_time *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
