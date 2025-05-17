#ifndef TOLERANCE_SPECIFIC_RESTRAINT_CONDITION_H
#define TOLERANCE_SPECIFIC_RESTRAINT_CONDITION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <restraint_condition.h>

// Unions

// Enumerations

class AP210ARM_API tolerance_specific_restraint_condition:
public restraint_condition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 836};

   private:
      // Required attributes
      union geometric_or_dimension_select *_affected_tolerances[2000];

      // Optional attributes

   protected:
      tolerance_specific_restraint_condition();

   public:
      ~tolerance_specific_restraint_condition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static tolerance_specific_restraint_condition *InstanceOf(ARMObject *);
      static tolerance_specific_restraint_condition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static tolerance_specific_restraint_condition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
