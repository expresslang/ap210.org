#ifndef EE_RULE_PREMISE_DEFINITION_H
#define EE_RULE_PREMISE_DEFINITION_H

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

class AP210ARM_API ee_rule_premise_definition:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 524};

   private:
      // Required attributes
      class ee_rule_definition *_rule_definition;
      STR _identifier;
      class ee_rule_complex_clause *_disjunctive_content[2000];

      // Optional attributes

   protected:
      ee_rule_premise_definition();

   public:
      ~ee_rule_premise_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static ee_rule_premise_definition *InstanceOf(ARMObject *);
      static ee_rule_premise_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static ee_rule_premise_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
