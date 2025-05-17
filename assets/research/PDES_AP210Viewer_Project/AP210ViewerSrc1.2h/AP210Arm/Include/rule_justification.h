#ifndef RULE_JUSTIFICATION_H
#define RULE_JUSTIFICATION_H

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

class AP210ARM_API rule_justification:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 761};

   private:
      // Required attributes
      class rule_action *_justified_action;
      STR _justification_rationale;

      // Optional attributes

   protected:
      rule_justification();

   public:
      ~rule_justification();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static rule_justification *InstanceOf(ARMObject *);
      static rule_justification *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static rule_justification *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
