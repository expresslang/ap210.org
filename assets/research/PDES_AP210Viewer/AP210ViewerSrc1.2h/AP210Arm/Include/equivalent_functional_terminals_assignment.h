#ifndef EQUIVALENT_FUNCTIONAL_TERMINALS_ASSIGNMENT_H
#define EQUIVALENT_FUNCTIONAL_TERMINALS_ASSIGNMENT_H

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

class AP210ARM_API equivalent_functional_terminals_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 535};

   private:
      // Required attributes
      class functional_unit_usage_view_terminal_definition *_equivalent_terminals[2000];
      STR _name;

      // Optional attributes

   protected:
      equivalent_functional_terminals_assignment();

   public:
      ~equivalent_functional_terminals_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static equivalent_functional_terminals_assignment *InstanceOf(ARMObject *);
      static equivalent_functional_terminals_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static equivalent_functional_terminals_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
