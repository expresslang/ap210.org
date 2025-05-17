#ifndef THERMAL_ISOLATION_REQUIREMENT_ASSIGNMENT_H
#define THERMAL_ISOLATION_REQUIREMENT_ASSIGNMENT_H

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

class AP210ARM_API thermal_isolation_requirement_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 832};

   private:
      // Required attributes
      class thermal_isolation_removal_structure *_resulting_structure;
      class ee_requirement_occurrence *_thermal_isolation_spacing_requirement;
      class ee_requirement_occurrence *_effective_current_capacity_requirement;
      class ee_requirement_occurrence *_angular_orientation_requirement;

      // Optional attributes

   protected:
      thermal_isolation_requirement_assignment();

   public:
      ~thermal_isolation_requirement_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static thermal_isolation_requirement_assignment *InstanceOf(ARMObject *);
      static thermal_isolation_requirement_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static thermal_isolation_requirement_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
