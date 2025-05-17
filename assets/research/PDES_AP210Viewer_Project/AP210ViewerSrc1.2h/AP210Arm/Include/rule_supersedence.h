#ifndef RULE_SUPERSEDENCE_H
#define RULE_SUPERSEDENCE_H

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

class AP210ARM_API rule_supersedence:
public rule_action
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 771};

   private:
      // Required attributes
      class ee_rule_version *_superseded_rule;

      // Optional attributes

   protected:
      rule_supersedence();

   public:
      ~rule_supersedence();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static rule_supersedence *InstanceOf(ARMObject *);
      static rule_supersedence *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static rule_supersedence *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
