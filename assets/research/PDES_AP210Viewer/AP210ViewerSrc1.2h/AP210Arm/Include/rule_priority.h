#ifndef RULE_PRIORITY_H
#define RULE_PRIORITY_H

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

class AP210ARM_API rule_priority:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 763};

   private:
      // Required attributes
      RoseInteger _priority;
      class ee_rule_version *_prioritized_rule;

      // Optional attributes

   protected:
      rule_priority();

   public:
      ~rule_priority();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static rule_priority *InstanceOf(ARMObject *);
      static rule_priority *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static rule_priority *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
