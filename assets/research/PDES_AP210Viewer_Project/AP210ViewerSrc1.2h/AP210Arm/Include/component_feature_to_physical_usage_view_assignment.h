#ifndef COMPONENT_FEATURE_TO_PHYSICAL_USAGE_VIEW_ASSIGNMENT_H
#define COMPONENT_FEATURE_TO_PHYSICAL_USAGE_VIEW_ASSIGNMENT_H

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

class AP210ARM_API component_feature_to_physical_usage_view_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 306};

   private:
      // Required attributes
      class part_feature *_defined_part_feature;
      class component_feature *_assigned_design_object;

      // Optional attributes

   protected:
      component_feature_to_physical_usage_view_assignment();

   public:
      ~component_feature_to_physical_usage_view_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static component_feature_to_physical_usage_view_assignment *InstanceOf(ARMObject *);
      static component_feature_to_physical_usage_view_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static component_feature_to_physical_usage_view_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
