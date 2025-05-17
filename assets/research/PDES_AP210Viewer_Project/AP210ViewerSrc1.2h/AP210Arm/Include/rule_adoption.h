#ifndef RULE_ADOPTION_H
#define RULE_ADOPTION_H

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

class AP210ARM_API rule_adoption:
public rule_action
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 757};

   private:
      // Required attributes

      // Optional attributes

   protected:
      rule_adoption();

   public:
      ~rule_adoption();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static rule_adoption *InstanceOf(ARMObject *);
      static rule_adoption *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static rule_adoption *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
