#ifndef LISTOFDATE_AND_TIME_H
#define LISTOFDATE_AND_TIME_H

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

class AP210ARM_API ListOfdate_and_time:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 23};

   private:
      // Required attributes
      class date_and_time *_date_and_time;

      // Optional attributes

   protected:
      ListOfdate_and_time();

   public:
      ~ListOfdate_and_time();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ListOfdate_and_time *InstanceOf(ARMObject *);
      static ListOfdate_and_time *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ListOfdate_and_time *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
