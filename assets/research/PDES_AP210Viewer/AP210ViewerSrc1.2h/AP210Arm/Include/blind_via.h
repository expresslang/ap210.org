#ifndef BLIND_VIA_H
#define BLIND_VIA_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <via.h>

// Unions

// Enumerations

class AP210ARM_API blind_via:
public via
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 226};

   private:
      // Required attributes

      // Optional attributes

   protected:
      blind_via();

   public:
      ~blind_via();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static blind_via *InstanceOf(ARMObject *);
      static blind_via *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static blind_via *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
