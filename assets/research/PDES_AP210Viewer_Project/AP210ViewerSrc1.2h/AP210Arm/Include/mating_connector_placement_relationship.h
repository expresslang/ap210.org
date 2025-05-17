#ifndef MATING_CONNECTOR_PLACEMENT_RELATIONSHIP_H
#define MATING_CONNECTOR_PLACEMENT_RELATIONSHIP_H

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

class AP210ARM_API mating_connector_placement_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 651};

   private:
      // Required attributes
      class mating_connector_component *_placed_connector;
      class next_higher_assembly_interface_requirement *_interface_context;
      class axis_placement *_connector_placement;

      // Optional attributes

   protected:
      mating_connector_placement_relationship();

   public:
      ~mating_connector_placement_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static mating_connector_placement_relationship *InstanceOf(ARMObject *);
      static mating_connector_placement_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static mating_connector_placement_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
