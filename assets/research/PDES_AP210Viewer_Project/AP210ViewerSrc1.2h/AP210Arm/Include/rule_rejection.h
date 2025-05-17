#ifndef RULE_REJECTION_H
#define RULE_REJECTION_H

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

class AP210ARM_API rule_rejection:
public rule_action
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 764};

   private:
      // Required attributes
      STR _rejection_reason;

      // Optional attributes

   protected:
      rule_rejection();

   public:
      ~rule_rejection();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static rule_rejection *InstanceOf(ARMObject *);
      static rule_rejection *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static rule_rejection *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
