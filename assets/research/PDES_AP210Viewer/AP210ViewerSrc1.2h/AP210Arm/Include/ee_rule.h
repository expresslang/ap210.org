#ifndef EE_RULE_H
#define EE_RULE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <library_item.h>

// Unions

// Enumerations

class AP210ARM_API ee_rule:
public library_item
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 398};

   private:
      // Required attributes
      STR _rule_description;

      // Optional attributes

   protected:
      ee_rule();

   public:
      ~ee_rule();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_rule *InstanceOf(ARMObject *);
      static ee_rule *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_rule *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
