#ifndef RULE_CREATION_H
#define RULE_CREATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <rule_action.h>

// Unions

// Enumerations

class AP210ARM_API rule_creation:
public rule_action
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 759};

   private:
      // Required attributes

      // Optional attributes

   protected:
      rule_creation();

   public:
      ~rule_creation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static rule_creation *InstanceOf(ARMObject *);
      static rule_creation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static rule_creation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
