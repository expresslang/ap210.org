#ifndef RULE_SET_H
#define RULE_SET_H

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

class AP210ARM_API rule_set:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 766};

   private:
      // Required attributes
      class rule_priority *_rule_priority_member[2000];
      STR _identifier;
      STR _purpose;

      // Optional attributes

   protected:
      rule_set();

   public:
      ~rule_set();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static rule_set *InstanceOf(ARMObject *);
      static rule_set *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static rule_set *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
