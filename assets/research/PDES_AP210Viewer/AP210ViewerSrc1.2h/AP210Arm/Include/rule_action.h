#ifndef RULE_ACTION_H
#define RULE_ACTION_H

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

class AP210ARM_API rule_action:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 756};

   private:
      // Required attributes
      class participant_date_and_time_assignment *_subject_action_assignment;
      class ee_rule_version *_subject_rule;

      // Optional attributes

   protected:
      rule_action();

   public:
      ~rule_action();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static rule_action *InstanceOf(ARMObject *);
      static rule_action *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static rule_action *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
