#ifndef FUNCTIONAL_SPECIFICATION_TO_REQUIREMENT_OCCURRENCE_ASSIGNMENT_H
#define FUNCTIONAL_SPECIFICATION_TO_REQUIREMENT_OCCURRENCE_ASSIGNMENT_H

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

class AP210ARM_API functional_specification_to_requirement_occurrence_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 560};

   private:
      // Required attributes
      class functional_specification *_specification_data;
      class ee_requirement_occurrence *_assigned_requirement_occurrence;

      // Optional attributes

   protected:
      functional_specification_to_requirement_occurrence_assignment();

   public:
      ~functional_specification_to_requirement_occurrence_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static functional_specification_to_requirement_occurrence_assignment *InstanceOf(ARMObject *);
      static functional_specification_to_requirement_occurrence_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static functional_specification_to_requirement_occurrence_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
