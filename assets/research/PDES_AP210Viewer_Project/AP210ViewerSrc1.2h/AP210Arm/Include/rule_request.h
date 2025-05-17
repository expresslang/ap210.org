#ifndef RULE_REQUEST_H
#define RULE_REQUEST_H

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

class AP210ARM_API rule_request:
public rule_action
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 765};

   private:
      // Required attributes

      // Optional attributes

   protected:
      rule_request();

   public:
      ~rule_request();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static rule_request *InstanceOf(ARMObject *);
      static rule_request *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static rule_request *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
