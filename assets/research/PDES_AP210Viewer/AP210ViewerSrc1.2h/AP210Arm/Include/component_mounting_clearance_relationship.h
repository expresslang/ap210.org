#ifndef COMPONENT_MOUNTING_CLEARANCE_RELATIONSHIP_H
#define COMPONENT_MOUNTING_CLEARANCE_RELATIONSHIP_H

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

class AP210ARM_API component_mounting_clearance_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 310};

   private:
      // Required attributes
      class next_higher_assembly_relationship *_previously_placed_component;
      class next_higher_assembly_relationship *_current_component;
      class length_data_element *_minimum_mounting_clearance;

      // Optional attributes
      class length_data_element *_maximum_mounting_clearance;

   protected:
      component_mounting_clearance_relationship();

   public:
      ~component_mounting_clearance_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static component_mounting_clearance_relationship *InstanceOf(ARMObject *);
      static component_mounting_clearance_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static component_mounting_clearance_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
