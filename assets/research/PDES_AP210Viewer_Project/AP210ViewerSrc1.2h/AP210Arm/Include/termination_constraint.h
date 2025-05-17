#ifndef TERMINATION_CONSTRAINT_H
#define TERMINATION_CONSTRAINT_H

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

class AP210ARM_API termination_constraint:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 825};

   private:
      // Required attributes
      class mating_connector_termination *_constrained_termination[2000];
      class ee_requirement_occurrence *_termination_usage_constraint;

      // Optional attributes

   protected:
      termination_constraint();

   public:
      ~termination_constraint();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static termination_constraint *InstanceOf(ARMObject *);
      static termination_constraint *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static termination_constraint *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
