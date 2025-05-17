#ifndef COMPONENT_PLACEMENT_RESTRICTION_ASSIGNMENT_H
#define COMPONENT_PLACEMENT_RESTRICTION_ASSIGNMENT_H

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

class AP210ARM_API component_placement_restriction_assignment:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 318};

   private:
      // Required attributes
      class mounting_restriction_area *_area;
      class item_restricted_requirement_occurrence *_requirement;
      RoseBoolean _components_permitted;

      // Optional attributes
      class datum_based_length_measure *_maximum_negative_component_height;
      class datum_based_length_measure *_maximum_positive_component_height;
      class datum_based_length_measure *_maximum_mounting_clearance;
      class datum_based_length_measure *_minimum_mounting_clearance;

   protected:
      component_placement_restriction_assignment();

   public:
      ~component_placement_restriction_assignment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static component_placement_restriction_assignment *InstanceOf(ARMObject *);
      static component_placement_restriction_assignment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static component_placement_restriction_assignment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
