#ifndef DATUM_TARGET_SET_H
#define DATUM_TARGET_SET_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <datum_feature.h>

// Unions

// Enumerations

class AP210ARM_API datum_target_set:
public datum_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 429};

   private:
      // Required attributes

      // Optional attributes

   protected:
      datum_target_set();

   public:
      ~datum_target_set();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static datum_target_set *InstanceOf(ARMObject *);
      static datum_target_set *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static datum_target_set *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
