#ifndef FUNCTIONAL_UNIT_DEFINITION_H
#define FUNCTIONAL_UNIT_DEFINITION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ee_product_definition.h>

// Unions

// Enumerations

class AP210ARM_API functional_unit_definition:
public ee_product_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 47};

   private:
      // Required attributes
      STR _ee_function;

      // Optional attributes
      class analytical_representation *_analytical_functional_unit_representation[2000];

   protected:
      functional_unit_definition();

   public:
      ~functional_unit_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static functional_unit_definition *InstanceOf(ARMObject *);
      static functional_unit_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static functional_unit_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
