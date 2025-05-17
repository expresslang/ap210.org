#ifndef EE_RULE_COMPLEX_CLAUSE_H
#define EE_RULE_COMPLEX_CLAUSE_H

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

class AP210ARM_API ee_rule_complex_clause:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 518};

   private:
      // Required attributes
      class ee_rule_simple_clause *_conjunctive_content[2000];
      STR _identifier;

      // Optional attributes

   protected:
      ee_rule_complex_clause();

   public:
      ~ee_rule_complex_clause();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_rule_complex_clause *InstanceOf(ARMObject *);
      static ee_rule_complex_clause *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_rule_complex_clause *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
