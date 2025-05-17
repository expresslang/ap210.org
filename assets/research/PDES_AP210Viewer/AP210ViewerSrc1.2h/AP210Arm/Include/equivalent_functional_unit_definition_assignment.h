#ifndef EQUIVALENT_FUNCTIONAL_UNIT_DEFINITION_ASSIGNMENT_H
#define EQUIVALENT_FUNCTIONAL_UNIT_DEFINITION_ASSIGNMENT_H

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

class AP210ARM_API equivalent_functional_unit_definition_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 537};

   private:
      // Required attributes
      class functional_unit_definition *_equivalent_functional_unit_definitions[2000];
      STR _name;

      // Optional attributes

   protected:
      equivalent_functional_unit_definition_assignment();

   public:
      ~equivalent_functional_unit_definition_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static equivalent_functional_unit_definition_assignment *InstanceOf(ARMObject *);
      static equivalent_functional_unit_definition_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static equivalent_functional_unit_definition_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
