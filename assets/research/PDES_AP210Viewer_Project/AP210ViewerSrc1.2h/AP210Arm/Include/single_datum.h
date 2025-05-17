#ifndef SINGLE_DATUM_H
#define SINGLE_DATUM_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <datum.h>

// Unions

// Enumerations

class AP210ARM_API single_datum:
public datum
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 409};

   private:
      // Required attributes

      // Optional attributes

   protected:
      single_datum();

   public:
      ~single_datum();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static single_datum *InstanceOf(ARMObject *);
      static single_datum *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static single_datum *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
