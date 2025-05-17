#ifndef SETOFEE_RULE_COMPLEX_CLAUSE_H
#define SETOFEE_RULE_COMPLEX_CLAUSE_H

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

class AP210ARM_API SetOfee_rule_complex_clause:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 525};

   private:
      // Required attributes
      class ee_rule_complex_clause *_ee_rule_complex_clause;

      // Optional attributes

   protected:
      SetOfee_rule_complex_clause();

   public:
      ~SetOfee_rule_complex_clause();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfee_rule_complex_clause *InstanceOf(ARMObject *);
      static SetOfee_rule_complex_clause *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfee_rule_complex_clause *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
