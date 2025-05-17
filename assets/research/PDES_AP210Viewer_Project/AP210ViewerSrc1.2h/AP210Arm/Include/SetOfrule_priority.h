#ifndef SETOFRULE_PRIORITY_H
#define SETOFRULE_PRIORITY_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions

// Enumerations

class AP210ARM_API SetOfrule_priority:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 767};

   private:
      // Required attributes
      class rule_priority *_rule_priority;

      // Optional attributes

   protected:
      SetOfrule_priority();

   public:
      ~SetOfrule_priority();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfrule_priority *InstanceOf(ARMObject *);
      static SetOfrule_priority *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfrule_priority *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
