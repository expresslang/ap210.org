#ifndef COMMON_DATUM_H
#define COMMON_DATUM_H

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

class AP210ARM_API common_datum:
public datum
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 291};

   private:
      // Required attributes

      // Optional attributes

   protected:
      common_datum();

   public:
      ~common_datum();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static common_datum *InstanceOf(ARMObject *);
      static common_datum *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static common_datum *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
