#ifndef BURIED_VIA_H
#define BURIED_VIA_H

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

class AP210ARM_API buried_via:
public via
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 254};

   private:
      // Required attributes

      // Optional attributes

   protected:
      buried_via();

   public:
      ~buried_via();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static buried_via *InstanceOf(ARMObject *);
      static buried_via *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static buried_via *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
