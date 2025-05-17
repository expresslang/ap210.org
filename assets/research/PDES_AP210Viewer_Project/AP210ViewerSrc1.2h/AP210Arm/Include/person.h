#ifndef PERSON_H
#define PERSON_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions

// Enumerations

class AP210ARM_API person:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 7};

   private:
      // Required attributes
      STR _identifier;

      // Optional attributes
      STR _Address;

   protected:
      person();

   public:
      ~person();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static person *InstanceOf(ARMObject *);
      static person *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static person *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
