#ifndef STRATUM_CONCEPT_TO_PHYSICAL_USAGE_VIEW_ASSIGNMENT_H
#define STRATUM_CONCEPT_TO_PHYSICAL_USAGE_VIEW_ASSIGNMENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <stratum_concept.h>

// Enumerations

class AP210ARM_API stratum_concept_to_physical_usage_view_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 801};

   private:
      // Required attributes
      union stratum_concept *_assigned_design_object;
      class part_feature *_defined_part_feature;

      // Optional attributes

   protected:
      stratum_concept_to_physical_usage_view_assignment();

   public:
      ~stratum_concept_to_physical_usage_view_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static stratum_concept_to_physical_usage_view_assignment *InstanceOf(ARMObject *);
      static stratum_concept_to_physical_usage_view_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static stratum_concept_to_physical_usage_view_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
