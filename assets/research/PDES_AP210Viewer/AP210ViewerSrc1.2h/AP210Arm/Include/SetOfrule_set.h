#ifndef SETOFRULE_SET_H
#define SETOFRULE_SET_H

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

class AP210ARM_API SetOfrule_set:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 769};

   private:
      // Required attributes
      class rule_set *_rule_set;

      // Optional attributes

   protected:
      SetOfrule_set();

   public:
      ~SetOfrule_set();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfrule_set *InstanceOf(ARMObject *);
      static SetOfrule_set *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfrule_set *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
