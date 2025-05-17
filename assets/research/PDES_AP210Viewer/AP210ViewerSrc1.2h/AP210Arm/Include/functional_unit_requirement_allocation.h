#ifndef FUNCTIONAL_UNIT_REQUIREMENT_ALLOCATION_H
#define FUNCTIONAL_UNIT_REQUIREMENT_ALLOCATION_H

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

class AP210ARM_API functional_unit_requirement_allocation:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 283};

   private:
      // Required attributes
      class ee_requirement_occurrence *_functional_requirement;
      class functional_unit *_functional_unit_assignment;

      // Optional attributes

   protected:
      functional_unit_requirement_allocation();

   public:
      ~functional_unit_requirement_allocation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static functional_unit_requirement_allocation *InstanceOf(ARMObject *);
      static functional_unit_requirement_allocation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static functional_unit_requirement_allocation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
