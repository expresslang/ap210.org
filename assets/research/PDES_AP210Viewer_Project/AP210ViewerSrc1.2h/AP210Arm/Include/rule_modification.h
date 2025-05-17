#ifndef RULE_MODIFICATION_H
#define RULE_MODIFICATION_H

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

class AP210ARM_API rule_modification:
public rule_action
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 762};

   private:
      // Required attributes
      class rule_change_request *_modification_rationale;

      // Optional attributes

   protected:
      rule_modification();

   public:
      ~rule_modification();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static rule_modification *InstanceOf(ARMObject *);
      static rule_modification *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static rule_modification *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
