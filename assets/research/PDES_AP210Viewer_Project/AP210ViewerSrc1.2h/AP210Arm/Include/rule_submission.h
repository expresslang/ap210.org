#ifndef RULE_SUBMISSION_H
#define RULE_SUBMISSION_H

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

class AP210ARM_API rule_submission:
public rule_action
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 770};

   private:
      // Required attributes
      STR _submission_rationale;

      // Optional attributes

   protected:
      rule_submission();

   public:
      ~rule_submission();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static rule_submission *InstanceOf(ARMObject *);
      static rule_submission *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static rule_submission *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
