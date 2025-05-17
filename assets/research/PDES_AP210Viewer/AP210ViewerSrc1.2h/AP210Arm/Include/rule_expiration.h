#ifndef RULE_EXPIRATION_H
#define RULE_EXPIRATION_H

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

class AP210ARM_API rule_expiration:
public rule_action
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 760};

   private:
      // Required attributes
      STR _expiration_rationale;

      // Optional attributes

   protected:
      rule_expiration();

   public:
      ~rule_expiration();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static rule_expiration *InstanceOf(ARMObject *);
      static rule_expiration *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static rule_expiration *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
