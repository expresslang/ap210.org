#ifndef RULE_SET_GROUP_H
#define RULE_SET_GROUP_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <rule_set.h>

// Unions

// Enumerations

class AP210ARM_API rule_set_group:
public rule_set
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 768};

   private:
      // Required attributes
      class rule_set *_elements[2000];

      // Optional attributes

   protected:
      rule_set_group();

   public:
      ~rule_set_group();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static rule_set_group *InstanceOf(ARMObject *);
      static rule_set_group *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static rule_set_group *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
