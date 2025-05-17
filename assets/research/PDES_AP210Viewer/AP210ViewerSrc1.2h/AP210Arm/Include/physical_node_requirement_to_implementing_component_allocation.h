#ifndef PHYSICAL_NODE_REQUIREMENT_TO_IMPLEMENTING_COMPONENT_ALLOCATION_H
#define PHYSICAL_NODE_REQUIREMENT_TO_IMPLEMENTING_COMPONENT_ALLOCATION_H

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

class AP210ARM_API physical_node_requirement_to_implementing_component_allocation:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 700};

   private:
      // Required attributes
      class physical_connectivity_definition *_physical_node_requirement;
      class assembly_component *_implementation_component;

      // Optional attributes
      class interface_mounted_join *_implementation_interface_joint_set[2000];
      class assembly_joint *_implementation_joint_set[2000];

   protected:
      physical_node_requirement_to_implementing_component_allocation();

   public:
      ~physical_node_requirement_to_implementing_component_allocation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static physical_node_requirement_to_implementing_component_allocation *InstanceOf(ARMObject *);
      static physical_node_requirement_to_implementing_component_allocation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static physical_node_requirement_to_implementing_component_allocation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
