#ifndef CONSTRAINT_OCCURRENCE_H
#define CONSTRAINT_OCCURRENCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ee_requirement_occurrence.h>

// Unions

// Enumerations

class AP210ARM_API constraint_occurrence:
public ee_requirement_occurrence
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 396};

   private:
      // Required attributes
      class ee_rule_version *_design_constraint;

      // Optional attributes

   protected:
      constraint_occurrence();

   public:
      ~constraint_occurrence();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static constraint_occurrence *InstanceOf(ARMObject *);
      static constraint_occurrence *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static constraint_occurrence *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
